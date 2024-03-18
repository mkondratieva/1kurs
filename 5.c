#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int **matrixget(FILE *in, size_t *rows, size_t **col);//функция чтения матрицы из файла 
void pr(int**,size_t,size_t*);//печать 
void pr(int **m,size_t rows,size_t *columns){
       for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<columns[i];j++)
                printf("%2d ",m[i][j]);
        puts("");
    } 
}
int ** matrixget(FILE *in, size_t *rows,size_t **col){ //чтение кривой матрицы из файла, память отводим единым куском, длины строк в файле ограничены
    size_t N=1,M=1,i=0,j=0;//N -- размер блока памяти для массива длин строк, M -- под массив элементов матрицы, i-- счетчик строк,j -- счетчик элементов массива
    char buf[111],*begin;int **matrix=NULL,*data=NULL,x,pos;//data -- массив, в котором хранятся элементы матрицы, а в конце зарезервировано место под указатели на строки кривого двумерного массива
    if(in==NULL)
        return NULL;
    (*col)=NULL;//*col-- массив длин строк
    while(fgets(buf,111,in)){ //извлекаем строку из файла
        size_t s=0;//счетчик элементов строки buf
        if(!i||i==N){//если память еще не отводилась или отведенная под массив длин строк закончилась
               N*=2;//увеличиваем блок 
               (*col)=(size_t*)realloc(*col,N*sizeof(size_t));//расширяем память под массив длин строк матрицы
               data=(int *)realloc(data,N*sizeof(int*)+M*sizeof(int)); //расширяем память зарезервированного куска под матрицу
           }
        for(begin=buf;sscanf(begin,"%d%n",&x,&pos)==1;begin+=pos){//извлекаем из buf числа и помещаем в массив
                    if(!j||j==M){ //если память закончилась
                        M*=2;
                        data=(int *)realloc(data,N*sizeof(int*)+M*sizeof(int));//отводим новую
                    }
                    data[j]=x;//извлеченное число кладем в массив
                    j++;s++;
        }
        (*col)[i]=s;i++;//yfqltyyjt rjkbxtcndj 'ktvtynjd cnhjrb rkfltv d vfccbd lkby
    }
    *rows=i;//количество строк матрицы теперь известно
     memmove((int **)data+i,(int**)data,j*sizeof(int));//переносим элементы матрицы в конец массива, сразу заполнять  конец массива элементами матрицы сложно из-за использования realloc
     matrix=(int **)data;//зарезервированное под указатели на строки место в отведенном куске памяти теперь в начале массива
     matrix[0]=(int *)(matrix+i);//первый элемент массива natrix указывает на начало блока данных (чисел)
     for(size_t k=1;k<i;k++)
         matrix[k]=matrix[k-1]+(*col)[k-1];//разметка
     return matrix;
}
int main(void){
    int **matrix;
    size_t rows=7,*columns;
    FILE *in=fopen("1.txt","r");
//_______________________________   извлечение  строки из файла 
    
    size_t L=1,begin=0;
    char *buf=(char *)malloc(sizeof(char)*L);
    while(fgets(buf+begin,L-begin,in)){
        begin=L-1;
        if(strchr(buf,'\n'))
            break;
        L*=2;
        buf=(char*)realloc(buf,sizeof(char)*L);
    }
    puts("First row");	
    puts(buf);
    free(buf);    
    //__________________ 
       
    matrix= matrixget(in,&rows,&columns);
    if(matrix){
        puts("Matrix:");
        pr(matrix,rows,columns);
       //..............
        //pr(matrix,rows,columns);
    }
    else{
        printf("error=\n");
    //......... 
    } 		
    free(matrix);
    free(columns);
    fclose(in);
    return 0;
}
	
