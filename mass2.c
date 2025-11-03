#include<stdio.h>  //удалить эл-ты a_i, которые равны a_{i/2}, сохранив взаимный порядок (=уплотнение к наалу)
void pr(int  [],size_t );  //печать массива
int null_value(int *a, int n);//находит  за линейное время элемент, которого нет в массиве a
int task(int *, int ,int);

int null_value(int *a, int n){ //допускается  использование  дополнительного массива длины n
        //  ?????
	return //?;
}
void pr(int  c[],size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
}
int task(int *a, int n, int null_value){
	int left=0;
	for(int i=n-1;i>=0;i--)
		if(a[i]==a[i/2])
			a[i]=null_value;//пометили элементы, которые надо удалить
	for(size_t right=0;right<n;right++) //левый бегунок - размер уплотненного массива, правый просматривает  элементы исходного
		if(a[right]!=null_value)//если элемент нужно оставить
			a[left++]=a[right];//копируем и увеличиваем левый бегунок, элементы, которые нужно удалить, пропускаем
        return left;//возвращаем новый размер массива
}
int main(void){
	size_t n=9,null_val;
	int mass[]={8,6,6,2,3,2,2,3,3} ;
	pr(mass,n); 
	null_val=null_value(mass,n);
	n=task(mass,n,null_val); 
	pr(mass,n); 
	return 0; 
}
	