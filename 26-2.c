#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 4
int main(void){ 
//одномерные массивы Си, 2 сарсоба задания
{	//1) type array  или массив (фиксированного размера)
	int mass[N]={1,2,3},(*p)[N]=&mass;//тип int [N], p -- указатель на этот тип
	(&mass)[0][1]=3;//==(*&)mass[1]==mass[1]
	printf("%d  %d \n",mass[0],mass[1]); //1 3
	((int **)mass)[0]=0; //==  *(int **)mass=NULL (обнуляет 8 байт по адресу mass) 
	printf("%d  %d \n",mass[0],mass[1]); //0 0
	((int *)&mass)[0]=1; //== *(int *)&mass ==*(int *)(&mass[0]) =1; ==  *(&mass[0]) ==  mass[0]=1;
	printf("%d  %d \n",mass[0],mass[1]); //1 0
	for(size_t i=0;i<N;i++)  
		(*p)[i]=i+1; //*p==mass
	for(int i=0;i<N;i++) 
		printf("mass[%d]=%d %d\n",i,mass[i],(*p)[i]); // i+1  i+1
	puts("____");
}
{	//2) type pointer
	int *mass,*(*p)=&mass;
	mass=(int *)alloca(N*sizeof(*mass));
	mass[0]=1;(&mass)[0][1]=2; //==  (*&mass)[1] == mass[1]=2
	printf("%d  %d \n",mass[0],mass[1]); //1 2
	((int **)&mass)[0][2]=3; //== &mass[0][2]=3
	printf("%d  %d \n",mass[1],mass[2]); //2 3
	p[0][0]=1;//== *(*&mass) == *mass ==mass[0]=1
	printf("%d  %d \n",mass[0],mass[1]); //1 2
	for(size_t i=0;i<N;i++)  
		(*p)[i]=i+1; //*p == mass
	for(size_t i=0;i<N;i++) 
		printf("%d %d\n",mass[i],(*p)[i]); //i+1 i+1
	puts("______");
}       
// Матрицы == двумерные массивы, 4 способа задания
{       //1) знаем оба размера (количество строк + количество столбцов  array arrays int [M][N]
	int matrix[M][N],(*p)[M][N]=NULL; 
	p=&matrix;
	for(size_t i=0;i<N*M;i++)
		matrix[0][i]=i;   //память отведена единым куском
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<N;j++)
			printf("%d ",(*p)[i][j]);
		puts(""); 
	}
	puts("__________"); 
}
{       //2) знаем только  N (количество столбцов) указатель на массив   
	int (*matrix)[N]=NULL,(*(*p))[N]=NULL;//р - указатель на указатель на массив
	matrix=(int (*)[N])alloca(M*sizeof(*matrix)); 
	p=&matrix;;
	for(size_t i=0;i<N*M;i++) 
		matrix[0][i]=i; //память отведена единым куском
	for(size_t i=0;i<4;i++){
		for(size_t j=0;j<N;j++)
			printf("%d ",(*p)[i][j]);
		puts(""); 
	}
	puts("_______________");
}
{       // 3) знаем только M (количество строк) -  массив указателей
	int *matrix[M]={NULL},*(*p)[M]=NULL;// р -- указатель на массив указателей
	for(size_t i=0;i<M;i++)
		matrix[i]=(int *)alloca(N*sizeof(*matrix[i]));//не единый кусок!
	p=&matrix;
	for(size_t i=0;i<M;i++)
		for(size_t j=0;j<N;j++)
			matrix [i][j]=i+j;
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<N;j++)
			printf("%d ",(*p) [i][j]);
		puts(""); 
	}
	puts("_________________");
}
{       //3)a  знаем только M (количество строк, отведение памяти единым куском
	int *matrix[M]={NULL},*(*p)[M]=NULL; //массив указателей
	matrix[0]=(int *)alloca(M*N*sizeof(*matrix[0]));// одно отведение памяти
	for(size_t i=1;i<M;i++) //разметка отведенной памяти
		matrix[i]=matrix[0]+i*N;
	p=&matrix;
	for(size_t i=0;i<M;i++)
		for(size_t j=0;j<N;j++)
			matrix [i][j]=i+j;
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<N;j++)
			printf("%d ",(*p) [i][j]);
		puts(""); 
	}
}
	puts("ok");
	return 0;
} 