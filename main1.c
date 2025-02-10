#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 4
typedef  int Type[N];    // Type стал синонимом "массив N целых"
int main(void){
{ //++ массив массивов, известны M,N
Type  mass[M], (*p)[M]=&mass; //mass -- массив размера M  элементов типа Type
//т.е. массив размера M массивов  из N целых 
    for(size_t k=0;k<N*M;k++) 
	((int *)(*p))[k]=k; //заполнение матрицы через указатель на matr
    for(size_t k=0;k<N*M;k++) 
	((int *)(*p))[k]=k;  //т.к. при таком хранении матрицы ее строки располагаются единым куском
    for(size_t i=0;i<M;i++){
	for(size_t j=0;j<N;j++)
	        printf("%d ",mass[i][j]); 
    	puts("");
    }
    puts("_____________");     
}
{ //-+ указатель на  массив
    Type   *mass=NULL,**p=NULL;  //mass -- указатель на массив из N целых
    mass =(Type *)alloca(M*sizeof(*mass));// под указатель требуется отвести память
    p=&mass;
    for(size_t k=0;k<N*M;k++) 
	((int *)(*p))[k]=k;  //т.к. при таком хранении матрицы ее строки располагаются единым куском
    for(size_t i=0;i<M;i++){
	for(size_t j=0;j<N;j++)
	        printf("%d ",mass[i][j]); 
    	puts("");
    }
    puts("_____________");     
}
{ //+-  ммссив указателей
    int *mass[M]={NULL}; //заполнение массива из M указателей нулями
    for(size_t i=0;i<M;i++) {
	mass[i]=(int *)alloca(N*sizeof(*mass[0]));//под каждую строку матрицы отводим память
    }
//!!!! более эффективно отводить память сразу под все указатели вместе, единым куском
    for(size_t i=0;i<M;i++)  //т.к. мы отвели память отдельными (под каждую строку) кусками,  ее нельзя заполнять как в 1 и 2 случае
	for(size_t j=0;j<N;j++)
	       mass[i][j]=i*N+j;
    for(size_t i=0;i<M;i++){
	for(size_t j=0;j<N;j++)
	        printf("%d ",mass[i][j]); 
    	puts("");
    }

    puts("_____________");     
}
{ //--  указатель на указатель
    int **mass={NULL}; 
    mass=(int **)alloca(M*sizeof(*mass));
   for(size_t i=0;i<M;i++) {
	mass[i]=(int *)alloca(N*sizeof(**mass)); 
    }
//!!!! более эффективно отводить память сразу под все указатели и все элементы матрицы единым куском
    for(size_t i=0;i<M;i++)  //т.к. мы отвели память отдельными кусками, ее нельзя заполнять как в 1 и 2 случае
//при отведении памяти единым куском заполнение матрицы возможно  в одном цикле как в случае 1 и 2
	for(size_t j=0;j<N;j++)
	       mass[i][j]=i*N+j;
    for(size_t i=0;i<M;i++){
	for(size_t j=0;j<N;j++)
	        printf("%d ",mass[i][j]); 
    	puts("");
    }
    puts("_____________");     
}
    return 0;
}
