CFLGAS = -g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG

all:
	make build/liblcthw.so
	make tests/list_test

tests/list_test:	tests/list_tests.c build/liblcthw.a
	gcc $(CFLAGS) build/liblcthw.a tests/list_tests.c -o tests/list_tests

build/liblcthw.so:	src/lcthw/list.o
	gcc -shared -o build/liblcthw.so src/lcthw/list.o

build/liblcthw.a:	src/lcthw/list.o
	ar rcs build/liblcthw.a src/lcthw/list.o
	ranlib build/liblcthw.a

src/lcthw/list.o:	src/lcthw/list.c
	gcc $(CFLAGS) -fPIC -c src/lcthw/list.c -o src/lcthw/list.o

clean:
	rm -f build/* tests/list_tests
