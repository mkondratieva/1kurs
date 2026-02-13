#include<stdio.h>
#include<stdlib.h>
#define N 3
int main(void){ 
{	int p,*p1=&p,**p2=&p1;//....целое, указатель на целое, указатель на указатель на целое
 	*p1=1;  printf("%d\n",p);    //p==1
	p1[0]=2; printf("%d\n",p);   //p==2   a[k]==*(a+k)
 	**p2=3;  printf("%d\n",p);   //p==3
	p2[0][0]=4; printf("%d\n",p);//p==4
}
{
	double q=1;    //  8b
	float 	z=123256;//4b 
	int *p=(int *)&q;  //указатели на разные типы нельзя присваивать, но можно использовать преобразование
	p[0]=0;p[1]=1<<30; //q=2;
	printf("%lf\n",q);
	p=(int *)&z;
	p[0]^=1<<31;  	// 
	printf("%f\n",z); //-z 
	p[0]+=1<<23; // z*2
	printf("%f\n",z);
	p[0]^=1<<31;  	// -z
	printf("%f\n",z);
}
{	//type array int [N]  99% -- int * ; 1% (sizeof + &) =  int (*)[N], type array
	int mass[]={1,2,3},(*p)[N]=&mass//bez nakladnyh rashodov
	,**p1;
	p1=(int **)&mass; //p1 указывает на младший байт первого элемента массива
	printf("%d  %d \n",mass[0],mass[1]);
	*p1=0; //p1 --указатель на указатель, поэтому *p1- имеет размер 8 байт, и операция обнуляет два первых цедых по адресу, на который указывает p1
	printf("%d  %d \n",mass[0],mass[1]);
	for(size_t i=0;i<N;i++)  
		(*p)[i]=-i+1;//p, как и p1, указывает на mass, но тип p (а, значит, и размер *p) отличается
	for(size_t i=0;i<N;i++){ 
		printf("%d %d\n",mass[i],(*p)[i]); //mass и *p -- один и тот же массив фиксированного размера
	}  
}	
    return 0;
} 