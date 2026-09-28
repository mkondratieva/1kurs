#include<stdio.h>
int task(FILE *, int *);
int main(void){
//  поиск фрагмента  1 2 2
	FILE *in=fopen("1.txt","r");
	int cur,res=0,tail=0;//tail (w)-- максимальное количество чисел в конце последовательности w, совпадающих с еачалом фрагмента
	while(fscanf(in,"%d",&cur)==1){
		switch(cur){
			case 1:tail=1; break;
			case 2:if(tail>0){tail++;}break;
			default:tail=0;
		}
		if(tail==3){
			res++;tail=0;
		}
	}
	printf("\nres=%d\n",res);
	fclose(in);
}

		
