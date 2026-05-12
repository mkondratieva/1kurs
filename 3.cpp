#include<iostream>
#include<fstream>

using namespace std;
struct Student{
	string name ;size_t group; //класс простой
        Student(){} //без конструктора без параметров не получится создать массив объектов этого класса
	Student (string name, int group){ 
        	this->name=name;
        	this->group=group;
    }    
};    
struct Group{
	Student **students;size_t len; //класс сложный, но с ограниченными возможностями (написан для конкретной задачи)
	Group(){students=nullptr;len=0;}   
	void input(size_t len){//работает, как конструктор 
	       	this->students=new Student*[len];; 
       		this->len=len;   
   	} 
	~Group(){
		delete []students;
	}
	Group(size_t len){ //конструктор с параметром, не нужен, если используте input
		students=new Student*[len];this->len=len;
	}  
	//Group& operator=(Group &&o){students=o.students;len=o.len;o.students=nullptr;return *this;}
//перегрузка = для анонимных объектов, необходима, если не использовать input
};    
std::ifstream &operator>>(std::ifstream &f,Student &l){ 
    string s;size_t a;
    f>>s>>a;
    if(f)
	l=Student(s,a);
    return f; 
}
std::ostream &operator<<(std::ostream &f,const Student &l){ 
    f<<l.name<<" "<<l.group<<"\n";
    return f; 
}
std::ostream &operator<<(std::ostream &f,const Group &l){ 
        for(size_t i=0;i<l.len;i++)
		f<<*l.students[i];
    return f; 
}
int main(){
	size_t n=0;
        ifstream in("input.txt");  
	Student students[111],s; //массив объектов (структур)
        while(in>>s){
		students[n++]=s;//заполнение элементов массива данным конкретных студентов
	}
 	for(size_t i=0;i<n;i++)
		cout<<students[i];
	Group groups[100]; //массив объектов (групп студентов)
	for(size_t i=0;i<100;i++){
		size_t len=0;;//ищем количество студентов в группн t
		for(size_t j=0;j<n;j++)  
			if(students[j].group==i)
				len++;
		if(len>0){ //если группа непустая
			//groups[i]=Group(len);// здесь парисваивание! Справа от = стоит анонимный объект. Такой вариант будет работать, только если в Goup перегрузить =
                        groups[i].input(len);//этот вариант работает без перегрузки = и вызова конструкторас параметром. Зная len, можем отвести память под массив students внутри оъекта group[i]
			len=0; //заполняем  массив group[i].students данными студентов из группы с номером i
			for(size_t j=0;j<n;j++)  
				if(students[j].group==i)
					groups[i].students[len++]=students+j;//новых отведений памяти под данные студента students[j]  нет, т.к. в массив group[i].students кладем адремс студента
		}
	}
	puts("______");
	for(size_t i=0;i<100;i++)
		if(groups[i].len){ //для непустых групп
			ofstream f(to_string(i)+".txt"); //открываем на записть текстовый файл с именем = номеру группы
			f<<groups[i];
        		cout<<groups[i]<<"\n"; 
	}
	return 0;
}

