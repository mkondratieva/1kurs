#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int **matrixget(FILE *in, size_t *rows,size_t **col);//функция чтения матрицы из файла, возврашает кривой двумерный массив, память отводим единым куском
void pr(int**,size_t,size_t*);//печать
char * mygets(char **,size_t *, FILE *);//функция чтения строки из файла без ограничения на длину строки, пмять отводится внутри и, если достигнут конец файла, очищается.

void pr(int **m,size_t rows,size_t *columns){
       for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<columns[i];j++)
                printf("%2d ",m[i][j]);
        puts("");
    } 
}
int ** matrixget(FILE *in, size_t *rows,size_t **col){
    size_t N=1,M=1,i=0,j=0,L=1;
    char *buf=NULL,*begin;int **matrix=NULL,*data=NULL,x,pos;
    if(in==NULL)
        return NULL;
    (*col)=NULL;
    while(mygets(&buf,&L,in)){
        int s=0;
        if(!i||i==N){
               N*=2;
               (*col)=(size_t*)realloc(*col,N*sizeof(size_t));
               data=(int *)realloc(data,N*sizeof(int*)+M*sizeof(int));
           }
        for(begin=buf;sscanf(begin,"%d%n",&x,&pos)==1;begin+=pos){
                    if(!j||j==M){
                        M*=2;
                        data=(int *)realloc(data,N*sizeof(int*)+M*sizeof(int));
                    }
                    data[j]=x;
                    j++;s++;
        } 
	if(sscanf(begin,"%*d")!=EOF){  
                free(data);
                free(*col);
                fclose(in);
                free(buf);
                return NULL;
        }            
        (*col)[i]=s;i++;
    }
    if(!data){
        fclose(in);
        return NULL;
     }
    *rows=i;
    memmove((int **)data+i,(int**)data,j*sizeof(int));
    matrix=(int **)data;
    matrix[0]=(int *)(matrix+i);
    for(size_t k=1;k<i;k++)
         matrix[k]=matrix[k-1]+(*col)[k-1];//разметка
    return matrix;
}
char * mygets(char **s,size_t *L, FILE *in){ //s - строка, в которой сохраняется строка файла, L - количество отведенной под *s памяти
    size_t begin=0;
    if(*s==NULL)
        *s=(char *)malloc(sizeof(char)**L);
    while(fgets(*s+begin,*L-begin,in)){ //под каждую строку файла используется память, отведенная под предыдущую (при необходимости, расширяется)
        begin=*L-1;     
        if(strchr(*s,'\n'))
            break;
        *L*=2;
        *s=(char*)realloc(*s,sizeof(char)**L);
    }
    if(begin==0){
        free(*s);
        return NULL;
    }
    return *s;
}
    
int main(void){
    int **matrix;
    size_t rows,*columns;
    FILE *in=fopen("1.txt","r");

    matrix= matrixget(in,&rows,&columns);
    
    if(matrix){
        pr(matrix,rows,columns);
    }
    else{
        printf("error=\n");
        return -1;
    //......... 
    } 		
    free(matrix);
    free(columns);
    fclose(in);
    return 0;
}
	
