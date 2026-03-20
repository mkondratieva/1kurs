#include<stdio.h>
//#include<string.h>
#include<stdlib.h>
#define M 6
#define swap(t, x, y)  { t temp = x; x = y; y = temp; } 
void pr(int **matrix, size_t *rows){
	for(size_t i=0;i<M;i++){
		for(size_t j=0;j<rows[i];j++)
			printf("%d ",matrix[i][j]);  
		puts("");      
	}
}
void del_rows(int **matrix, size_t *rows){ //2 бегунка для строк матрицы -- строки с нечетными индексами уплотняем к началу, с четными сохраняем после них (взаимный порядок строк с  с четными индексами может измениться, это сепарирование двумя бегунками
	size_t right=0,left=0;
	for(;right<M;right++)
		if(right%2){ 
		swap(int* ,matrix[right],matrix[left]);
		swap(size_t ,rows[right],rows[left]); left++;
	}
}
void del_col(int **matrix, size_t *rows){//удаляем столбцы с четными индексами двумя бегунками
	size_t right=0,left=0,max=0,i;
	for(i=0;i<M;i++)
		if(rows[i]>max)max=rows[i];//находим максимальную длину строки
	for(;right<max;right++) //перебор столбцов
		if(right%2){ //если индеск столбца нечетный, для его сохранения:
			for(i=0;i<M;i++) //перебираем строке, т.к. два бегунка должны работать в  каждой строке
			//нужно скопировать matrix[i][right] в matrix[i][left], и т.к. матрица кривая, возможны два случая:
				if(right<rows[i])//1) элемент matrix[i][right] существует (не дырка)
					matrix[i][left]=matrix[i][right]; //т.к left<=right, в столбце left в i строке нет дырки
				else if(left<rows[i])//2) в i строке d столбце right дырка, тогда ее надо скопировать в столбец left	
					rows[i]=left;//если в left дырки не было, обрезаем строку i до длины left
			left++; //после выполнения копирования в каждой строке увеличиваем left
		}
	for(i=0;i<M;i++) if(rows[i]>left)rows[i]=left; //после того, как бегунки закончили работу, обрезаем строки, длины которых больше left
}
int main(void){ 
	int **matrix=NULL; //построим криволинейный двумерный массив со случайными размерами строк и заполним случайными числами
	size_t *rows=alloca(M*sizeof(*rows)),s=0;//нам нужен массив длин строк
	srand(time(NULL));
	for(size_t i=0;i<M;i++){rows[i]=rand()%11; s+=rows[i];}//заполняем его и подсчитываем количество чисел в матрице
	matrix=(int **)alloca(M*sizeof(*matrix)+s*sizeof(**matrix)); //отводим место для матрицы единым куском
	matrix[0]=(int *)(matrix+M); //разметка памяти
	for(size_t i=1;i<M;i++)
		matrix[i]=matrix[i-1]+rows[i-1];//разметка памяти 
	for(size_t i=0;i<s;i++)
			matrix [0][i]=rand()%10; //заполнение массива (попутно видим, что  строки расположены одна за другой
	pr(matrix,rows);	
//	del_rows(matrix,rows);
	del_col(matrix,rows);
	puts("res");
	pr(matrix,rows);
	return 0;
} 
