#include <xf_main.h>

void process_events() {
    xf_event_swap_buffers();
    XF_Event *evt;
    while ((evt = xf_poll_event())) {
        xf_push_event(evt);
    }
}

void mainloop() {
    value caml_eventloop_iter = *caml_named_value("eventloop iter");
    while(1) {
        caml_release_runtime_system();
        long frame_interval = xf_wait_for_frame();
        process_events();
        caml_acquire_runtime_system();
        caml_callback(caml_eventloop_iter, Val_long(frame_interval));
    }
}

void xf_main(char *name, int window_width, int window_height) {

    xf_event_init();

    EGLNativeWindowType window = xf_init_app(name, window_width, window_height);
    mainloop();
}



