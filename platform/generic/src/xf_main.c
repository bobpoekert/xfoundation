#include <xf_main.h>

void process_events() {
    XF_Event *evt;
    while ((evt = xf_poll_event())) {
        xf_push_event(evt);
    }
}

void mainloop() {
    value *caml_eventloop_iter = caml_named_value("eventloop iter");
    while(1) {
        caml_release_runtime_system();
        long frame_interval = xf_wait_for_frame();
        process_events();
        caml_acquire_runtime_system();
        caml_callback(*caml_eventloop_iter, Val_long(frame_interval));
    }
}

int xf_main(int argc, char **argv) {
    pthread_t ocaml_thread;
    xf_event_init();

    char **caml_argv = malloc(sizeof(char *) * (argc + 1));
    memcpy(caml_argv, argv, sizeof(char *) * argc);
    caml_argv[argc] = 0;

    EGLNativeWindowType window = xf_init_app(argv[0], 1024, 768);
    xf_egl_init(window);
    caml_main(caml_argv);
    mainloop();
    return 0;
}



