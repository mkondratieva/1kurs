#include"my.h"
void pr(int  *c, size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
}
void init(int **m,size_t n){
	*m=(int *)malloc(sizeof(int)*n);
	for(size_t i=0;i<n;i++) 
		(*m)[i]=rand()%44;
}
int cmp(const void *a, const void *b){  //возвращает положительное число, если *a>*b, отрицательное, если *a<*b, 0, если *a==*b
	return *(int *)a%10-*(int *)b%10; //голый указатель для сравнения целых нужно преобразовать в тип (int *)
}
	