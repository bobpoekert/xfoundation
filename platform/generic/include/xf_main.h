#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/threads.h>

#include <readerwriterqueue.h>

#include <xf_event.h>
#include <xf_command.h>
#include <xf_window.h>

int xf_main(int argc, char **argv);