#include<iostream>
#include<ctime>
void foo(int &x){ //ссыдка вместо указателя
	x++;
}
int&  foo1(int &x){//можно вернуть ссылку на аргумент (но не локальный объект)
	return ++x;
}

class vec{ 
    int *row; size_t len; 
    public: 
    vec(){ 
        len=rand()%11+1;
        row=new int [len];
        for(size_t i=0;i<len;i++)
            row[i]=rand()%5; 
    }
    ~vec(){ 
        delete []row;
    }
    void pr(){
        for(size_t i=0;i<len;i++)
            std::cout<<row[i]<<" ";
        puts("");
    }
    int &operator[](size_t i){ 
        return row[i];
    }
    size_t &Len(){
	return len;
     }
    void operator=(const vec&other){ //вариант перегрузки оператора присваивания
	if(len<other.len){
		delete []row;
		row=new int[other.len];
	}
	len=other.len;
	for(size_t i=0;i<len;i++)
		row[i]=other.row[i];
    }	
};
int main(){
	int x=0,&ref=x; //ref -- ссылка, ее необходимо инициализировать
	int  y=11; ref=y;ref++;//ref по-прежнему ссылается на х
	std::cout<<x<<" "<<ref<<" "<<y<<"\n";
	int z=0;int &z1=foo1(z);//z1 -- ссылка на z 
	z1++; std::cout<<z<<" "<<z1<<"\n";

        srand(time(nullptr));
	size_t n=5;
	vec *matrix=new vec[n];//кривой двумерный массив
	for(size_t i=0;i<n;i++)
		matrix[i].pr();
	for(size_t i=0;i<n;i++)
		if( matrix[i].Len()>7) //обрезка строк матрицы по длине  7
		    matrix[i].Len()=7;
	puts("new matrix");
	for(size_t i=0;i<n;i++)
		matrix[i].pr();
	size_t left=0,right=0;//удаление строк длины более 5
	for(;right<n;right++) { //метод двух бегунков
		if(matrix[right].Len()<=5){
			matrix[left]=matrix[right];//без перегрузки оператора - в классе vec будет работать, но некорректно
			left++;
		}
	}
	n=left;
	puts("new matrix");
	for(size_t i=0;i<n;i++)
		matrix[i].pr();

	delete []matrix;
    return 0;
}
