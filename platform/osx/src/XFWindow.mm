#include "XFWindow.h"

XF_Event *xf_translate_nsevent(NSEvent *inp) {
    if (!inp) return 0;

    XF_Event_Type eventType;
    XF_Event_Mouse_Subtype mouseSubtype;
    XF_Event_Key_Subtype keySubtype;
    XF_Event_Gesture_Subtype gestureSubtype;
    switch([inp type]) {

        /* mouse events */
        case NSEvent.EventType.leftMouseDown:
            eventType = MOUSE;
            mouseSubtype = MOUSE_DOWN;
            break;
        case NSEvent.EventType.leftMouseUp:
            eventType = MOUSE;
            mouseSubtype = MOUSE_UP;
            break;
        case NSEvent.EventType.rightMouseDown:
            eventType = MOUSE;
            mouseSubtype = RIGHT_MOUSE_DOWN;
            break;
        case NSEvent.EventType.rightMouseUp:
            eventType = MOUSE;
            mouseSubtype = RIGHT_MOUSE_UP;
            break;
        case NSEvent.EventType.mouseMoved:
            eventType = MOUSE;
            mouseSubtype = MOUSE_MOVED;
            break;
        case NSEvent.EventType.mouseEntered:
            eventType = MOUSE;
            mouseSubtype = MOUSE_ENTERED;
            break;
        case NSEvent.EventType.scrollWheel:
            NSPoint loc = inp.locationInWindow;
            return xf_make_event_scroll(inp.deltaX, inp.deltaY, inp.deltaZ, loc.x, loc.y);
        case NSEvent.EventType.mouseExited:
            eventType = MOUSE;
            mouseSubtype = MOUSE_EXITED;
            break;


        /* key events */
        case NSEvent.EventType.keyDown:
            eventType = KEY;
            keySubtype = KEY_DOWN;
            break;
        case NSEvent.EventType.keyUP:
            eventType = KEY;
            keySubtype = KEY_UP;
            break;

        /* gesture events */
        case NSEvent.EventType.magnify:
            eventType = GESTURE;
            gestureSubtype = MAGNIFY;
            break
        case NSEvent.EventType.swipe:
            eventType = GESTURE;
            gestureSubtype = SWIPE;
            break;
        case NSEvent.EventType.rotate:
            eventType = GESTURE;
            gestureSubtype = ROTATE;
            break;
        case NSEvent.EventType.smartMagnify:
            eventType = GESTURE;
            gestureSubtype = SMART_MAGNIFY;
            break;

        default:
            [NSApp sendEvent:inp];
            return XF_EVENT_UNK;
    }
    switch(eventType) {
        case MOUSE:
            NSPoint loc = inp.locationInWindow;
            int windowNumber = inp.windowNumber;
            int nClicks = inp.clickCount;
            return xf_make_event_mouse(mouseSubtype, windowNumber, loc.x, loc.y, n_clicks);
        case KEY:
            uint16_t keycode = inp.keyCode;
            return xf_make_event_keyboard(keySubtype, keycode);
        case GESTURE:
            NSPoint loc = inp.locationInWindow;
            double magnitude = (gestureSubtype == MAGNIFY) ? inp.magnification : 0.0;
            return xf_make_event_gesture(gestureSubtype, loc.x, loc.y, magnitude);

        default:
            return XF_EVENT_UNK;
    }
}

XF_Event *xf_poll_event() {
    NSEvent *event = [NSApp nextEventMatchingMask:NSEventMaskAny
                        untilDate:nil
                        inMode:NSDefaultRunLoopMode
                        dequeue:YES];
    if (event == nil) return nil;
    [NSApp sendEvent:event];
    return xf_translate_nsevent(event);
}

XF_Event_Window *xf_window_event_from_nswindow(NSWindow *win, XF_Event_Window_Subtype type) {
    XF_Event_Window *res = xf_event_window_alloc();
    NSRect frame = [frame win];
    res->type = type;
    res->top_left_x = frame.origin.x;
    res->top_left_y = frame.origin.y;
    res->width = [NSWidth frame];
    res->height = [NSHeight frame];
    return res;
}

@interface XFApplication : NSApplication

@end

@implementation XFApplication 
-(void)sendEvent(NSEvent *)nsEvt 
{
    xf_push_event(xf_translate_nsevent(nsEvt));
}
@end

@implementation XFWindowDelegate 
-(id)initWithWindow:(XFWindow *)window 
{
    self = [super init]
    if (self != nil) {
        mWindow = window;
    }
    return self;
}


-(BOOL)windowShouldClose:(id)sender
{
    xf_push_event(xf_window_event_from_nswindow(window, CLOSING));
    return NO;
}

