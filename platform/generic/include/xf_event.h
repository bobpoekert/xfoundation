#pragma once

#include <stdint.h>
#include <stdlib.h>

#include <xf_bufferqueue.h>

typedef enum {

    MOUSE,
    SCROLL,
    TOUCH,
    KEY,
    GESTURE,
    WINDOW, /* move, resize, etc */
    APP, /* closing, backgrounded, etc */
    UNK /* unknown or invalid */

} XF_Event_Type;

typedef struct XF_Event {
    XF_Event_Type type;
} XF_Event;

static XF_Event XF_EVENT_UNK = {UNK};

typedef enum {
    MOUSE_DOWN,
    MOUSE_DRAGGED,
    MOUSE_UP,
    MOUSE_MOVED,
    MOUSE_ENTERED,
    MOUSE_EXITED,
    RIGHT_MOUSE_DOWN,
    RIGHT_MOUSE_DRAGGED,
    RIGHT_MOUSE_UP,
    OTHER_MOUSE_DOWN,
    OTHER_MOUSE_DRAGGED,
    OTHER_MOUSE_UP
} XF_Event_Mouse_Subtype;

typedef struct XF_Event_Mouse {
    XF_Event event;
    XF_Event_Mouse_Subtype type;
    int window_number;
    double x;
    double y;
    int n_clicks;
} XF_Event_Mouse;

#define XF_MAX_KEY_CHARACTERS 1024

typedef enum {

    KEY_DOWN,
    KEY_UP

} XF_Event_Key_Subtype;

typedef struct XF_Event_Key {
    XF_Event event;
    XF_Event_Key_Subtype type;
    uint16_t keycode;
} XF_Event_Key;


typedef struct XF_Event_Scroll {
    XF_Event event;
    double x;
    double y;
    double dx;
    double dy;
    double dz;
} XF_Event_Scroll;

typedef enum {

    MAGNIFY,
    SWIPE,
    ROTATE,
    SMART_MAGNIFY

} XF_Event_Gesture_Subtype;

typedef struct XF_Event_Gesture {
    XF_Event event;
    XF_Event_Gesture_Subtype type;
    double x;
    double y;
    double magnitude;
} XF_Event_Gesture;

typedef enum {

    MOVE,
    RESIZE,
    MINIMIZE,
    MAXIMIZE

} XF_Event_Window_Subtype;


typedef struct XF_Event_Window {

    XF_Event event;
    XF_Event_Window_Subtype type;
    double top_left_x;
    double top_left_y;
    double width;
    double height;


} XF_Event_Window;

typedef enum {
    CLOSING,
    FOCUS,
    BLUR,
    HIDE,
    UNHIDE
} XF_Event_App_Subtype;

typedef struct XF_Event_App {
    XF_Event event;
    XF_Event_App_Subtype type;
} XF_Event_App;

extern XF_Buffer_Queue *xf_global_event_queue;

#define xf_push_event(evt) xf_buffer_queue_append(xf_global_event_queue, evt)

void xf_event_init();
XF_Event *xf_pop_event();


XF_Event_Key *xf_make_event_keyboard(XF_Event_Key_Subtype subtype, uint16_t keycode);
XF_Event_Scroll *xf_make_event_scroll(double x, double y, double dx, double dy, double dz);
XF_Event_Gesture *xf_make_event_gesture(XF_Event_Gesture_Subtype type, double x, double y, double magnitude);
XF_Event_Mouse *xf_make_event_mouse(
    XF_Event_Mouse_Subtype type,
    int window_number,
    double x, double y,
    int n_clicks);
XF_Event_Window *xf_make_event_window(
    XF_Event_Window_Subtype type, double top_left_x, double top_left_y, double width, double height);
XF_Event_App *xf_make_event_app(XF_Event_App_Subtype type);