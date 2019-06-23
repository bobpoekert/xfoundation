
CFLAGS := -g -I./include

lib/xf_bufferqueue.o:
	gcc -c $(CFLAGS) -o lib/xf_bufferqueue.o src/xf_bufferqueue.c

lib/xf_bufferqueue_pic.o:
	gcc -fPIC -c $(CFLAGS) -o lib/xf_bufferqueue_pic.o src/xf_bufferqueue.c

lib/xf_event.o:
	gcc -c $(CFLAGS) src/xf_event.c -o lib/xf_event.o

lib/xf_event_pic.o:
	gcc -fPIC -c $(CFLAGS) src/xf_event.c -o lib/xf_event_pic.o

lib/xf_main.o:
	gcc -c $(CFLAGS) -I`ocamlopt -where` src/xf_main.c -o lib/xf_main.o

lib/xf_main_pic.o:
	gcc -fPIC -c $(CFLAGS) -I`ocamlopt -where` src/xf_main.c -o lib/xf_main_pic.o

lib/xf_platform.a lib/xf_platform_pic.a: lib/xf_event.o lib/xf_main.o lib/xf_bufferqueue.o 
	ar -cvq lib/xf_platform.a `ocamlopt -where`/libasmrun.a lib/xf_main.o lib/xf_event.o lib/xf_bufferqueue.o

lib/xf_platform_pic.a: lib/xf_event_pic.o lib/xf_main_pic.o lib/xf_bufferqueue_pic.o 
	ar -cvq lib/xf_platform_pic.a `ocamlopt -where`/libasmrun_pic.a lib/xf_main_pic.o lib/xf_event_pic.o lib/xf_bufferqueue_pic.o