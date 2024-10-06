#include<stdio.h>
int task1213(FILE *in, int *res);
int task1213(FILE *in, int *res){
	int cur,n=0;//максимальное количество чисел в конце последовательности, совпадающих с началом фрагмента
// w=(98,1,2 ) n(w)=2
// w=(9,8,1,2, 1) n(w)=3
//n(w)=4 --> w=(*,*,*,*, 1,2,1,3)
	*res=0;
	while(fscanf(in,"%d",&cur)==1){
		switch(cur){
			case 1:  
				if(n==2)
					n=3;
				else
					n=1;
				break;
			case 2:
				if(n==1||n==3)
					n=2;
				else
					n=0;
				break;
			case 3:
				if(n==3)
					n=4;
				else
					n=0;
				break;

			default: 
				n=0;
		}
		if(n==4){
			(*res)++;
			n=0;
		}
	}
	return 0;
}
int main(void){
	FILE *in=fopen("1.txt","r");
	int res;
	task1213(in,&res);
	printf("res=%d\n",res);
	fclose(in);
	return 0;
}