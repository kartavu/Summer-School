all: clean libcalc.so main

libcalc.so: add.o div.o sub.o mul.o
	gcc -shared -o libcalc.so add.o div.o sub.o mul.o

add.o: add.c
	gcc -fPIC -c add.c -o add.o

div.o: div.c
	gcc -fPIC -c div.c -o div.o

sub.o: sub.c
	gcc -fPIC -c sub.c -o sub.o

mul.o: mul.c
	gcc -fPIC -c mul.c -o mul.o

main.o: main.c
	gcc -c main.c -o main.o

main: main.o libcalc.so
	gcc -o calculator main.o -L. -lcalc

clean:
	-rm -f *.o *.a calculator *.so
