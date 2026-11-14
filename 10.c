#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
void pr(int  c[],size_t n);
size_t init(int **);
int cmp(const  void *, const void *);
void sort(int *, size_t, int(const  void *, const void *));
void merge(int *a, size_t n, int * b, size_t k, int *c);
void sort_merge(int *a, size_t, int *);


void swap(int *, int *);
void swap(int *a, int *b){
	int tmp=*a;*a=*b; *b=tmp;
}
void pr(int  c[],size_t n){
	for(size_t i=0;i<//n  //
(n<10?n:10)
		;i++)
		printf("%d ",c[i]); 
	puts("");        
}
size_t init(int  **c){
	size_t n=111111//1+rand()%22
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
void sort(int *a, size_t n,int foo(const  void *, const void *)){//простые вставки  устойчивая
	if(n<=1)return;
	sort(a,n-1,foo);  
	{
		int tmp=a[n-1]; size_t i;
		for(i=n-1;i>0;i--)
			if(foo(&tmp,&a[i-1])<0)
				a[i]=a[i-1];
			else break;
		a[i]=tmp;
	}

}
void merge(int *a, size_t n, int *b, size_t k, int *c){//слияние упорядоченных массивов a и b в упорядоченный массив с за линейное время
	size_t n1=0,k1=0,l=0;
	while(k1<k&&n1<n)
		if (cmp(a+n1,&b[k1])<=0)
			c[l++]=a[n1++];
		else
			c[l++]=b[k1++];
	while(n1<n)
		c[l++]=a[n1++];

	while(k1<k)
		c[l++]=b[k1++];
}
void sort_merge(int *a, size_t n,int *c){
	if (n<=1) return;
	sort_merge(a,n/2,c);
	sort_merge(a+n/2,n-n/2,c);
	merge(a,n/2,a+n/2,n-n/2,c);
	for(size_t i=0;i<n;i++)
		a[i]=c[i];
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
        sort_merge(copy, n,mass);
	t2=clock();
	pr(copy,n);
	printf("time1=%lf\n" ,(double)(t2-t1));
	puts("end");
	free(mass); 
	free(copy);
	return 0; 
}
