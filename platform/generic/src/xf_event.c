#include <xf_event.h>


XF_Event_Mouse *xf_make_event_mouse(
    XF_Event_Mouse_Sybtype type,
    int window_number,
    double x, double y,
    int n_clicks) {

    XF_Event_Mouse *res = malloc(sizeof(XF_Event_Mouse));
    if (!res) return 0;
    res->event->type = MOUSE;
    res->window_number = window_number;
    res->x = x;
    rex->y = y;
    res->n_clicks = n_clicks;

    return res;

}


XF_Event_Key *xf_make_event_keyboard(XF_Event_Key_Subtype subtype, uint16_t keycode) {
    XF_Event_Keyboard *res = malloc(sizeof(XF_Event_Key));
    if (!res) return 0;
    res->event->type = KEY;
    res->type = subtype;
    res->keycode = keycode;
    return res;
}

XF_Event_Scroll *xf_make_event_scroll(double x, double y, double dx, double dy, double dz) {
    XF_Event_Scroll *res = malloc(sizeof(XF_Event_Scroll));
    if (!res) return 0;
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
    res->x = x;
    res->y = y;
    res->magnitude = magnitude;
    return res;
}


void xf_event_init() {
    xf_global_event_queue = new EventQueue();
}

XF_Event *pop_event() {
    return xf_global_event_queue->dequeue();
}