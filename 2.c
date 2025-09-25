#include<stdio.h>  
int max(void);

int main(void){
	unsigned char x= 0xff;
	signed char y=0x7f,z=(signed char)0x80;
	printf("sizeof(char)=%lu, sizeof(short)=%lu, sizeof(int)=%lu,sizeof(long)=%lu,sizeof(long long) =%lu, \nmax unsigned char=%d  max signed char=%d, min siigned char=%d\n",
	sizeof(char), sizeof(short),sizeof(int),sizeof(long),sizeof(long long), 
	x,y,z);
	return 0;
}  