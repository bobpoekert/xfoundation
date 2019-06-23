#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/threads.h>
#include <caml/callback.h>

#include <xf_event.h>
#include <xf_window.h>
#include <xf_bufferqueue.h>

void xf_main(char *name, int window_width, int window_height);