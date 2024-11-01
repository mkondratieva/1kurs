#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
void pr(int  *c,size_t n);  //печать массива
void init(int *,size_t ); //отведение памяти под массив случайного размера
//и заполнение его случайными числами  
int task(int *mass, size_t n);//уплотнение к началу

void pr(int  *c,size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]); //индексы элементов массива лежат в диапазоне от 0 до 10 (включительно)
	printf("\n");
}
void init(int  *c,size_t n){
	for(size_t i=0;i<n;i++)
		c[i]=rand()%11; 
}
int task(int *mass, size_t n){//уплоттнение массива (удаление четных элементов)
	size_t i=0,j=0;//индекс по уплотненному массиву
		for(;i<n;i++) //перебор элементов исходного массива
		if(mass[i]%2)//если элемент нечетный, копируем его в уплотненный массив, иначе переходим к следующему
			mass[j++]=mass[i];
	return j;//размер уплотненного массива
}                        

int main(void){
	size_t n=11;
	int *a= (int*)malloc(sizeof(int)*n);
	srand(time(NULL));
	init(a,n);
	puts("Begin");
	pr(a,n);
//_______________________уплотнение массива к началу за счет удаления нечетных элементов
	n=task(a,n);
	puts("pop chet");
	pr(a,n);
	free(a);
	return 0; 
}
	