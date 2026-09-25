#include<stdio.h>
int task(FILE *, int *);
void foo(int *); //прототип
void foo(int *k){*k=0100;} //реализация. Позволяет передавать изменения аргумента в вызывающую
int main(void){
	int res=0,x=0;
	foo(&res); //вызов foo, значение  переменной res изменилось!
	printf("res=%d\n",res);


	x|=(1<<31);//старший бит изменили на 1, получилось максимальное int
printf("max_int=%d max_int=%d  min_int=%d max_int=%d \n-10^8=%d\n",x,0x7fffffff,~0x7fffffff,(1u<<31)-1,-10^8);
{//0 1 1 2 5 7  - последовательность Фибоначчи, число равно сумме двух предыдущих
	int prev=0,cur=1,next;
	for( ;cur<100;){
		next=cur+prev;
		printf("%d ",next);
		prev=cur;
		cur=next; 
	}
	return 0;
}
}

		
