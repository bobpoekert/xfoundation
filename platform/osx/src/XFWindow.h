
#pragma once

#import <Cocoa/Cocoa.h>
#import <CoreVideo/CVDisplayLink.h>
#include <EGL/egl.h>
#include <pthread.h>
#include <xf_event.h>
#include <xf_window.h>


@interface XFWindowDelegate : NSObject {
    NSWindow *mWindow;
}
-(id)initWithWindow:(NSWindow *)window;
@end 

@interface XFContentView : NSView {
    NSWindow *mWindow;
    NSTrackingArea *mTrackingArea;
    int mCurrentModifier;
}
-(id)initWithWindow:(NSWindow *)window; 
@end 

@interface XFApplicationDelegate : NSObject <NSApplicationDelegate> {
}
@end