#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int words(const char *s,const char *q); //������� ���������� ���� � ������ s �� ������ ������������ q
int words(const char *s,const char *q){
	int stat=0,count=0;// stat ����� ����������, ��������� �� ������� ������ ��� ��� ������ �����
	while(1){
		if(strchr(q,*s)){//��������, �������� �� ������ ������������
			if(stat) //���� �������, ���� ������ �������� ������������ � stat ����� 1 (�.�. �� ����� �� �����)
				count++; //����������� ������� ���������� ����
			stat=0; //������ ����������, ��� �� ��� �����
		}
		else //������� ������ �� �������� ������������, �.�. �� ������ �����
			stat=1;
		if(*s==0) //���� ��������� ����� ������, ��������� ����
			break;
		s++;//��������� � ���������� �����
	}
	return count;
}
int main(void){
	char str[111],*tmp;
	while(fgets(str,111,stdin)){ //������ � ����������  ������ � ���������� �� � str 
		printf("words=%d\n",words(str," \t\n"));
		tmp=strtok(str," \t\n");//�������� ������ �����, ��� ���� tmp ����� ��������� �� ��� ������, � ������ ����������� ����� ����� ����� ���������� �����
		while(tmp){ //����  ����� ������ ��������, tmp ����� ������ NULL
			puts(tmp);//������ ����������� �����
			tmp=strtok(NULL," \t\n"); //���� ��������� �����
		} 
	}
	return 0;
}
