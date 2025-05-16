#include<iostream>
#include<ctime>
#include<cstring>
class vec{ //объявление класса
   int *row; size_t len; //поля класса (приватные)
    public: //далее методы класса - публичные
    vec(){ //конструктор класса, вызывается при рождении объектов
        len=rand()%11+2; //длиа вектора
        row=new int [len];//сам вектор
        for(size_t i=0;i<len;i++)
            row[i]=rand()%5;  //заполняем случайными числами
    }
    ~vec(){ //деструктор класса, вызывается при смерти объекта
        delete []row;
    }
    void pr(){ //печать содержимого вектора
        for(size_t i=0;i<len;i++)
            std::cout<<row[i]<<" ";
        puts("");
    }
};
int main(){
       srand(time(nullptr));
       vec *matrix;
       size_t n=5;
       matrix=new vec[n];
       for(size_t i=0;i<n;i++)
           matrix[i].pr();
/*  //  1)
	vec buf=matrix[0];
	buf=matrix[0];
	matrix[0]=matrix[1];

*/

/*  //  2)
       vec buf]; 
       memcpy((void *)&matrix[0],&matrix[1],sizeof(vec));
       memcpy((void *)&matrix[1],(void *)&buf,sizeof(vec));
       buf.row=0;

*/
/*   //  3)
       vec buf=matrix[0]; 
       memcpy((void *)&matrix[0],&matrix[1],sizeof(vec));
       memcpy((void *)&matrix[1],(void *)&buf,sizeof(vec));
       buf.row=0;
*/

//4)

       char buf[sizeof(vec)];
       memcpy((void *)&buf,&matrix[0],sizeof(vec));
       memcpy((void *)&matrix[0],&matrix[1],sizeof(vec));
       memcpy((void *)&matrix[1],(void *)&buf,sizeof(vec));
       puts("______swap(matrix[0], matrix[1]___________");
       for(size_t i=0;i<n;i++)
           matrix[i].pr();
       
       
       delete[]matrix;
       return 0;
}
