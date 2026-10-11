#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int test(unsigned long long );
int test(unsigned long long x){
	for(int k=0;k<32;k++){
	if ((x>>k&1)!=(x>>(63-k)&1))  
		return 0;
	}
	return 1;
}

#define N 1111
void pr(int  c[N],size_t n);  //печать массива
size_t init(int []); //заполнение массива случайного размера случайными числами  
void invert(int *a, size_t n);//переворот (элементы в обратном порядке)

void pr(int  c[N],size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]); //индексы элементов массива лежат в диапазоне от 0 до 10 (включительно)
}

void invert(int *a, size_t n){ //рекурсию в этой функции необходимо заменить циклом!
	int tmp;
	if (n<=1)
		return;
	tmp=a[0]; a[0]=a[n-1];a[n-1]=tmp;  //меняем местами первый и последний элементы массива
	invert(a+1,n-2); //записываем остальные элементы в обратном порядке
}
size_t init(int  c[]){
	size_t n=1+ rand()%11; //размер массива задаем случайным числом, не большим N
	for(size_t i=0;i<n;i++)
		c[i]=rand()%11; 
	return n;
}

int main(void){
{//зеркалены ли младшие 64 бит числа послед. фибоначчи?
	unsigned long long  prev=0,cur=1,count=1;
	for( ;test(cur)==0;){
		count++;
		cur+=prev;
		prev=cur-prev; 
} 
  	printf("%llx %llo %llu\n %llu\n", cur,cur,cur,count);
}
puts("");
{// 1 1 2 3 5 8  ... 8 5 3 2 1
	int prev=0,cur=1;
	for(;cur<10000;){  
		cur+=prev;
		printf("%d ",cur); 
		prev=cur-prev; 
	}
	cur+=prev;
	prev=cur-prev; 
	cur+=prev;
	prev=cur-prev; 
	puts("");
	for(;prev>1;){  //числа Фибоначчи в обратном порядке
		prev=cur-prev;
		printf("%d ",prev);
		cur=cur-prev; 
	}
}
puts("");
{ 	int mass[N];size_t n;//mass -- массив фиксированного размера N
	srand(time(NULL));
	n=init(mass); //используем часть массива 
	puts("Begin");
	pr(mass,n);
//______________________ циклический сдвиг массива на 1 элемент влево 
	invert(mass,n);     
	puts("\nEnd");
	pr(mass,n);
//______________________ циклический сдвиг массива на 1 элемент  вправо

}
puts("");
	return 0;
}

		
