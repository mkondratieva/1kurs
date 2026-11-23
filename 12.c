#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
void pr(int  c[],size_t n);
size_t init(int **);
int cmp(const  void *, const void *);
int key(int);
void median(int *, size_t n, size_t );
void lsort(int *, size_t n);//сортировка подсчетами
int key(int a){return a%2;}

void swap(int *, int *);
void swap(int *a, int *b){
	//if(cmp(a,b)==0) puts("swap");
	{int tmp=*a;*a=*b; *b=tmp; }

}
void pr(int  c[],size_t n){
	for(size_t i=0;i<n  //(n<10?n:10)
		;i++)
		printf("%d ",c[i]); 
	puts("");        
}
size_t init(int  **c){
	size_t n=//111111//
1+rand()%32
;	
	*c=(int *)malloc(n*sizeof(int));	
	for(size_t i=0;i<n;i++)
		(*c)[i]=rand()%22
; 
	return n;
}
int cmp(const  void *a, const void *b){
	int a1=*(int *)a,b1=*(int *)b;
//return key(a1)-key(b1);
	return a1-b1//(a1%10-b1%10)
;
}
void median(int *a, size_t n, size_t mid){  //  ******a[mid]****
	size_t left=1;
	if(n<=1) return;
	swap(a,a+n/2);
	for(size_t right=1;right<n;right++)
		if(a[right]<a[0]) swap(a+right,a+left++);  //a[0]  ****<a[0] left **** >=a[0]
	swap(a,a+left-1);
	if(left-1==mid) return;
	if(mid<left-1)
		median(a,left-1,mid);
	else
		median(a+left,n-left,mid-left);
}	

void lsort(int *a, size_t n){
	int max=a[0],min=a[0],*dop,k=0;
	for(size_t i=0;i<n;i++) {
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}
	dop=(int *)calloc(max-min+ 1,sizeof(int)); 
	for(size_t i=0;i<n;i++)
		dop[a[i]-min]++;
	for(int i=0;i<max-min+1;i++)
		for(int j=0;j<dop[i];j++)
			a[k++]=i+min;
	free(dop);

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
	printf("time1=%lf median=%d\n" ,(double)(t2-t1),mass[n/2]);
	pr(copy,n);
	t1=clock();
        median(copy,n,n/2);//lsort(copy, n);
	t2=clock();
	pr(copy,n);
	printf("time1=%lf mymedian=%d\n" ,(double)(t2-t1),copy[n/2]);
	puts("end");
	free(mass); 
	free(copy);
	return 0; 
}
