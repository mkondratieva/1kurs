#include<stdio.h>    
#include<stdlib.h>
#include<time.h>
#define N 1111
void pr(int  c[],size_t n);  //печать массива
size_t init(int []); //заполнение массива случайного размера случайными числами  
void invert(int *a, size_t n);//переворот (элементы в обратном порядке)

void pr(int  *c,size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]); //индексы элементов массива лежат в диапазоне от 0 до 10 (включительно)
	printf("\n");
}
void invert(int *a, size_t n){ //рекурсию в этой функции необходимо заменить циклом!
	int tmp;
	if (n<=1)
		return;
	tmp=a[0]; a[0]=a[n-1];a[n-1]=tmp;  //меняем местами первый и последний элементы массива
	invert(a+1,n-2); //записываем остальные элементы в обратном порядке
}
size_t init(int  c[]){
	size_t n= rand()%11; //размер массива задаем случайным числом, не большим N
	for(size_t i=0;i<n;i++)
		c[i]=rand()%11; 
	return n;
}

int main(void){
	int mass[N];size_t n;//mass -- массив фиксированного размера N
	srand(time(NULL));
	n=init(mass); //используем часть массива 
	puts("Begin");
	pr(mass,n);
//______________________ циклический сдвиг массива на 1 элемент влево 
	invert(mass,n);     
	invert(mass,n-1); //переворот первых n-1 элементов в массиве mass
	puts("Sdvig vlevo");
	pr(mass,n);
//______________________ циклический сдвиг массива на 1 элемент  вправо

	invert(mass,n-1);
	invert(mass,n);     
	puts("Sdvig vpravo");
	pr(mass,n);
	return 0; 
}
	