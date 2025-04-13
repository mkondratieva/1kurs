#include<iostream>
#include<ctime>
#define N 11

class vec{ 
    int row[N]; size_t len;  //класс стал простым, не нужно отводить память в конструкторе, не нужен деструктор и перегрузка конструктора копии и оператора присваивания
    public: 
    vec(){ 
        len=rand()%N;
        for(size_t i=0;i<len;i++)
            row[i]=rand()%5; 
    }
    void pr()const &{  //в метод будет передаваться не указатель на объект, а const vec& ссылка
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
};

void foo(const vec &v){
	v.pr();
}
void foo1(vec v){
	v.pr();
}
int main(){
        srand(time(nullptr));
	vec v;
	//foo(v); //печать вектора по ссылке, при этом вектор не копируется
        foo1(v); // печать копии вектора, внутри foo1 создается объект-клон v
	const  vec  &ref=vec();  //безымянный объект, на него нельзя сделать ссылку vec &,  но можно const vec&,  это продлевает жизнь безымянного объекта
	//foo(ref); 
        foo1(ref);
        v=ref; //v изменился на vec()
	v.pr();
	puts("Matrix");

	size_t n=5;
	vec *matrix=new vec[n];
	for(size_t i=0;i<n;i++)
		matrix[i].pr();
	for(size_t i=0;i<n;i++)
		if( matrix[i].Len()>7) 
		    matrix[i].Len()=7;
	puts("new matrix");
	for(size_t i=0;i<n;i++)
		matrix[i].pr();
	size_t left=0,right=0;
	for(;right<n;right++) { 
		if(matrix[right].Len()<=5){
			matrix[left]=matrix[right];
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
