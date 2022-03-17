main:
	gcc -o matrixMultiplication matrixMultiplication.c functionProcedure.c
debug:
	gcc -g -o debug matrixMultiplication.c functionProcedure.c
	gdb debug	
clean:
	rm debug
