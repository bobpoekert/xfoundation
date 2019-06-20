#include <xf_event.h>


XF_Event_Mouse *xf_make_event_mouse(
    XF_Event_Mouse_Subtype type,
    int window_number,
    double x, double y,
    int n_clicks) {

    XF_Event_Mouse *res = malloc(sizeof(XF_Event_Mouse));
    if (!res) return 0;
    res->event.type = MOUSE;
    res->window_number = window_number;
    res->x = x;
    res->y = y;
    res->n_clicks = n_clicks;

    return res;

}

XF_Event_Window *xf_make_event_window(
    XF_Event_Window_Subtype type, double top_left_x, double top_left_y, double width, double height) {

    XF_Event_Window *res = malloc(sizeof(XF_Event_Window));
    if (!res) return 0;

    res->event.type = WINDOW;
    res->type = type;
    res->top_left_x = top_left_x;
    res->top_left_y = top_left_y;
    res->width = width;
    res->height = height;

    return res;

}


XF_Event_Key *xf_make_event_keyboard(XF_Event_Key_Subtype subtype, uint16_t keycode) {
    XF_Event_Key *res = malloc(sizeof(XF_Event_Key));
    if (!res) return 0;
    res->event.type = KEY;
    res->type = subtype;
    res->keycode = keycode;
    return res;
}

XF_Event_Scroll *xf_make_event_scroll(double x, double y, double dx, double dy, double dz) {
    XF_Event_Scroll *res = malloc(sizeof(XF_Event_Scroll));
    if (!res) return 0;
    res->event.type = SCROLL;
    res->x = x;
    res->y = y;
    res->dx = dx;
    res->dy = dy;
    res->dz = dz;
    return res;
}

XF_Event_Gesture *xf_make_event_gesture(XF_Event_Gesture_Subtype type, double x, double y, double magnitude) {
    XF_Event_Gesture *res = malloc(sizeof(XF_Event_Gesture));
    if (!res) return 0;
    res->event.type = GESTURE;
    res->x = x;
    res->y = y;
    res->magnitude = magnitude;
    return res;
}

XF_Event_App *xf_make_event_app(XF_Event_App_Subtype type) {
    XF_Event_App *res = malloc(sizeof(XF_Event_App));
    res->event.type = APP;
    res->type = type;
    return res;
}

void xf_event_init() {
    xf_global_event_queue = xf_buffer_queue_create(sizeof(XF_Event *), 1024, 256);
}

XF_Event *pop_event() {
    XF_Event *res;
    xf_buffer_queue_take(xf_global_event_queue, &res);
    return res;
}