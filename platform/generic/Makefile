
CFLAGS := -g -I./include

lib/xf_bufferqueue.o:
	gcc -c $(CFLAGS) -o lib/xf_bufferqueue.o src/xf_bufferqueue.c

lib/xf_event.o:
	gcc -c $(CFLAGS) src/xf_event.c -o lib/xf_event.o

lib/xf_main.o:
	gcc -c $(CFLAGS) -I`ocamlopt -where` src/xf_main.c -o lib/xf_main.o

lib/xf_platform.a: lib/xf_event.o lib/xf_main.o lib/xf_bufferqueue.o 
	ar -cvq lib/xf_platform.a lib/xf_bufferqueue.o lib/xf_main.o lib/xf_event.o