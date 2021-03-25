#include <stdio.h> //   кривая матрица единым куском, финальная версия
#include <stdlib.h>  
#include<time.h>
#include<string.h>
#define IN
#define OUT

void pr(int **, size_t n,size_t *); //печать кривого двумерного массива
char *mygets(char **, size_t *LMax, FILE *); ///getline
int **Input( OUT size_t *, size_t **nrows, IN FILE *);   //единый массив  для данных, кол-во строк ограничено, на количество чилсел ограничений нет
int get_int(char *s,int *); ///извлечение числа из строки

char *mygets(char **str, size_t *LMax, FILE *in){ //на длину строки нет ограничений
	int begin=0; //это номер позиции в строке для загрузки очередного блока символов
	if(!*str)
		*str=(char *)malloc(*LMax); //считываем блоками размера *LMax
	while(fgets(*str+begin,*LMax-begin,in)){//туда, где закончилась  строка, полученная на предыдущей итерации, кладем следующий извлеченный из файла блок символов
		begin=*LMax-1; //передвигаемся туда, где должен быть конец строки
		if(strchr(*str,'\n')) //если строка считалась до конца
			break; //заканчиваем с текущей строкой
		(*LMax)*=2;  //иначе размер блока удваиваем
		(*str)=(char *)realloc(*str,*LMax);//захватываем память под новый блок, автоматом будет выполнено копирование старых данных по новому адресу
       	}
	if(begin==0){ //сюда попадаем, только если достигнут конец файла
 		free(*str); //освобождаем память. Здесь надо подумать, как обработать ошибки, возможно, освобождать память под строку лучше в вызывающей функции
		return NULL;
	}
	return *str;
}
int get_int(char *s,int *x){
	int pos;
	if(sscanf(s,"%d%n",x,&pos)==1)
		return pos;
	if(sscanf(s,"%s",s)==1)
		return -1;
	return 0;
}
int **Input(size_t *n, size_t **nrows,FILE *in ){// бесконечное количество чисел в матрице, но количество строк ограничено N
	int **a,x=0,*d;
	char *buf=NULL;
	size_t *b,k=0,sum=0, LMax=2,KMax=1,NMax=1; //для теста выбираем минимальные значения блоков
	b=(size_t*)malloc(NMax *sizeof(size_t));
	d=(int*)malloc(sizeof(int)*KMax); //массив разрезали на 2 части,  d  временный массив, куда подряд записаны числа файла
	while(mygets(&buf,&LMax,in)){//считываем очередную "бесконечную" строку из файла
		size_t l=0;char *s=buf;
		int pos;
		if(k==NMax){
			NMax*=2;
			b=(size_t*)realloc(b,NMax *sizeof(size_t));//если выделенной памяти под массив длин строк не хватило, расширяем
		}
		while(pos=get_int(s,&x),pos){
			if(sum==KMax){//если памяти, выделенной под матрицу, не хватило, переаллоцируем
				KMax*=2; //размер блока удваиваем
			d=(int*)realloc(d,sizeof(int)*KMax);//если памяти, вфделенной под данные (числа атрицы) не хватило, расширяем
		} 
		d[sum] =x;sum++;
		s+=pos; l++;
		}
	b[k++]=l;
	}
   	a=(int **)malloc(k*sizeof(int *)+sizeof(int)*sum);//кусок памяти для размещения матрицы из k строк и sum чисел
	a[0]=(int *)&a[k];//разметка
	for(size_t i=1;i<=k;i++) 
		a[i]=a[i-1]+b[i-1]; //a[i] указывает на i-ю строку
	memcpy(a+k,d,sizeof(int)*sum);//копируем данные в двумерный массив
	free(d);
	*n=k;
	*nrows=b;
	return a;
}	
int main(void){
	FILE *in=fopen("1.txt","r");
	int **a; size_t n=6,*nrows; 
//	size_t l=2; char *buf=NULL;
//	mygets(&buf,&l,stdin);//тестируем функцию, считывающую строку произвольной длины
//	puts(buf);
//	printf("\nl=%d\n",(int)l);
//	free(buf);
	
	srand(time(NULL));//для заполнения массива различными случайными числами
	a=Input(&n,&nrows,in);
	pr(a,n,nrows);
	free(a); //память,  захваченная одним куском, освобождается в одно действие
	free(nrows);
	fclose(in);
	return 0;
}
void pr(int **a, size_t n, size_t *m){
	for(size_t i=0;i<n;i++){
		for(size_t j=0;j<m[i];j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}	


