#include<stdio.h>    //Количество элементов последовательности
int task(FILE *, int *);//возвращает код ошибки, *res -- ответ к задаче

int main(void){
	FILE *in=fopen("1.txt","r");
	int res,err=task(in,&res);// в функцию отправлляем адрес переменной res, тогда task сможет изменить ее значения
	if(err==0){
		printf("Not file\n");
		return -1;
	}
	fclose(in);
	if(err==1){
		printf("Bad file\n");
		return -1;
	}
	if(err==2){
		printf("Empty file");
		return -1;
	}
        if(err==3){//если код ошибки 3, печатаем результат (res)
			printf("result=%d\n",res);
	}
	return 0;
}
int task(FILE *in, int *count){
	int cur;//текущий элемент
	????///инициализация счетчика
	if(in==NULL) //файл не открылся
		return 0;
	while(fscanf(in,"%d", &cur)==1){
		//  ??????;
		}
	if(???)
		return 1;
	if (???)
		return 2;

	return  3;
}


		
