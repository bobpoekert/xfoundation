
MAC_SDK := "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
TARGET_ARCH := "x86_64"

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

obj/xfoundation.o:
	clang -arch $(TARGET_ARCH) -isysroot $(MAC_SDK) -F AppKit -I$(current_dir)/include -I$(current_dir)/../generic/include $(current_dir)/src/xfoundation.m -o $(current_dir)/obj/xfoundation.o
