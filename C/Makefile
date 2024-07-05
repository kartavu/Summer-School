all: clean bit_operation array

bit_operation: bit_operation.o
	gcc -Wall -g -o bit_operation bit_operation.o
	./bit_operation

array: array.o
	gcc -Wall -g -o array array.o
	./array

bit_operation.o: bit_operation.c
	gcc -Wall -g -c bit_operation.c -o bit_operation.o

array.o: array.c
	gcc -Wall -g -c array.c -o array.o

clean:
	rm -rf bit_operation array bit_operation.o array.o