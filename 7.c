#include<stdio.h>    
#include<stdlib.h>
#include<time.h>

void pr(int  c[],size_t n);  //печать массива
size_t init(int **); //заполнение массива случайного размера случайными числами  
void task(int *a, size_t *);//2 бегунка

void pr(int  c[],size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]); 
	puts("");        
}
void task(int *a, size_t *n){ //удаление  из массива четных чисел
	size_t left=0;
	for(size_t right=0;right<*n;right++)
		if (a[right]%2)
			a[left++]=a[right];
	*n=left;
}
size_t init(int  **c){
	size_t n=1+ rand()%11; //размер массива задаем случайным числом, не большим N
	*c=(int *)malloc(n*sizeof(int));	
	for(size_t i=0;i<n;i++)
		(*c)[i]=rand()%11; 
	return n;
}

int main(void){
	int *mass=NULL;
	size_t n;
	srand(time(NULL));
	n=init(&mass);  
	puts("Begin");
	pr(mass,n);
	task(mass,&n);     
	puts("end");
	pr(mass,n);
	free(mass);
	return 0; 
}
	