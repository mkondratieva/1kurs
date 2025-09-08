#include<stdio.h>
void foo(const char []); //декларация функции foo

int main(void){
	foo("Ivanov");// вызов foo с аргументом  Ivanov
	foo("Petrov");// вызов с аргументом   Petrov
	return 0;
}
void foo(const char str[]){ //описание функциии foo
	printf("Hello, %s!\n",str); //печать
}