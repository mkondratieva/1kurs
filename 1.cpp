#include<iostream>
struct vec{     //новый тип данных vec, который объединяет массив и его длину
	int *row; size_t len;
	vec(){ //конструктор - метод класса, который вызывается при рождении объекта
        	len=rand()%11;  //этот конструктор отводит память под массив случайной длины и заполняет его случайными числами
        	row=new int[len];//метод класса получает (неявно) указатель на объект, для которого вызывается, т.е. ему не нужно передавать как параметры масссив и его длину
        	for(size_t i=0;i<len;i++)
            		row[i]=rand()%11;
    }
    ~vec(){//puts("destr");//деструктор -- метод, который вызывается в момент смерти объекта
       // std::cout<<"\ndestr ";
        //for(size_t i=0;i<len;i++)
          //  std::cout<<row[i]<<" ";
        delete []row;
    }
    void operator=(const vec &other){ //набросок перегрузки оператора присваивания
    	delete []row;//ранее отведенную под row память очищаем
    	len=other.len; //копируем длину массива
    	row =new int [len];//снова отводим память (если длина массива справа от = больше, чем старое len, ранее выделенной под row памяти недостаточно для  работы оператора присваивания
    	for(size_t i=0;i<len;i++)
        	row[i]=other.row[i];//копируем массив
    }
    int operator[](size_t );//перегрузка оператора []
    void del(size_t);//метод, которы удаляет координату вектора по индексу
};
int vec::operator[](size_t i){// теперь корректно для объектов класса vec применять квадратные скобки
    return row[i];
}
 void vec::del(size_t k){
     if(k>=len)
         return;
     len--;
     for(size_t i=k;i<len;i++)
         row[i]=row[i+1];
 }
void g(int &k){ //передача параметра по сссылке
    k++;
}
int main(){
    int x=0;g(x);std::cout<<x<<"\n";
    //return 0;    
    srand(time(nullptr));
    vec *v=new vec;
    if(v->len)
        std::cout<<(*v)[0]<<"\n";
    delete v;  //очистка памяти, отведенной для v и вызов деструктора
    //return 0;
    
    size_t n=7;
    vec matrix[7]; //создали (статический) массив из 7 объектов класса vec, этот массив можно  рассматривать как кривую матрицу целых чисел
    for(size_t k=0;k<7;k++){
         for(size_t i=0;i<matrix[k].len;i++)//matrix[k] -- это k-й элемент массива объектов vec,  доступ к полю объекта осуществляется через точку, т.е. matrix[k].len -- это длина массива , который хранится в объекте matrix[k]
        std::cout<<matrix[k][i]<<" "; //перегрузка оператора [] позволяет доступаться к элементам матрицы через двойные квадратные скобки
        puts("");
    }
    size_t a=rand()%5;
    std::cout<<"a="<<a<<"\n";
    for(size_t k=0;k<7;k++){
        matrix[k].del(a);
    }
    puts("____");
    for(size_t k=0;k<7;k++){
         for(size_t i=0;i<matrix[k].len;i++)
        std::cout<<matrix[k][i]<<" ";
        puts("");
    } {     //циклический сдвиг строк матрицы на 1 позицию вверх
    vec tmp; 
    tmp=matrix[0];//необходима перегрузка оператора =, его версия по умолчанию (побайтовое копирование) для сложного класса даст некорректный код
    for(size_t i=0;i<n-1;i++)
        matrix[i]=matrix[i+1];
    //matrix[0]=matrix[n-1];
    matrix[n-1]=tmp; }
    puts("____");
    for(size_t k=0;k<7;k++){
         for(size_t i=0;i<matrix[k].len;i++)
        std::cout<<matrix[k][i]<<" ";
        puts("");
    }
    return 0;
    
}

