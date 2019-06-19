#!/bin/sh

MAC_SDK = "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
TARGET_ARCH = "x86_64"

APP_NAME = $1
APP_OBJ_DIR = $2

WORKDIR = `pwd`

clang -arch $TARGET_ARCH -isysroot $MAC_SDK -F AppKit -L$WORKDIR/obj -lANGLE -lEGL_static -lGLESv2_static -L`ocamlopt -where` -lunix -lasmrun -lxfoundation -L$APP_OBJ_DIR -l$APP_NAME -o $APP_NAME


