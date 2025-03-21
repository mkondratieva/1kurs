#include <stdio.h>   //   str ***0***********
#include <stdlib.h>   //          begin 
#include<string.h>
#include<ctype.h>

struct line{ //объявление структуры с 2 полями
    int *arr; size_t len;
 };
 
typedef struct line Line;  //введение нового типа данных (struct line =Line)

char *mygets(char **str,size_t *Lmax, FILE *in){//требует доработки  str - очередная  строка файла, Lmax -- начальный блок (который будем увеличивать вдвое в случае необходимости
    size_t begin=0; 
    if(*str==NULL)
        *str=malloc(*Lmax);//паммять отводим первый рз для первой строки, остальные строки загружаем, используя ранее отведенную
    while(fgets(*str+begin, *Lmax-begin,in)){
        begin=*Lmax-1;  //встаем на конец строки
        if(strchr(*str,'\n'))//если в строке есть символ '\n', ввод очередной строки закончен
                    break;
        *Lmax*=2;//иначе увеличиваем размер блока
        *str=realloc(*str,*Lmax); //переносим извлеченные данные по овому дресу, при этом позиция begin не меняется
    }
    if(begin==0){ //когда-нибудь файл закончится и больше нельзя извлечь строку, очищаем память
        free(*str);
        return NULL;
    }
    return *str;
}
void pr(int **matr, size_t *m, size_t n){ //печать криволинейного двумерного массива
   for(size_t i=0;i<n;i++){
        for(size_t j=0;j<m[i];j++)
            printf("%d ",matr[i][j]);
        puts("");
   }
   puts("");
}    
int main(void){
{     
    Line *a=(Line *)malloc(sizeof(*a)); 
    a->len=11;   a->arr=(int *)malloc(a->len*sizeof(int));;
    for(size_t j=0;j<a->len;j++)a->arr[j]=j ;//заполнение массива
    //.............
    free(a->arr); free(a);
}	
   char *str=NULL,*tmp; int pos,buf; size_t Lmax=2,len[11],n=0,k=0;
    int *matr[11]; //будем предполагать, что количество строк матрицы не более 11, и в каждой строке не более 11 чисел
     matr[0]=malloc(11*11*sizeof(int));
    FILE *in=fopen("1.txt","r");
    while(mygets(&str,&Lmax,in)){ //записываем в str очередную строку
		len[n]=0;//нужно вычислить количество чисел в sstr 
		tmp=str;//чтобы не потерять начало строки, 
        	for(;sscanf(tmp,"%d%n",&buf,&pos)==1;tmp+=pos){ //перебор чисел в строке str
	                len[n]++; //при извлечении очередного числа из str счетчик длины строки увеличиваем на 1
        	        matr[0][k++]=buf;//все числа кладем в первую строку матрицы (единым куском)
	        }
		n++;//увеличиваем считчик количества строк
	}
	for(size_t i=1;i<n;i++)
              matr[i]=matr[i-1]+len[i-1];//разметка памяти, отведенной для чисел матрицы
	puts("Matr=");
	pr(matr,len,n);
	free(matr[0]);
	fclose(in);
	return 0;
}
