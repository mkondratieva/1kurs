#простой пример makefile для проекта из main.c 1.c head.h

all:main.o 1.o  #если проект откомпилирован, линкуем	
	wgcc main.o 1.o
main.o: main.c head.h  #если файлы head.h или main.c изменялись, компилируем
	wgcc -c main.c
1.o: 1.c   head.h  #если файлы head.h или 1.c изменялись, компилируем
	wgcc -c 1.c