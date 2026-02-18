#include"1.h"
void full_matrix(int ** matrix){
	for(size_t i=0;i<M;i++)
		for(size_t j=0;j<N;j++)
			matrix [i][j]=i+j;
}
