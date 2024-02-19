#include<stdio.h>
#include<stdlib.h>
#define N 111  //максимально допустимое количество строк матрицы
int matrixget(FILE *,int  *[], size_t *,size_t *);//функция чтения матрицы из файла, возврашает код ошибки
void pr(int**,size_t,size_t);//печать 
void pr(int **m,size_t rows,size_t columns){
       for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<columns;j++)
                printf("%d ",m[i][j]);
        puts("");
    } 
}
int matrixget(FILE *in,int *matrix[], size_t *rows,size_t *columns){
    size_t k=0;
    if(in==NULL)
        return 1;
    if(fscanf(in,"%lu%lu",rows,columns)!=2){//извлекаем размеры матрицы
        return 2;
    }
    if(*rows>N)
        return 3;
    matrix[0]=(int *)malloc(*rows**columns*sizeof(int));//отводим память единым куском
    if(matrix[0]==NULL)//проверка успешности выделения памяти
            return 4;
     for(size_t i=1;i<*rows;i++)
         matrix[i]=matrix[i-1]+*columns;//разметка
        while(fscanf(in,"%d",&matrix[0][k])==1){//загружаем матрицу
                if(k>*rows**columns) //протестировать на некорректных данных
                    return 5;
                k++; 
        }
    if(!feof(in))
        return  6;
    if(k<*rows**columns)
        return 7;
    return 0;
}
void del(int **matrix,size_t *rows, size_t k);
void del(int **matrix,size_t *rows, size_t k){
    for(size_t i=k;i<*rows-1;i++)
        matrix[i]=matrix[i+1];
    (*rows)--;
}
int main(void){
    int *matrix[N];
    size_t rows,columns;
    FILE *in=fopen("1.txt","r");
    int err= matrixget(in,matrix,&rows,&columns);
    if(err==0){
        pr(matrix,rows,columns);
        puts("");
        del(matrix,&rows,1);
        puts("");
        pr(matrix,rows,columns);
    }
    else{
        printf("error=%d\n",err);
    //......... 
    } 		
    free(matrix[0]);
    fclose(in);
    return 0;
}
	
