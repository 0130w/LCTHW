CFLAGS = -Wall -g -DNDEBUG

ex22_main:	ex22_main.c ex22.o
	gcc $(CFLAGS) ex22_main.c ex22.o -o ex22_main

ex22.o:	ex22.c
	gcc $(CFLAGS) -c ex22.c -o ex22.o

clean:
	rm -f ex22.o ex22_main
