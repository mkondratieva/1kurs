#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 6 //количество строк, нужно убрать
#define swap(t, x, y)  { t temp = x; x = y; y = temp; } 
void pr(int **matrix, size_t *rows){ //печать матрицы, сюда нужно передавать ещеи  количество строк
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<rows[i];j++)
			printf("%d ",matrix[i][j]);  
		puts("");      
	}
}
void del_col(int **matrix, size_t *rows){ //удаление столбцов с четными индексами
	size_t right=0,left=0,max=0,i;
	for(i=0;i<M;i++)
		if(rows[i]>max)max=rows[i];
	for(;right<max;right++) 
		if(right%2){ 
			for(i=0;i<M;i++) 
				if(right<rows[i])
					matrix[i][left]=matrix[i][right];
				else if(left<rows[i])
					rows[i]=left;
			left++; 
		}
	for(i=0;i<M;i++) if(rows[i]>left)rows[i]=left; 
}
int main(void){ 
    {  //чтение из фпайла строки произвольной длины, из этого фрагмента требуется создать функцию mygets наподобии getline
//от 3 параметров (указатель на файл, char** --строка для чтения строки файла, size_t * -- размер отведенной (внутри функции) памяти)
//возвращать должна NULL, если достигнут конец файла, malloc и free на отведенную память должны быть внутри функции!
     FILE *in=fopen("1.txt","r");
     size_t L=1,begin=0; //L - количество отведенной памяти, begin -- позиция в строке s, в которую будет считываться лчередные L байтов из файла
     char *s=alloca(L);
     while(fgets(s+begin,L-begin,in)){ //заполнение строки s, начиная с позиции begin, символами из 1.txt, если встретится симвод '\n' или конец файла, ввод прекращается и записывается '\0' (иначе этот символ ставится после L-1 символа из файла)
         if(strchr(s,'\n')){ //если в s есть '\n', ввод строки щакончке
                puts(s);begin=0; //печатаем извлеченную строку и переходим к следующей (которую будем читать в начало s)
        }
        else{ //иначе вся отведенная память закончилась и нужно отводить новую, здесь можно использовать reallooc
            char *tmp;begin=L-1; L*=2;  //tmp -- расширенная до 2L строка, begin -- позиция в s, в которую будем записывать сдедующие символы из строки файла
            tmp=alloca(L); //заменить на malloc
            memcpy(tmp,s,L/2);//копируем старые данные по новому адресу
            s=tmp;//обновление строки
       }
    }
    puts(s);//последняя строка файла может не иметь символа '\n', она сохранисать в s, но не была еще напечатана
    fclose(in);
     puts("_________");
    }
    {   //чтение из файла криволинейного массива, здесь нужно найти и исправить две опечатки
     FILE *in=fopen("1.txt","r");
     char buf[111];//нужно заменить динамическим массивом 
     int **matrix,*data=NULL; size_t *rows=NULL,Ldata=1,Lrows=1,s=0,j=0;
//data -- одномерный массив всех чисел файла,s -- их количество, rows -- массив длин матрицы, 
//j -- количество строк, Ldata, Lrows -- размеры отведенной под data и rows памяти
     while(fgets(buf,111,in)){ //fgets нужно заменить на mygets   
         char *tmp=buf; int pos,k; //переменные для sscanf, которая извлечет числа из buf
         if(j+1>=Lrows){ //количество строк матрицы должно увеличиться на 1, проверяем, достаточно ди отведенной ранее памяти
             Lrows*=2; rows=realloc(rows,Lrows*sizeof(*rows)); //если нет, запрашиваем новую и переносим туда старые данные для массива rows
         }
         rows[j]=0; //теперь памяти достаточно, rows[j] должно стать количеством чисес в buf
         for(;sscanf(tmp,"%d%n",&k,&pos)==1;tmp+=pos){ //пока возможно, извлекаем из buf число, чтобы записать его в массив data
	     if(s+1>Ldata){  // проверяем, достаточно ли отведенной для data памяти для записи числа k
        	     Ldata*=2;data=realloc(data,Ldata*sizeof(*data));
	     }
             data[s]=k;rows[j]++;s++;
	}
             j++; //переходим к следующей строке
     } 
     data=realloc(data, s*sizeof(*data)+j*sizeof(*matrix));//последний realloc для сокращения отведенной под data памяти + добавляем посде data место для j указателей на строки
//это и будет матрица, под которую память отведена единым куском
     for(size_t i=s-1;i+1>=1;s--)//нужно сместить элементы массива data в конец отведенной памяти
	       data[i+j*sizeof(*matrix)/sizeof(int)]=data[i];

      matrix=(int**)data;
     //далее нужно сделать разметку отведенной памяти. Она делаетсястандартно, см. следующий фрагмент этого кода
        
      pr(matrix,rows);	
      //здесь нужно протестировать,например, вызвать del_col
     fclose(in);
     puts("_________");
    }
	int **matrix=NULL; 
	size_t *rows=alloca(M*sizeof(*rows)),s=0;
	srand(time(NULL));
	for(size_t i=0;i<M;i++){rows[i]=rand()%11; s+=rows[i];}
	matrix=(int **)alloca(M*sizeof(*matrix)+s*sizeof(**matrix)); 
	matrix[0]=(int *)(matrix+M); 
	for(size_t i=1;i<M;i++)
		matrix[i]=matrix[i-1]+rows[i-1];
	for(size_t i=0;i<s;i++)
			matrix [0][i]=rand()%10; 
	pr(matrix,rows);	
	del_col(matrix,rows);
	puts("res");
	pr(matrix,rows);
	return 0;
} 
