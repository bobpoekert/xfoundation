#include <xf_main.h>

#include <caml/mlvalues.h>

int main(int argc, char **argv) {

    char **caml_argv = malloc(sizeof(char *) * (argc + 1));
    memcpy(caml_argv, argv, sizeof(char *) * argc);
    caml_argv[argc] = 0;

    caml_main(caml_argv);

    return xf_main(argc, argv);
}