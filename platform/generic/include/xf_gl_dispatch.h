#include <EGL/egl.h>
#include <GLES2/gl2.h>

enum { XF_GL_OPCODE_glPixelStorei,
XF_GL_OPCODE_glUniformMatrix4fv,
XF_GL_OPCODE_glShaderBinary,
XF_GL_OPCODE_eglQueryAPI,
XF_GL_OPCODE_glGetBooleanv,
XF_GL_OPCODE_glBindFramebuffer,
XF_GL_OPCODE_eglGetCurrentContext,
XF_GL_OPCODE_glCompileShader,
XF_GL_OPCODE_glCompressedTexImage2D,
XF_GL_OPCODE_glGenerateMipmap,
XF_GL_OPCODE_eglGetConfigAttrib,
XF_GL_OPCODE_glDeleteShader,
XF_GL_OPCODE_eglCreatePlatformWindowSurface,
XF_GL_OPCODE_glPolygonOffset,
XF_GL_OPCODE_glFrontFace,
XF_GL_OPCODE_glUniform3iv,
XF_GL_OPCODE_glGetTexParameteriv,
XF_GL_OPCODE_glVertexAttrib3f,
XF_GL_OPCODE_glVertexAttrib2fv,
XF_GL_OPCODE_glSampleCoverage,
XF_GL_OPCODE_glUniformMatrix3fv,
XF_GL_OPCODE_glGenFramebuffers,
XF_GL_OPCODE_glFramebufferTexture2D,
XF_GL_OPCODE_eglWaitSync,
XF_GL_OPCODE_glDeleteRenderbuffers,
XF_GL_OPCODE_glAttachShader,
XF_GL_OPCODE_glUniform2i,
XF_GL_OPCODE_glGetVertexAttribPointerv,
XF_GL_OPCODE_glBlendColor,
XF_GL_OPCODE_glTexParameterfv,
XF_GL_OPCODE_eglSurfaceAttrib,
XF_GL_OPCODE_glTexParameteri,
XF_GL_OPCODE_glIsRenderbuffer,
XF_GL_OPCODE_glDeleteTextures,
XF_GL_OPCODE_eglWaitClient,
XF_GL_OPCODE_glCopyTexSubImage2D,
XF_GL_OPCODE_glDetachShader,
XF_GL_OPCODE_glLineWidth,
XF_GL_OPCODE_glFinish,
XF_GL_OPCODE_glScissor,
XF_GL_OPCODE_glBlendFuncSeparate,
XF_GL_OPCODE_glStencilFunc,
XF_GL_OPCODE_glClear,
XF_GL_OPCODE_eglDestroySurface,
XF_GL_OPCODE_eglMakeCurrent,
XF_GL_OPCODE_glReadPixels,
XF_GL_OPCODE_eglDestroyImage,
XF_GL_OPCODE_glCompressedTexSubImage2D,
XF_GL_OPCODE_glCullFace,
XF_GL_OPCODE_glUniform1f,
XF_GL_OPCODE_glShaderSource,
XF_GL_OPCODE_eglTerminate,
XF_GL_OPCODE_glUniform4iv,
XF_GL_OPCODE_glGenTextures,
XF_GL_OPCODE_glGetError,
XF_GL_OPCODE_glVertexAttrib2f,
XF_GL_OPCODE_glHint,
XF_GL_OPCODE_glFramebufferRenderbuffer,
XF_GL_OPCODE_eglWaitGL,
XF_GL_OPCODE_eglReleaseTexImage,
XF_GL_OPCODE_glUniformMatrix2fv,
XF_GL_OPCODE_glGetVertexAttribfv,
XF_GL_OPCODE_glDeleteProgram,
XF_GL_OPCODE_glBufferData,
XF_GL_OPCODE_glValidateProgram,
XF_GL_OPCODE_glGetShaderInfoLog,
XF_GL_OPCODE_glRenderbufferStorage,
XF_GL_OPCODE_glVertexAttrib1fv,
XF_GL_OPCODE_eglBindAPI,
XF_GL_OPCODE_glDeleteFramebuffers,
XF_GL_OPCODE_glEnableVertexAttribArray,
XF_GL_OPCODE_eglGetSyncAttrib,
XF_GL_OPCODE_glGetRenderbufferParameteriv,
XF_GL_OPCODE_glGetProgramInfoLog,
XF_GL_OPCODE_glUniform1iv,
XF_GL_OPCODE_eglGetCurrentDisplay,
XF_GL_OPCODE_glGetActiveUniform,
XF_GL_OPCODE_glUniform3i,
XF_GL_OPCODE_eglCreatePixmapSurface,
XF_GL_OPCODE_eglGetPlatformDisplay,
XF_GL_OPCODE_glGetBufferParameteriv,
XF_GL_OPCODE_glUniform3f,
XF_GL_OPCODE_glDrawElements,
XF_GL_OPCODE_glIsProgram,
XF_GL_OPCODE_glDeleteBuffers,
XF_GL_OPCODE_glIsTexture,
XF_GL_OPCODE_eglCreateContext,
XF_GL_OPCODE_glTexParameterf,
XF_GL_OPCODE_eglDestroyContext,
XF_GL_OPCODE_glVertexAttrib4f,
XF_GL_OPCODE_glUniform4f,
XF_GL_OPCODE_glGetFramebufferAttachmentParameteriv,
XF_GL_OPCODE_glGetShaderSource,
XF_GL_OPCODE_glStencilFuncSeparate,
XF_GL_OPCODE_glStencilMaskSeparate,
XF_GL_OPCODE_glBindAttribLocation,
XF_GL_OPCODE_eglWaitNative,
XF_GL_OPCODE_glBindBuffer,
XF_GL_OPCODE_glGenBuffers,
XF_GL_OPCODE_glUniform1fv,
XF_GL_OPCODE_glUniform3fv,
XF_GL_OPCODE_glReleaseShaderCompiler,
XF_GL_OPCODE_glCreateShader,
XF_GL_OPCODE_glDepthMask,
XF_GL_OPCODE_glGenRenderbuffers,
XF_GL_OPCODE_glStencilOpSeparate,
XF_GL_OPCODE_glUniform4fv,
XF_GL_OPCODE_glUniform1i,
XF_GL_OPCODE_glLinkProgram,
XF_GL_OPCODE_eglCreateSync,
XF_GL_OPCODE_glTexImage2D,
XF_GL_OPCODE_glGetUniformLocation,
XF_GL_OPCODE_glTexSubImage2D,
XF_GL_OPCODE_eglGetConfigs,
XF_GL_OPCODE_eglCreatePlatformPixmapSurface,
XF_GL_OPCODE_eglGetError,
XF_GL_OPCODE_eglSwapInterval,
XF_GL_OPCODE_glVertexAttribPointer,
XF_GL_OPCODE_glStencilOp,
XF_GL_OPCODE_glClearStencil,
XF_GL_OPCODE_glViewport,
XF_GL_OPCODE_eglCopyBuffers,
XF_GL_OPCODE_glActiveTexture,
XF_GL_OPCODE_eglReleaseThread,
XF_GL_OPCODE_glCopyTexImage2D,
XF_GL_OPCODE_glGetProgramiv,
XF_GL_OPCODE_glEnable,
XF_GL_OPCODE_glGetVertexAttribiv,
XF_GL_OPCODE_glGetUniformfv,
XF_GL_OPCODE_eglQuerySurface,
XF_GL_OPCODE_glBindRenderbuffer,
XF_GL_OPCODE_eglBindTexImage,
XF_GL_OPCODE_glGetAttribLocation,
XF_GL_OPCODE_glGetFloatv,
XF_GL_OPCODE_glIsBuffer,
XF_GL_OPCODE_glUniform2fv,
XF_GL_OPCODE_glVertexAttrib4fv,
XF_GL_OPCODE_eglCreatePbufferSurface,
XF_GL_OPCODE_eglCreateImage,
XF_GL_OPCODE_eglDestroySync,
XF_GL_OPCODE_glGetShaderPrecisionFormat,
XF_GL_OPCODE_glBindTexture,
XF_GL_OPCODE_eglGetCurrentSurface,
XF_GL_OPCODE_glGetShaderiv,
XF_GL_OPCODE_eglClientWaitSync,
XF_GL_OPCODE_glUseProgram,
XF_GL_OPCODE_glClearColor,
XF_GL_OPCODE_glGetActiveAttrib,
XF_GL_OPCODE_eglInitialize,
XF_GL_OPCODE_eglQueryContext,
XF_GL_OPCODE_glFlush,
XF_GL_OPCODE_glDepthRangef,
XF_GL_OPCODE_eglGetProcAddress,
XF_GL_OPCODE_glIsFramebuffer,
XF_GL_OPCODE_glVertexAttrib3fv,
XF_GL_OPCODE_glBlendFunc,
XF_GL_OPCODE_glGetAttachedShaders,
XF_GL_OPCODE_glBlendEquationSeparate,
XF_GL_OPCODE_glTexParameteriv,
XF_GL_OPCODE_eglSwapBuffers,
XF_GL_OPCODE_eglCreateWindowSurface,
XF_GL_OPCODE_glDisableVertexAttribArray,
XF_GL_OPCODE_glGetUniformiv,
XF_GL_OPCODE_glBlendEquation,
XF_GL_OPCODE_glDisable,
XF_GL_OPCODE_glGetTexParameterfv,
XF_GL_OPCODE_glBufferSubData,
XF_GL_OPCODE_glDepthFunc,
XF_GL_OPCODE_eglCreatePbufferFromClientBuffer,
XF_GL_OPCODE_glClearDepthf,
XF_GL_OPCODE_glGetString,
XF_GL_OPCODE_glColorMask,
XF_GL_OPCODE_eglQueryString,
XF_GL_OPCODE_glIsShader,
XF_GL_OPCODE_glGetIntegerv,
XF_GL_OPCODE_eglGetDisplay,
XF_GL_OPCODE_glCheckFramebufferStatus,
XF_GL_OPCODE_glStencilMask,
XF_GL_OPCODE_glUniform4i,
XF_GL_OPCODE_glDrawArrays,
XF_GL_OPCODE_glUniform2iv,
XF_GL_OPCODE_glUniform2f,
XF_GL_OPCODE_glVertexAttrib1f,
XF_GL_OPCODE_glCreateProgram,
XF_GL_OPCODE_eglChooseConfig,
XF_GL_OPCODE_glIsEnabled } XF_GL_Opcode;typedef struct XF_GL_Op_Args_glPixelStorei {XF_GL_Op __xf_op; GLenum pname; GLint param} XF_GL_Op_Args_glPixelStorei
typedef struct XF_GL_Op_Args_glUniformMatrix4fv {XF_GL_Op __xf_op; GLint location; GLsizei count; GLboolean transpose; const GLfloat *value} XF_GL_Op_Args_glUniformMatrix4fv
typedef struct XF_GL_Op_Args_glShaderBinary {XF_GL_Op __xf_op; GLsizei count; const GLuint *shaders; GLenum binaryformat; const void *binary; GLsizei length} XF_GL_Op_Args_glShaderBinary
typedef struct XF_GL_Op_Args_eglQueryAPI {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglQueryAPI
typedef struct XF_GL_Op_Args_glGetBooleanv {XF_GL_Op __xf_op; GLenum pname; GLboolean *data} XF_GL_Op_Args_glGetBooleanv
typedef struct XF_GL_Op_Args_glBindFramebuffer {XF_GL_Op __xf_op; GLenum target; GLuint framebuffer} XF_GL_Op_Args_glBindFramebuffer
typedef struct XF_GL_Op_Args_eglGetCurrentContext {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglGetCurrentContext
typedef struct XF_GL_Op_Args_glCompileShader {XF_GL_Op __xf_op; GLuint shader} XF_GL_Op_Args_glCompileShader
typedef struct XF_GL_Op_Args_glCompressedTexImage2D {XF_GL_Op __xf_op; GLenum target; GLint level; GLenum internalformat; GLsizei width; GLsizei height; GLint border; GLsizei imageSize; const void *data} XF_GL_Op_Args_glCompressedTexImage2D
typedef struct XF_GL_Op_Args_glGenerateMipmap {XF_GL_Op __xf_op; GLenum target} XF_GL_Op_Args_glGenerateMipmap
typedef struct XF_GL_Op_Args_eglGetConfigAttrib {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; EGLint attribute; EGLint *value} XF_GL_Op_Args_eglGetConfigAttrib
typedef struct XF_GL_Op_Args_glDeleteShader {XF_GL_Op __xf_op; GLuint shader} XF_GL_Op_Args_glDeleteShader
typedef struct XF_GL_Op_Args_eglCreatePlatformWindowSurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; void *native_window; const EGLAttrib *attrib_list} XF_GL_Op_Args_eglCreatePlatformWindowSurface
typedef struct XF_GL_Op_Args_glPolygonOffset {XF_GL_Op __xf_op; GLfloat factor; GLfloat units} XF_GL_Op_Args_glPolygonOffset
typedef struct XF_GL_Op_Args_glFrontFace {XF_GL_Op __xf_op; GLenum mode} XF_GL_Op_Args_glFrontFace
typedef struct XF_GL_Op_Args_glUniform3iv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLint *value} XF_GL_Op_Args_glUniform3iv
typedef struct XF_GL_Op_Args_glGetTexParameteriv {XF_GL_Op __xf_op; GLenum target; GLenum pname; GLint *params} XF_GL_Op_Args_glGetTexParameteriv
typedef struct XF_GL_Op_Args_glVertexAttrib3f {XF_GL_Op __xf_op; GLuint index; GLfloat x; GLfloat y; GLfloat z} XF_GL_Op_Args_glVertexAttrib3f
typedef struct XF_GL_Op_Args_glVertexAttrib2fv {XF_GL_Op __xf_op; GLuint index; const GLfloat *v} XF_GL_Op_Args_glVertexAttrib2fv
typedef struct XF_GL_Op_Args_glSampleCoverage {XF_GL_Op __xf_op; GLfloat value; GLboolean invert} XF_GL_Op_Args_glSampleCoverage
typedef struct XF_GL_Op_Args_glUniformMatrix3fv {XF_GL_Op __xf_op; GLint location; GLsizei count; GLboolean transpose; const GLfloat *value} XF_GL_Op_Args_glUniformMatrix3fv
typedef struct XF_GL_Op_Args_glGenFramebuffers {XF_GL_Op __xf_op; GLsizei n; GLuint *framebuffers} XF_GL_Op_Args_glGenFramebuffers
typedef struct XF_GL_Op_Args_glFramebufferTexture2D {XF_GL_Op __xf_op; GLenum target; GLenum attachment; GLenum textarget; GLuint texture; GLint level} XF_GL_Op_Args_glFramebufferTexture2D
typedef struct XF_GL_Op_Args_eglWaitSync {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSync sync; EGLint flags} XF_GL_Op_Args_eglWaitSync
typedef struct XF_GL_Op_Args_glDeleteRenderbuffers {XF_GL_Op __xf_op; GLsizei n; const GLuint *renderbuffers} XF_GL_Op_Args_glDeleteRenderbuffers
typedef struct XF_GL_Op_Args_glAttachShader {XF_GL_Op __xf_op; GLuint program; GLuint shader} XF_GL_Op_Args_glAttachShader
typedef struct XF_GL_Op_Args_glUniform2i {XF_GL_Op __xf_op; GLint location; GLint v0; GLint v1} XF_GL_Op_Args_glUniform2i
typedef struct XF_GL_Op_Args_glGetVertexAttribPointerv {XF_GL_Op __xf_op; GLuint index; GLenum pname; void **pointer} XF_GL_Op_Args_glGetVertexAttribPointerv
typedef struct XF_GL_Op_Args_glBlendColor {XF_GL_Op __xf_op; GLfloat red; GLfloat green; GLfloat blue; GLfloat alpha} XF_GL_Op_Args_glBlendColor
typedef struct XF_GL_Op_Args_glTexParameterfv {XF_GL_Op __xf_op; GLenum target; GLenum pname; const GLfloat *params} XF_GL_Op_Args_glTexParameterfv
typedef struct XF_GL_Op_Args_eglSurfaceAttrib {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface; EGLint attribute; EGLint value} XF_GL_Op_Args_eglSurfaceAttrib
typedef struct XF_GL_Op_Args_glTexParameteri {XF_GL_Op __xf_op; GLenum target; GLenum pname; GLint param} XF_GL_Op_Args_glTexParameteri
typedef struct XF_GL_Op_Args_glIsRenderbuffer {XF_GL_Op __xf_op; GLuint renderbuffer} XF_GL_Op_Args_glIsRenderbuffer
typedef struct XF_GL_Op_Args_glDeleteTextures {XF_GL_Op __xf_op; GLsizei n; const GLuint *textures} XF_GL_Op_Args_glDeleteTextures
typedef struct XF_GL_Op_Args_eglWaitClient {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglWaitClient
typedef struct XF_GL_Op_Args_glCopyTexSubImage2D {XF_GL_Op __xf_op; GLenum target; GLint level; GLint xoffset; GLint yoffset; GLint x; GLint y; GLsizei width; GLsizei height} XF_GL_Op_Args_glCopyTexSubImage2D
typedef struct XF_GL_Op_Args_glDetachShader {XF_GL_Op __xf_op; GLuint program; GLuint shader} XF_GL_Op_Args_glDetachShader
typedef struct XF_GL_Op_Args_glLineWidth {XF_GL_Op __xf_op; GLfloat width} XF_GL_Op_Args_glLineWidth
typedef struct XF_GL_Op_Args_glFinish {XF_GL_Op __xf_op; } XF_GL_Op_Args_glFinish
typedef struct XF_GL_Op_Args_glScissor {XF_GL_Op __xf_op; GLint x; GLint y; GLsizei width; GLsizei height} XF_GL_Op_Args_glScissor
typedef struct XF_GL_Op_Args_glBlendFuncSeparate {XF_GL_Op __xf_op; GLenum sfactorRGB; GLenum dfactorRGB; GLenum sfactorAlpha; GLenum dfactorAlpha} XF_GL_Op_Args_glBlendFuncSeparate
typedef struct XF_GL_Op_Args_glStencilFunc {XF_GL_Op __xf_op; GLenum func; GLint ref; GLuint mask} XF_GL_Op_Args_glStencilFunc
typedef struct XF_GL_Op_Args_glClear {XF_GL_Op __xf_op; GLbitfield mask} XF_GL_Op_Args_glClear
typedef struct XF_GL_Op_Args_eglDestroySurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface} XF_GL_Op_Args_eglDestroySurface
typedef struct XF_GL_Op_Args_eglMakeCurrent {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface draw; EGLSurface read; EGLContext ctx} XF_GL_Op_Args_eglMakeCurrent
typedef struct XF_GL_Op_Args_glReadPixels {XF_GL_Op __xf_op; GLint x; GLint y; GLsizei width; GLsizei height; GLenum format; GLenum type; void *pixels} XF_GL_Op_Args_glReadPixels
typedef struct XF_GL_Op_Args_eglDestroyImage {XF_GL_Op __xf_op; EGLDisplay dpy; EGLImage image} XF_GL_Op_Args_eglDestroyImage
typedef struct XF_GL_Op_Args_glCompressedTexSubImage2D {XF_GL_Op __xf_op; GLenum target; GLint level; GLint xoffset; GLint yoffset; GLsizei width; GLsizei height; GLenum format; GLsizei imageSize; const void *data} XF_GL_Op_Args_glCompressedTexSubImage2D
typedef struct XF_GL_Op_Args_glCullFace {XF_GL_Op __xf_op; GLenum mode} XF_GL_Op_Args_glCullFace
typedef struct XF_GL_Op_Args_glUniform1f {XF_GL_Op __xf_op; GLint location; GLfloat v0} XF_GL_Op_Args_glUniform1f
typedef struct XF_GL_Op_Args_glShaderSource {XF_GL_Op __xf_op; GLuint shader; GLsizei count; const GLchar *const*string; const GLint *length} XF_GL_Op_Args_glShaderSource
typedef struct XF_GL_Op_Args_eglTerminate {XF_GL_Op __xf_op; EGLDisplay dpy} XF_GL_Op_Args_eglTerminate
typedef struct XF_GL_Op_Args_glUniform4iv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLint *value} XF_GL_Op_Args_glUniform4iv
typedef struct XF_GL_Op_Args_glGenTextures {XF_GL_Op __xf_op; GLsizei n; GLuint *textures} XF_GL_Op_Args_glGenTextures
typedef struct XF_GL_Op_Args_glGetError {XF_GL_Op __xf_op; } XF_GL_Op_Args_glGetError
typedef struct XF_GL_Op_Args_glVertexAttrib2f {XF_GL_Op __xf_op; GLuint index; GLfloat x; GLfloat y} XF_GL_Op_Args_glVertexAttrib2f
typedef struct XF_GL_Op_Args_glHint {XF_GL_Op __xf_op; GLenum target; GLenum mode} XF_GL_Op_Args_glHint
typedef struct XF_GL_Op_Args_glFramebufferRenderbuffer {XF_GL_Op __xf_op; GLenum target; GLenum attachment; GLenum renderbuffertarget; GLuint renderbuffer} XF_GL_Op_Args_glFramebufferRenderbuffer
typedef struct XF_GL_Op_Args_eglWaitGL {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglWaitGL
typedef struct XF_GL_Op_Args_eglReleaseTexImage {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface; EGLint buffer} XF_GL_Op_Args_eglReleaseTexImage
typedef struct XF_GL_Op_Args_glUniformMatrix2fv {XF_GL_Op __xf_op; GLint location; GLsizei count; GLboolean transpose; const GLfloat *value} XF_GL_Op_Args_glUniformMatrix2fv
typedef struct XF_GL_Op_Args_glGetVertexAttribfv {XF_GL_Op __xf_op; GLuint index; GLenum pname; GLfloat *params} XF_GL_Op_Args_glGetVertexAttribfv
typedef struct XF_GL_Op_Args_glDeleteProgram {XF_GL_Op __xf_op; GLuint program} XF_GL_Op_Args_glDeleteProgram
typedef struct XF_GL_Op_Args_glBufferData {XF_GL_Op __xf_op; GLenum target; GLsizeiptr size; const void *data; GLenum usage} XF_GL_Op_Args_glBufferData
typedef struct XF_GL_Op_Args_glValidateProgram {XF_GL_Op __xf_op; GLuint program} XF_GL_Op_Args_glValidateProgram
typedef struct XF_GL_Op_Args_glGetShaderInfoLog {XF_GL_Op __xf_op; GLuint shader; GLsizei bufSize; GLsizei *length; GLchar *infoLog} XF_GL_Op_Args_glGetShaderInfoLog
typedef struct XF_GL_Op_Args_glRenderbufferStorage {XF_GL_Op __xf_op; GLenum target; GLenum internalformat; GLsizei width; GLsizei height} XF_GL_Op_Args_glRenderbufferStorage
typedef struct XF_GL_Op_Args_glVertexAttrib1fv {XF_GL_Op __xf_op; GLuint index; const GLfloat *v} XF_GL_Op_Args_glVertexAttrib1fv
typedef struct XF_GL_Op_Args_eglBindAPI {XF_GL_Op __xf_op; EGLenum api} XF_GL_Op_Args_eglBindAPI
typedef struct XF_GL_Op_Args_glDeleteFramebuffers {XF_GL_Op __xf_op; GLsizei n; const GLuint *framebuffers} XF_GL_Op_Args_glDeleteFramebuffers
typedef struct XF_GL_Op_Args_glEnableVertexAttribArray {XF_GL_Op __xf_op; GLuint index} XF_GL_Op_Args_glEnableVertexAttribArray
typedef struct XF_GL_Op_Args_eglGetSyncAttrib {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSync sync; EGLint attribute; EGLAttrib *value} XF_GL_Op_Args_eglGetSyncAttrib
typedef struct XF_GL_Op_Args_glGetRenderbufferParameteriv {XF_GL_Op __xf_op; GLenum target; GLenum pname; GLint *params} XF_GL_Op_Args_glGetRenderbufferParameteriv
typedef struct XF_GL_Op_Args_glGetProgramInfoLog {XF_GL_Op __xf_op; GLuint program; GLsizei bufSize; GLsizei *length; GLchar *infoLog} XF_GL_Op_Args_glGetProgramInfoLog
typedef struct XF_GL_Op_Args_glUniform1iv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLint *value} XF_GL_Op_Args_glUniform1iv
typedef struct XF_GL_Op_Args_eglGetCurrentDisplay {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglGetCurrentDisplay
typedef struct XF_GL_Op_Args_glGetActiveUniform {XF_GL_Op __xf_op; GLuint program; GLuint index; GLsizei bufSize; GLsizei *length; GLint *size; GLenum *type; GLchar *name} XF_GL_Op_Args_glGetActiveUniform
typedef struct XF_GL_Op_Args_glUniform3i {XF_GL_Op __xf_op; GLint location; GLint v0; GLint v1; GLint v2} XF_GL_Op_Args_glUniform3i
typedef struct XF_GL_Op_Args_eglCreatePixmapSurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; EGLNativePixmapType pixmap; const EGLint *attrib_list} XF_GL_Op_Args_eglCreatePixmapSurface
typedef struct XF_GL_Op_Args_eglGetPlatformDisplay {XF_GL_Op __xf_op; EGLenum platform; void *native_display; const EGLAttrib *attrib_list} XF_GL_Op_Args_eglGetPlatformDisplay
typedef struct XF_GL_Op_Args_glGetBufferParameteriv {XF_GL_Op __xf_op; GLenum target; GLenum pname; GLint *params} XF_GL_Op_Args_glGetBufferParameteriv
typedef struct XF_GL_Op_Args_glUniform3f {XF_GL_Op __xf_op; GLint location; GLfloat v0; GLfloat v1; GLfloat v2} XF_GL_Op_Args_glUniform3f
typedef struct XF_GL_Op_Args_glDrawElements {XF_GL_Op __xf_op; GLenum mode; GLsizei count; GLenum type; const void *indices} XF_GL_Op_Args_glDrawElements
typedef struct XF_GL_Op_Args_glIsProgram {XF_GL_Op __xf_op; GLuint program} XF_GL_Op_Args_glIsProgram
typedef struct XF_GL_Op_Args_glDeleteBuffers {XF_GL_Op __xf_op; GLsizei n; const GLuint *buffers} XF_GL_Op_Args_glDeleteBuffers
typedef struct XF_GL_Op_Args_glIsTexture {XF_GL_Op __xf_op; GLuint texture} XF_GL_Op_Args_glIsTexture
typedef struct XF_GL_Op_Args_eglCreateContext {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; EGLContext share_context; const EGLint *attrib_list} XF_GL_Op_Args_eglCreateContext
typedef struct XF_GL_Op_Args_glTexParameterf {XF_GL_Op __xf_op; GLenum target; GLenum pname; GLfloat param} XF_GL_Op_Args_glTexParameterf
typedef struct XF_GL_Op_Args_eglDestroyContext {XF_GL_Op __xf_op; EGLDisplay dpy; EGLContext ctx} XF_GL_Op_Args_eglDestroyContext
typedef struct XF_GL_Op_Args_glVertexAttrib4f {XF_GL_Op __xf_op; GLuint index; GLfloat x; GLfloat y; GLfloat z; GLfloat w} XF_GL_Op_Args_glVertexAttrib4f
typedef struct XF_GL_Op_Args_glUniform4f {XF_GL_Op __xf_op; GLint location; GLfloat v0; GLfloat v1; GLfloat v2; GLfloat v3} XF_GL_Op_Args_glUniform4f
typedef struct XF_GL_Op_Args_glGetFramebufferAttachmentParameteriv {XF_GL_Op __xf_op; GLenum target; GLenum attachment; GLenum pname; GLint *params} XF_GL_Op_Args_glGetFramebufferAttachmentParameteriv
typedef struct XF_GL_Op_Args_glGetShaderSource {XF_GL_Op __xf_op; GLuint shader; GLsizei bufSize; GLsizei *length; GLchar *source} XF_GL_Op_Args_glGetShaderSource
typedef struct XF_GL_Op_Args_glStencilFuncSeparate {XF_GL_Op __xf_op; GLenum face; GLenum func; GLint ref; GLuint mask} XF_GL_Op_Args_glStencilFuncSeparate
typedef struct XF_GL_Op_Args_glStencilMaskSeparate {XF_GL_Op __xf_op; GLenum face; GLuint mask} XF_GL_Op_Args_glStencilMaskSeparate
typedef struct XF_GL_Op_Args_glBindAttribLocation {XF_GL_Op __xf_op; GLuint program; GLuint index; const GLchar *name} XF_GL_Op_Args_glBindAttribLocation
typedef struct XF_GL_Op_Args_eglWaitNative {XF_GL_Op __xf_op; EGLint engine} XF_GL_Op_Args_eglWaitNative
typedef struct XF_GL_Op_Args_glBindBuffer {XF_GL_Op __xf_op; GLenum target; GLuint buffer} XF_GL_Op_Args_glBindBuffer
typedef struct XF_GL_Op_Args_glGenBuffers {XF_GL_Op __xf_op; GLsizei n; GLuint *buffers} XF_GL_Op_Args_glGenBuffers
typedef struct XF_GL_Op_Args_glUniform1fv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLfloat *value} XF_GL_Op_Args_glUniform1fv
typedef struct XF_GL_Op_Args_glUniform3fv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLfloat *value} XF_GL_Op_Args_glUniform3fv
typedef struct XF_GL_Op_Args_glReleaseShaderCompiler {XF_GL_Op __xf_op; } XF_GL_Op_Args_glReleaseShaderCompiler
typedef struct XF_GL_Op_Args_glCreateShader {XF_GL_Op __xf_op; GLenum type} XF_GL_Op_Args_glCreateShader
typedef struct XF_GL_Op_Args_glDepthMask {XF_GL_Op __xf_op; GLboolean flag} XF_GL_Op_Args_glDepthMask
typedef struct XF_GL_Op_Args_glGenRenderbuffers {XF_GL_Op __xf_op; GLsizei n; GLuint *renderbuffers} XF_GL_Op_Args_glGenRenderbuffers
typedef struct XF_GL_Op_Args_glStencilOpSeparate {XF_GL_Op __xf_op; GLenum face; GLenum sfail; GLenum dpfail; GLenum dppass} XF_GL_Op_Args_glStencilOpSeparate
typedef struct XF_GL_Op_Args_glUniform4fv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLfloat *value} XF_GL_Op_Args_glUniform4fv
typedef struct XF_GL_Op_Args_glUniform1i {XF_GL_Op __xf_op; GLint location; GLint v0} XF_GL_Op_Args_glUniform1i
typedef struct XF_GL_Op_Args_glLinkProgram {XF_GL_Op __xf_op; GLuint program} XF_GL_Op_Args_glLinkProgram
typedef struct XF_GL_Op_Args_eglCreateSync {XF_GL_Op __xf_op; EGLDisplay dpy; EGLenum type; const EGLAttrib *attrib_list} XF_GL_Op_Args_eglCreateSync
typedef struct XF_GL_Op_Args_glTexImage2D {XF_GL_Op __xf_op; GLenum target; GLint level; GLint internalformat; GLsizei width; GLsizei height; GLint border; GLenum format; GLenum type; const void *pixels} XF_GL_Op_Args_glTexImage2D
typedef struct XF_GL_Op_Args_glGetUniformLocation {XF_GL_Op __xf_op; GLuint program; const GLchar *name} XF_GL_Op_Args_glGetUniformLocation
typedef struct XF_GL_Op_Args_glTexSubImage2D {XF_GL_Op __xf_op; GLenum target; GLint level; GLint xoffset; GLint yoffset; GLsizei width; GLsizei height; GLenum format; GLenum type; const void *pixels} XF_GL_Op_Args_glTexSubImage2D
typedef struct XF_GL_Op_Args_eglGetConfigs {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig *configs; EGLint config_size; EGLint *num_config} XF_GL_Op_Args_eglGetConfigs
typedef struct XF_GL_Op_Args_eglCreatePlatformPixmapSurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; void *native_pixmap; const EGLAttrib *attrib_list} XF_GL_Op_Args_eglCreatePlatformPixmapSurface
typedef struct XF_GL_Op_Args_eglGetError {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglGetError
typedef struct XF_GL_Op_Args_eglSwapInterval {XF_GL_Op __xf_op; EGLDisplay dpy; EGLint interval} XF_GL_Op_Args_eglSwapInterval
typedef struct XF_GL_Op_Args_glVertexAttribPointer {XF_GL_Op __xf_op; GLuint index; GLint size; GLenum type; GLboolean normalized; GLsizei stride; const void *pointer} XF_GL_Op_Args_glVertexAttribPointer
typedef struct XF_GL_Op_Args_glStencilOp {XF_GL_Op __xf_op; GLenum fail; GLenum zfail; GLenum zpass} XF_GL_Op_Args_glStencilOp
typedef struct XF_GL_Op_Args_glClearStencil {XF_GL_Op __xf_op; GLint s} XF_GL_Op_Args_glClearStencil
typedef struct XF_GL_Op_Args_glViewport {XF_GL_Op __xf_op; GLint x; GLint y; GLsizei width; GLsizei height} XF_GL_Op_Args_glViewport
typedef struct XF_GL_Op_Args_eglCopyBuffers {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface; EGLNativePixmapType target} XF_GL_Op_Args_eglCopyBuffers
typedef struct XF_GL_Op_Args_glActiveTexture {XF_GL_Op __xf_op; GLenum texture} XF_GL_Op_Args_glActiveTexture
typedef struct XF_GL_Op_Args_eglReleaseThread {XF_GL_Op __xf_op; } XF_GL_Op_Args_eglReleaseThread
typedef struct XF_GL_Op_Args_glCopyTexImage2D {XF_GL_Op __xf_op; GLenum target; GLint level; GLenum internalformat; GLint x; GLint y; GLsizei width; GLsizei height; GLint border} XF_GL_Op_Args_glCopyTexImage2D
typedef struct XF_GL_Op_Args_glGetProgramiv {XF_GL_Op __xf_op; GLuint program; GLenum pname; GLint *params} XF_GL_Op_Args_glGetProgramiv
typedef struct XF_GL_Op_Args_glEnable {XF_GL_Op __xf_op; GLenum cap} XF_GL_Op_Args_glEnable
typedef struct XF_GL_Op_Args_glGetVertexAttribiv {XF_GL_Op __xf_op; GLuint index; GLenum pname; GLint *params} XF_GL_Op_Args_glGetVertexAttribiv
typedef struct XF_GL_Op_Args_glGetUniformfv {XF_GL_Op __xf_op; GLuint program; GLint location; GLfloat *params} XF_GL_Op_Args_glGetUniformfv
typedef struct XF_GL_Op_Args_eglQuerySurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface; EGLint attribute; EGLint *value} XF_GL_Op_Args_eglQuerySurface
typedef struct XF_GL_Op_Args_glBindRenderbuffer {XF_GL_Op __xf_op; GLenum target; GLuint renderbuffer} XF_GL_Op_Args_glBindRenderbuffer
typedef struct XF_GL_Op_Args_eglBindTexImage {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface; EGLint buffer} XF_GL_Op_Args_eglBindTexImage
typedef struct XF_GL_Op_Args_glGetAttribLocation {XF_GL_Op __xf_op; GLuint program; const GLchar *name} XF_GL_Op_Args_glGetAttribLocation
typedef struct XF_GL_Op_Args_glGetFloatv {XF_GL_Op __xf_op; GLenum pname; GLfloat *data} XF_GL_Op_Args_glGetFloatv
typedef struct XF_GL_Op_Args_glIsBuffer {XF_GL_Op __xf_op; GLuint buffer} XF_GL_Op_Args_glIsBuffer
typedef struct XF_GL_Op_Args_glUniform2fv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLfloat *value} XF_GL_Op_Args_glUniform2fv
typedef struct XF_GL_Op_Args_glVertexAttrib4fv {XF_GL_Op __xf_op; GLuint index; const GLfloat *v} XF_GL_Op_Args_glVertexAttrib4fv
typedef struct XF_GL_Op_Args_eglCreatePbufferSurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; const EGLint *attrib_list} XF_GL_Op_Args_eglCreatePbufferSurface
typedef struct XF_GL_Op_Args_eglCreateImage {XF_GL_Op __xf_op; EGLDisplay dpy; EGLContext ctx; EGLenum target; EGLClientBuffer buffer; const EGLAttrib *attrib_list} XF_GL_Op_Args_eglCreateImage
typedef struct XF_GL_Op_Args_eglDestroySync {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSync sync} XF_GL_Op_Args_eglDestroySync
typedef struct XF_GL_Op_Args_glGetShaderPrecisionFormat {XF_GL_Op __xf_op; GLenum shadertype; GLenum precisiontype; GLint *range; GLint *precision} XF_GL_Op_Args_glGetShaderPrecisionFormat
typedef struct XF_GL_Op_Args_glBindTexture {XF_GL_Op __xf_op; GLenum target; GLuint texture} XF_GL_Op_Args_glBindTexture
typedef struct XF_GL_Op_Args_eglGetCurrentSurface {XF_GL_Op __xf_op; EGLint readdraw} XF_GL_Op_Args_eglGetCurrentSurface
typedef struct XF_GL_Op_Args_glGetShaderiv {XF_GL_Op __xf_op; GLuint shader; GLenum pname; GLint *params} XF_GL_Op_Args_glGetShaderiv
typedef struct XF_GL_Op_Args_eglClientWaitSync {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSync sync; EGLint flags; EGLTime timeout} XF_GL_Op_Args_eglClientWaitSync
typedef struct XF_GL_Op_Args_glUseProgram {XF_GL_Op __xf_op; GLuint program} XF_GL_Op_Args_glUseProgram
typedef struct XF_GL_Op_Args_glClearColor {XF_GL_Op __xf_op; GLfloat red; GLfloat green; GLfloat blue; GLfloat alpha} XF_GL_Op_Args_glClearColor
typedef struct XF_GL_Op_Args_glGetActiveAttrib {XF_GL_Op __xf_op; GLuint program; GLuint index; GLsizei bufSize; GLsizei *length; GLint *size; GLenum *type; GLchar *name} XF_GL_Op_Args_glGetActiveAttrib
typedef struct XF_GL_Op_Args_eglInitialize {XF_GL_Op __xf_op; EGLDisplay dpy; EGLint *major; EGLint *minor} XF_GL_Op_Args_eglInitialize
typedef struct XF_GL_Op_Args_eglQueryContext {XF_GL_Op __xf_op; EGLDisplay dpy; EGLContext ctx; EGLint attribute; EGLint *value} XF_GL_Op_Args_eglQueryContext
typedef struct XF_GL_Op_Args_glFlush {XF_GL_Op __xf_op; } XF_GL_Op_Args_glFlush
typedef struct XF_GL_Op_Args_glDepthRangef {XF_GL_Op __xf_op; GLfloat n; GLfloat f} XF_GL_Op_Args_glDepthRangef
typedef struct XF_GL_Op_Args_eglGetProcAddress {XF_GL_Op __xf_op; const char *procname} XF_GL_Op_Args_eglGetProcAddress
typedef struct XF_GL_Op_Args_glIsFramebuffer {XF_GL_Op __xf_op; GLuint framebuffer} XF_GL_Op_Args_glIsFramebuffer
typedef struct XF_GL_Op_Args_glVertexAttrib3fv {XF_GL_Op __xf_op; GLuint index; const GLfloat *v} XF_GL_Op_Args_glVertexAttrib3fv
typedef struct XF_GL_Op_Args_glBlendFunc {XF_GL_Op __xf_op; GLenum sfactor; GLenum dfactor} XF_GL_Op_Args_glBlendFunc
typedef struct XF_GL_Op_Args_glGetAttachedShaders {XF_GL_Op __xf_op; GLuint program; GLsizei maxCount; GLsizei *count; GLuint *shaders} XF_GL_Op_Args_glGetAttachedShaders
typedef struct XF_GL_Op_Args_glBlendEquationSeparate {XF_GL_Op __xf_op; GLenum modeRGB; GLenum modeAlpha} XF_GL_Op_Args_glBlendEquationSeparate
typedef struct XF_GL_Op_Args_glTexParameteriv {XF_GL_Op __xf_op; GLenum target; GLenum pname; const GLint *params} XF_GL_Op_Args_glTexParameteriv
typedef struct XF_GL_Op_Args_eglSwapBuffers {XF_GL_Op __xf_op; EGLDisplay dpy; EGLSurface surface} XF_GL_Op_Args_eglSwapBuffers
typedef struct XF_GL_Op_Args_eglCreateWindowSurface {XF_GL_Op __xf_op; EGLDisplay dpy; EGLConfig config; EGLNativeWindowType win; const EGLint *attrib_list} XF_GL_Op_Args_eglCreateWindowSurface
typedef struct XF_GL_Op_Args_glDisableVertexAttribArray {XF_GL_Op __xf_op; GLuint index} XF_GL_Op_Args_glDisableVertexAttribArray
typedef struct XF_GL_Op_Args_glGetUniformiv {XF_GL_Op __xf_op; GLuint program; GLint location; GLint *params} XF_GL_Op_Args_glGetUniformiv
typedef struct XF_GL_Op_Args_glBlendEquation {XF_GL_Op __xf_op; GLenum mode} XF_GL_Op_Args_glBlendEquation
typedef struct XF_GL_Op_Args_glDisable {XF_GL_Op __xf_op; GLenum cap} XF_GL_Op_Args_glDisable
typedef struct XF_GL_Op_Args_glGetTexParameterfv {XF_GL_Op __xf_op; GLenum target; GLenum pname; GLfloat *params} XF_GL_Op_Args_glGetTexParameterfv
typedef struct XF_GL_Op_Args_glBufferSubData {XF_GL_Op __xf_op; GLenum target; GLintptr offset; GLsizeiptr size; const void *data} XF_GL_Op_Args_glBufferSubData
typedef struct XF_GL_Op_Args_glDepthFunc {XF_GL_Op __xf_op; GLenum func} XF_GL_Op_Args_glDepthFunc
typedef struct XF_GL_Op_Args_eglCreatePbufferFromClientBuffer {XF_GL_Op __xf_op; EGLDisplay dpy; EGLenum buftype; EGLClientBuffer buffer; EGLConfig config; const EGLint *attrib_list} XF_GL_Op_Args_eglCreatePbufferFromClientBuffer
typedef struct XF_GL_Op_Args_glClearDepthf {XF_GL_Op __xf_op; GLfloat d} XF_GL_Op_Args_glClearDepthf
typedef struct XF_GL_Op_Args_glGetString {XF_GL_Op __xf_op; GLenum name} XF_GL_Op_Args_glGetString
typedef struct XF_GL_Op_Args_glColorMask {XF_GL_Op __xf_op; GLboolean red; GLboolean green; GLboolean blue; GLboolean alpha} XF_GL_Op_Args_glColorMask
typedef struct XF_GL_Op_Args_eglQueryString {XF_GL_Op __xf_op; EGLDisplay dpy; EGLint name} XF_GL_Op_Args_eglQueryString
typedef struct XF_GL_Op_Args_glIsShader {XF_GL_Op __xf_op; GLuint shader} XF_GL_Op_Args_glIsShader
typedef struct XF_GL_Op_Args_glGetIntegerv {XF_GL_Op __xf_op; GLenum pname; GLint *data} XF_GL_Op_Args_glGetIntegerv
typedef struct XF_GL_Op_Args_eglGetDisplay {XF_GL_Op __xf_op; EGLNativeDisplayType display_id} XF_GL_Op_Args_eglGetDisplay
typedef struct XF_GL_Op_Args_glCheckFramebufferStatus {XF_GL_Op __xf_op; GLenum target} XF_GL_Op_Args_glCheckFramebufferStatus
typedef struct XF_GL_Op_Args_glStencilMask {XF_GL_Op __xf_op; GLuint mask} XF_GL_Op_Args_glStencilMask
typedef struct XF_GL_Op_Args_glUniform4i {XF_GL_Op __xf_op; GLint location; GLint v0; GLint v1; GLint v2; GLint v3} XF_GL_Op_Args_glUniform4i
typedef struct XF_GL_Op_Args_glDrawArrays {XF_GL_Op __xf_op; GLenum mode; GLint first; GLsizei count} XF_GL_Op_Args_glDrawArrays
typedef struct XF_GL_Op_Args_glUniform2iv {XF_GL_Op __xf_op; GLint location; GLsizei count; const GLint *value} XF_GL_Op_Args_glUniform2iv
typedef struct XF_GL_Op_Args_glUniform2f {XF_GL_Op __xf_op; GLint location; GLfloat v0; GLfloat v1} XF_GL_Op_Args_glUniform2f
typedef struct XF_GL_Op_Args_glVertexAttrib1f {XF_GL_Op __xf_op; GLuint index; GLfloat x} XF_GL_Op_Args_glVertexAttrib1f
typedef struct XF_GL_Op_Args_glCreateProgram {XF_GL_Op __xf_op; } XF_GL_Op_Args_glCreateProgram
typedef struct XF_GL_Op_Args_eglChooseConfig {XF_GL_Op __xf_op; EGLDisplay dpy; const EGLint *attrib_list; EGLConfig *configs; EGLint config_size; EGLint *num_config} XF_GL_Op_Args_eglChooseConfig
typedef struct XF_GL_Op_Args_glIsEnabled {XF_GL_Op __xf_op; GLenum cap} XF_GL_Op_Args_glIsEnabledtypedef struct XF_GL_Op_Return_eglQueryAPI { XF_GL_Op __xf_op; EGLenum v; } XF_GL_Op_Return_eglQueryAPI
typedef struct XF_GL_Op_Return_eglGetCurrentContext { XF_GL_Op __xf_op; EGLContext v; } XF_GL_Op_Return_eglGetCurrentContext
typedef struct XF_GL_Op_Return_eglGetConfigAttrib { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglGetConfigAttrib
typedef struct XF_GL_Op_Return_eglCreatePlatformWindowSurface { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglCreatePlatformWindowSurface
typedef struct XF_GL_Op_Return_eglWaitSync { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglWaitSync
typedef struct XF_GL_Op_Return_eglSurfaceAttrib { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglSurfaceAttrib
typedef struct XF_GL_Op_Return_glIsRenderbuffer { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsRenderbuffer
typedef struct XF_GL_Op_Return_eglWaitClient { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglWaitClient
typedef struct XF_GL_Op_Return_eglDestroySurface { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglDestroySurface
typedef struct XF_GL_Op_Return_eglMakeCurrent { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglMakeCurrent
typedef struct XF_GL_Op_Return_eglDestroyImage { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglDestroyImage
typedef struct XF_GL_Op_Return_eglTerminate { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglTerminate
typedef struct XF_GL_Op_Return_glGetError { XF_GL_Op __xf_op; GLenum v; } XF_GL_Op_Return_glGetError
typedef struct XF_GL_Op_Return_eglWaitGL { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglWaitGL
typedef struct XF_GL_Op_Return_eglReleaseTexImage { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglReleaseTexImage
typedef struct XF_GL_Op_Return_eglBindAPI { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglBindAPI
typedef struct XF_GL_Op_Return_eglGetSyncAttrib { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglGetSyncAttrib
typedef struct XF_GL_Op_Return_eglGetCurrentDisplay { XF_GL_Op __xf_op; EGLDisplay v; } XF_GL_Op_Return_eglGetCurrentDisplay
typedef struct XF_GL_Op_Return_eglCreatePixmapSurface { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglCreatePixmapSurface
typedef struct XF_GL_Op_Return_eglGetPlatformDisplay { XF_GL_Op __xf_op; EGLDisplay v; } XF_GL_Op_Return_eglGetPlatformDisplay
typedef struct XF_GL_Op_Return_glIsProgram { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsProgram
typedef struct XF_GL_Op_Return_glIsTexture { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsTexture
typedef struct XF_GL_Op_Return_eglCreateContext { XF_GL_Op __xf_op; EGLContext v; } XF_GL_Op_Return_eglCreateContext
typedef struct XF_GL_Op_Return_eglDestroyContext { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglDestroyContext
typedef struct XF_GL_Op_Return_eglWaitNative { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglWaitNative
typedef struct XF_GL_Op_Return_glCreateShader { XF_GL_Op __xf_op; GLuint v; } XF_GL_Op_Return_glCreateShader
typedef struct XF_GL_Op_Return_eglCreateSync { XF_GL_Op __xf_op; EGLSync v; } XF_GL_Op_Return_eglCreateSync
typedef struct XF_GL_Op_Return_glGetUniformLocation { XF_GL_Op __xf_op; GLint v; } XF_GL_Op_Return_glGetUniformLocation
typedef struct XF_GL_Op_Return_eglGetConfigs { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglGetConfigs
typedef struct XF_GL_Op_Return_eglCreatePlatformPixmapSurface { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglCreatePlatformPixmapSurface
typedef struct XF_GL_Op_Return_eglGetError { XF_GL_Op __xf_op; EGLint v; } XF_GL_Op_Return_eglGetError
typedef struct XF_GL_Op_Return_eglSwapInterval { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglSwapInterval
typedef struct XF_GL_Op_Return_eglCopyBuffers { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglCopyBuffers
typedef struct XF_GL_Op_Return_eglReleaseThread { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglReleaseThread
typedef struct XF_GL_Op_Return_eglQuerySurface { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglQuerySurface
typedef struct XF_GL_Op_Return_eglBindTexImage { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglBindTexImage
typedef struct XF_GL_Op_Return_glGetAttribLocation { XF_GL_Op __xf_op; GLint v; } XF_GL_Op_Return_glGetAttribLocation
typedef struct XF_GL_Op_Return_glIsBuffer { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsBuffer
typedef struct XF_GL_Op_Return_eglCreatePbufferSurface { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglCreatePbufferSurface
typedef struct XF_GL_Op_Return_eglCreateImage { XF_GL_Op __xf_op; EGLImage v; } XF_GL_Op_Return_eglCreateImage
typedef struct XF_GL_Op_Return_eglDestroySync { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglDestroySync
typedef struct XF_GL_Op_Return_eglGetCurrentSurface { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglGetCurrentSurface
typedef struct XF_GL_Op_Return_eglClientWaitSync { XF_GL_Op __xf_op; EGLint v; } XF_GL_Op_Return_eglClientWaitSync
typedef struct XF_GL_Op_Return_eglInitialize { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglInitialize
typedef struct XF_GL_Op_Return_eglQueryContext { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglQueryContext
typedef struct XF_GL_Op_Return_eglGetProcAddress { XF_GL_Op __xf_op; __eglMustCastToProperFunctionPointerType v; } XF_GL_Op_Return_eglGetProcAddress
typedef struct XF_GL_Op_Return_glIsFramebuffer { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsFramebuffer
typedef struct XF_GL_Op_Return_eglSwapBuffers { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglSwapBuffers
typedef struct XF_GL_Op_Return_eglCreateWindowSurface { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglCreateWindowSurface
typedef struct XF_GL_Op_Return_eglCreatePbufferFromClientBuffer { XF_GL_Op __xf_op; EGLSurface v; } XF_GL_Op_Return_eglCreatePbufferFromClientBuffer
typedef struct XF_GL_Op_Return_glGetString { XF_GL_Op __xf_op; const GLubyte * v; } XF_GL_Op_Return_glGetString
typedef struct XF_GL_Op_Return_eglQueryString { XF_GL_Op __xf_op; const char * v; } XF_GL_Op_Return_eglQueryString
typedef struct XF_GL_Op_Return_glIsShader { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsShader
typedef struct XF_GL_Op_Return_eglGetDisplay { XF_GL_Op __xf_op; EGLDisplay v; } XF_GL_Op_Return_eglGetDisplay
typedef struct XF_GL_Op_Return_glCheckFramebufferStatus { XF_GL_Op __xf_op; GLenum v; } XF_GL_Op_Return_glCheckFramebufferStatus
typedef struct XF_GL_Op_Return_glCreateProgram { XF_GL_Op __xf_op; GLuint v; } XF_GL_Op_Return_glCreateProgram
typedef struct XF_GL_Op_Return_eglChooseConfig { XF_GL_Op __xf_op; EGLBoolean v; } XF_GL_Op_Return_eglChooseConfig
typedef struct XF_GL_Op_Return_glIsEnabled { XF_GL_Op __xf_op; GLboolean v; } XF_GL_Op_Return_glIsEnabled
    typedef struct XF_GL_Op {
        XF_GL_Opcode opcode;
        size_t id;
    } XF_GL_Op;

    XF_GL_Op *xf_gl_eval_op(XF_GL_Op *inp) {
        XF_GL_Op *outp;
        switch(inp->opcode) {

            case XF_GL_OPCODE_glPixelStorei:
glPixelStorei(inp_args->pname, inp_args->param);
free(inp);break;
case XF_GL_OPCODE_glUniformMatrix4fv:
glUniformMatrix4fv(inp_args->location, inp_args->count, inp_args->transpose, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glShaderBinary:
glShaderBinary(inp_args->count, inp_args->shaders, inp_args->binaryformat, inp_args->binary, inp_args->length);
free(inp);break;
case XF_GL_OPCODE_eglQueryAPI:
XF_GL_Op_Args_eglQueryAPI *inp_args = (XF_GL_Op_Args_eglQueryAPI *)inp;XF_GL_Op_Return_eglQueryAPI *retval = malloc(sizeof(XF_GL_Op_Return_eglQueryAPI));
retval->v = eglQueryAPI();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetBooleanv:
glGetBooleanv(inp_args->pname, inp_args->data);
free(inp);break;
case XF_GL_OPCODE_glBindFramebuffer:
glBindFramebuffer(inp_args->target, inp_args->framebuffer);
free(inp);break;
case XF_GL_OPCODE_eglGetCurrentContext:
XF_GL_Op_Args_eglGetCurrentContext *inp_args = (XF_GL_Op_Args_eglGetCurrentContext *)inp;XF_GL_Op_Return_eglGetCurrentContext *retval = malloc(sizeof(XF_GL_Op_Return_eglGetCurrentContext));
retval->v = eglGetCurrentContext();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glCompileShader:
glCompileShader(inp_args->shader);
free(inp);break;
case XF_GL_OPCODE_glCompressedTexImage2D:
glCompressedTexImage2D(inp_args->target, inp_args->level, inp_args->internalformat, inp_args->width, inp_args->height, inp_args->border, inp_args->imageSize, inp_args->data);
free(inp);break;
case XF_GL_OPCODE_glGenerateMipmap:
glGenerateMipmap(inp_args->target);
free(inp);break;
case XF_GL_OPCODE_eglGetConfigAttrib:
XF_GL_Op_Args_eglGetConfigAttrib *inp_args = (XF_GL_Op_Args_eglGetConfigAttrib *)inp;XF_GL_Op_Return_eglGetConfigAttrib *retval = malloc(sizeof(XF_GL_Op_Return_eglGetConfigAttrib));
retval->v = eglGetConfigAttrib(inp_args->dpy, inp_args->config, inp_args->attribute, inp_args->value);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDeleteShader:
glDeleteShader(inp_args->shader);
free(inp);break;
case XF_GL_OPCODE_eglCreatePlatformWindowSurface:
XF_GL_Op_Args_eglCreatePlatformWindowSurface *inp_args = (XF_GL_Op_Args_eglCreatePlatformWindowSurface *)inp;XF_GL_Op_Return_eglCreatePlatformWindowSurface *retval = malloc(sizeof(XF_GL_Op_Return_eglCreatePlatformWindowSurface));
retval->v = eglCreatePlatformWindowSurface(inp_args->dpy, inp_args->config, inp_args->native_window, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glPolygonOffset:
glPolygonOffset(inp_args->factor, inp_args->units);
free(inp);break;
case XF_GL_OPCODE_glFrontFace:
glFrontFace(inp_args->mode);
free(inp);break;
case XF_GL_OPCODE_glUniform3iv:
glUniform3iv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glGetTexParameteriv:
glGetTexParameteriv(inp_args->target, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glVertexAttrib3f:
glVertexAttrib3f(inp_args->index, inp_args->x, inp_args->y, inp_args->z);
free(inp);break;
case XF_GL_OPCODE_glVertexAttrib2fv:
glVertexAttrib2fv(inp_args->index, inp_args->v);
free(inp);break;
case XF_GL_OPCODE_glSampleCoverage:
glSampleCoverage(inp_args->value, inp_args->invert);
free(inp);break;
case XF_GL_OPCODE_glUniformMatrix3fv:
glUniformMatrix3fv(inp_args->location, inp_args->count, inp_args->transpose, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glGenFramebuffers:
glGenFramebuffers(inp_args->n, inp_args->framebuffers);
free(inp);break;
case XF_GL_OPCODE_glFramebufferTexture2D:
glFramebufferTexture2D(inp_args->target, inp_args->attachment, inp_args->textarget, inp_args->texture, inp_args->level);
free(inp);break;
case XF_GL_OPCODE_eglWaitSync:
XF_GL_Op_Args_eglWaitSync *inp_args = (XF_GL_Op_Args_eglWaitSync *)inp;XF_GL_Op_Return_eglWaitSync *retval = malloc(sizeof(XF_GL_Op_Return_eglWaitSync));
retval->v = eglWaitSync(inp_args->dpy, inp_args->sync, inp_args->flags);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDeleteRenderbuffers:
glDeleteRenderbuffers(inp_args->n, inp_args->renderbuffers);
free(inp);break;
case XF_GL_OPCODE_glAttachShader:
glAttachShader(inp_args->program, inp_args->shader);
free(inp);break;
case XF_GL_OPCODE_glUniform2i:
glUniform2i(inp_args->location, inp_args->v0, inp_args->v1);
free(inp);break;
case XF_GL_OPCODE_glGetVertexAttribPointerv:
glGetVertexAttribPointerv(inp_args->index, inp_args->pname, inp_args->pointer);
free(inp);break;
case XF_GL_OPCODE_glBlendColor:
glBlendColor(inp_args->red, inp_args->green, inp_args->blue, inp_args->alpha);
free(inp);break;
case XF_GL_OPCODE_glTexParameterfv:
glTexParameterfv(inp_args->target, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_eglSurfaceAttrib:
XF_GL_Op_Args_eglSurfaceAttrib *inp_args = (XF_GL_Op_Args_eglSurfaceAttrib *)inp;XF_GL_Op_Return_eglSurfaceAttrib *retval = malloc(sizeof(XF_GL_Op_Return_eglSurfaceAttrib));
retval->v = eglSurfaceAttrib(inp_args->dpy, inp_args->surface, inp_args->attribute, inp_args->value);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glTexParameteri:
glTexParameteri(inp_args->target, inp_args->pname, inp_args->param);
free(inp);break;
case XF_GL_OPCODE_glIsRenderbuffer:
XF_GL_Op_Args_glIsRenderbuffer *inp_args = (XF_GL_Op_Args_glIsRenderbuffer *)inp;XF_GL_Op_Return_glIsRenderbuffer *retval = malloc(sizeof(XF_GL_Op_Return_glIsRenderbuffer));
retval->v = glIsRenderbuffer(inp_args->renderbuffer);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDeleteTextures:
glDeleteTextures(inp_args->n, inp_args->textures);
free(inp);break;
case XF_GL_OPCODE_eglWaitClient:
XF_GL_Op_Args_eglWaitClient *inp_args = (XF_GL_Op_Args_eglWaitClient *)inp;XF_GL_Op_Return_eglWaitClient *retval = malloc(sizeof(XF_GL_Op_Return_eglWaitClient));
retval->v = eglWaitClient();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glCopyTexSubImage2D:
glCopyTexSubImage2D(inp_args->target, inp_args->level, inp_args->xoffset, inp_args->yoffset, inp_args->x, inp_args->y, inp_args->width, inp_args->height);
free(inp);break;
case XF_GL_OPCODE_glDetachShader:
glDetachShader(inp_args->program, inp_args->shader);
free(inp);break;
case XF_GL_OPCODE_glLineWidth:
glLineWidth(inp_args->width);
free(inp);break;
case XF_GL_OPCODE_glFinish:
glFinish();
free(inp);break;
case XF_GL_OPCODE_glScissor:
glScissor(inp_args->x, inp_args->y, inp_args->width, inp_args->height);
free(inp);break;
case XF_GL_OPCODE_glBlendFuncSeparate:
glBlendFuncSeparate(inp_args->sfactorRGB, inp_args->dfactorRGB, inp_args->sfactorAlpha, inp_args->dfactorAlpha);
free(inp);break;
case XF_GL_OPCODE_glStencilFunc:
glStencilFunc(inp_args->func, inp_args->ref, inp_args->mask);
free(inp);break;
case XF_GL_OPCODE_glClear:
glClear(inp_args->mask);
free(inp);break;
case XF_GL_OPCODE_eglDestroySurface:
XF_GL_Op_Args_eglDestroySurface *inp_args = (XF_GL_Op_Args_eglDestroySurface *)inp;XF_GL_Op_Return_eglDestroySurface *retval = malloc(sizeof(XF_GL_Op_Return_eglDestroySurface));
retval->v = eglDestroySurface(inp_args->dpy, inp_args->surface);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglMakeCurrent:
XF_GL_Op_Args_eglMakeCurrent *inp_args = (XF_GL_Op_Args_eglMakeCurrent *)inp;XF_GL_Op_Return_eglMakeCurrent *retval = malloc(sizeof(XF_GL_Op_Return_eglMakeCurrent));
retval->v = eglMakeCurrent(inp_args->dpy, inp_args->draw, inp_args->read, inp_args->ctx);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glReadPixels:
glReadPixels(inp_args->x, inp_args->y, inp_args->width, inp_args->height, inp_args->format, inp_args->type, inp_args->pixels);
free(inp);break;
case XF_GL_OPCODE_eglDestroyImage:
XF_GL_Op_Args_eglDestroyImage *inp_args = (XF_GL_Op_Args_eglDestroyImage *)inp;XF_GL_Op_Return_eglDestroyImage *retval = malloc(sizeof(XF_GL_Op_Return_eglDestroyImage));
retval->v = eglDestroyImage(inp_args->dpy, inp_args->image);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glCompressedTexSubImage2D:
glCompressedTexSubImage2D(inp_args->target, inp_args->level, inp_args->xoffset, inp_args->yoffset, inp_args->width, inp_args->height, inp_args->format, inp_args->imageSize, inp_args->data);
free(inp);break;
case XF_GL_OPCODE_glCullFace:
glCullFace(inp_args->mode);
free(inp);break;
case XF_GL_OPCODE_glUniform1f:
glUniform1f(inp_args->location, inp_args->v0);
free(inp);break;
case XF_GL_OPCODE_glShaderSource:
glShaderSource(inp_args->shader, inp_args->count, inp_args->string, inp_args->length);
free(inp);break;
case XF_GL_OPCODE_eglTerminate:
XF_GL_Op_Args_eglTerminate *inp_args = (XF_GL_Op_Args_eglTerminate *)inp;XF_GL_Op_Return_eglTerminate *retval = malloc(sizeof(XF_GL_Op_Return_eglTerminate));
retval->v = eglTerminate(inp_args->dpy);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glUniform4iv:
glUniform4iv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glGenTextures:
glGenTextures(inp_args->n, inp_args->textures);
free(inp);break;
case XF_GL_OPCODE_glGetError:
XF_GL_Op_Args_glGetError *inp_args = (XF_GL_Op_Args_glGetError *)inp;XF_GL_Op_Return_glGetError *retval = malloc(sizeof(XF_GL_Op_Return_glGetError));
retval->v = glGetError();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glVertexAttrib2f:
glVertexAttrib2f(inp_args->index, inp_args->x, inp_args->y);
free(inp);break;
case XF_GL_OPCODE_glHint:
glHint(inp_args->target, inp_args->mode);
free(inp);break;
case XF_GL_OPCODE_glFramebufferRenderbuffer:
glFramebufferRenderbuffer(inp_args->target, inp_args->attachment, inp_args->renderbuffertarget, inp_args->renderbuffer);
free(inp);break;
case XF_GL_OPCODE_eglWaitGL:
XF_GL_Op_Args_eglWaitGL *inp_args = (XF_GL_Op_Args_eglWaitGL *)inp;XF_GL_Op_Return_eglWaitGL *retval = malloc(sizeof(XF_GL_Op_Return_eglWaitGL));
retval->v = eglWaitGL();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglReleaseTexImage:
XF_GL_Op_Args_eglReleaseTexImage *inp_args = (XF_GL_Op_Args_eglReleaseTexImage *)inp;XF_GL_Op_Return_eglReleaseTexImage *retval = malloc(sizeof(XF_GL_Op_Return_eglReleaseTexImage));
retval->v = eglReleaseTexImage(inp_args->dpy, inp_args->surface, inp_args->buffer);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glUniformMatrix2fv:
glUniformMatrix2fv(inp_args->location, inp_args->count, inp_args->transpose, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glGetVertexAttribfv:
glGetVertexAttribfv(inp_args->index, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glDeleteProgram:
glDeleteProgram(inp_args->program);
free(inp);break;
case XF_GL_OPCODE_glBufferData:
glBufferData(inp_args->target, inp_args->size, inp_args->data, inp_args->usage);
free(inp);break;
case XF_GL_OPCODE_glValidateProgram:
glValidateProgram(inp_args->program);
free(inp);break;
case XF_GL_OPCODE_glGetShaderInfoLog:
glGetShaderInfoLog(inp_args->shader, inp_args->bufSize, inp_args->length, inp_args->infoLog);
free(inp);break;
case XF_GL_OPCODE_glRenderbufferStorage:
glRenderbufferStorage(inp_args->target, inp_args->internalformat, inp_args->width, inp_args->height);
free(inp);break;
case XF_GL_OPCODE_glVertexAttrib1fv:
glVertexAttrib1fv(inp_args->index, inp_args->v);
free(inp);break;
case XF_GL_OPCODE_eglBindAPI:
XF_GL_Op_Args_eglBindAPI *inp_args = (XF_GL_Op_Args_eglBindAPI *)inp;XF_GL_Op_Return_eglBindAPI *retval = malloc(sizeof(XF_GL_Op_Return_eglBindAPI));
retval->v = eglBindAPI(inp_args->api);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDeleteFramebuffers:
glDeleteFramebuffers(inp_args->n, inp_args->framebuffers);
free(inp);break;
case XF_GL_OPCODE_glEnableVertexAttribArray:
glEnableVertexAttribArray(inp_args->index);
free(inp);break;
case XF_GL_OPCODE_eglGetSyncAttrib:
XF_GL_Op_Args_eglGetSyncAttrib *inp_args = (XF_GL_Op_Args_eglGetSyncAttrib *)inp;XF_GL_Op_Return_eglGetSyncAttrib *retval = malloc(sizeof(XF_GL_Op_Return_eglGetSyncAttrib));
retval->v = eglGetSyncAttrib(inp_args->dpy, inp_args->sync, inp_args->attribute, inp_args->value);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetRenderbufferParameteriv:
glGetRenderbufferParameteriv(inp_args->target, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glGetProgramInfoLog:
glGetProgramInfoLog(inp_args->program, inp_args->bufSize, inp_args->length, inp_args->infoLog);
free(inp);break;
case XF_GL_OPCODE_glUniform1iv:
glUniform1iv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_eglGetCurrentDisplay:
XF_GL_Op_Args_eglGetCurrentDisplay *inp_args = (XF_GL_Op_Args_eglGetCurrentDisplay *)inp;XF_GL_Op_Return_eglGetCurrentDisplay *retval = malloc(sizeof(XF_GL_Op_Return_eglGetCurrentDisplay));
retval->v = eglGetCurrentDisplay();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetActiveUniform:
glGetActiveUniform(inp_args->program, inp_args->index, inp_args->bufSize, inp_args->length, inp_args->size, inp_args->type, inp_args->name);
free(inp);break;
case XF_GL_OPCODE_glUniform3i:
glUniform3i(inp_args->location, inp_args->v0, inp_args->v1, inp_args->v2);
free(inp);break;
case XF_GL_OPCODE_eglCreatePixmapSurface:
XF_GL_Op_Args_eglCreatePixmapSurface *inp_args = (XF_GL_Op_Args_eglCreatePixmapSurface *)inp;XF_GL_Op_Return_eglCreatePixmapSurface *retval = malloc(sizeof(XF_GL_Op_Return_eglCreatePixmapSurface));
retval->v = eglCreatePixmapSurface(inp_args->dpy, inp_args->config, inp_args->pixmap, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglGetPlatformDisplay:
XF_GL_Op_Args_eglGetPlatformDisplay *inp_args = (XF_GL_Op_Args_eglGetPlatformDisplay *)inp;XF_GL_Op_Return_eglGetPlatformDisplay *retval = malloc(sizeof(XF_GL_Op_Return_eglGetPlatformDisplay));
retval->v = eglGetPlatformDisplay(inp_args->platform, inp_args->native_display, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetBufferParameteriv:
glGetBufferParameteriv(inp_args->target, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glUniform3f:
glUniform3f(inp_args->location, inp_args->v0, inp_args->v1, inp_args->v2);
free(inp);break;
case XF_GL_OPCODE_glDrawElements:
glDrawElements(inp_args->mode, inp_args->count, inp_args->type, inp_args->indices);
free(inp);break;
case XF_GL_OPCODE_glIsProgram:
XF_GL_Op_Args_glIsProgram *inp_args = (XF_GL_Op_Args_glIsProgram *)inp;XF_GL_Op_Return_glIsProgram *retval = malloc(sizeof(XF_GL_Op_Return_glIsProgram));
retval->v = glIsProgram(inp_args->program);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDeleteBuffers:
glDeleteBuffers(inp_args->n, inp_args->buffers);
free(inp);break;
case XF_GL_OPCODE_glIsTexture:
XF_GL_Op_Args_glIsTexture *inp_args = (XF_GL_Op_Args_glIsTexture *)inp;XF_GL_Op_Return_glIsTexture *retval = malloc(sizeof(XF_GL_Op_Return_glIsTexture));
retval->v = glIsTexture(inp_args->texture);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglCreateContext:
XF_GL_Op_Args_eglCreateContext *inp_args = (XF_GL_Op_Args_eglCreateContext *)inp;XF_GL_Op_Return_eglCreateContext *retval = malloc(sizeof(XF_GL_Op_Return_eglCreateContext));
retval->v = eglCreateContext(inp_args->dpy, inp_args->config, inp_args->share_context, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glTexParameterf:
glTexParameterf(inp_args->target, inp_args->pname, inp_args->param);
free(inp);break;
case XF_GL_OPCODE_eglDestroyContext:
XF_GL_Op_Args_eglDestroyContext *inp_args = (XF_GL_Op_Args_eglDestroyContext *)inp;XF_GL_Op_Return_eglDestroyContext *retval = malloc(sizeof(XF_GL_Op_Return_eglDestroyContext));
retval->v = eglDestroyContext(inp_args->dpy, inp_args->ctx);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glVertexAttrib4f:
glVertexAttrib4f(inp_args->index, inp_args->x, inp_args->y, inp_args->z, inp_args->w);
free(inp);break;
case XF_GL_OPCODE_glUniform4f:
glUniform4f(inp_args->location, inp_args->v0, inp_args->v1, inp_args->v2, inp_args->v3);
free(inp);break;
case XF_GL_OPCODE_glGetFramebufferAttachmentParameteriv:
glGetFramebufferAttachmentParameteriv(inp_args->target, inp_args->attachment, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glGetShaderSource:
glGetShaderSource(inp_args->shader, inp_args->bufSize, inp_args->length, inp_args->source);
free(inp);break;
case XF_GL_OPCODE_glStencilFuncSeparate:
glStencilFuncSeparate(inp_args->face, inp_args->func, inp_args->ref, inp_args->mask);
free(inp);break;
case XF_GL_OPCODE_glStencilMaskSeparate:
glStencilMaskSeparate(inp_args->face, inp_args->mask);
free(inp);break;
case XF_GL_OPCODE_glBindAttribLocation:
glBindAttribLocation(inp_args->program, inp_args->index, inp_args->name);
free(inp);break;
case XF_GL_OPCODE_eglWaitNative:
XF_GL_Op_Args_eglWaitNative *inp_args = (XF_GL_Op_Args_eglWaitNative *)inp;XF_GL_Op_Return_eglWaitNative *retval = malloc(sizeof(XF_GL_Op_Return_eglWaitNative));
retval->v = eglWaitNative(inp_args->engine);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glBindBuffer:
glBindBuffer(inp_args->target, inp_args->buffer);
free(inp);break;
case XF_GL_OPCODE_glGenBuffers:
glGenBuffers(inp_args->n, inp_args->buffers);
free(inp);break;
case XF_GL_OPCODE_glUniform1fv:
glUniform1fv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glUniform3fv:
glUniform3fv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glReleaseShaderCompiler:
glReleaseShaderCompiler();
free(inp);break;
case XF_GL_OPCODE_glCreateShader:
XF_GL_Op_Args_glCreateShader *inp_args = (XF_GL_Op_Args_glCreateShader *)inp;XF_GL_Op_Return_glCreateShader *retval = malloc(sizeof(XF_GL_Op_Return_glCreateShader));
retval->v = glCreateShader(inp_args->type);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDepthMask:
glDepthMask(inp_args->flag);
free(inp);break;
case XF_GL_OPCODE_glGenRenderbuffers:
glGenRenderbuffers(inp_args->n, inp_args->renderbuffers);
free(inp);break;
case XF_GL_OPCODE_glStencilOpSeparate:
glStencilOpSeparate(inp_args->face, inp_args->sfail, inp_args->dpfail, inp_args->dppass);
free(inp);break;
case XF_GL_OPCODE_glUniform4fv:
glUniform4fv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glUniform1i:
glUniform1i(inp_args->location, inp_args->v0);
free(inp);break;
case XF_GL_OPCODE_glLinkProgram:
glLinkProgram(inp_args->program);
free(inp);break;
case XF_GL_OPCODE_eglCreateSync:
XF_GL_Op_Args_eglCreateSync *inp_args = (XF_GL_Op_Args_eglCreateSync *)inp;XF_GL_Op_Return_eglCreateSync *retval = malloc(sizeof(XF_GL_Op_Return_eglCreateSync));
retval->v = eglCreateSync(inp_args->dpy, inp_args->type, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glTexImage2D:
glTexImage2D(inp_args->target, inp_args->level, inp_args->internalformat, inp_args->width, inp_args->height, inp_args->border, inp_args->format, inp_args->type, inp_args->pixels);
free(inp);break;
case XF_GL_OPCODE_glGetUniformLocation:
XF_GL_Op_Args_glGetUniformLocation *inp_args = (XF_GL_Op_Args_glGetUniformLocation *)inp;XF_GL_Op_Return_glGetUniformLocation *retval = malloc(sizeof(XF_GL_Op_Return_glGetUniformLocation));
retval->v = glGetUniformLocation(inp_args->program, inp_args->name);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glTexSubImage2D:
glTexSubImage2D(inp_args->target, inp_args->level, inp_args->xoffset, inp_args->yoffset, inp_args->width, inp_args->height, inp_args->format, inp_args->type, inp_args->pixels);
free(inp);break;
case XF_GL_OPCODE_eglGetConfigs:
XF_GL_Op_Args_eglGetConfigs *inp_args = (XF_GL_Op_Args_eglGetConfigs *)inp;XF_GL_Op_Return_eglGetConfigs *retval = malloc(sizeof(XF_GL_Op_Return_eglGetConfigs));
retval->v = eglGetConfigs(inp_args->dpy, inp_args->configs, inp_args->config_size, inp_args->num_config);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglCreatePlatformPixmapSurface:
XF_GL_Op_Args_eglCreatePlatformPixmapSurface *inp_args = (XF_GL_Op_Args_eglCreatePlatformPixmapSurface *)inp;XF_GL_Op_Return_eglCreatePlatformPixmapSurface *retval = malloc(sizeof(XF_GL_Op_Return_eglCreatePlatformPixmapSurface));
retval->v = eglCreatePlatformPixmapSurface(inp_args->dpy, inp_args->config, inp_args->native_pixmap, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglGetError:
XF_GL_Op_Args_eglGetError *inp_args = (XF_GL_Op_Args_eglGetError *)inp;XF_GL_Op_Return_eglGetError *retval = malloc(sizeof(XF_GL_Op_Return_eglGetError));
retval->v = eglGetError();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglSwapInterval:
XF_GL_Op_Args_eglSwapInterval *inp_args = (XF_GL_Op_Args_eglSwapInterval *)inp;XF_GL_Op_Return_eglSwapInterval *retval = malloc(sizeof(XF_GL_Op_Return_eglSwapInterval));
retval->v = eglSwapInterval(inp_args->dpy, inp_args->interval);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glVertexAttribPointer:
glVertexAttribPointer(inp_args->index, inp_args->size, inp_args->type, inp_args->normalized, inp_args->stride, inp_args->pointer);
free(inp);break;
case XF_GL_OPCODE_glStencilOp:
glStencilOp(inp_args->fail, inp_args->zfail, inp_args->zpass);
free(inp);break;
case XF_GL_OPCODE_glClearStencil:
glClearStencil(inp_args->s);
free(inp);break;
case XF_GL_OPCODE_glViewport:
glViewport(inp_args->x, inp_args->y, inp_args->width, inp_args->height);
free(inp);break;
case XF_GL_OPCODE_eglCopyBuffers:
XF_GL_Op_Args_eglCopyBuffers *inp_args = (XF_GL_Op_Args_eglCopyBuffers *)inp;XF_GL_Op_Return_eglCopyBuffers *retval = malloc(sizeof(XF_GL_Op_Return_eglCopyBuffers));
retval->v = eglCopyBuffers(inp_args->dpy, inp_args->surface, inp_args->target);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glActiveTexture:
glActiveTexture(inp_args->texture);
free(inp);break;
case XF_GL_OPCODE_eglReleaseThread:
XF_GL_Op_Args_eglReleaseThread *inp_args = (XF_GL_Op_Args_eglReleaseThread *)inp;XF_GL_Op_Return_eglReleaseThread *retval = malloc(sizeof(XF_GL_Op_Return_eglReleaseThread));
retval->v = eglReleaseThread();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glCopyTexImage2D:
glCopyTexImage2D(inp_args->target, inp_args->level, inp_args->internalformat, inp_args->x, inp_args->y, inp_args->width, inp_args->height, inp_args->border);
free(inp);break;
case XF_GL_OPCODE_glGetProgramiv:
glGetProgramiv(inp_args->program, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glEnable:
glEnable(inp_args->cap);
free(inp);break;
case XF_GL_OPCODE_glGetVertexAttribiv:
glGetVertexAttribiv(inp_args->index, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glGetUniformfv:
glGetUniformfv(inp_args->program, inp_args->location, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_eglQuerySurface:
XF_GL_Op_Args_eglQuerySurface *inp_args = (XF_GL_Op_Args_eglQuerySurface *)inp;XF_GL_Op_Return_eglQuerySurface *retval = malloc(sizeof(XF_GL_Op_Return_eglQuerySurface));
retval->v = eglQuerySurface(inp_args->dpy, inp_args->surface, inp_args->attribute, inp_args->value);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glBindRenderbuffer:
glBindRenderbuffer(inp_args->target, inp_args->renderbuffer);
free(inp);break;
case XF_GL_OPCODE_eglBindTexImage:
XF_GL_Op_Args_eglBindTexImage *inp_args = (XF_GL_Op_Args_eglBindTexImage *)inp;XF_GL_Op_Return_eglBindTexImage *retval = malloc(sizeof(XF_GL_Op_Return_eglBindTexImage));
retval->v = eglBindTexImage(inp_args->dpy, inp_args->surface, inp_args->buffer);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetAttribLocation:
XF_GL_Op_Args_glGetAttribLocation *inp_args = (XF_GL_Op_Args_glGetAttribLocation *)inp;XF_GL_Op_Return_glGetAttribLocation *retval = malloc(sizeof(XF_GL_Op_Return_glGetAttribLocation));
retval->v = glGetAttribLocation(inp_args->program, inp_args->name);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetFloatv:
glGetFloatv(inp_args->pname, inp_args->data);
free(inp);break;
case XF_GL_OPCODE_glIsBuffer:
XF_GL_Op_Args_glIsBuffer *inp_args = (XF_GL_Op_Args_glIsBuffer *)inp;XF_GL_Op_Return_glIsBuffer *retval = malloc(sizeof(XF_GL_Op_Return_glIsBuffer));
retval->v = glIsBuffer(inp_args->buffer);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glUniform2fv:
glUniform2fv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glVertexAttrib4fv:
glVertexAttrib4fv(inp_args->index, inp_args->v);
free(inp);break;
case XF_GL_OPCODE_eglCreatePbufferSurface:
XF_GL_Op_Args_eglCreatePbufferSurface *inp_args = (XF_GL_Op_Args_eglCreatePbufferSurface *)inp;XF_GL_Op_Return_eglCreatePbufferSurface *retval = malloc(sizeof(XF_GL_Op_Return_eglCreatePbufferSurface));
retval->v = eglCreatePbufferSurface(inp_args->dpy, inp_args->config, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglCreateImage:
XF_GL_Op_Args_eglCreateImage *inp_args = (XF_GL_Op_Args_eglCreateImage *)inp;XF_GL_Op_Return_eglCreateImage *retval = malloc(sizeof(XF_GL_Op_Return_eglCreateImage));
retval->v = eglCreateImage(inp_args->dpy, inp_args->ctx, inp_args->target, inp_args->buffer, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglDestroySync:
XF_GL_Op_Args_eglDestroySync *inp_args = (XF_GL_Op_Args_eglDestroySync *)inp;XF_GL_Op_Return_eglDestroySync *retval = malloc(sizeof(XF_GL_Op_Return_eglDestroySync));
retval->v = eglDestroySync(inp_args->dpy, inp_args->sync);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetShaderPrecisionFormat:
glGetShaderPrecisionFormat(inp_args->shadertype, inp_args->precisiontype, inp_args->range, inp_args->precision);
free(inp);break;
case XF_GL_OPCODE_glBindTexture:
glBindTexture(inp_args->target, inp_args->texture);
free(inp);break;
case XF_GL_OPCODE_eglGetCurrentSurface:
XF_GL_Op_Args_eglGetCurrentSurface *inp_args = (XF_GL_Op_Args_eglGetCurrentSurface *)inp;XF_GL_Op_Return_eglGetCurrentSurface *retval = malloc(sizeof(XF_GL_Op_Return_eglGetCurrentSurface));
retval->v = eglGetCurrentSurface(inp_args->readdraw);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetShaderiv:
glGetShaderiv(inp_args->shader, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_eglClientWaitSync:
XF_GL_Op_Args_eglClientWaitSync *inp_args = (XF_GL_Op_Args_eglClientWaitSync *)inp;XF_GL_Op_Return_eglClientWaitSync *retval = malloc(sizeof(XF_GL_Op_Return_eglClientWaitSync));
retval->v = eglClientWaitSync(inp_args->dpy, inp_args->sync, inp_args->flags, inp_args->timeout);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glUseProgram:
glUseProgram(inp_args->program);
free(inp);break;
case XF_GL_OPCODE_glClearColor:
glClearColor(inp_args->red, inp_args->green, inp_args->blue, inp_args->alpha);
free(inp);break;
case XF_GL_OPCODE_glGetActiveAttrib:
glGetActiveAttrib(inp_args->program, inp_args->index, inp_args->bufSize, inp_args->length, inp_args->size, inp_args->type, inp_args->name);
free(inp);break;
case XF_GL_OPCODE_eglInitialize:
XF_GL_Op_Args_eglInitialize *inp_args = (XF_GL_Op_Args_eglInitialize *)inp;XF_GL_Op_Return_eglInitialize *retval = malloc(sizeof(XF_GL_Op_Return_eglInitialize));
retval->v = eglInitialize(inp_args->dpy, inp_args->major, inp_args->minor);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglQueryContext:
XF_GL_Op_Args_eglQueryContext *inp_args = (XF_GL_Op_Args_eglQueryContext *)inp;XF_GL_Op_Return_eglQueryContext *retval = malloc(sizeof(XF_GL_Op_Return_eglQueryContext));
retval->v = eglQueryContext(inp_args->dpy, inp_args->ctx, inp_args->attribute, inp_args->value);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glFlush:
glFlush();
free(inp);break;
case XF_GL_OPCODE_glDepthRangef:
glDepthRangef(inp_args->n, inp_args->f);
free(inp);break;
case XF_GL_OPCODE_eglGetProcAddress:
XF_GL_Op_Args_eglGetProcAddress *inp_args = (XF_GL_Op_Args_eglGetProcAddress *)inp;XF_GL_Op_Return_eglGetProcAddress *retval = malloc(sizeof(XF_GL_Op_Return_eglGetProcAddress));
retval->v = eglGetProcAddress(inp_args->procname);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glIsFramebuffer:
XF_GL_Op_Args_glIsFramebuffer *inp_args = (XF_GL_Op_Args_glIsFramebuffer *)inp;XF_GL_Op_Return_glIsFramebuffer *retval = malloc(sizeof(XF_GL_Op_Return_glIsFramebuffer));
retval->v = glIsFramebuffer(inp_args->framebuffer);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glVertexAttrib3fv:
glVertexAttrib3fv(inp_args->index, inp_args->v);
free(inp);break;
case XF_GL_OPCODE_glBlendFunc:
glBlendFunc(inp_args->sfactor, inp_args->dfactor);
free(inp);break;
case XF_GL_OPCODE_glGetAttachedShaders:
glGetAttachedShaders(inp_args->program, inp_args->maxCount, inp_args->count, inp_args->shaders);
free(inp);break;
case XF_GL_OPCODE_glBlendEquationSeparate:
glBlendEquationSeparate(inp_args->modeRGB, inp_args->modeAlpha);
free(inp);break;
case XF_GL_OPCODE_glTexParameteriv:
glTexParameteriv(inp_args->target, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_eglSwapBuffers:
XF_GL_Op_Args_eglSwapBuffers *inp_args = (XF_GL_Op_Args_eglSwapBuffers *)inp;XF_GL_Op_Return_eglSwapBuffers *retval = malloc(sizeof(XF_GL_Op_Return_eglSwapBuffers));
retval->v = eglSwapBuffers(inp_args->dpy, inp_args->surface);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglCreateWindowSurface:
XF_GL_Op_Args_eglCreateWindowSurface *inp_args = (XF_GL_Op_Args_eglCreateWindowSurface *)inp;XF_GL_Op_Return_eglCreateWindowSurface *retval = malloc(sizeof(XF_GL_Op_Return_eglCreateWindowSurface));
retval->v = eglCreateWindowSurface(inp_args->dpy, inp_args->config, inp_args->win, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glDisableVertexAttribArray:
glDisableVertexAttribArray(inp_args->index);
free(inp);break;
case XF_GL_OPCODE_glGetUniformiv:
glGetUniformiv(inp_args->program, inp_args->location, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glBlendEquation:
glBlendEquation(inp_args->mode);
free(inp);break;
case XF_GL_OPCODE_glDisable:
glDisable(inp_args->cap);
free(inp);break;
case XF_GL_OPCODE_glGetTexParameterfv:
glGetTexParameterfv(inp_args->target, inp_args->pname, inp_args->params);
free(inp);break;
case XF_GL_OPCODE_glBufferSubData:
glBufferSubData(inp_args->target, inp_args->offset, inp_args->size, inp_args->data);
free(inp);break;
case XF_GL_OPCODE_glDepthFunc:
glDepthFunc(inp_args->func);
free(inp);break;
case XF_GL_OPCODE_eglCreatePbufferFromClientBuffer:
XF_GL_Op_Args_eglCreatePbufferFromClientBuffer *inp_args = (XF_GL_Op_Args_eglCreatePbufferFromClientBuffer *)inp;XF_GL_Op_Return_eglCreatePbufferFromClientBuffer *retval = malloc(sizeof(XF_GL_Op_Return_eglCreatePbufferFromClientBuffer));
retval->v = eglCreatePbufferFromClientBuffer(inp_args->dpy, inp_args->buftype, inp_args->buffer, inp_args->config, inp_args->attrib_list);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glClearDepthf:
glClearDepthf(inp_args->d);
free(inp);break;
case XF_GL_OPCODE_glGetString:
XF_GL_Op_Args_glGetString *inp_args = (XF_GL_Op_Args_glGetString *)inp;XF_GL_Op_Return_glGetString *retval = malloc(sizeof(XF_GL_Op_Return_glGetString));
retval->v = glGetString(inp_args->name);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glColorMask:
glColorMask(inp_args->red, inp_args->green, inp_args->blue, inp_args->alpha);
free(inp);break;
case XF_GL_OPCODE_eglQueryString:
XF_GL_Op_Args_eglQueryString *inp_args = (XF_GL_Op_Args_eglQueryString *)inp;XF_GL_Op_Return_eglQueryString *retval = malloc(sizeof(XF_GL_Op_Return_eglQueryString));
retval->v = eglQueryString(inp_args->dpy, inp_args->name);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glIsShader:
XF_GL_Op_Args_glIsShader *inp_args = (XF_GL_Op_Args_glIsShader *)inp;XF_GL_Op_Return_glIsShader *retval = malloc(sizeof(XF_GL_Op_Return_glIsShader));
retval->v = glIsShader(inp_args->shader);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glGetIntegerv:
glGetIntegerv(inp_args->pname, inp_args->data);
free(inp);break;
case XF_GL_OPCODE_eglGetDisplay:
XF_GL_Op_Args_eglGetDisplay *inp_args = (XF_GL_Op_Args_eglGetDisplay *)inp;XF_GL_Op_Return_eglGetDisplay *retval = malloc(sizeof(XF_GL_Op_Return_eglGetDisplay));
retval->v = eglGetDisplay(inp_args->display_id);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glCheckFramebufferStatus:
XF_GL_Op_Args_glCheckFramebufferStatus *inp_args = (XF_GL_Op_Args_glCheckFramebufferStatus *)inp;XF_GL_Op_Return_glCheckFramebufferStatus *retval = malloc(sizeof(XF_GL_Op_Return_glCheckFramebufferStatus));
retval->v = glCheckFramebufferStatus(inp_args->target);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glStencilMask:
glStencilMask(inp_args->mask);
free(inp);break;
case XF_GL_OPCODE_glUniform4i:
glUniform4i(inp_args->location, inp_args->v0, inp_args->v1, inp_args->v2, inp_args->v3);
free(inp);break;
case XF_GL_OPCODE_glDrawArrays:
glDrawArrays(inp_args->mode, inp_args->first, inp_args->count);
free(inp);break;
case XF_GL_OPCODE_glUniform2iv:
glUniform2iv(inp_args->location, inp_args->count, inp_args->value);
free(inp);break;
case XF_GL_OPCODE_glUniform2f:
glUniform2f(inp_args->location, inp_args->v0, inp_args->v1);
free(inp);break;
case XF_GL_OPCODE_glVertexAttrib1f:
glVertexAttrib1f(inp_args->index, inp_args->x);
free(inp);break;
case XF_GL_OPCODE_glCreateProgram:
XF_GL_Op_Args_glCreateProgram *inp_args = (XF_GL_Op_Args_glCreateProgram *)inp;XF_GL_Op_Return_glCreateProgram *retval = malloc(sizeof(XF_GL_Op_Return_glCreateProgram));
retval->v = glCreateProgram();
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_eglChooseConfig:
XF_GL_Op_Args_eglChooseConfig *inp_args = (XF_GL_Op_Args_eglChooseConfig *)inp;XF_GL_Op_Return_eglChooseConfig *retval = malloc(sizeof(XF_GL_Op_Return_eglChooseConfig));
retval->v = eglChooseConfig(inp_args->dpy, inp_args->attrib_list, inp_args->configs, inp_args->config_size, inp_args->num_config);
free(inp);outp = (XF_GL_Op *) retval;break;
case XF_GL_OPCODE_glIsEnabled:
XF_GL_Op_Args_glIsEnabled *inp_args = (XF_GL_Op_Args_glIsEnabled *)inp;XF_GL_Op_Return_glIsEnabled *retval = malloc(sizeof(XF_GL_Op_Return_glIsEnabled));
retval->v = glIsEnabled(inp_args->cap);
free(inp);outp = (XF_GL_Op *) retval;break;

            default:
                return 0;
        }
        outp->opcode = inp->opcode;
        outp->id = inp->id;
        return outp;
    }

    XF_GL_Op xf_pack_glPixelStorei(GLenum pname,  GLint param) {
        XF_GL_Op_Args_glPixelStorei *res = malloc(sizeof(XF_GL_Op_Args_glPixelStorei));
        res->__xf_op->opcode = XF_GL_OPCODE_glPixelStorei;
    res->pname = pname;
res->param = param;

        return res;
    }


    XF_GL_Op xf_pack_glUniformMatrix4fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value) {
        XF_GL_Op_Args_glUniformMatrix4fv *res = malloc(sizeof(XF_GL_Op_Args_glUniformMatrix4fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniformMatrix4fv;
    res->location = location;
res->count = count;
res->transpose = transpose;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glShaderBinary(GLsizei count,  const GLuint *shaders,  GLenum binaryformat,  const void *binary,  GLsizei length) {
        XF_GL_Op_Args_glShaderBinary *res = malloc(sizeof(XF_GL_Op_Args_glShaderBinary));
        res->__xf_op->opcode = XF_GL_OPCODE_glShaderBinary;
    res->count = count;
res->shaders = shaders;
res->binaryformat = binaryformat;
res->binary = binary;
res->length = length;

        return res;
    }


    XF_GL_Op xf_pack_eglQueryAPI() {
        XF_GL_Op_Args_eglQueryAPI *res = malloc(sizeof(XF_GL_Op_Args_eglQueryAPI));
        res->__xf_op->opcode = XF_GL_OPCODE_eglQueryAPI;
    
        return res;
    }


    XF_GL_Op xf_pack_glGetBooleanv(GLenum pname,  GLboolean *data) {
        XF_GL_Op_Args_glGetBooleanv *res = malloc(sizeof(XF_GL_Op_Args_glGetBooleanv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetBooleanv;
    res->pname = pname;
res->data = data;

        return res;
    }


    XF_GL_Op xf_pack_glBindFramebuffer(GLenum target,  GLuint framebuffer) {
        XF_GL_Op_Args_glBindFramebuffer *res = malloc(sizeof(XF_GL_Op_Args_glBindFramebuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glBindFramebuffer;
    res->target = target;
res->framebuffer = framebuffer;

        return res;
    }


    XF_GL_Op xf_pack_eglGetCurrentContext() {
        XF_GL_Op_Args_eglGetCurrentContext *res = malloc(sizeof(XF_GL_Op_Args_eglGetCurrentContext));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetCurrentContext;
    
        return res;
    }


    XF_GL_Op xf_pack_glCompileShader(GLuint shader) {
        XF_GL_Op_Args_glCompileShader *res = malloc(sizeof(XF_GL_Op_Args_glCompileShader));
        res->__xf_op->opcode = XF_GL_OPCODE_glCompileShader;
    res->shader = shader;

        return res;
    }


    XF_GL_Op xf_pack_glCompressedTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const void *data) {
        XF_GL_Op_Args_glCompressedTexImage2D *res = malloc(sizeof(XF_GL_Op_Args_glCompressedTexImage2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glCompressedTexImage2D;
    res->target = target;
res->level = level;
res->internalformat = internalformat;
res->width = width;
res->height = height;
res->border = border;
res->imageSize = imageSize;
res->data = data;

        return res;
    }


    XF_GL_Op xf_pack_glGenerateMipmap(GLenum target) {
        XF_GL_Op_Args_glGenerateMipmap *res = malloc(sizeof(XF_GL_Op_Args_glGenerateMipmap));
        res->__xf_op->opcode = XF_GL_OPCODE_glGenerateMipmap;
    res->target = target;

        return res;
    }


    XF_GL_Op xf_pack_eglGetConfigAttrib(EGLDisplay dpy,  EGLConfig config,  EGLint attribute,  EGLint *value) {
        XF_GL_Op_Args_eglGetConfigAttrib *res = malloc(sizeof(XF_GL_Op_Args_eglGetConfigAttrib));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetConfigAttrib;
    res->dpy = dpy;
res->config = config;
res->attribute = attribute;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glDeleteShader(GLuint shader) {
        XF_GL_Op_Args_glDeleteShader *res = malloc(sizeof(XF_GL_Op_Args_glDeleteShader));
        res->__xf_op->opcode = XF_GL_OPCODE_glDeleteShader;
    res->shader = shader;

        return res;
    }


    XF_GL_Op xf_pack_eglCreatePlatformWindowSurface(EGLDisplay dpy,  EGLConfig config,  void *native_window,  const EGLAttrib *attrib_list) {
        XF_GL_Op_Args_eglCreatePlatformWindowSurface *res = malloc(sizeof(XF_GL_Op_Args_eglCreatePlatformWindowSurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreatePlatformWindowSurface;
    res->dpy = dpy;
res->config = config;
res->native_window = native_window;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_glPolygonOffset(GLfloat factor,  GLfloat units) {
        XF_GL_Op_Args_glPolygonOffset *res = malloc(sizeof(XF_GL_Op_Args_glPolygonOffset));
        res->__xf_op->opcode = XF_GL_OPCODE_glPolygonOffset;
    res->factor = factor;
res->units = units;

        return res;
    }


    XF_GL_Op xf_pack_glFrontFace(GLenum mode) {
        XF_GL_Op_Args_glFrontFace *res = malloc(sizeof(XF_GL_Op_Args_glFrontFace));
        res->__xf_op->opcode = XF_GL_OPCODE_glFrontFace;
    res->mode = mode;

        return res;
    }


    XF_GL_Op xf_pack_glUniform3iv(GLint location,  GLsizei count,  const GLint *value) {
        XF_GL_Op_Args_glUniform3iv *res = malloc(sizeof(XF_GL_Op_Args_glUniform3iv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform3iv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glGetTexParameteriv(GLenum target,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetTexParameteriv *res = malloc(sizeof(XF_GL_Op_Args_glGetTexParameteriv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetTexParameteriv;
    res->target = target;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib3f(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z) {
        XF_GL_Op_Args_glVertexAttrib3f *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib3f));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib3f;
    res->index = index;
res->x = x;
res->y = y;
res->z = z;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib2fv(GLuint index,  const GLfloat *v) {
        XF_GL_Op_Args_glVertexAttrib2fv *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib2fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib2fv;
    res->index = index;
res->v = v;

        return res;
    }


    XF_GL_Op xf_pack_glSampleCoverage(GLfloat value,  GLboolean invert) {
        XF_GL_Op_Args_glSampleCoverage *res = malloc(sizeof(XF_GL_Op_Args_glSampleCoverage));
        res->__xf_op->opcode = XF_GL_OPCODE_glSampleCoverage;
    res->value = value;
res->invert = invert;

        return res;
    }


    XF_GL_Op xf_pack_glUniformMatrix3fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value) {
        XF_GL_Op_Args_glUniformMatrix3fv *res = malloc(sizeof(XF_GL_Op_Args_glUniformMatrix3fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniformMatrix3fv;
    res->location = location;
res->count = count;
res->transpose = transpose;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glGenFramebuffers(GLsizei n,  GLuint *framebuffers) {
        XF_GL_Op_Args_glGenFramebuffers *res = malloc(sizeof(XF_GL_Op_Args_glGenFramebuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_glGenFramebuffers;
    res->n = n;
res->framebuffers = framebuffers;

        return res;
    }


    XF_GL_Op xf_pack_glFramebufferTexture2D(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level) {
        XF_GL_Op_Args_glFramebufferTexture2D *res = malloc(sizeof(XF_GL_Op_Args_glFramebufferTexture2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glFramebufferTexture2D;
    res->target = target;
res->attachment = attachment;
res->textarget = textarget;
res->texture = texture;
res->level = level;

        return res;
    }


    XF_GL_Op xf_pack_eglWaitSync(EGLDisplay dpy,  EGLSync sync,  EGLint flags) {
        XF_GL_Op_Args_eglWaitSync *res = malloc(sizeof(XF_GL_Op_Args_eglWaitSync));
        res->__xf_op->opcode = XF_GL_OPCODE_eglWaitSync;
    res->dpy = dpy;
res->sync = sync;
res->flags = flags;

        return res;
    }


    XF_GL_Op xf_pack_glDeleteRenderbuffers(GLsizei n,  const GLuint *renderbuffers) {
        XF_GL_Op_Args_glDeleteRenderbuffers *res = malloc(sizeof(XF_GL_Op_Args_glDeleteRenderbuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_glDeleteRenderbuffers;
    res->n = n;
res->renderbuffers = renderbuffers;

        return res;
    }


    XF_GL_Op xf_pack_glAttachShader(GLuint program,  GLuint shader) {
        XF_GL_Op_Args_glAttachShader *res = malloc(sizeof(XF_GL_Op_Args_glAttachShader));
        res->__xf_op->opcode = XF_GL_OPCODE_glAttachShader;
    res->program = program;
res->shader = shader;

        return res;
    }


    XF_GL_Op xf_pack_glUniform2i(GLint location,  GLint v0,  GLint v1) {
        XF_GL_Op_Args_glUniform2i *res = malloc(sizeof(XF_GL_Op_Args_glUniform2i));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform2i;
    res->location = location;
res->v0 = v0;
res->v1 = v1;

        return res;
    }


    XF_GL_Op xf_pack_glGetVertexAttribPointerv(GLuint index,  GLenum pname,  void **pointer) {
        XF_GL_Op_Args_glGetVertexAttribPointerv *res = malloc(sizeof(XF_GL_Op_Args_glGetVertexAttribPointerv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetVertexAttribPointerv;
    res->index = index;
res->pname = pname;
res->pointer = pointer;

        return res;
    }


    XF_GL_Op xf_pack_glBlendColor(GLfloat red,  GLfloat green,  GLfloat blue,  GLfloat alpha) {
        XF_GL_Op_Args_glBlendColor *res = malloc(sizeof(XF_GL_Op_Args_glBlendColor));
        res->__xf_op->opcode = XF_GL_OPCODE_glBlendColor;
    res->red = red;
res->green = green;
res->blue = blue;
res->alpha = alpha;

        return res;
    }


    XF_GL_Op xf_pack_glTexParameterfv(GLenum target,  GLenum pname,  const GLfloat *params) {
        XF_GL_Op_Args_glTexParameterfv *res = malloc(sizeof(XF_GL_Op_Args_glTexParameterfv));
        res->__xf_op->opcode = XF_GL_OPCODE_glTexParameterfv;
    res->target = target;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_eglSurfaceAttrib(EGLDisplay dpy,  EGLSurface surface,  EGLint attribute,  EGLint value) {
        XF_GL_Op_Args_eglSurfaceAttrib *res = malloc(sizeof(XF_GL_Op_Args_eglSurfaceAttrib));
        res->__xf_op->opcode = XF_GL_OPCODE_eglSurfaceAttrib;
    res->dpy = dpy;
res->surface = surface;
res->attribute = attribute;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glTexParameteri(GLenum target,  GLenum pname,  GLint param) {
        XF_GL_Op_Args_glTexParameteri *res = malloc(sizeof(XF_GL_Op_Args_glTexParameteri));
        res->__xf_op->opcode = XF_GL_OPCODE_glTexParameteri;
    res->target = target;
res->pname = pname;
res->param = param;

        return res;
    }


    XF_GL_Op xf_pack_glIsRenderbuffer(GLuint renderbuffer) {
        XF_GL_Op_Args_glIsRenderbuffer *res = malloc(sizeof(XF_GL_Op_Args_glIsRenderbuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsRenderbuffer;
    res->renderbuffer = renderbuffer;

        return res;
    }


    XF_GL_Op xf_pack_glDeleteTextures(GLsizei n,  const GLuint *textures) {
        XF_GL_Op_Args_glDeleteTextures *res = malloc(sizeof(XF_GL_Op_Args_glDeleteTextures));
        res->__xf_op->opcode = XF_GL_OPCODE_glDeleteTextures;
    res->n = n;
res->textures = textures;

        return res;
    }


    XF_GL_Op xf_pack_eglWaitClient() {
        XF_GL_Op_Args_eglWaitClient *res = malloc(sizeof(XF_GL_Op_Args_eglWaitClient));
        res->__xf_op->opcode = XF_GL_OPCODE_eglWaitClient;
    
        return res;
    }


    XF_GL_Op xf_pack_glCopyTexSubImage2D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height) {
        XF_GL_Op_Args_glCopyTexSubImage2D *res = malloc(sizeof(XF_GL_Op_Args_glCopyTexSubImage2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glCopyTexSubImage2D;
    res->target = target;
res->level = level;
res->xoffset = xoffset;
res->yoffset = yoffset;
res->x = x;
res->y = y;
res->width = width;
res->height = height;

        return res;
    }


    XF_GL_Op xf_pack_glDetachShader(GLuint program,  GLuint shader) {
        XF_GL_Op_Args_glDetachShader *res = malloc(sizeof(XF_GL_Op_Args_glDetachShader));
        res->__xf_op->opcode = XF_GL_OPCODE_glDetachShader;
    res->program = program;
res->shader = shader;

        return res;
    }


    XF_GL_Op xf_pack_glLineWidth(GLfloat width) {
        XF_GL_Op_Args_glLineWidth *res = malloc(sizeof(XF_GL_Op_Args_glLineWidth));
        res->__xf_op->opcode = XF_GL_OPCODE_glLineWidth;
    res->width = width;

        return res;
    }


    XF_GL_Op xf_pack_glFinish() {
        XF_GL_Op_Args_glFinish *res = malloc(sizeof(XF_GL_Op_Args_glFinish));
        res->__xf_op->opcode = XF_GL_OPCODE_glFinish;
    
        return res;
    }


    XF_GL_Op xf_pack_glScissor(GLint x,  GLint y,  GLsizei width,  GLsizei height) {
        XF_GL_Op_Args_glScissor *res = malloc(sizeof(XF_GL_Op_Args_glScissor));
        res->__xf_op->opcode = XF_GL_OPCODE_glScissor;
    res->x = x;
res->y = y;
res->width = width;
res->height = height;

        return res;
    }


    XF_GL_Op xf_pack_glBlendFuncSeparate(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha) {
        XF_GL_Op_Args_glBlendFuncSeparate *res = malloc(sizeof(XF_GL_Op_Args_glBlendFuncSeparate));
        res->__xf_op->opcode = XF_GL_OPCODE_glBlendFuncSeparate;
    res->sfactorRGB = sfactorRGB;
res->dfactorRGB = dfactorRGB;
res->sfactorAlpha = sfactorAlpha;
res->dfactorAlpha = dfactorAlpha;

        return res;
    }


    XF_GL_Op xf_pack_glStencilFunc(GLenum func,  GLint ref,  GLuint mask) {
        XF_GL_Op_Args_glStencilFunc *res = malloc(sizeof(XF_GL_Op_Args_glStencilFunc));
        res->__xf_op->opcode = XF_GL_OPCODE_glStencilFunc;
    res->func = func;
res->ref = ref;
res->mask = mask;

        return res;
    }


    XF_GL_Op xf_pack_glClear(GLbitfield mask) {
        XF_GL_Op_Args_glClear *res = malloc(sizeof(XF_GL_Op_Args_glClear));
        res->__xf_op->opcode = XF_GL_OPCODE_glClear;
    res->mask = mask;

        return res;
    }


    XF_GL_Op xf_pack_eglDestroySurface(EGLDisplay dpy,  EGLSurface surface) {
        XF_GL_Op_Args_eglDestroySurface *res = malloc(sizeof(XF_GL_Op_Args_eglDestroySurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglDestroySurface;
    res->dpy = dpy;
res->surface = surface;

        return res;
    }


    XF_GL_Op xf_pack_eglMakeCurrent(EGLDisplay dpy,  EGLSurface draw,  EGLSurface read,  EGLContext ctx) {
        XF_GL_Op_Args_eglMakeCurrent *res = malloc(sizeof(XF_GL_Op_Args_eglMakeCurrent));
        res->__xf_op->opcode = XF_GL_OPCODE_eglMakeCurrent;
    res->dpy = dpy;
res->draw = draw;
res->read = read;
res->ctx = ctx;

        return res;
    }


    XF_GL_Op xf_pack_glReadPixels(GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  void *pixels) {
        XF_GL_Op_Args_glReadPixels *res = malloc(sizeof(XF_GL_Op_Args_glReadPixels));
        res->__xf_op->opcode = XF_GL_OPCODE_glReadPixels;
    res->x = x;
res->y = y;
res->width = width;
res->height = height;
res->format = format;
res->type = type;
res->pixels = pixels;

        return res;
    }


    XF_GL_Op xf_pack_eglDestroyImage(EGLDisplay dpy,  EGLImage image) {
        XF_GL_Op_Args_eglDestroyImage *res = malloc(sizeof(XF_GL_Op_Args_eglDestroyImage));
        res->__xf_op->opcode = XF_GL_OPCODE_eglDestroyImage;
    res->dpy = dpy;
res->image = image;

        return res;
    }


    XF_GL_Op xf_pack_glCompressedTexSubImage2D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const void *data) {
        XF_GL_Op_Args_glCompressedTexSubImage2D *res = malloc(sizeof(XF_GL_Op_Args_glCompressedTexSubImage2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glCompressedTexSubImage2D;
    res->target = target;
res->level = level;
res->xoffset = xoffset;
res->yoffset = yoffset;
res->width = width;
res->height = height;
res->format = format;
res->imageSize = imageSize;
res->data = data;

        return res;
    }


    XF_GL_Op xf_pack_glCullFace(GLenum mode) {
        XF_GL_Op_Args_glCullFace *res = malloc(sizeof(XF_GL_Op_Args_glCullFace));
        res->__xf_op->opcode = XF_GL_OPCODE_glCullFace;
    res->mode = mode;

        return res;
    }


    XF_GL_Op xf_pack_glUniform1f(GLint location,  GLfloat v0) {
        XF_GL_Op_Args_glUniform1f *res = malloc(sizeof(XF_GL_Op_Args_glUniform1f));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform1f;
    res->location = location;
res->v0 = v0;

        return res;
    }


    XF_GL_Op xf_pack_glShaderSource(GLuint shader,  GLsizei count,  const GLchar *const*string,  const GLint *length) {
        XF_GL_Op_Args_glShaderSource *res = malloc(sizeof(XF_GL_Op_Args_glShaderSource));
        res->__xf_op->opcode = XF_GL_OPCODE_glShaderSource;
    res->shader = shader;
res->count = count;
res->string = string;
res->length = length;

        return res;
    }


    XF_GL_Op xf_pack_eglTerminate(EGLDisplay dpy) {
        XF_GL_Op_Args_eglTerminate *res = malloc(sizeof(XF_GL_Op_Args_eglTerminate));
        res->__xf_op->opcode = XF_GL_OPCODE_eglTerminate;
    res->dpy = dpy;

        return res;
    }


    XF_GL_Op xf_pack_glUniform4iv(GLint location,  GLsizei count,  const GLint *value) {
        XF_GL_Op_Args_glUniform4iv *res = malloc(sizeof(XF_GL_Op_Args_glUniform4iv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform4iv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glGenTextures(GLsizei n,  GLuint *textures) {
        XF_GL_Op_Args_glGenTextures *res = malloc(sizeof(XF_GL_Op_Args_glGenTextures));
        res->__xf_op->opcode = XF_GL_OPCODE_glGenTextures;
    res->n = n;
res->textures = textures;

        return res;
    }


    XF_GL_Op xf_pack_glGetError() {
        XF_GL_Op_Args_glGetError *res = malloc(sizeof(XF_GL_Op_Args_glGetError));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetError;
    
        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib2f(GLuint index,  GLfloat x,  GLfloat y) {
        XF_GL_Op_Args_glVertexAttrib2f *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib2f));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib2f;
    res->index = index;
res->x = x;
res->y = y;

        return res;
    }


    XF_GL_Op xf_pack_glHint(GLenum target,  GLenum mode) {
        XF_GL_Op_Args_glHint *res = malloc(sizeof(XF_GL_Op_Args_glHint));
        res->__xf_op->opcode = XF_GL_OPCODE_glHint;
    res->target = target;
res->mode = mode;

        return res;
    }


    XF_GL_Op xf_pack_glFramebufferRenderbuffer(GLenum target,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer) {
        XF_GL_Op_Args_glFramebufferRenderbuffer *res = malloc(sizeof(XF_GL_Op_Args_glFramebufferRenderbuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glFramebufferRenderbuffer;
    res->target = target;
res->attachment = attachment;
res->renderbuffertarget = renderbuffertarget;
res->renderbuffer = renderbuffer;

        return res;
    }


    XF_GL_Op xf_pack_eglWaitGL() {
        XF_GL_Op_Args_eglWaitGL *res = malloc(sizeof(XF_GL_Op_Args_eglWaitGL));
        res->__xf_op->opcode = XF_GL_OPCODE_eglWaitGL;
    
        return res;
    }


    XF_GL_Op xf_pack_eglReleaseTexImage(EGLDisplay dpy,  EGLSurface surface,  EGLint buffer) {
        XF_GL_Op_Args_eglReleaseTexImage *res = malloc(sizeof(XF_GL_Op_Args_eglReleaseTexImage));
        res->__xf_op->opcode = XF_GL_OPCODE_eglReleaseTexImage;
    res->dpy = dpy;
res->surface = surface;
res->buffer = buffer;

        return res;
    }


    XF_GL_Op xf_pack_glUniformMatrix2fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value) {
        XF_GL_Op_Args_glUniformMatrix2fv *res = malloc(sizeof(XF_GL_Op_Args_glUniformMatrix2fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniformMatrix2fv;
    res->location = location;
res->count = count;
res->transpose = transpose;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glGetVertexAttribfv(GLuint index,  GLenum pname,  GLfloat *params) {
        XF_GL_Op_Args_glGetVertexAttribfv *res = malloc(sizeof(XF_GL_Op_Args_glGetVertexAttribfv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetVertexAttribfv;
    res->index = index;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glDeleteProgram(GLuint program) {
        XF_GL_Op_Args_glDeleteProgram *res = malloc(sizeof(XF_GL_Op_Args_glDeleteProgram));
        res->__xf_op->opcode = XF_GL_OPCODE_glDeleteProgram;
    res->program = program;

        return res;
    }


    XF_GL_Op xf_pack_glBufferData(GLenum target,  GLsizeiptr size,  const void *data,  GLenum usage) {
        XF_GL_Op_Args_glBufferData *res = malloc(sizeof(XF_GL_Op_Args_glBufferData));
        res->__xf_op->opcode = XF_GL_OPCODE_glBufferData;
    res->target = target;
res->size = size;
res->data = data;
res->usage = usage;

        return res;
    }


    XF_GL_Op xf_pack_glValidateProgram(GLuint program) {
        XF_GL_Op_Args_glValidateProgram *res = malloc(sizeof(XF_GL_Op_Args_glValidateProgram));
        res->__xf_op->opcode = XF_GL_OPCODE_glValidateProgram;
    res->program = program;

        return res;
    }


    XF_GL_Op xf_pack_glGetShaderInfoLog(GLuint shader,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog) {
        XF_GL_Op_Args_glGetShaderInfoLog *res = malloc(sizeof(XF_GL_Op_Args_glGetShaderInfoLog));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetShaderInfoLog;
    res->shader = shader;
res->bufSize = bufSize;
res->length = length;
res->infoLog = infoLog;

        return res;
    }


    XF_GL_Op xf_pack_glRenderbufferStorage(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height) {
        XF_GL_Op_Args_glRenderbufferStorage *res = malloc(sizeof(XF_GL_Op_Args_glRenderbufferStorage));
        res->__xf_op->opcode = XF_GL_OPCODE_glRenderbufferStorage;
    res->target = target;
res->internalformat = internalformat;
res->width = width;
res->height = height;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib1fv(GLuint index,  const GLfloat *v) {
        XF_GL_Op_Args_glVertexAttrib1fv *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib1fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib1fv;
    res->index = index;
res->v = v;

        return res;
    }


    XF_GL_Op xf_pack_eglBindAPI(EGLenum api) {
        XF_GL_Op_Args_eglBindAPI *res = malloc(sizeof(XF_GL_Op_Args_eglBindAPI));
        res->__xf_op->opcode = XF_GL_OPCODE_eglBindAPI;
    res->api = api;

        return res;
    }


    XF_GL_Op xf_pack_glDeleteFramebuffers(GLsizei n,  const GLuint *framebuffers) {
        XF_GL_Op_Args_glDeleteFramebuffers *res = malloc(sizeof(XF_GL_Op_Args_glDeleteFramebuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_glDeleteFramebuffers;
    res->n = n;
res->framebuffers = framebuffers;

        return res;
    }


    XF_GL_Op xf_pack_glEnableVertexAttribArray(GLuint index) {
        XF_GL_Op_Args_glEnableVertexAttribArray *res = malloc(sizeof(XF_GL_Op_Args_glEnableVertexAttribArray));
        res->__xf_op->opcode = XF_GL_OPCODE_glEnableVertexAttribArray;
    res->index = index;

        return res;
    }


    XF_GL_Op xf_pack_eglGetSyncAttrib(EGLDisplay dpy,  EGLSync sync,  EGLint attribute,  EGLAttrib *value) {
        XF_GL_Op_Args_eglGetSyncAttrib *res = malloc(sizeof(XF_GL_Op_Args_eglGetSyncAttrib));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetSyncAttrib;
    res->dpy = dpy;
res->sync = sync;
res->attribute = attribute;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glGetRenderbufferParameteriv(GLenum target,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetRenderbufferParameteriv *res = malloc(sizeof(XF_GL_Op_Args_glGetRenderbufferParameteriv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetRenderbufferParameteriv;
    res->target = target;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glGetProgramInfoLog(GLuint program,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog) {
        XF_GL_Op_Args_glGetProgramInfoLog *res = malloc(sizeof(XF_GL_Op_Args_glGetProgramInfoLog));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetProgramInfoLog;
    res->program = program;
res->bufSize = bufSize;
res->length = length;
res->infoLog = infoLog;

        return res;
    }


    XF_GL_Op xf_pack_glUniform1iv(GLint location,  GLsizei count,  const GLint *value) {
        XF_GL_Op_Args_glUniform1iv *res = malloc(sizeof(XF_GL_Op_Args_glUniform1iv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform1iv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_eglGetCurrentDisplay() {
        XF_GL_Op_Args_eglGetCurrentDisplay *res = malloc(sizeof(XF_GL_Op_Args_eglGetCurrentDisplay));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetCurrentDisplay;
    
        return res;
    }


    XF_GL_Op xf_pack_glGetActiveUniform(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  GLchar *name) {
        XF_GL_Op_Args_glGetActiveUniform *res = malloc(sizeof(XF_GL_Op_Args_glGetActiveUniform));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetActiveUniform;
    res->program = program;
res->index = index;
res->bufSize = bufSize;
res->length = length;
res->size = size;
res->type = type;
res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_glUniform3i(GLint location,  GLint v0,  GLint v1,  GLint v2) {
        XF_GL_Op_Args_glUniform3i *res = malloc(sizeof(XF_GL_Op_Args_glUniform3i));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform3i;
    res->location = location;
res->v0 = v0;
res->v1 = v1;
res->v2 = v2;

        return res;
    }


    XF_GL_Op xf_pack_eglCreatePixmapSurface(EGLDisplay dpy,  EGLConfig config,  EGLNativePixmapType pixmap,  const EGLint *attrib_list) {
        XF_GL_Op_Args_eglCreatePixmapSurface *res = malloc(sizeof(XF_GL_Op_Args_eglCreatePixmapSurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreatePixmapSurface;
    res->dpy = dpy;
res->config = config;
res->pixmap = pixmap;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_eglGetPlatformDisplay(EGLenum platform,  void *native_display,  const EGLAttrib *attrib_list) {
        XF_GL_Op_Args_eglGetPlatformDisplay *res = malloc(sizeof(XF_GL_Op_Args_eglGetPlatformDisplay));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetPlatformDisplay;
    res->platform = platform;
res->native_display = native_display;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_glGetBufferParameteriv(GLenum target,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetBufferParameteriv *res = malloc(sizeof(XF_GL_Op_Args_glGetBufferParameteriv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetBufferParameteriv;
    res->target = target;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glUniform3f(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2) {
        XF_GL_Op_Args_glUniform3f *res = malloc(sizeof(XF_GL_Op_Args_glUniform3f));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform3f;
    res->location = location;
res->v0 = v0;
res->v1 = v1;
res->v2 = v2;

        return res;
    }


    XF_GL_Op xf_pack_glDrawElements(GLenum mode,  GLsizei count,  GLenum type,  const void *indices) {
        XF_GL_Op_Args_glDrawElements *res = malloc(sizeof(XF_GL_Op_Args_glDrawElements));
        res->__xf_op->opcode = XF_GL_OPCODE_glDrawElements;
    res->mode = mode;
res->count = count;
res->type = type;
res->indices = indices;

        return res;
    }


    XF_GL_Op xf_pack_glIsProgram(GLuint program) {
        XF_GL_Op_Args_glIsProgram *res = malloc(sizeof(XF_GL_Op_Args_glIsProgram));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsProgram;
    res->program = program;

        return res;
    }


    XF_GL_Op xf_pack_glDeleteBuffers(GLsizei n,  const GLuint *buffers) {
        XF_GL_Op_Args_glDeleteBuffers *res = malloc(sizeof(XF_GL_Op_Args_glDeleteBuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_glDeleteBuffers;
    res->n = n;
res->buffers = buffers;

        return res;
    }


    XF_GL_Op xf_pack_glIsTexture(GLuint texture) {
        XF_GL_Op_Args_glIsTexture *res = malloc(sizeof(XF_GL_Op_Args_glIsTexture));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsTexture;
    res->texture = texture;

        return res;
    }


    XF_GL_Op xf_pack_eglCreateContext(EGLDisplay dpy,  EGLConfig config,  EGLContext share_context,  const EGLint *attrib_list) {
        XF_GL_Op_Args_eglCreateContext *res = malloc(sizeof(XF_GL_Op_Args_eglCreateContext));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreateContext;
    res->dpy = dpy;
res->config = config;
res->share_context = share_context;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_glTexParameterf(GLenum target,  GLenum pname,  GLfloat param) {
        XF_GL_Op_Args_glTexParameterf *res = malloc(sizeof(XF_GL_Op_Args_glTexParameterf));
        res->__xf_op->opcode = XF_GL_OPCODE_glTexParameterf;
    res->target = target;
res->pname = pname;
res->param = param;

        return res;
    }


    XF_GL_Op xf_pack_eglDestroyContext(EGLDisplay dpy,  EGLContext ctx) {
        XF_GL_Op_Args_eglDestroyContext *res = malloc(sizeof(XF_GL_Op_Args_eglDestroyContext));
        res->__xf_op->opcode = XF_GL_OPCODE_eglDestroyContext;
    res->dpy = dpy;
res->ctx = ctx;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib4f(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w) {
        XF_GL_Op_Args_glVertexAttrib4f *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib4f));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib4f;
    res->index = index;
res->x = x;
res->y = y;
res->z = z;
res->w = w;

        return res;
    }


    XF_GL_Op xf_pack_glUniform4f(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3) {
        XF_GL_Op_Args_glUniform4f *res = malloc(sizeof(XF_GL_Op_Args_glUniform4f));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform4f;
    res->location = location;
res->v0 = v0;
res->v1 = v1;
res->v2 = v2;
res->v3 = v3;

        return res;
    }


    XF_GL_Op xf_pack_glGetFramebufferAttachmentParameteriv(GLenum target,  GLenum attachment,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetFramebufferAttachmentParameteriv *res = malloc(sizeof(XF_GL_Op_Args_glGetFramebufferAttachmentParameteriv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetFramebufferAttachmentParameteriv;
    res->target = target;
res->attachment = attachment;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glGetShaderSource(GLuint shader,  GLsizei bufSize,  GLsizei *length,  GLchar *source) {
        XF_GL_Op_Args_glGetShaderSource *res = malloc(sizeof(XF_GL_Op_Args_glGetShaderSource));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetShaderSource;
    res->shader = shader;
res->bufSize = bufSize;
res->length = length;
res->source = source;

        return res;
    }


    XF_GL_Op xf_pack_glStencilFuncSeparate(GLenum face,  GLenum func,  GLint ref,  GLuint mask) {
        XF_GL_Op_Args_glStencilFuncSeparate *res = malloc(sizeof(XF_GL_Op_Args_glStencilFuncSeparate));
        res->__xf_op->opcode = XF_GL_OPCODE_glStencilFuncSeparate;
    res->face = face;
res->func = func;
res->ref = ref;
res->mask = mask;

        return res;
    }


    XF_GL_Op xf_pack_glStencilMaskSeparate(GLenum face,  GLuint mask) {
        XF_GL_Op_Args_glStencilMaskSeparate *res = malloc(sizeof(XF_GL_Op_Args_glStencilMaskSeparate));
        res->__xf_op->opcode = XF_GL_OPCODE_glStencilMaskSeparate;
    res->face = face;
res->mask = mask;

        return res;
    }


    XF_GL_Op xf_pack_glBindAttribLocation(GLuint program,  GLuint index,  const GLchar *name) {
        XF_GL_Op_Args_glBindAttribLocation *res = malloc(sizeof(XF_GL_Op_Args_glBindAttribLocation));
        res->__xf_op->opcode = XF_GL_OPCODE_glBindAttribLocation;
    res->program = program;
res->index = index;
res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_eglWaitNative(EGLint engine) {
        XF_GL_Op_Args_eglWaitNative *res = malloc(sizeof(XF_GL_Op_Args_eglWaitNative));
        res->__xf_op->opcode = XF_GL_OPCODE_eglWaitNative;
    res->engine = engine;

        return res;
    }


    XF_GL_Op xf_pack_glBindBuffer(GLenum target,  GLuint buffer) {
        XF_GL_Op_Args_glBindBuffer *res = malloc(sizeof(XF_GL_Op_Args_glBindBuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glBindBuffer;
    res->target = target;
res->buffer = buffer;

        return res;
    }


    XF_GL_Op xf_pack_glGenBuffers(GLsizei n,  GLuint *buffers) {
        XF_GL_Op_Args_glGenBuffers *res = malloc(sizeof(XF_GL_Op_Args_glGenBuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_glGenBuffers;
    res->n = n;
res->buffers = buffers;

        return res;
    }


    XF_GL_Op xf_pack_glUniform1fv(GLint location,  GLsizei count,  const GLfloat *value) {
        XF_GL_Op_Args_glUniform1fv *res = malloc(sizeof(XF_GL_Op_Args_glUniform1fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform1fv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glUniform3fv(GLint location,  GLsizei count,  const GLfloat *value) {
        XF_GL_Op_Args_glUniform3fv *res = malloc(sizeof(XF_GL_Op_Args_glUniform3fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform3fv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glReleaseShaderCompiler() {
        XF_GL_Op_Args_glReleaseShaderCompiler *res = malloc(sizeof(XF_GL_Op_Args_glReleaseShaderCompiler));
        res->__xf_op->opcode = XF_GL_OPCODE_glReleaseShaderCompiler;
    
        return res;
    }


    XF_GL_Op xf_pack_glCreateShader(GLenum type) {
        XF_GL_Op_Args_glCreateShader *res = malloc(sizeof(XF_GL_Op_Args_glCreateShader));
        res->__xf_op->opcode = XF_GL_OPCODE_glCreateShader;
    res->type = type;

        return res;
    }


    XF_GL_Op xf_pack_glDepthMask(GLboolean flag) {
        XF_GL_Op_Args_glDepthMask *res = malloc(sizeof(XF_GL_Op_Args_glDepthMask));
        res->__xf_op->opcode = XF_GL_OPCODE_glDepthMask;
    res->flag = flag;

        return res;
    }


    XF_GL_Op xf_pack_glGenRenderbuffers(GLsizei n,  GLuint *renderbuffers) {
        XF_GL_Op_Args_glGenRenderbuffers *res = malloc(sizeof(XF_GL_Op_Args_glGenRenderbuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_glGenRenderbuffers;
    res->n = n;
res->renderbuffers = renderbuffers;

        return res;
    }


    XF_GL_Op xf_pack_glStencilOpSeparate(GLenum face,  GLenum sfail,  GLenum dpfail,  GLenum dppass) {
        XF_GL_Op_Args_glStencilOpSeparate *res = malloc(sizeof(XF_GL_Op_Args_glStencilOpSeparate));
        res->__xf_op->opcode = XF_GL_OPCODE_glStencilOpSeparate;
    res->face = face;
res->sfail = sfail;
res->dpfail = dpfail;
res->dppass = dppass;

        return res;
    }


    XF_GL_Op xf_pack_glUniform4fv(GLint location,  GLsizei count,  const GLfloat *value) {
        XF_GL_Op_Args_glUniform4fv *res = malloc(sizeof(XF_GL_Op_Args_glUniform4fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform4fv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glUniform1i(GLint location,  GLint v0) {
        XF_GL_Op_Args_glUniform1i *res = malloc(sizeof(XF_GL_Op_Args_glUniform1i));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform1i;
    res->location = location;
res->v0 = v0;

        return res;
    }


    XF_GL_Op xf_pack_glLinkProgram(GLuint program) {
        XF_GL_Op_Args_glLinkProgram *res = malloc(sizeof(XF_GL_Op_Args_glLinkProgram));
        res->__xf_op->opcode = XF_GL_OPCODE_glLinkProgram;
    res->program = program;

        return res;
    }


    XF_GL_Op xf_pack_eglCreateSync(EGLDisplay dpy,  EGLenum type,  const EGLAttrib *attrib_list) {
        XF_GL_Op_Args_eglCreateSync *res = malloc(sizeof(XF_GL_Op_Args_eglCreateSync));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreateSync;
    res->dpy = dpy;
res->type = type;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_glTexImage2D(GLenum target,  GLint level,  GLint internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLenum format,  GLenum type,  const void *pixels) {
        XF_GL_Op_Args_glTexImage2D *res = malloc(sizeof(XF_GL_Op_Args_glTexImage2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glTexImage2D;
    res->target = target;
res->level = level;
res->internalformat = internalformat;
res->width = width;
res->height = height;
res->border = border;
res->format = format;
res->type = type;
res->pixels = pixels;

        return res;
    }


    XF_GL_Op xf_pack_glGetUniformLocation(GLuint program,  const GLchar *name) {
        XF_GL_Op_Args_glGetUniformLocation *res = malloc(sizeof(XF_GL_Op_Args_glGetUniformLocation));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetUniformLocation;
    res->program = program;
res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_glTexSubImage2D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const void *pixels) {
        XF_GL_Op_Args_glTexSubImage2D *res = malloc(sizeof(XF_GL_Op_Args_glTexSubImage2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glTexSubImage2D;
    res->target = target;
res->level = level;
res->xoffset = xoffset;
res->yoffset = yoffset;
res->width = width;
res->height = height;
res->format = format;
res->type = type;
res->pixels = pixels;

        return res;
    }


    XF_GL_Op xf_pack_eglGetConfigs(EGLDisplay dpy,  EGLConfig *configs,  EGLint config_size,  EGLint *num_config) {
        XF_GL_Op_Args_eglGetConfigs *res = malloc(sizeof(XF_GL_Op_Args_eglGetConfigs));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetConfigs;
    res->dpy = dpy;
res->configs = configs;
res->config_size = config_size;
res->num_config = num_config;

        return res;
    }


    XF_GL_Op xf_pack_eglCreatePlatformPixmapSurface(EGLDisplay dpy,  EGLConfig config,  void *native_pixmap,  const EGLAttrib *attrib_list) {
        XF_GL_Op_Args_eglCreatePlatformPixmapSurface *res = malloc(sizeof(XF_GL_Op_Args_eglCreatePlatformPixmapSurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreatePlatformPixmapSurface;
    res->dpy = dpy;
res->config = config;
res->native_pixmap = native_pixmap;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_eglGetError() {
        XF_GL_Op_Args_eglGetError *res = malloc(sizeof(XF_GL_Op_Args_eglGetError));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetError;
    
        return res;
    }


    XF_GL_Op xf_pack_eglSwapInterval(EGLDisplay dpy,  EGLint interval) {
        XF_GL_Op_Args_eglSwapInterval *res = malloc(sizeof(XF_GL_Op_Args_eglSwapInterval));
        res->__xf_op->opcode = XF_GL_OPCODE_eglSwapInterval;
    res->dpy = dpy;
res->interval = interval;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttribPointer(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const void *pointer) {
        XF_GL_Op_Args_glVertexAttribPointer *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttribPointer));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttribPointer;
    res->index = index;
res->size = size;
res->type = type;
res->normalized = normalized;
res->stride = stride;
res->pointer = pointer;

        return res;
    }


    XF_GL_Op xf_pack_glStencilOp(GLenum fail,  GLenum zfail,  GLenum zpass) {
        XF_GL_Op_Args_glStencilOp *res = malloc(sizeof(XF_GL_Op_Args_glStencilOp));
        res->__xf_op->opcode = XF_GL_OPCODE_glStencilOp;
    res->fail = fail;
res->zfail = zfail;
res->zpass = zpass;

        return res;
    }


    XF_GL_Op xf_pack_glClearStencil(GLint s) {
        XF_GL_Op_Args_glClearStencil *res = malloc(sizeof(XF_GL_Op_Args_glClearStencil));
        res->__xf_op->opcode = XF_GL_OPCODE_glClearStencil;
    res->s = s;

        return res;
    }


    XF_GL_Op xf_pack_glViewport(GLint x,  GLint y,  GLsizei width,  GLsizei height) {
        XF_GL_Op_Args_glViewport *res = malloc(sizeof(XF_GL_Op_Args_glViewport));
        res->__xf_op->opcode = XF_GL_OPCODE_glViewport;
    res->x = x;
res->y = y;
res->width = width;
res->height = height;

        return res;
    }


    XF_GL_Op xf_pack_eglCopyBuffers(EGLDisplay dpy,  EGLSurface surface,  EGLNativePixmapType target) {
        XF_GL_Op_Args_eglCopyBuffers *res = malloc(sizeof(XF_GL_Op_Args_eglCopyBuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCopyBuffers;
    res->dpy = dpy;
res->surface = surface;
res->target = target;

        return res;
    }


    XF_GL_Op xf_pack_glActiveTexture(GLenum texture) {
        XF_GL_Op_Args_glActiveTexture *res = malloc(sizeof(XF_GL_Op_Args_glActiveTexture));
        res->__xf_op->opcode = XF_GL_OPCODE_glActiveTexture;
    res->texture = texture;

        return res;
    }


    XF_GL_Op xf_pack_eglReleaseThread() {
        XF_GL_Op_Args_eglReleaseThread *res = malloc(sizeof(XF_GL_Op_Args_eglReleaseThread));
        res->__xf_op->opcode = XF_GL_OPCODE_eglReleaseThread;
    
        return res;
    }


    XF_GL_Op xf_pack_glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border) {
        XF_GL_Op_Args_glCopyTexImage2D *res = malloc(sizeof(XF_GL_Op_Args_glCopyTexImage2D));
        res->__xf_op->opcode = XF_GL_OPCODE_glCopyTexImage2D;
    res->target = target;
res->level = level;
res->internalformat = internalformat;
res->x = x;
res->y = y;
res->width = width;
res->height = height;
res->border = border;

        return res;
    }


    XF_GL_Op xf_pack_glGetProgramiv(GLuint program,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetProgramiv *res = malloc(sizeof(XF_GL_Op_Args_glGetProgramiv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetProgramiv;
    res->program = program;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glEnable(GLenum cap) {
        XF_GL_Op_Args_glEnable *res = malloc(sizeof(XF_GL_Op_Args_glEnable));
        res->__xf_op->opcode = XF_GL_OPCODE_glEnable;
    res->cap = cap;

        return res;
    }


    XF_GL_Op xf_pack_glGetVertexAttribiv(GLuint index,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetVertexAttribiv *res = malloc(sizeof(XF_GL_Op_Args_glGetVertexAttribiv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetVertexAttribiv;
    res->index = index;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glGetUniformfv(GLuint program,  GLint location,  GLfloat *params) {
        XF_GL_Op_Args_glGetUniformfv *res = malloc(sizeof(XF_GL_Op_Args_glGetUniformfv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetUniformfv;
    res->program = program;
res->location = location;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_eglQuerySurface(EGLDisplay dpy,  EGLSurface surface,  EGLint attribute,  EGLint *value) {
        XF_GL_Op_Args_eglQuerySurface *res = malloc(sizeof(XF_GL_Op_Args_eglQuerySurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglQuerySurface;
    res->dpy = dpy;
res->surface = surface;
res->attribute = attribute;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glBindRenderbuffer(GLenum target,  GLuint renderbuffer) {
        XF_GL_Op_Args_glBindRenderbuffer *res = malloc(sizeof(XF_GL_Op_Args_glBindRenderbuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glBindRenderbuffer;
    res->target = target;
res->renderbuffer = renderbuffer;

        return res;
    }


    XF_GL_Op xf_pack_eglBindTexImage(EGLDisplay dpy,  EGLSurface surface,  EGLint buffer) {
        XF_GL_Op_Args_eglBindTexImage *res = malloc(sizeof(XF_GL_Op_Args_eglBindTexImage));
        res->__xf_op->opcode = XF_GL_OPCODE_eglBindTexImage;
    res->dpy = dpy;
res->surface = surface;
res->buffer = buffer;

        return res;
    }


    XF_GL_Op xf_pack_glGetAttribLocation(GLuint program,  const GLchar *name) {
        XF_GL_Op_Args_glGetAttribLocation *res = malloc(sizeof(XF_GL_Op_Args_glGetAttribLocation));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetAttribLocation;
    res->program = program;
res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_glGetFloatv(GLenum pname,  GLfloat *data) {
        XF_GL_Op_Args_glGetFloatv *res = malloc(sizeof(XF_GL_Op_Args_glGetFloatv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetFloatv;
    res->pname = pname;
res->data = data;

        return res;
    }


    XF_GL_Op xf_pack_glIsBuffer(GLuint buffer) {
        XF_GL_Op_Args_glIsBuffer *res = malloc(sizeof(XF_GL_Op_Args_glIsBuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsBuffer;
    res->buffer = buffer;

        return res;
    }


    XF_GL_Op xf_pack_glUniform2fv(GLint location,  GLsizei count,  const GLfloat *value) {
        XF_GL_Op_Args_glUniform2fv *res = malloc(sizeof(XF_GL_Op_Args_glUniform2fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform2fv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib4fv(GLuint index,  const GLfloat *v) {
        XF_GL_Op_Args_glVertexAttrib4fv *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib4fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib4fv;
    res->index = index;
res->v = v;

        return res;
    }


    XF_GL_Op xf_pack_eglCreatePbufferSurface(EGLDisplay dpy,  EGLConfig config,  const EGLint *attrib_list) {
        XF_GL_Op_Args_eglCreatePbufferSurface *res = malloc(sizeof(XF_GL_Op_Args_eglCreatePbufferSurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreatePbufferSurface;
    res->dpy = dpy;
res->config = config;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_eglCreateImage(EGLDisplay dpy,  EGLContext ctx,  EGLenum target,  EGLClientBuffer buffer,  const EGLAttrib *attrib_list) {
        XF_GL_Op_Args_eglCreateImage *res = malloc(sizeof(XF_GL_Op_Args_eglCreateImage));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreateImage;
    res->dpy = dpy;
res->ctx = ctx;
res->target = target;
res->buffer = buffer;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_eglDestroySync(EGLDisplay dpy,  EGLSync sync) {
        XF_GL_Op_Args_eglDestroySync *res = malloc(sizeof(XF_GL_Op_Args_eglDestroySync));
        res->__xf_op->opcode = XF_GL_OPCODE_eglDestroySync;
    res->dpy = dpy;
res->sync = sync;

        return res;
    }


    XF_GL_Op xf_pack_glGetShaderPrecisionFormat(GLenum shadertype,  GLenum precisiontype,  GLint *range,  GLint *precision) {
        XF_GL_Op_Args_glGetShaderPrecisionFormat *res = malloc(sizeof(XF_GL_Op_Args_glGetShaderPrecisionFormat));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetShaderPrecisionFormat;
    res->shadertype = shadertype;
res->precisiontype = precisiontype;
res->range = range;
res->precision = precision;

        return res;
    }


    XF_GL_Op xf_pack_glBindTexture(GLenum target,  GLuint texture) {
        XF_GL_Op_Args_glBindTexture *res = malloc(sizeof(XF_GL_Op_Args_glBindTexture));
        res->__xf_op->opcode = XF_GL_OPCODE_glBindTexture;
    res->target = target;
res->texture = texture;

        return res;
    }


    XF_GL_Op xf_pack_eglGetCurrentSurface(EGLint readdraw) {
        XF_GL_Op_Args_eglGetCurrentSurface *res = malloc(sizeof(XF_GL_Op_Args_eglGetCurrentSurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetCurrentSurface;
    res->readdraw = readdraw;

        return res;
    }


    XF_GL_Op xf_pack_glGetShaderiv(GLuint shader,  GLenum pname,  GLint *params) {
        XF_GL_Op_Args_glGetShaderiv *res = malloc(sizeof(XF_GL_Op_Args_glGetShaderiv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetShaderiv;
    res->shader = shader;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_eglClientWaitSync(EGLDisplay dpy,  EGLSync sync,  EGLint flags,  EGLTime timeout) {
        XF_GL_Op_Args_eglClientWaitSync *res = malloc(sizeof(XF_GL_Op_Args_eglClientWaitSync));
        res->__xf_op->opcode = XF_GL_OPCODE_eglClientWaitSync;
    res->dpy = dpy;
res->sync = sync;
res->flags = flags;
res->timeout = timeout;

        return res;
    }


    XF_GL_Op xf_pack_glUseProgram(GLuint program) {
        XF_GL_Op_Args_glUseProgram *res = malloc(sizeof(XF_GL_Op_Args_glUseProgram));
        res->__xf_op->opcode = XF_GL_OPCODE_glUseProgram;
    res->program = program;

        return res;
    }


    XF_GL_Op xf_pack_glClearColor(GLfloat red,  GLfloat green,  GLfloat blue,  GLfloat alpha) {
        XF_GL_Op_Args_glClearColor *res = malloc(sizeof(XF_GL_Op_Args_glClearColor));
        res->__xf_op->opcode = XF_GL_OPCODE_glClearColor;
    res->red = red;
res->green = green;
res->blue = blue;
res->alpha = alpha;

        return res;
    }


    XF_GL_Op xf_pack_glGetActiveAttrib(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  GLchar *name) {
        XF_GL_Op_Args_glGetActiveAttrib *res = malloc(sizeof(XF_GL_Op_Args_glGetActiveAttrib));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetActiveAttrib;
    res->program = program;
res->index = index;
res->bufSize = bufSize;
res->length = length;
res->size = size;
res->type = type;
res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_eglInitialize(EGLDisplay dpy,  EGLint *major,  EGLint *minor) {
        XF_GL_Op_Args_eglInitialize *res = malloc(sizeof(XF_GL_Op_Args_eglInitialize));
        res->__xf_op->opcode = XF_GL_OPCODE_eglInitialize;
    res->dpy = dpy;
res->major = major;
res->minor = minor;

        return res;
    }


    XF_GL_Op xf_pack_eglQueryContext(EGLDisplay dpy,  EGLContext ctx,  EGLint attribute,  EGLint *value) {
        XF_GL_Op_Args_eglQueryContext *res = malloc(sizeof(XF_GL_Op_Args_eglQueryContext));
        res->__xf_op->opcode = XF_GL_OPCODE_eglQueryContext;
    res->dpy = dpy;
res->ctx = ctx;
res->attribute = attribute;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glFlush() {
        XF_GL_Op_Args_glFlush *res = malloc(sizeof(XF_GL_Op_Args_glFlush));
        res->__xf_op->opcode = XF_GL_OPCODE_glFlush;
    
        return res;
    }


    XF_GL_Op xf_pack_glDepthRangef(GLfloat n,  GLfloat f) {
        XF_GL_Op_Args_glDepthRangef *res = malloc(sizeof(XF_GL_Op_Args_glDepthRangef));
        res->__xf_op->opcode = XF_GL_OPCODE_glDepthRangef;
    res->n = n;
res->f = f;

        return res;
    }


    XF_GL_Op xf_pack_eglGetProcAddress(const char *procname) {
        XF_GL_Op_Args_eglGetProcAddress *res = malloc(sizeof(XF_GL_Op_Args_eglGetProcAddress));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetProcAddress;
    res->procname = procname;

        return res;
    }


    XF_GL_Op xf_pack_glIsFramebuffer(GLuint framebuffer) {
        XF_GL_Op_Args_glIsFramebuffer *res = malloc(sizeof(XF_GL_Op_Args_glIsFramebuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsFramebuffer;
    res->framebuffer = framebuffer;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib3fv(GLuint index,  const GLfloat *v) {
        XF_GL_Op_Args_glVertexAttrib3fv *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib3fv));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib3fv;
    res->index = index;
res->v = v;

        return res;
    }


    XF_GL_Op xf_pack_glBlendFunc(GLenum sfactor,  GLenum dfactor) {
        XF_GL_Op_Args_glBlendFunc *res = malloc(sizeof(XF_GL_Op_Args_glBlendFunc));
        res->__xf_op->opcode = XF_GL_OPCODE_glBlendFunc;
    res->sfactor = sfactor;
res->dfactor = dfactor;

        return res;
    }


    XF_GL_Op xf_pack_glGetAttachedShaders(GLuint program,  GLsizei maxCount,  GLsizei *count,  GLuint *shaders) {
        XF_GL_Op_Args_glGetAttachedShaders *res = malloc(sizeof(XF_GL_Op_Args_glGetAttachedShaders));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetAttachedShaders;
    res->program = program;
res->maxCount = maxCount;
res->count = count;
res->shaders = shaders;

        return res;
    }


    XF_GL_Op xf_pack_glBlendEquationSeparate(GLenum modeRGB,  GLenum modeAlpha) {
        XF_GL_Op_Args_glBlendEquationSeparate *res = malloc(sizeof(XF_GL_Op_Args_glBlendEquationSeparate));
        res->__xf_op->opcode = XF_GL_OPCODE_glBlendEquationSeparate;
    res->modeRGB = modeRGB;
res->modeAlpha = modeAlpha;

        return res;
    }


    XF_GL_Op xf_pack_glTexParameteriv(GLenum target,  GLenum pname,  const GLint *params) {
        XF_GL_Op_Args_glTexParameteriv *res = malloc(sizeof(XF_GL_Op_Args_glTexParameteriv));
        res->__xf_op->opcode = XF_GL_OPCODE_glTexParameteriv;
    res->target = target;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_eglSwapBuffers(EGLDisplay dpy,  EGLSurface surface) {
        XF_GL_Op_Args_eglSwapBuffers *res = malloc(sizeof(XF_GL_Op_Args_eglSwapBuffers));
        res->__xf_op->opcode = XF_GL_OPCODE_eglSwapBuffers;
    res->dpy = dpy;
res->surface = surface;

        return res;
    }


    XF_GL_Op xf_pack_eglCreateWindowSurface(EGLDisplay dpy,  EGLConfig config,  EGLNativeWindowType win,  const EGLint *attrib_list) {
        XF_GL_Op_Args_eglCreateWindowSurface *res = malloc(sizeof(XF_GL_Op_Args_eglCreateWindowSurface));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreateWindowSurface;
    res->dpy = dpy;
res->config = config;
res->win = win;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_glDisableVertexAttribArray(GLuint index) {
        XF_GL_Op_Args_glDisableVertexAttribArray *res = malloc(sizeof(XF_GL_Op_Args_glDisableVertexAttribArray));
        res->__xf_op->opcode = XF_GL_OPCODE_glDisableVertexAttribArray;
    res->index = index;

        return res;
    }


    XF_GL_Op xf_pack_glGetUniformiv(GLuint program,  GLint location,  GLint *params) {
        XF_GL_Op_Args_glGetUniformiv *res = malloc(sizeof(XF_GL_Op_Args_glGetUniformiv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetUniformiv;
    res->program = program;
res->location = location;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glBlendEquation(GLenum mode) {
        XF_GL_Op_Args_glBlendEquation *res = malloc(sizeof(XF_GL_Op_Args_glBlendEquation));
        res->__xf_op->opcode = XF_GL_OPCODE_glBlendEquation;
    res->mode = mode;

        return res;
    }


    XF_GL_Op xf_pack_glDisable(GLenum cap) {
        XF_GL_Op_Args_glDisable *res = malloc(sizeof(XF_GL_Op_Args_glDisable));
        res->__xf_op->opcode = XF_GL_OPCODE_glDisable;
    res->cap = cap;

        return res;
    }


    XF_GL_Op xf_pack_glGetTexParameterfv(GLenum target,  GLenum pname,  GLfloat *params) {
        XF_GL_Op_Args_glGetTexParameterfv *res = malloc(sizeof(XF_GL_Op_Args_glGetTexParameterfv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetTexParameterfv;
    res->target = target;
res->pname = pname;
res->params = params;

        return res;
    }


    XF_GL_Op xf_pack_glBufferSubData(GLenum target,  GLintptr offset,  GLsizeiptr size,  const void *data) {
        XF_GL_Op_Args_glBufferSubData *res = malloc(sizeof(XF_GL_Op_Args_glBufferSubData));
        res->__xf_op->opcode = XF_GL_OPCODE_glBufferSubData;
    res->target = target;
res->offset = offset;
res->size = size;
res->data = data;

        return res;
    }


    XF_GL_Op xf_pack_glDepthFunc(GLenum func) {
        XF_GL_Op_Args_glDepthFunc *res = malloc(sizeof(XF_GL_Op_Args_glDepthFunc));
        res->__xf_op->opcode = XF_GL_OPCODE_glDepthFunc;
    res->func = func;

        return res;
    }


    XF_GL_Op xf_pack_eglCreatePbufferFromClientBuffer(EGLDisplay dpy,  EGLenum buftype,  EGLClientBuffer buffer,  EGLConfig config,  const EGLint *attrib_list) {
        XF_GL_Op_Args_eglCreatePbufferFromClientBuffer *res = malloc(sizeof(XF_GL_Op_Args_eglCreatePbufferFromClientBuffer));
        res->__xf_op->opcode = XF_GL_OPCODE_eglCreatePbufferFromClientBuffer;
    res->dpy = dpy;
res->buftype = buftype;
res->buffer = buffer;
res->config = config;
res->attrib_list = attrib_list;

        return res;
    }


    XF_GL_Op xf_pack_glClearDepthf(GLfloat d) {
        XF_GL_Op_Args_glClearDepthf *res = malloc(sizeof(XF_GL_Op_Args_glClearDepthf));
        res->__xf_op->opcode = XF_GL_OPCODE_glClearDepthf;
    res->d = d;

        return res;
    }


    XF_GL_Op xf_pack_glGetString(GLenum name) {
        XF_GL_Op_Args_glGetString *res = malloc(sizeof(XF_GL_Op_Args_glGetString));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetString;
    res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_glColorMask(GLboolean red,  GLboolean green,  GLboolean blue,  GLboolean alpha) {
        XF_GL_Op_Args_glColorMask *res = malloc(sizeof(XF_GL_Op_Args_glColorMask));
        res->__xf_op->opcode = XF_GL_OPCODE_glColorMask;
    res->red = red;
res->green = green;
res->blue = blue;
res->alpha = alpha;

        return res;
    }


    XF_GL_Op xf_pack_eglQueryString(EGLDisplay dpy,  EGLint name) {
        XF_GL_Op_Args_eglQueryString *res = malloc(sizeof(XF_GL_Op_Args_eglQueryString));
        res->__xf_op->opcode = XF_GL_OPCODE_eglQueryString;
    res->dpy = dpy;
res->name = name;

        return res;
    }


    XF_GL_Op xf_pack_glIsShader(GLuint shader) {
        XF_GL_Op_Args_glIsShader *res = malloc(sizeof(XF_GL_Op_Args_glIsShader));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsShader;
    res->shader = shader;

        return res;
    }


    XF_GL_Op xf_pack_glGetIntegerv(GLenum pname,  GLint *data) {
        XF_GL_Op_Args_glGetIntegerv *res = malloc(sizeof(XF_GL_Op_Args_glGetIntegerv));
        res->__xf_op->opcode = XF_GL_OPCODE_glGetIntegerv;
    res->pname = pname;
res->data = data;

        return res;
    }


    XF_GL_Op xf_pack_eglGetDisplay(EGLNativeDisplayType display_id) {
        XF_GL_Op_Args_eglGetDisplay *res = malloc(sizeof(XF_GL_Op_Args_eglGetDisplay));
        res->__xf_op->opcode = XF_GL_OPCODE_eglGetDisplay;
    res->display_id = display_id;

        return res;
    }


    XF_GL_Op xf_pack_glCheckFramebufferStatus(GLenum target) {
        XF_GL_Op_Args_glCheckFramebufferStatus *res = malloc(sizeof(XF_GL_Op_Args_glCheckFramebufferStatus));
        res->__xf_op->opcode = XF_GL_OPCODE_glCheckFramebufferStatus;
    res->target = target;

        return res;
    }


    XF_GL_Op xf_pack_glStencilMask(GLuint mask) {
        XF_GL_Op_Args_glStencilMask *res = malloc(sizeof(XF_GL_Op_Args_glStencilMask));
        res->__xf_op->opcode = XF_GL_OPCODE_glStencilMask;
    res->mask = mask;

        return res;
    }


    XF_GL_Op xf_pack_glUniform4i(GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3) {
        XF_GL_Op_Args_glUniform4i *res = malloc(sizeof(XF_GL_Op_Args_glUniform4i));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform4i;
    res->location = location;
res->v0 = v0;
res->v1 = v1;
res->v2 = v2;
res->v3 = v3;

        return res;
    }


    XF_GL_Op xf_pack_glDrawArrays(GLenum mode,  GLint first,  GLsizei count) {
        XF_GL_Op_Args_glDrawArrays *res = malloc(sizeof(XF_GL_Op_Args_glDrawArrays));
        res->__xf_op->opcode = XF_GL_OPCODE_glDrawArrays;
    res->mode = mode;
res->first = first;
res->count = count;

        return res;
    }


    XF_GL_Op xf_pack_glUniform2iv(GLint location,  GLsizei count,  const GLint *value) {
        XF_GL_Op_Args_glUniform2iv *res = malloc(sizeof(XF_GL_Op_Args_glUniform2iv));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform2iv;
    res->location = location;
res->count = count;
res->value = value;

        return res;
    }


    XF_GL_Op xf_pack_glUniform2f(GLint location,  GLfloat v0,  GLfloat v1) {
        XF_GL_Op_Args_glUniform2f *res = malloc(sizeof(XF_GL_Op_Args_glUniform2f));
        res->__xf_op->opcode = XF_GL_OPCODE_glUniform2f;
    res->location = location;
res->v0 = v0;
res->v1 = v1;

        return res;
    }


    XF_GL_Op xf_pack_glVertexAttrib1f(GLuint index,  GLfloat x) {
        XF_GL_Op_Args_glVertexAttrib1f *res = malloc(sizeof(XF_GL_Op_Args_glVertexAttrib1f));
        res->__xf_op->opcode = XF_GL_OPCODE_glVertexAttrib1f;
    res->index = index;
res->x = x;

        return res;
    }


    XF_GL_Op xf_pack_glCreateProgram() {
        XF_GL_Op_Args_glCreateProgram *res = malloc(sizeof(XF_GL_Op_Args_glCreateProgram));
        res->__xf_op->opcode = XF_GL_OPCODE_glCreateProgram;
    
        return res;
    }


    XF_GL_Op xf_pack_eglChooseConfig(EGLDisplay dpy,  const EGLint *attrib_list,  EGLConfig *configs,  EGLint config_size,  EGLint *num_config) {
        XF_GL_Op_Args_eglChooseConfig *res = malloc(sizeof(XF_GL_Op_Args_eglChooseConfig));
        res->__xf_op->opcode = XF_GL_OPCODE_eglChooseConfig;
    res->dpy = dpy;
res->attrib_list = attrib_list;
res->configs = configs;
res->config_size = config_size;
res->num_config = num_config;

        return res;
    }


    XF_GL_Op xf_pack_glIsEnabled(GLenum cap) {
        XF_GL_Op_Args_glIsEnabled *res = malloc(sizeof(XF_GL_Op_Args_glIsEnabled));
        res->__xf_op->opcode = XF_GL_OPCODE_glIsEnabled;
    res->cap = cap;

        return res;
    }

