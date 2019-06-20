#include "XFWindow.h"

XF_Event *xf_translate_nsevent(NSEvent *inp) {
    if (!inp) return 0;

    XF_Event_Type eventType;
    XF_Event_Mouse_Subtype mouseSubtype;
    XF_Event_Key_Subtype keySubtype;
    XF_Event_Gesture_Subtype gestureSubtype;
    NSPoint loc = inp.locationInWindow;
    int windowNumber = inp.windowNumber;
    int nClicks = inp.clickCount;
    uint16_t keycode = inp.keyCode;
    double magnitude = (gestureSubtype == MAGNIFY) ? inp.magnification : 0.0;
    switch(inp.type) {

        /* mouse events */
        case NSEventTypeLeftMouseDown:
            eventType = MOUSE;
            mouseSubtype = MOUSE_DOWN;
            break;
        case NSEventTypeLeftMouseUp:
            eventType = MOUSE;
            mouseSubtype = MOUSE_UP;
            break;
        case NSEventTypeRightMouseDown:
            eventType = MOUSE;
            mouseSubtype = RIGHT_MOUSE_DOWN;
            break;
        case NSEventTypeRightMouseUp:
            eventType = MOUSE;
            mouseSubtype = RIGHT_MOUSE_UP;
            break;
        case NSEventTypeMouseMoved:
            eventType = MOUSE;
            mouseSubtype = MOUSE_MOVED;
            break;
        case NSEventTypeMouseEntered:
            eventType = MOUSE;
            mouseSubtype = MOUSE_ENTERED;
            break;
        case NSEventTypeScrollWheel:
            return (XF_Event *) xf_make_event_scroll(inp.deltaX, inp.deltaY, inp.deltaZ, loc.x, loc.y);
        case NSEventTypeMouseExited:
            eventType = MOUSE;
            mouseSubtype = MOUSE_EXITED;
            break;


        /* key events */
        case NSEventTypeKeyDown:
            eventType = KEY;
            keySubtype = KEY_DOWN;
            break;
        case NSEventTypeKeyUp:
            eventType = KEY;
            keySubtype = KEY_UP;
            break;

        /* gesture events */
        case NSEventTypeMagnify:
            eventType = GESTURE;
            gestureSubtype = MAGNIFY;
            break;
        case NSEventTypeSwipe:
            eventType = GESTURE;
            gestureSubtype = SWIPE;
            break;
        case NSEventTypeRotate:
            eventType = GESTURE;
            gestureSubtype = ROTATE;
            break;
        case NSEventTypeSmartMagnify:
            eventType = GESTURE;
            gestureSubtype = SMART_MAGNIFY;
            break;

        default:
            [NSApp sendEvent:inp];
            return &XF_EVENT_UNK;
    }
    switch(eventType) {
        case MOUSE:
            return (XF_Event *) xf_make_event_mouse(mouseSubtype, windowNumber, loc.x, loc.y, nClicks);
        case KEY:
            return (XF_Event *) xf_make_event_keyboard(keySubtype, keycode);
        case GESTURE:
            return (XF_Event *) xf_make_event_gesture(gestureSubtype, loc.x, loc.y, magnitude);

        default:
            return &XF_EVENT_UNK;
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
    NSRect frame = [win frame];
    return xf_make_event_window(type, 
        NSMinX(frame), NSMinY(frame),
        NSWidth(frame), NSHeight(frame));
}

@interface XFApplication : NSApplication

@end

@implementation XFApplication 
-(void)sendEvent:(NSEvent *)nsEvt 
{
    xf_push_event(xf_translate_nsevent(nsEvt));
}
@end

@implementation XFWindowDelegate 
-(id)initWithWindow:(NSWindow *)window 
{
    self = [super init];
    if (self != nil) {
        mWindow = window;
    }
    return self;
}


-(BOOL)windowShouldClose:(id)sender
{
    xf_push_event(xf_make_event_app(CLOSING));
    return NO;
}

-(void)windowDidResize:(NSNotification *)notification 
{
    xf_push_event(xf_window_event_from_nswindow(mWindow, RESIZE));
}

-(void)windowDidMove:(NSNotification *)notification
{
    xf_push_event(xf_window_event_from_nswindow(mWindow, MOVE));
}

-(void)windowDidBecomeKey:(NSNotification *)notification
{
    xf_push_event(xf_make_event_app(FOCUS));
}

-(void)windowDidResignKey:(NSNotification *)notification
{
    xf_push_event(xf_make_event_app(BLUR));
}

@end

@implementation XFContentView 

-(id)initWithWindow:(NSWindow *)window 
{
    if (window != nil) {
        mWindow = window;
    }
    return self;
}

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

@implementation XFApplicationDelegate 


- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender
{
    xf_push_event(xf_make_event_app(CLOSING));
    return NSTerminateNow;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}

- (void)applicationDidHide:(NSNotification *)notification
{
    xf_push_event(xf_make_event_app(HIDE));
}

- (void)applicationWillUnhide:(NSNotification *)notification 
{
    xf_push_event(xf_make_event_app(UNHIDE));
}

@end

static bool xf_init_appkit() {
    if (NSApp != nil)
    {
        return true;
    }

    // Initialize the global variable "NSApp"
    [NSApplication sharedApplication];

    // Make us appear in the dock
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

    // Register our global event handler
    XFApplicationDelegate *gApplicationDelegate = [[XFApplicationDelegate alloc] init];
    if (gApplicationDelegate == nil)
    {
        return false;
    }
    [NSApp setDelegate:static_cast<id>(gApplicationDelegate)];



    // Set our status to "started" so we are not bouncing in the doc and can activate
    [NSApp finishLaunching];
    return true;
}

static EGLNativeWindowType xf_init_window(char *name, size_t width, size_t height) {
    
    unsigned int styleMask = NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask |
                             NSMiniaturizableWindowMask;
    NSWindow *mWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, width, height)
                                          styleMask:styleMask
                                            backing:NSBackingStoreBuffered
                                              defer:NO];

    if (mWindow == nil)
    {
        return 0;
    }

    XFWindowDelegate *mDelegate = [[XFWindowDelegate alloc] initWithWindow:mWindow];
    if (mDelegate == nil)
    {
        return 0;
    }
    [mWindow setDelegate:static_cast<id>(mDelegate)];

    XFContentView *mView = [[XFContentView alloc] initWithWindow:mWindow];
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


CVReturn xf_cvdisplay_poller(
    CVDisplayLinkRef displayLink, const CVTimeStamp *inNow, const CVTimeStamp *inOutputTime,
    CVOptionFlags flagsIn, CVOptionFlags *flagsOut, void *displayLinkContext) {
        double scale_factor = (inOutputTime->videoTimeScale) / 1000000;
        frame_prev_time = frame_time;
        frame_time = inOutputTime->hostTime * scale_factor;
        pthread_cond_broadcast(&frame_cond);
        return kCVReturnSuccess;
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

EGLNativeWindowType xf_init_app(
    char *name, size_t width, size_t height) {
    if (!xf_init_appkit()) return 0;
    pthread_cond_init(&frame_cond, 0);
    frame_time = 0;
    frame_prev_time = 0;
    CVDisplayLinkRef displayRef;
    CVDisplayLinkCreateWithActiveCGDisplays(&displayRef);
    CVDisplayLinkSetOutputCallback(displayRef, xf_cvdisplay_poller, 0);
    return xf_init_window(name, width, height);
}

