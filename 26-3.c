#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 4 
int main(void){ 
{	void *ptr=NULL; 
	printf("%p\n",ptr);
	ptr=(char *)ptr+1;
	printf("%p\n",ptr);//(null)
	ptr=NULL;
	ptr=(int *)ptr+1;
	printf("%p\n",ptr);//0x1
	ptr=NULL;
	ptr=(int **)ptr+1;
	printf("%p\n",ptr); //0x8
	ptr=NULL;
	ptr=(int (*)[N])ptr+1;
	printf("%p\n",ptr); //0xc
	ptr=NULL;
	ptr=(int (**)[N])ptr+1;
	printf("%p\n",ptr); //0x8
	ptr=NULL;
	ptr=(int (*)[M][N])ptr+1;
	printf("%p\n",ptr); //0x30
}
{	//3б( знаем только количество строк, массив указателей, единый кусок
	char*matrix[M]={NULL};
	matrix[0]=(void *)alloca(M*N*sizeof(*matrix[0]));
	for(size_t i=1;i<M;i++){ 
		matrix[i]=matrix[0]+i*N;//разметка памяти
	}
	puts("");
	for(size_t i=0;i<N*M;i++)matrix[0][i]='a'+i;
	for(size_t i=0;i<M;i++) {
		for(size_t j=0;j<N;j++)
			printf("%c ",matrix[i][j]);
		puts(""); 
	}
	puts("");
	{char *tmp;tmp=matrix[0];matrix[0]=matrix[M-1];matrix[M-1]=tmp;}
	for(size_t i=0;i<M;i++) {
		for(size_t j=0;j<N;j++)
			printf("%c ",matrix[i][j]);
		puts(""); 
	}
	puts("");
}       
{       // 4a) не знаем количество строк и количество столбцов, не единый кусок
	int **matrix=NULL,***p=NULL;//указатель на указатель
	matrix=(int **)alloca(M*sizeof(*matrix)); 
	for(size_t i=0;i<M;i++)
		matrix[i]=(int *)alloca(N*sizeof(*matrix[i])); 
	p=&matrix;
	for(size_t i=0;i<M*N;i++)
			matrix [i/N][i%N]=i;
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<N;j++)
			printf("%d ",(*p) [i][j]);
		puts(""); 
	}
	puts("");
}
{       //4б) ----- единый кусок
	int **matrix=NULL;
	matrix=(int **)alloca(M*sizeof(*matrix)+N*M*sizeof(**matrix)); 
	matrix[0]=(int *)(matrix+M);
	for(size_t i=1;i<M;i++)
		matrix[i]=matrix[i-1]+N;//разметка памяти 
	for(size_t i=0;i<M*N;i++)
			matrix [0][i]=i;
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<N;j++)
			printf("%d ",matrix [i][j]);
		puts(""); 
	}
}
	puts("ok");
	return 0;
} 