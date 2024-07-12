all: clean calculator main

calculator: add.o div.o sub.o mul.o
	ar rc libcalc.a add.o div.o sub.o mul.o

add.o: add.c
	gcc -c add.c -o add.o

div.o: div.c
	gcc -c div.c -o div.o

sub.o: sub.c
	gcc -c sub.c -o sub.o

mul.o: mul.c
	gcc -c mul.c -o mul.o

main.o: main.c
	gcc -c main.c -o main.o

main: main.o
	gcc -o calculator main.o -L. -lcalc

start: main
	./calculator

clean:
	-rm -f *.o *.a calculator
