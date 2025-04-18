#include<iostream>
#include<ctime>
class my{
	int x=rand() ;
	public: 
	double method(const double &y){return x+y;}
	double operator+(const double &y)const &{
		return x+y;
	}
	friend double operator +(const double &, const  my &);
};
double operator +(const double &y, const  my &obj){ 
	return obj+y;
}

int main(){
srand(time(0));
	my z; 
std::cout<<my().method(0.1)<<"   "<<my()+-0.1<<"  "<<0.7+my();
	return 0;
}
