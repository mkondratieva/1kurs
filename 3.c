#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define N 111
int words(char *, const char *); //подсчет количества слов 
int words(char *s, const char *sep){//s - строка,в которой будем выделять слова, sep - строка разделителей
    int count=0,stat =0;//stat будет показывать, находимся мы при проходе по строке внутри слова или вне
    for(;;s++){ //бесконечный цикл перебора символов в строке
        if(strchr(sep,*s)){ //если символ является разделителем
            if(stat) //если были внутри слова, оно закончилось
                count++;//увеличиваем счетчик количества слов
            stat=0;//для разделителя stat=0
        }
        else //находимся внутри слова
            stat=1; //внутри слова stat=1
        if(*s=='\0') //выход из цикла, если текущий символ является концом строки, при этом последнее слово не потеряно
            break;
    }
    return count;
}
void seach(char *);
void seach(char *s){ //вывод символов внутри "...",  остальные символы игнорируются
    char word[N];//нет проверки, что       количество " в строке четно.
        for(char *begin=strchr(s,'\"'),*end;begin;begin=strchr(end+1,'\"')){ //begin указывает на отрывающую кавычку
            end=strchr(begin+1,'\"');//end на закрывающую
            memset(word,0,N);//обнулили все символы, чтобы не выставлять конец строки, лучше так не делать
            strncpy(word,begin+1,end-begin-1);//скопировали символы между двумя кавычками в word,  strncpy не выставит конец строки, но мы перед копированием обнулили все символы
            puts(word);//печать слова и переход к следующей открывающей кавычке (приращение в for)
        }
    }
int main(void){
    char str[N]="\"33331\"23333\"664trtyryurty56\"",sep[]="36";//строка и набор разделителей
    puts(str);puts("___________________________");
    printf("count_words=%d\n____________________\n",words(str,sep));
    seach(str);//вывод "слов" ,  когда под словом понимается набор символов между кавычками
    puts("_________________________");
    for(char *buf=strtok(str,sep);buf;buf=strtok(NULL,sep))
        puts(buf);//вывод слов с использованием strtok
    return 0;
}
