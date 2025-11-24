#include<stdio.h> 
#include<stdlib.h> 
void pr(int  c[],size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
}
void sort(int  *a, size_t n){ //qsort   быстрая сортировка
	if (n<=1)return;size_t left=1;
	for(size_t right=1;right<n;right++) //сепартрование массива a[1],...,a[n-1]  по опорному элементу a]0]
//a[i]: i=1,...,left-1 => a[i] <=a[0] && a[i]: i=left,...,n-1 => a[i]<a[0]
		if(a[right]<=a[0])
		{//обмен a[left], a[right]+ корректировка индекса}		
	{//обмен опорного элемента с ????, опорный должен всчтать на свое место в отсортированном массиве
		//.......;}
        if(left>0)
		sort(a,left-1);//рекурсия. Сортируем часть массива до опорного, не включая его 
	sort(a+left,n-left);//сортируем часть массива после опорного, не включая его
}
int main(void){
	size_t n=12;
	srand(time(0));
	int *mass=(int *)malloc(n*sizeof(int));
	for(size_t i=0;i<n;i++)mass[i]=rand()%111;
	pr(mass,n); 
	sort(mass,n);
	pr(mass,n);
	free(mass); 
	return 0; 
}
	