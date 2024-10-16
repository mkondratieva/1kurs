#include"4.h"
int main(void){
	FILE *in=fopen("1.txt","r");
	int res;
	task1213(in,&res);
	printf("res=%d\n",res);
	fclose(in);
	return 0;
}