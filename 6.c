#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
#define N 1111
void pr(int  c[],size_t n);  //печать матрицы
size_t init(int []); //заполнение квадратной матрицы случайного размера случайными числами  
void invert(int *a, size_t n);//переворот (элементы в обратном порядке)

void pr(int  *c,size_t n){
	for(size_t i=0;i<n*n;i++) {
		printf("%d ",c[i]); 
		if(i%n==n-1)        //когда закончилась строка, переходим на новую
			printf("\n");
	}
}
void invert(int *a, size_t n){ //рекурсию в этой функции необходимо заменить циклом!
	int tmp;
	if (n<=1)
		return;
	tmp=a[0]; a[0]=a[n-1];a[n-1]=tmp;  //меняем местами первый и последний элементы массива
	invert(a+1,n-2); //записываем остальные элементы в обратном порядке
}
size_t init(int  c[]){
	size_t n= rand()%10; 
	for(size_t i=0;i<n*n;i++)
		c[i]=rand()%10; 
	return n;
}

int main(void){
	int mass[N];size_t n;
	int i,j,k;
	srand(time(NULL));
	n=init(mass); 
	puts("Begin");
	pr(mass,n); 
	i=rand()%n; j=rand()%n,k=rand()%n*n; 
	printf("i=%d, j=%d,mass[i][j]=%d ",i,j,mass[i*n+j]);//формула перевода  mass[i][j]->mass[k]
	i=k/n;j=k%n; // формула обратного перевода mass[k]->mass[i][j]
	printf("k=%d mass[k]=%d i=%d j=%d\n",k,mass[k], i,j);

	invert(mass,n*n);
	if(n>1) {
	invert(mass,2*n); 
	invert(mass+2*n,n*n-2*n);  
	}
	puts("Shift down 2");
	pr(mass,n);
	if(n>1) {
	invert(mass,2*n); 
	invert(mass+2*n,n*n-2*n);  
	}
    	invert(mass,n*n);
	puts("Shift up 2"); 
	pr(mass,n); 
	return 0;
}
	