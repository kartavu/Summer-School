all: clean dynamic

dynamic: dynamic.o
	gcc -Wall -g -o dynamic dynamic.o

dynamic.o: dynamic.c
	gcc -Wall -g -c dynamic.c -o dynamic.o

clean:
	rm -rf dynamic dynamic.o