
MAC_SDK := "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
TARGET_ARCH := "x86_64"

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

../generic/lib/xf_platform.a:
	cd ../generic; make lib/xf_platform.a

lib/XFWindow.o: ../generic/lib/xf_platform.a
	clang -c \
		-arch $(TARGET_ARCH) \
		-isysroot $(MAC_SDK) \
		-F AppKit \
		-I../generic/include\
		-I./include\
		-ObjC++\
		./src/XFWindow.mm\
		-o ./lib/XFWindow.o

lib/xf_platform.a: lib/XFWindow.o ../generic/lib/xf_platform.a 
	ar -cvq lib/xf_platform.a lib/XFWindow.o ../generic/lib/*.o ./lib/*/*.o