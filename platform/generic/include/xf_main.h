#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/threads.h>
#include <caml/callback.h>

#include <xf_event.h>
#include <xf_window.h>
#include <xf_bufferqueue.h>

int xf_main(int argc, char **argv);