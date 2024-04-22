#include<iostream>
#include<fstream>
#include<cstring>
#define N 111
struct Student{//новый тип данных, который объединяет статический массив и его длину
	char name [N];size_t age;//имя не должно быть длиннее 111 букв
        Student(){}   
	Student (const char *name, int age){ //конструктор с параметром
        	strcpy(this->name,name);
        	this->age=age;
    }    
};    
std::ifstream &operator>>(std::ifstream &f,Student &l){ //перегрузка оператора извлечь из потока (>>) студента
    char s[N];int a;
    f>>s>>a;
    if(f)l=Student(s,a);
    return f; 
}
 
int main(){
    Student *a[117]; //будем читать из файла данные студентов и сохранять их в массиве указателей, в файле должно быть не более 117 записей о студентах
    std::ifstream in("1.txt");  
    size_t n=0;
    Student s; //вспомогательный студент
    while(in>>s){ //пока из файла извлекаются данные о студентах ! плохо здесь поставить условие while(in)
            a[n]=new Student;//отводим память под указатель на студента
            *a[n]=s;//копируем  студента s в объект, на которы указывает a[i]
            n++;
    }
    for(size_t i=0;i<n;i++)
            std::cout<<a[i]->name<<"  " <<a[i]->age<<"\n";//печать данных всех записанных в файл студентов
    puts("_______________"); //отсортируем студентов по возрасту
    for(size_t i=0;i<n;i++) //сортировка пузырьком
            for(size_t j=0;j<n-1;j++)
                if(a[j]->age>a[j+1]->age){
                    Student *tmp=a[j];a[j]=a[j+1];a[j+1]=tmp;
                 }
    for(size_t i=0;i<n;i++)
            std::cout<<a[i]->name<<"  " <<a[i]->age<<"\n";

    for(size_t i=0;i<n;i++)
            delete a[i];
     return 0;    
}

