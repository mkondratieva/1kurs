#include<stdio.h>  //Найти слово максимальной длины. В качестве разделителей взять пробелы и табуляции 
#include<stdlib.h>
#include<string.h>

int search(const char *SInputFile, char *word); // имя файла , результат

int main(void){
	char name[11]="1.txt",word[512];
	int err;
	word[0]=0;//кладем в word слово минимальной длины
//	scanf("%s",name); //запрашиваем имя файла
	err=search(name, word);
	if(err==-1)
		printf("Err\n");
	puts(word);
//добавить печать о возможном отсутствии слов в файле: программа всегда должна выводить понятный результат
	return 0;
}
int search(const char *SInputFile, char *word){
	FILE *in=fopen( SInputFile,"r"); char buf[512];
// //////.............ошибки открытия файла

        while(fscanf(in,"%s",buf)==1)//цикл перебобра слов
		if(strlen(buf)>strlen(word)) //если текущее слово длиннее word
			strcpy(word,buf); //записываем найденное слово в результат
	fclose(in);
	return 0;
}


	
