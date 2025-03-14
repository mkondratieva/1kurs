#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int **matrixget(size_t n,size_t  **m);
void pr(int **matr, size_t *m,size_t n);

char *mygets(char **str,size_t *Lmax, FILE *in){//требует доработки  str - очередная  строка файла, Lmax -- начальный блок (который будем увеличивать вдвое в случае необходимости
    size_t begin=0; //показывает позицию в строке, куда следует загружать очередной блок символов из строки файла
    if(*str==NULL)
        *str=malloc(*Lmax);//паммять отводим первый рз для первой строки, остальные строки загружаем, используя ранее отведенную
    while(fgets(*str+begin, *Lmax-begin,in)){
        begin=Lmax-1;  //встаем на конец строки
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

int **matrixget(size_t n,size_t  **m){ //строит криволинейную матрицу с заданным количеством строк и их случайными размерами и заполняет ее случайными числами
    int **matr;
    size_t s=0;
    *m=malloc(n*sizeof(**m));
    for(size_t i=0;i<n;i++){
        (*m)[i]=rand()%11;
        s+=(*m)[i];
    }
    matr=malloc(n*sizeof(int*)+s*sizeof(int));
    matr[0]=(int*)(matr+n);
    for(size_t i=1;i<n;i++)
        matr[i]=matr[i-1]+(*m)[i-1];//разметка
    for(size_t i=0;i<n;i++)
        for(size_t j=0;j<(*m)[i];j++)
            matr[i][j]=rand()%11;
    return matr;
}
void pr(int **matr, size_t *m,size_t n){
   for(size_t i=0;i<n;i++){
        for(size_t j=0;j<m[i];j++)
            printf("%d ",matr[i][j]);
        puts("");
   }
   puts("");
}    

int main(void){
    int **matrix; size_t n=5,*m;
    srand(time(NULL));
    matrix=matrixget(n,&m);
    pr(matrix,m,n); 
    free(matrix);free(m);
    return 0;
}
