all: 1.o 26-2.o
	gcc   26-2.o 1.o 
26-2.o:26-2.c 
	gcc 26-2.c -c
1.o:1.c 
	gcc 1.c -c
 