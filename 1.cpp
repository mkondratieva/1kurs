#include<iostream>
#include<fstream>

class Student{//новый тип данных, который объединяет строку (имя студента) и целое число (возраст)
	std::string name;int age;
	public:  
	Student(){} //конструктор без параметра  
	Student(std::string &name, int age){ //конструктор с параметром
        	this->name=name;
        	this->age=age;
    	} 
	friend std::ostream &operator<<(std::ostream &,const Student &);
	friend void sort(Student**, size_t);//сортировка массива указателей по возрасту студентов
};    
std::ostream &operator<<(std::ostream &out,const Student &l){ //печать  данных одного студента
	out<<l.name<<" "<<l.age;
	return out;
}

std::ifstream &operator>>(std::ifstream &f,Student &l){ //перегрузка оператора извлечь из потока (>>) студента
    std::string s;int a;
    f>>s>>a;
    if(f)l=Student(s,a);
    return f; 
}
void sort(Student **students, size_t n){
   for(size_t i=0;i<n;i++) //сортировка пузырьком
            for(size_t j=0;j<n-1;j++)
                if(students[j]->age>students[j+1]->age){
                    std::swap(students[j],students[j+1]);
                }
}

int main(){
    Student *a[117]; //будем читать из файла данные студентов и сохранять их в массиве указателей, в файле должно быть не более 117 записей о студентах
    std::ifstream in("1.txt");  
    size_t n=0;
    Student s; //вспомогательный студент
    while(in>>s){ //пока из файла извлекаются данные о студентах ! плохо здесь поставить условие while(in)
            a[n]=new Student;//отводим память под указатель на студента
            *a[n]=s;//копируем  студента s в объект, на которы указывает a[i] через оператор =
            n++;
    }
    for(size_t i=0;i<n;i++)
            std::cout<<*a[i]<<"\n";//печать данных всех записанных в файл студентов
    puts("_______________"); //отсортируем студентов по возрасту
    sort(a,n);
    for(size_t i=0;i<n;i++)
            std::cout<<*a[i]<<"\n";
    for(size_t i=0;i<n;i++)
            delete a[i];
     return 0;    
}

