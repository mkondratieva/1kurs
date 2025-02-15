#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3  // количество столбцов
#define M 9  // количество строк
int main(void){
    int *mass[M]={NULL};//массив указателей 
	mass[0]=(int *)alloca(N*M*sizeof(*mass[0]));// отведение памяти единым куском
    for(size_t i=1;i<M;i++) {
	mass[i]=mass[0]+i; //разметка памяти
    }
    srand(time(NULL)); //так случайные числа будут разными 
    for(size_t i=0;i<M;i++)  
	for(size_t j=0;j<N;j++)
	       mass[i][j]=rand()%3;  //заполнение случайными числами матрицы
    for(size_t i=0;i<M;i++){
	for(size_t j=0;j<N;j++)
	        printf("%d ",mass[i][j]); 
    	puts("");
    }
    puts("_____________");     

{                           // удаление строк матрицы, для которых предыдущая строк начинается с того же числа
    size_t left=1,right=1;  // метод двух бегунков
    for(;right<M;right++){ 
	if(mass[right-1][0]!=mass[right][0]){ 
		mass[left++]=mass[right];
	}	
    }
    for(size_t i=0;i<left;i++){
	for(size_t j=0;j<N;j++)
	        printf("%d ",mass[i][j]); 
    	puts("");
    }
    puts("_____________");     
}
    return 0;
}
