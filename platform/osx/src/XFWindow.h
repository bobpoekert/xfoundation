
#pragma once

#import <Cocoa/Cocoa.h>
#import <CoreVideo/CVDisplayLink.h>
#include <EGL/egl.h>
#include <pthread.h>
#include <xf_event.h>
#include <xf_window.h>


class XFWindow;

@interface XFWindowDelegate : NSObject {
    XFWindow *mWindow;
}
-(id)initWithWindow:(XFWindow *)window;
@end 

@interface ContentView : NSView {
    XFoundationWindow *mWindow;
    NSTrackingArea *mTrackingArea;
    int mCurrentModifier;
}
-(id)initWithWindow:(XFWindow *)window; 
@end 
