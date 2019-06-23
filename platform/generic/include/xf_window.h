#pragma once

#include <stdint.h>
#include <xf_event.h>
#include <EGL/egl.h>

extern XF_Event *xf_poll_event();
extern EGLNativeWindowType xf_init_app(char *name, size_t width, size_t height);
extern long xf_wait_for_frame(); /* returns the interval in microseconds from the previous frame */