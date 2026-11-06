a.exe: my.o main.o
	wgcc main.o my.o
my.o:my.c my.h
	wgcc -c my.c  
main.o: main.c my.h
	wgcc -c main.c  