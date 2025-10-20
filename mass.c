#include<stdio.h>    
//#include<stdlib.h>
#define N 1111
void pr(int  [],size_t );  //печать массива
void invert(int [], size_t );//переворот (элементы в обратном порядке)
int read (FILE *, int [], size_t *);

int read (FILE *in, int mass[1], size_t *n){
	*n=0;
	if(in==NULL)
		return 0;
	while(fscanf(in, "%d",&mass[*n])==1)
		(*n)++;
	if(!feof(in))
		return -1;
	if(*n==0)
		return -2;
	return 1;
}

void pr(int  c[],size_t n){
	for(size_t i=0;i<n;i++)
		printf("%d ",c[i]); //индексы элементов массива лежат в диапазоне от 0 до 10 (включительно)
	printf("\n");
}
void invert(int a[], size_t n){ //рекурсию в этой функции необходимо заменить циклом!
	if (n<=1)
		return;
	{ 
		int tmp;
		tmp=a[0]; a[0]=a[n-1];a[n-1]=tmp;  //меняем местами первый и последний элементы массива
	}
	invert(a+1,n-2); //записываем остальные элементы в обратном порядке
}
int main(void){
	FILE *in=fopen("1.txt","r");
	size_t n;
	int mass[N], err=//mass -- массив фиксированного размера N
	read(in,mass,&n), //используем часть массива 
        (*p)[N]=&mass;// p -- указатель на массив
	if(err)
		fclose(in);  
	printf("%p\n%p\n%p\n%p\n",(void *)p,(void *)mass,(void *)&mass[0],(void *)&mass);
	//эти значения совпадают, что позволяет передавать массивв в функцию по ссылке
	printf("dif sum\n%p\n%p\n",(void *)(p+1),(void *)(mass+1));
//но арифмеетика указателя на массив и указателя на первый элемент разная!
	switch(err){
		case 0:	printf("No file\n");break;
		case -1:printf("Bad file\n");break;
		case -2: printf("Empty file\n");break;
		default: 
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
	}
	return 0; 
}
	