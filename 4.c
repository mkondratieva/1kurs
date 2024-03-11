#include<stdio.h>
#include<stdlib.h>
#include<time.h>
                                              
int ** matrixget0(size_t ,size_t **);//функция, создающая кривую случайную матрицу
void task(int**,size_t,size_t*);//строки длины не более3 сдвигаются в конец без сохранения взаимного порядка
//метод 2-х бегунков, выполняется за один проход
void pr(int**,size_t,size_t*);//печать 

void pr(int **m,size_t rows,size_t *columns){ //m - кривая двумерная матрица, rows -- количество строк,columns-- массив длин строк
       for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<columns[i];j++)
                printf("%2d ",m[i][j]);
        puts("");
    } 
}
void task(int**matrix,size_t rows,size_t*col){//метод двух бегунков (уплотнение массива к началу)
        size_t left=0,right=0;
        for(;right<rows;right++) //запустим правый бегунок по массиву указателей
            if(col[right]>3){ //строки длины не более 3 пропускаем, иначе меняем местами строки, на которые указывают бегунки
                int *tmp=matrix[left];size_t t=col[left];
                matrix[left]=matrix[right];
                matrix[right]=tmp;
                col[left]=col[right];
                col[right]=t;
		left++;//сдвигаем левый бегунок 
            }
//удаленные строки лежат правее левого бегунка, если требуется только удаление, меняем        размер массива на left
}

int ** matrixget0(size_t rows,size_t **col){ //строит кривую двумерную матрицу с rows строками, длины строки элементы матрицы являются случайными
    size_t s=0;int ** matrix;// s -- общее количество элементов в массиве
    (*col)=(size_t*)malloc(rows*sizeof(size_t));//отводим память под массив длин строк
    if(*col==NULL) //проверяем корректность выделения памяти, это нужно делать всегда
        return NULL;
    for(size_t i=0;i<rows;i++){
            (*col)[i]=rand()%11; //заполняем  массив длин строк случайными числами
            s+=(*col)[i]; //подсчитываем количество чисел в матрице
        }
    matrix=(int **)malloc(rows*sizeof(int*)+s*sizeof(int));//отводим память единым куском
// этот кусок поделен на 2 части
//в первой части будем хранить указатели на строки, во второй -- элементы матрицы
    if(matrix==NULL)
        return NULL;
    matrix[0]=(int *)(matrix+rows);//первый элемент указывает на вторую часть отведенного куска памяти
    for(size_t i=1;i<rows;i++)
         matrix[i]=matrix[i-1]+(*col)[i-1];//matrix[i] должен указывать на i-ю строку матрицы, все строки размещаем последовательно во второй части отведенной памяти 
    for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<(*col)[i];j++)
                matrix[i][j]=rand()%11;//заполнение матрицы
    }
    return matrix;
}
int main(void){
    int **matrix;
    size_t rows=7,*columns;
    srand(time(NULL));
    matrix= matrixget0(rows,&columns);
    
    if(matrix){
        pr(matrix,rows,columns);
        puts("\nResult");
        task(matrix,rows,columns);
        pr(matrix,rows,columns);
    }
    else{
        printf("error=\n");
    //......... 
    } 		
    free(matrix);
    free(columns);
    return 0;
}
	
