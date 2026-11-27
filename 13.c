#include<stdio.h>    
#include<stdlib.h>           
#include<time.h>
void pr(int  c[],size_t n);
void task(int  *,size_t n);
void task(int  *,size_t n);  // группировка по равенству:   9 9 9 7 7 7 4 4 4 44 44 44 
void task1(int  *,size_t n);//модификация массива по подмножеству индексов
size_t init(int **);
int cmp(const  void *, const void *);
int key(int);
void lsort(int *, size_t n);//сортировка подсчетами устойчивая (пример)
int key(int a){return !(a%2);}
void swap(int *, int *);

void task1(int  *a,size_t n){ 
//В целочисленном массиве в рамках подмножества элементов, меньших 3,
//исключить все элементы данного подмножества, 
//имеющие слева меньшего соседа из того же подмножества. Сосед понимается 
//в смысле модифицируещего подмножества, а не исходного массива


	int ind[n]; //массив индексов элементов модифицирующего подмножества
	size_t j=0;
	for(size_t i=0;i<n;i++)
		if(a[i]<3)ind[j++]=i;//заполняем его индексами элементов, меньших 3
	pr(ind,j);// j -- размер массива индексов     
	for(size_t i=j-1;i>0;i--) //j==0?
		if(a[ind[i]]<= a[ind[i-1]])ind[i]=n;
//для массива ind в качестве null_value можно взять размер массива
//помечаем (меняем на nullvalue)  элементы ind, которые НЕ нужно удалять из массива а.
//Просматриваем массив ind с конца и если индекс таков, что элемент 
//в массиве а по этому индексу удалять не надо, меняем его на n

	ind[0]=n;
//первый элемент в ind нужно  пометить, т.к. соответствующий ему элемент массива а нужно оставить
	pr(ind,j);
//удаляем двумя бегунками из массива ind элементы, равные n
//..........
//в ind остались только индесы, элементы с которыми нужно удалить из а.
//... 
}
void task(int  *a,size_t n){
	size_t left=1;
	if(n<=1) return;
	for(size_t right=1;right<n;right++)
		if(a[right]==a[0])
			swap(a+right,a+left++);
	printf("%d\n",(int)left);
	task(a+left,n-left);
}

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
return key(a1)-key(b1);
	return a1-b1//(a1%10-b1%10)
;
}
void lsort(int *a, size_t n){ //пример устойчивой сортировки подсчетами для конкретного ключа (со значением 0 и 1
	int copy[n],*dop;
	dop=(int *)calloc(2,sizeof(int)); 
	for(size_t i=0;i<n;i++)
		dop[key(a[i])]++;  //   {40,60} ->{40,100}  ->0,40}
	dop[1]+=dop[0];
	for(size_t i=n-1;i+1>=1;i--){
		copy[dop[key(a[i])]-- -1]=a[i];

	}	
	for(size_t i=0;i<n;i++)a[i]=copy[i];
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
	//pr(mass,n);
	t1=clock();
	qsort(mass,n,sizeof(int),cmp);
	t2=clock();
	//pr(mass,n);
	printf("time1=%lf median=%d\n" ,(double)(t2-t1),mass[n/2]);
	pr(copy,n);
	t1=clock();
//	lsort(copy, n);
	task1(copy,n);
	t2=clock();
//	pr(copy,n);
//	printf("time1=%lf mymedian=%d\n" ,(double)(t2-t1),copy[n/2]);
	puts("end");
	free(mass); 
	free(copy);
	return 0; 
}
