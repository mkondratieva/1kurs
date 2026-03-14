#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void words(char *,const char *); //удалить все слова в строке s, оставить только символы-разделители из sep
void words(char *s,const char *sep){
	char *left=s,*right=s; 
	for(;*right;right++){
		if(strchr(sep,*right)){
			*left=*right; left++;
		}
	}
	*left=0;
}
int main(void){
{
        char  s[]="   yy   yriiew   ytrtrtyrfy4";
	puts(s);
	words(s,"w y4");//удаление из строки слов согласно разделитеям  "w y4"
	puts(s);
	puts("_____________");
}
{       FILE *in=fopen("1.txt","r");
	char buf[512];
	while(fscanf(in, "%s",buf)==1){  
		puts(buf); //печать всех слов из файла (разделители -- пробельные символы)
	}
	puts("_____________");
	fclose(in);
}
{       FILE *in=fopen("1.txt","r");
	char buf[512],sep[]=" \t\n";
	while(fgets(buf,512,in)){  
		puts("words:");
		for(char *tmp=strtok(buf,sep);tmp;tmp=strtok(NULL,sep))//печать слов из строки файла
			puts(tmp);
	}
	fclose(in);
	puts("_____________");
}
{       FILE *in=fopen("1.txt","r");
	char buf[111];
	while(fgets(buf,512,in)){  
		int pos; char *tmp=buf, word[512];
		puts("words:");
		for(;sscanf(tmp,"%s%n",word,&pos)==1;tmp+=pos)//печать слов из строки файла (разделители -- пробельные символы)
			puts(word);

	}
	fclose(in);
}
	return 0;
}