-(void)windowDidResize:(NSNotification *)notification 
{
    xf_push_event(xf_window_event_from_nswindow(window, RESIZE));
}

-(void)windowDidMove:(NSNotification *)notification
{
    xf_push_event(xf_window_event_from_nswindow(window, MOVE));
}

-(void)windowDidBecomeKey:(NSNotification *)notification
{
    xf_push_event(xf_window_event_from_nswindow(window, FOCUS));
}

-(void)windowDidResignKey:(NSNotification *)notification
{
    xf_push_event(xf_window_event_from_nswindow(window, BLUR));
}

@end

@implementation ContentView 

// Helps with performance
- (BOOL)isOpaque
{
    return YES;
}

- (BOOL)canBecomeKeyView
{
    return YES;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (void)updateTrackingAreas
{
    if (mTrackingArea != nil)
    {
        [self removeTrackingArea:mTrackingArea];
        [mTrackingArea release];
        mTrackingArea = nil;
    }

    NSRect bounds               = [self bounds];
    NSTrackingAreaOptions flags = NSTrackingMouseEnteredAndExited | NSTrackingActiveInKeyWindow |
                                  NSTrackingCursorUpdate | NSTrackingInVisibleRect |
                                  NSTrackingAssumeInside;
    mTrackingArea = [[NSTrackingArea alloc] initWithRect:bounds
                                                 options:flags
                                                   owner:self
                                                userInfo:nil];

    [self addTrackingArea:mTrackingArea];
    [super updateTrackingAreas];
}
@end

static bool xf_init_appkit() {
    if (NSApp != nil)
    {
        return true;
    }

    // Initialize the global variable "NSApp"
    [Application sharedApplication];

    // Make us appear in the dock
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

    // Register our global event handler
    gApplicationDelegate = [[ApplicationDelegate alloc] init];
    if (gApplicationDelegate == nil)
    {
        return false;
    }
    [NSApp setDelegate:static_cast<id>(gApplicationDelegate)];



    // Set our status to "started" so we are not bouncing in the doc and can activate
    [NSApp finishLaunching];
    return true;
}

static EGLNativeWindowType xf_init_window(char *name, size_t width, size_t height, 
    XF_FrameCallback callback) {
    
    unsigned int styleMask = NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask |
                             NSMiniaturizableWindowMask;
    NSWindow mWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, width, height)
                                          styleMask:styleMask
                                            backing:NSBackingStoreBuffered
                                              defer:NO];

    if (mWindow == nil)
    {
        return 0;
    }

    mDelegate = [[WindowDelegate alloc] initWithWindow:this];
    if (mDelegate == nil)
    {
        return 0;
    }
    [mWindow setDelegate:static_cast<id>(mDelegate)];

    ContentView mView = [[ContentView alloc] initWithWindow:mWindow];
    if (mView == nil)
    {
        return 0;
    }
    [mView setWantsLayer:YES];

    [mWindow setContentView:mView];
    [mWindow setTitle:[NSString stringWithUTF8String:name]];
    [mWindow setAcceptsMouseMovedEvents:YES];
    [mWindow center];

    [NSApp activateIgnoringOtherApps:YES];

    return [mView layer];
}

pthread_cond_t frame_cond;
long frame_prev_time;
long frame_time;


CVReturn *xf_cvdisplay_poller(
    CVDisplayLinkRef displayLink, const CVTimeStamp *inNow, const CVTimeStamp *inOutputTime,
    CVOptionFlags flagsIn, CVOptionFlags *flagsOut, void *displayLinkContext) {
        double scale_factor = (inOutputTime->videoTimeScale) / 1000000;
        frame_prev_time = frame_time;
        frame_time = inOutputTime->hostTime * scale_factor;
        pthread_cond_broadcast(&frame_cond);
}

long xf_wait_for_frame() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, 0);
    pthread_cond_wait(&frame_cond, &mutex);
    pthread_mutex_destroy(&mutex);
    if (frame_prev_time == 0) {
        return 0;
    } else {
        return (frame_time - frame_prev_time);
    }
}

static EGLNativeWindowType xf_init_app(
    char *name, size_t width, size_t height) {
    if (!xf_init_appkit()) return 0;
    pthread_cond_init(&frame_cond);
    frame_time = 0;
    frame_prev_time = 0;
    CVDisplayLinkRef displayRef;
    CVDisplayLinkCreateWithActiveCGDisplays(&displayRef);
    CVDisplayLinkGetCurrentCGDisplay(displayRef);
    CVDisplayLinkSetOutputCallback(displayRef, xf_cvdisplay_poller, 0);
    return xf_init_window(name, width, height);
}

