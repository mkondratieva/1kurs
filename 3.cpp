#include<iostream>
#include<fstream>
#include<cstring>
#define N 111
struct Student{//новый тип данных, который объединяет статический массив (имя студента и номер группы)
	char name [N];size_t age;//имя не должно быть длиннее 111 букв
        Student(){}   
	Student (const char *name, int age){ //конструктор с параметром
        	strcpy(this->name,name);
        	this->age=age;
    }    
};  
struct Group{  //кдасс группа студентов
	Student **students; size_t len; //в нем хранится массив указателей на Student
	Group (size_t len){ //конструктор с параметром
		this->len=len;
		students=new Student*[len]; 
	}
	Group (){      //конструктор без параметра

		this->len=0;
		students=nullptr; 
	}
	void input(size_t len){  //??????????
		this->len=len;
		students=new Student*[len]; 
	}
	~Group(){  //деструктор
		delete []students;
	}	
};
std::ifstream &operator>>(std::ifstream &f,Student &l){//перегрузка оператора извлечь из потока (>>) студента
    char s[N];int a;
    f>>s>>a;
    if(f)l=Student(s,a);
    return f; 
}
std::ostream &operator<<(std::ostream &f,const Student &l){//перегрузка оператора  вставить в поток(<<) студента
            std::cout<<l.name<<"  " <<l.age<<"\n";
    return f; 
}
std::ostream &operator<<(std::ostream &f,const Group &l){//перегрузка оператора  вставить в поток(<<) группу студентов
	for(size_t i=0;i<l.len;i++)
            std::cout<<*l.students[i];
    return f; 
}
int main(){
    Student students[117]; //будем читать из файла данные студентов и сохранять их в массиве, в файле должно быть не более 117 записей о студентах
    std::ifstream in("input.txt");  
    size_t n=0;
    Student s; //вспомогательный студент
    while(in>>s){ //пока из файла извлекаются данные о студентах ! плохо здесь поставить условие while(in)
            students[n]=s;//отводим память под указатель на студента
            n++;
    }
    for(size_t i=0;i<n;i++)
            std::cout<<students[i];//печать данных всех записанных в файл студентов
    puts("_______________"); 
	Group grops[100]; //массив групп студентов, номер групп  которых равен индексу группы в массиве grops
	for (size_t i=0;i<100;i++) {
		size_t len=0;
		for (size_t j=0;j<n;j++) 
			if(students[j].age==i)
				len++; //узнали количество студентов в  группе номер i
		//grops[i]=Group(len); //так не работает. Почему?
		grops[i].input(len); //а так работает
//		grops[i].len=len;       //размер группы студентов равен len
//		grops[i].students=new Student*[len];//отводим память для массива студентов, обучающихся в группе номер i
		len=0;
		for (size_t j=0;j<n;j++)//еще раз ищем студентов группы i
			if(students[j].age==i)
				grops[i].students[len++]=students+j;//в массив группы кладем  адрес найденного студента
//заметим, что  адреса студентов  не в куче, а в стеке, т.к. students -- статический массив
//поэтому в деструкторе Group очистки только самого массива, а не его элементов
	}
		
	for (size_t i=0;i<100;i++)
		if(grops[i].len)
		std::cout<<"i="<<i<<"\n"<<grops[i];
/*	                 //как можно записать число в строку
	int m=88;
	char  str[11];
	sprintf(str,"%d",m);
	std::cout<<str;
*/
return 0;
}

