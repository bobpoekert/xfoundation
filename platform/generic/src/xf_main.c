#include <xf_main.h>

void process_events() {
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

int xf_main(int argc, char **argv) {
    xf_event_init();

    char **caml_argv = malloc(sizeof(char *) * (argc + 1));
    memcpy(caml_argv, argv, sizeof(char *) * argc);
    caml_argv[argc] = 0;

    caml_main(caml_argv);

    value get_init_info = *caml_named_value("app init info");
    value info = caml_callback(get_init_info, caml_copy_string(argv[0]));

    char *name;
    int width;
    int height;

    if (Tag_val(info) != 0 || Wosize_val(info) != 3) {
        /* not a tuple or wrong length */
        name = "XFoundation App";
        width = 1024;
        height = 768;
    } else {
        name = String_val(Field(info, 0));
        width = Long_val(Field(info, 1));
        height = Long_val(Field(info, 2));
    }
    
    EGLNativeWindowType window = xf_init_app(name, width, height);
    mainloop();
    return 0;
}



