a: my.o main.o
	gcc main.o my.o
my.o:my.c my.h
	gcc -c my.c  
main.o: main.c my.h
	gcc -c main.c  