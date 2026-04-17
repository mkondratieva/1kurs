#include<iostream>
#include<time.h>
#define N 111
class vec{ 
	int row[N]; size_t len;
	public:
	vec(){}
	vec(size_t len){
		this->len=len;
		for(size_t i=0;i<len;i++)
			row[i]=rand()%4;
	}
	int operator[](size_t)const;
	void del(int k){ 
		size_t left=0;
		for(size_t right=0; right<len;right++)
		if(row[right]!=k)
			row[left++]=row[right];
		len=left;
	}
	void friend pr_matrix(const vec *matrix, size_t n){
        	for(size_t i=0;i<n;i++) {
	        	for(size_t j=0;j<matrix[i].len;j++)
				std::cout<<matrix[i][j]<<" ";
			puts("");  
		}
	}
	friend void del_rows(vec *matrix, size_t &n){
		size_t left=0;
		for(size_t right=0; right<n;right++)
			if(matrix[right].len>3)
				matrix[left++]=matrix[right];
		n=left;
	}
};
int vec::operator[](size_t i)const {
	return row[i];
}
int main(){
	srand(time(nullptr));
	size_t n=rand()%11;
	vec *matrix=new vec [n];
	for(size_t i=0;i<n;i++)
		matrix[i]=vec(rand()%11);
  	pr_matrix(matrix,n);
        for(size_t i=0;i<n;i++)
		matrix[i].del(3);
	puts("res");
  	pr_matrix(matrix,n);
	del_rows(matrix, n);
	puts("res1");
  	pr_matrix(matrix,n);
	delete []matrix;
	return 0;
}

