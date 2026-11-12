#include<stdio.h>    
#include<stdlib.h>
#include<time.h>


void pr(int  c[],size_t n);
size_t init(int **);
int cmp(const  void *, const void *);
void sort(int *, size_t, int(const  void *, const void *));
void sort1(int *, size_t, int(const  void *, const void *));
void sort2(int *, size_t, int(const  void *, const void *));


void swap(int *, int *);

void swap(int *a, int *b){
	int tmp=*a;*a=*b; *b=tmp;
}

void sort(int *a, size_t n,int foo(const  void *, const void *)){ //простые обмены
	if(n<=1)return;
	for(size_t i=0;i<n-1;i++)
		if(foo(&a[i],&a[n-1])>0)
			swap(&a[i],&a[n-1]);
	sort(a,n-1,foo);
}

void sort1(int *a, size_t n,int foo(const  void *, const void *)){//пузырек устойчивая
	if(n<=1)return;
	for(size_t i=1;i<n;i++)
		if(foo(&a[i-1],&a[i])>0)
			swap(&a[i],&a[i-1]);
	sort1(a,n-1,foo);
}

void sort2(int *a, size_t n,int foo(const  void *, const void *)){  //просеивание  устойчивая
	if(n<=1)return;
	sort2(a+1,n-1,foo);
	for(size_t i=1;i<n;i++)
		if(foo(&a[i-1],&a[i])>0)
			swap(&a[i],&a[i-1]);

}

 
void pr(int  c[],size_t n){
	for(size_t i=0;i<n  //(n<10?n:10)
		;i++)
		printf("%d ",c[i]); 
	puts("");        
}
size_t init(int  **c){
	size_t n=//11111//
1+rand()%22
;	
	*c=(int *)malloc(n*sizeof(int));	
	for(size_t i=0;i<n;i++)
		(*c)[i]=rand()%22; 
	return n;
}

int cmp(const  void *a, const void *b){
	int a1=*(int *)a,b1=*(int *)b;
	return //a1-b1//
	(a1%10-b1%10)
;

}
int main(void){
	int *mass=NULL,*copy=NULL;
	clock_t t1,t2; 
	size_t n;
	srand(time(NULL));
	n=init(&mass);
	copy=(int *)malloc(n*sizeof(int));
	for(size_t i=0;i<n;i++)
		copy[i]=mass[i];
	puts("Begin");
	pr(mass,n);
	t1=clock();
	qsort(mass,n,sizeof(int),cmp);
	t2=clock();
	pr(mass,n);
	printf("time1=%lf\n" ,(double)(t2-t1));
	pr(copy,n);
	t1=clock();
	sort2(copy,n,cmp);
	t2=clock();
	pr(copy,n);
	printf("time1=%lf\n" ,(double)(t2-t1));
	puts("end");
	free(mass); 
	free(copy);
	return 0; 
}
