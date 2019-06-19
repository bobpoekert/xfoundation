import re 

functions = set([])

egl_re = re.compile(r'^EGLAPI\s+(.*).*?EGLAPIENTRY\s+(.*?)\s+\((.*?)\).*')
gles_re = re.compile(r'^GL_APICALL\s+(.*).*?GL_APIENTRY\s+(.*?)\s+\((.*?)\).*')

with open('./platform/generic/include/EGL/egl.h', 'r') as inf:
    for row in inf:
        if 'EGLAPIENTRY' in row and 'typedef' not in row:
            match = egl_re.match(row)
            args = tuple(match.group(3).split(','))
            if args == ('void',):
                args = tuple()
            functions.add((match.group(1).strip(), match.group(2), args))

with open('./platform/generic/include/GLES2/gl2.h', 'r') as inf:
    for row in inf:
        if 'GL_APIENTRY ' in row and 'typedef' not in row:
            match = gles_re.match(row)
            args = tuple(match.group(3).split(','))
            if args == ('void',):
                args = tuple()
            functions.add((match.group(1).strip(), match.group(2), args))

opcodes = 'enum { %s } XF_GL_Opcode;' % ',\n'.join(['XF_GL_OPCODE_%s' % v[1] for v in functions])

structs = ['typedef struct XF_GL_Op_Args_%s {XF_GL_Op __xf_op; %s} XF_GL_Op_Args_%s' % (
    f[1], ';'.join(f[2]), f[1]
) for f in functions]

return_structs = ['typedef struct XF_GL_Op_Return_%s { XF_GL_Op __xf_op; %s v; } XF_GL_Op_Return_%s' % (
    name, retval, name
) for retval, name, args in functions if retval != 'void']

def split_arg(v):
    if '*' in v:
        parts = v.split('*')
        parts[0] += ' *'
    else:
        parts = v.split()
    return (' '.join(parts[:-1]), parts[-1])

def packer_function(_args):
    return_type, name, args = _args
    typename = 'XF_GL_Op_Args_%s' % name
    res ='''
    XF_GL_Op xf_pack_%(fname)s(%(args)s) {
        %(typename)s *res = malloc(sizeof(%(typename)s));
        res->__xf_op->opcode = XF_GL_OPCODE_%(fname)s;
    ''' % dict(fname=name, typename=typename, args=', '.join(args))
    for arg in args:
        arg_type, arg_name = split_arg(arg)
        res += 'res->%s = %s;\n' % (arg_name, arg_name)
    res += '''
        return res;
    }\n'''
    return res


dispatcher_cases = []
for return_type, name, args in functions:
    v = 'case XF_GL_OPCODE_%s:\n' % name 
    if return_type != 'void':
        v += 'XF_GL_Op_Args_%s *inp_args = (XF_GL_Op_Args_%s *)inp;' % (name, name)
        v += 'XF_GL_Op_Return_%s *retval = malloc(sizeof(XF_GL_Op_Return_%s));\n' % (name, name)
        v += 'retval->v = %s(' % name 
    else:
        v += '%s(' % name
    arg_params = []
    for arg in args:
        arg_type, arg_name = split_arg(arg)
        arg_params.append('inp_args->%s' % arg_name)
    v += ', '.join(arg_params)
    v += ');\n'
    v += 'free(inp);'
    if return_type != 'void':
        v += 'outp = (XF_GL_Op *) retval;'
    v += 'break;'
    dispatcher_cases.append(v)

dispatcher = '''
    typedef struct XF_GL_Op {
        XF_GL_Opcode opcode;
        size_t id;
    } XF_GL_Op;

    XF_GL_Op *xf_gl_eval_op(XF_GL_Op *inp) {
        XF_GL_Op *outp;
        switch(inp->opcode) {

            %s

            default:
                return 0;
        }
        outp->opcode = inp->opcode;
        outp->id = inp->id;
        return outp;
    }
''' % '\n'.join(dispatcher_cases)

for f in functions:
    dispatcher += packer_function(f)
    dispatcher += '\n'

with open('./platform/generic/include/xf_gl_dispatch.h', 'w') as outf:
    outf.write('#include <EGL/egl.h>\n#include <GLES2/gl2.h>\n\n')
    outf.write(opcodes)
    outf.write('\n'.join(structs))
    outf.write('\n'.join(return_structs))
    outf.write(dispatcher)
