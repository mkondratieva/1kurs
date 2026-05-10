#include<iostream>
#include<fstream>
using namespace std;

class My{
	int x,y;
	public: 
	My(int x=0, int y=0){ 
        	this->x=x;
        	this->y=y;
    	} 
	friend ostream &operator<<(ostream &out,const My &point){
		out<<point.x<<" "<<point.y;
		return out;
	}
};
ifstream &operator>>(ifstream &f, My &point){ 
		int x=0,y=0;
		if(f>>x>>y)
			point=My(x,y);
		f >>std::ws; //извлечь из потока f пробельные символы
		return f;
}

int main(){
    My **arr=new My*[111]; // убрать 111
    std::ifstream in("1.txt");  
    if(!in){
	cout<<"nofile";
	return 0;
    }	
    size_t n=0;
    My point; 
    while(1){ 
	if(in.eof()||in.fail()) //если конец потока или возникла ошибка
		break;
        in>>point;  
        arr[n]=new My(point);
        n++;
    }
    if (in.fail()){ //если при чтении произошла ошибка
     	cout<<" err\n";
	return 0;
    }
    for(size_t i=0;i<n;i++)
            std::cout<<*arr[i]<<"\n";
    puts("_______________"); 
    for(size_t i=0;i<n;i++)
            delete arr[i];
	delete []arr;
     return 0;    
}

