
MAC_SDK := "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
TARGET_ARCH := "x86_64"

../generic/lib/xf_platform.a:
	cd ../generic; make lib/xf_platform.a

../generic/lib/xf_platform_pic.a:
	cd ../generic; make lib/xf_platform_pic.a

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

lib/XFWindow_pic.o: ../generic/lib/xf_platform_pic.a
	clang -c \
		-fPIC \
		-arch $(TARGET_ARCH) \
		-isysroot $(MAC_SDK) \
		-F AppKit \
		-I../generic/include\
		-I./include\
		-ObjC++\
		./src/XFWindow.mm\
		-o ./lib/XFWindow_pic.o

lib/libxf_platform_stubs.a: lib/XFWindow.o ../generic/lib/xf_platform.a
	ar -cvq lib/libxf_platform_stubs.a  \
		lib/XFWindow.o \
		../generic/lib/xf_main.o ../generic/lib/xf_event.o ../generic/lib/xf_bufferqueue.o \

lib/libxf_platform_stubs_pic.a: lib/XFWindow_pic.o ../generic/lib/xf_platform_pic.a
	ar -cvq lib/libxf_platform_stubs_pic.a  \
		../generic/lib/xf_event_pic.o \
		../generic/lib/xf_main_pic.o \
		lib/XFWindow_pic.o \
		../generic/lib/xf_bufferqueue_pic.o

lib/dllxf_platform_stubs.so: lib/libxf_platform_stubs_pic.a
	clang -shared \
		-v\
		-lSystem \
		-Wl,-force_load,lib/libxf_platform_stubs_pic.a \
		-L`ocamlopt -where` -lasmrun -lunix \
		-framework Foundation \
		-framework AppKit \
		-framework CoreVideo \
		-o lib/dllxf_platform_stubs.so \

test: lib/libxf_platform_stubs.a
	clang \
		-v\
		-I`ocamlopt -where`\
		-I../generic/include\
		-framework Foundation \
		-framework AppKit \
		lib/libxf_platform_stubs.a \
		src/test.c\
		-o test
	./test