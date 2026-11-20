#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
void pr(int  c[],size_t n);
size_t init(int **);
int cmp(const  void *, const void *);
void merge(int *a, size_t n, int * b, size_t k, int *c);
void sort_merge(int *a, size_t, int *);
void Qsort(int *, size_t n);
void lsort(int *, size_t n);

void swap(int *, int *);
void swap(int *a, int *b){
	if(cmp(a,b)==0) puts("swap");
	{int tmp=*a;*a=*b; *b=tmp; }

}
void pr(int  c[],size_t n){
	for(size_t i=0;i<//n  // 
(n<10?n:10)
		;i++)
		printf("%d ",c[i]); 
	puts("");        
}
size_t init(int  **c){
	size_t n=111111//1+rand()%33
;	
	*c=(int *)malloc(n*sizeof(int));	
	for(size_t i=0;i<n;i++)
		(*c)[i]=rand()%22
; 
	return n;
}
int cmp(const  void *a, const void *b){
	int a1=*(int *)a,b1=*(int *)b;
//return 0;
	return a1-b1//(a1%10-b1%10)
;
}
void merge(int *a, size_t n, int *b, size_t k, int *c){//слияние упорядоченных массивов a и b в упорядоченный массив с за линейное время
	size_t n1=0,k1=0,l=0;
	while(k1<k&&n1<n)
		if (cmp(a+n1,&b[k1])<0)
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
void Qsort(int *a, size_t n){
	size_t left=1;
	if(n<=1) return;
	swap(a,a+n/2);
	for(size_t right=1;right<n;right++)
		if(a[right]<a[0]) swap(a+right,a+left++);  //a[0]  ****<a[0] left **** >=a[0]
	swap(a,a+left-1);
	Qsort(a,left-1);
	Qsort(a+left,n-left);
}	

void lsort(int *a, size_t n){
	int max=a[0],min=a[0];
	for(size_t i=0;i<n;i++) {
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}

}




int main(void){

	int *mass=NULL,*copy=NULL;
	clock_t t1,t2; 
	size_t n,i;
	for(i=5;i+1>=1;i--)
		printf("%zu ",i);

	printf("\n%zu  %zu\n",i,i+1);
//return 0;

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
        Qsort(copy, n);
	t2=clock();
	pr(copy,n);
	printf("time1=%lf\n" ,(double)(t2-t1));
	puts("end");
	free(mass); 
	free(copy);
	return 0; 
}
