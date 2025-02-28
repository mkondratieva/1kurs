#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

void words(const char *s,const char *q,char *word); //находит в s самое длинное слово, длиннее, чем worf
void words(const char *s,const char *q,char *word){
	int stat=0;// stat будет показывать, находится ли текущий символ вне или внутри слова равен длине слова
	while(1){
		if(strchr(q,*s)){//проверка, является ли символ разделителем
			if(stat>strlen(word)) //сюда попадем, если символ является разделителем и stat равен 1 (т.е. мы вышли из слова)
				strncpy(word, s-stat,stat); //увеличиваем счетчик количества слов
			stat=0; //флажок показывает, что мы вне слова
		}
		else //текущий символ не является разделителем, т.е. мы внутри слова
			stat++; //подсчет длины текущего слова
		if(*s==0) //если достигнут конец строки, завершаем цикл
			break;
		s++;//переходим к следующему слову
	}
	
}
int main(void){
	char str[111],*tmp,word[111],buf[111]; int pos;
	memset(word,0,111);
	while(fgets(str,111,stdin)){ //вводим с клавиатуры  строку и записываем ее в str 
	        words(str," \t\n",word);
        	printf("maxword=   ");
        	puts(word);
		tmp=str;
        	for(;sscanf(tmp,"%s%n",buf,&pos)==1;tmp+=pos) //находим все слова в строке str, sscanf (как и fscanf)извлекает данные из строки по указанному формату
//но в отличие от fscanf функция sscanf не обесспечивает изменение tmp. Чтобы извлечь все данные из str, tmp нужно изменять вручную, увеличивая на количество байт, затраченных на текущее извлечение
//аналогично можно извлечь все числа из строки (заменив формат %s на %d) !! нельзя писать for(int pos,tmp=str;sscanf(tmp,"%d%n",buf,&pos)==1;tmp+=pos), т.к. это означает, что tmp -целая !
			puts(buf); //печать слова
		puts("____________");
	}
	return 0;
}
