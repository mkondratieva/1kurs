#include<stdio.h>    
#include<stdlib.h>
#include<time.h>

void pr(int  *,size_t n);  
void init(int **,size_t);
void copy(int **, int *,size_t); 
void sort(int *, size_t);//сортировка простыми обменами 
int comp(const  void*, const void*); //сравнение элементов массива 

int comp(const  void* a, const void *b){ // >0, если a >b, <0, если a<b, 0, если a==b
	return *(int *)a-*(int *)b; //сортировка по возрастанию
}
void pr(int  *c, size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
}
void init(int **m,size_t n){
	*m=(int *)malloc(sizeof(int)*n);
	for(size_t i=0;i<n;i++) 
		(*m)[i]=rand()%11;
}
void copy(int **m, int *a,size_t n){
	*m=(int *)malloc(sizeof(int)*n);
	for(size_t i=0;i<n;i++) 
		(*m)[i]=a[i];
}
void sort(int *a, size_t n){
	if(n<=1) return;
	for(size_t i=0;i<n;i++)
		if(a[i]>a[n-1])
			{int tmp=a[n-1]; a[n-1]=a[i];a[i]=tmp;}		
	sort(a,n-1); //рекурсию необходимо убрать! 
}

int main(void){
	clock_t t1,t2;
	size_t n=11;
	int *mass=NULL,*mass1;
	srand(time(NULL));
	init(&mass,n);
	copy(&mass1,mass,n);
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
	free(mass);free(mass1);
	return 0; 
}
	