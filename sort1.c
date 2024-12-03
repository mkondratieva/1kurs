#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
#define N 11111
void pr(int  c[],size_t n);  
size_t init(int []); 
void sort(int *a, size_t);//сортировка простыми вставками 
int comp(const  void*, const void*); //сравнение элементов массива 
int comp(const  void* a, const void *b){ // >0, если a >b, <0, если a<b, 0, если a==b
	return *(int *)a%10-*(int *)b%10; //сортировка по последней цифре в 10-ной записи числа (со знаком)
}
void pr(int  *c,size_t n){
	for(size_t i=0;i<(n>11?11:n);i++)
		printf("%d ",c[i]); //индексы элементов массива лежат в диапазоне от 0 до 10 (включительно)
	printf("\n");
}
size_t init(int  c[]){
	size_t n= N;
	for(size_t i=0;i<n;i++)
		c[i]=rand()%100; 
	return n;
}
void sort(int *a, size_t n){
	if(n<=1) return;     
	sort(a+1,n-1);  
	{
		int x=a[0]; size_t i=1;
		while (i<n&&comp(&a[i],&x)<0) 
			{a[i-1]=a[i]; i++;}
		a[i-1]=x;
	} 
}
int main(void){
	clock_t t1,t2;
	int mass[N],mass1[N];size_t n;//mass -- массив фиксированного размера N
	srand(time(NULL));
	n=init(mass); 
	for(size_t i=0;i<n;i++)
		mass1[i]=mass[i]; 
	puts("Begin");
	pr(mass,n);
	t1=clock();
 	sort(mass,n);
	t2=clock();
	printf("my time=%lf\n",(double)(t2-t1));
	t1=clock();
	qsort(mass1,n,sizeof(int),comp);
	t2=clock();
	printf("qsort time=%lf\n",(double)(t2-t1));
	pr(mass,n);
	pr(mass1,n);

	for(size_t i=0;i<n;i++)if(mass1[i]!=mass[i])//qsort в некоторых реализациях является устойчивой
			printf("Error!");
	return 0; 
}
	