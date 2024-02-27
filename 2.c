#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define N 111

int main(void){
    char c='0',str[N]="123456",word[N],*buf=str;
    printf("%c %d  %d strlen=%d\n",c,c,isprint(c),(int)strlen(str));//код цифры 0 равен 48, не     является (yt hfdty 0) кодом буквы, в длине строки не учитывается ее конец (символ с кодом '\0')
    str[3]=0;//обрезали строку до символа 3
    strcat(str,str+ 5);//склейка частей одной строки
    puts(str);//вывод 1236, склейка корректная, strcat(str,str+4) некорректна, т.к.  пересекаются источник и приемник (по индексу  5 в массиве str)
    printf("strncmp=%d stncmp=%d\n",strncmp("10","1",1), strcmp("10","1"));    
    printf("%s\n",strchr(str,'3'));//поиск символа в строке. Возвращает 0, если символ не найден, иначе указатель на первый найденный символ
    //fscanf(stdin,"%s",str);  //ввод с клавитуры слова
    fgets(str,N,stdin); //ввод строки с клавиатуры, строка может содержать пробелы и табуляции
    puts(str); //печать строки на экран
    sscanf(buf,"%s",word); sscanf(buf,"%s",word);//выделение первого слова, нет смещения по строке для извлечения остальных слов
    puts(word);
    for(int pos;sscanf(buf,"%s%n",word,&pos)==1;buf+=pos){//вывод всех слов, %n - формат для определения смещения по строке для извлечения следующего слова
            puts(word);
           //printf("pos= %d\n",pos);  //
    }
	return 0;
}
