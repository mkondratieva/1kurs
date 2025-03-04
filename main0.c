#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 4
void full(int (**) [N]);
void full(int (**p) [N]){ 
    *p=(int (*) [N])//malloc// код будет рабочим, если память отвести не в стеке, а в куче
		alloca(sizeof(**p));
    for(size_t i=0;i<N;i++)
        (**p)[i]=-i;
}
void foo(void);
void foo(void){puts("Ok");}
int main(void){
    int mass[]={0,1,2},(*p)[N]; //mass -- массив фиксированного размера, p -- указатель на массив типа int размера 3, *p -- массив
    p=NULL; 
    printf("%p  %p   %p\n",p,p+1,(int *)p+1);//вывод: 0,12,4. Нужно уметь объяснить вывод
    p=&mass;//В Си нельзя присваивать указатели на разные типы данных (кроме void*)
//mass и *p -- один и тот же массив, а не две копии одно (!нельзя *p=mass)
   /*   //если нужны 2 копии
    p=(int (*) [N])alloca(sizeof(*p));// отводим память (в стеке) для хранения одного элемента  типа *p (т.е. одного массива из 3-х целых)
    for(size_t i=0;i<N;i++)
        (*p)[i]=-i; //заполняем другими числами. Это рабочий вариант
    */          
    full(&p);//попробуем отвести память  и заполнить новый массив в  функции full
    foo(); //без вызова посторонней функции стек может не очиститься
    for(size_t i=0;i<N;i++)
        printf("%d %d\n",mass[i],(*p)[i]); //видим, что работает неверно
    puts("");
    return 0;
}
