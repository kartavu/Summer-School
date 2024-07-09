all: clean bit_operation array pointer struct

bit_operation: bit_operation.o
	gcc -Wall -g -o bit_operation bit_operation.o
	./bit_operation

array: array.o
	gcc -Wall -g -o array array.o
	./array

pointer: pointer.o
	gcc -Wall -g -o pointer pointer.o
	./pointer

struct: struct.o
	gcc -Wall -g -o struct struct.o
	./struct

bit_operation.o: bit_operation.c
	gcc -Wall -g -c bit_operation.c -o bit_operation.o

array.o: array.c
	gcc -Wall -g -c array.c -o array.o

pointer.o: pointer.c
	gcc -Wall -g -c pointer.c -o pointer.o

struct.o: struct.c
	gcc -Wall -g -c struct.c -o struct.o

clean:
	rm -rf bit_operation array pointer struct bit_operation.o array.o pointer.o struct.o