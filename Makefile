a:4_.o main.o
	gcc main.o 4_.o
4_.o:4_.c 4.h
	gcc -c 4_.c  -c
main.o: main.c 4.h
	gcc main.c  -c