#include<stdio.h>  
#include<stdlib.h>
#include<time.h>

int task0(FILE *in, int *res); //x_{i}=n-i   ?
int task0(FILE *in, int *res){
	int cur,prev,count=0;
	*res=1;
	while(fscanf(in,"%d",&cur)==1){
		count++;
		if(count>1&&prev-1!=cur)
			*res=0;
		prev=cur;

	}
	if(cur!=0)
		*res=0;
	return 0;
}
int task1(FILE *in, int *res); //x_{n-1}=n-1  ?
int task1(FILE *in, int *res){
	int cur,i=0,pprev,prev;
	*res=1;
	while(fscanf(in,"%d",&cur)==1){
		i++;
		pprev=prev;
		prev=cur;

	}
	if(i==1||pprev!=i-1)
		*res=0;
	return 0;
}
int task(FILE *in, int *res);
//x_i==i    для всех i >foo(n)   maxindex  j=foo(n);  * * *  j+1...n
//x_i==i    для всех i <foo(n)   minindex  j=foo(n);  1 2 ...j-1 *** 

int foo(int);
int foo(int k ){return rand()%(1+k);}

int task(FILE *in, int *res){
	int cur,i=0,max_index=0,min_index=0;
	*res=1;
	while(fscanf(in,"%d",&cur)==1){
		i++;
		if(cur!=i) {
			max_index=i;
		}
		if(cur!=i&&min_index==0) {
			min_index=i;
		}

	}
	
	i=foo(i);
	printf("f(n)=%d max_index=%d  min_index=%d\n",i,max_index,min_index);
	if(max_index>i)
		*res=0;//var 5
	//if(min_index<i&&min_index>0) //var 6
	//	*res=0;	
	return 0;
}
int main(void){
	FILE *in=fopen("1.txt","r");
	int res;
	srand(time(NULL));
	task(in,&res);
	printf("res=%d\n",res);
	fclose(in);
	return 0;
}