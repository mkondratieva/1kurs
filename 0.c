#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct vec{ int *mass; size_t len;
};
typedef struct vec Vec;

void foo(Vec* );
void foo(Vec *f){
	f->len=7;f->mass=malloc(7*sizeof(int));
}
int main(void){ 
	size_t n=7,left=0,right=0;
	struct vec  *matrix=malloc( n*sizeof(matrix[0]));
	srand(time(0));
	for(size_t i=0;i<n;i++) {
		matrix[i].len=rand()%11;
		matrix[i].mass=malloc(matrix[i].len*sizeof(int));
	}
        for(size_t i=0;i<n;i++)
	for(size_t j=0; j<matrix[i].len;j++)
		matrix[i].mass[j]=rand()%11;
        for(size_t i=0;i<n;i++) {
	        for(size_t j=0;j<matrix[i].len;j++)
			printf("%d ",matrix[i].mass[j]);
		puts("");  
	}
        for(right=0;right<n;right++)
		if(matrix[right].len>5) {
			if(left!=right){
				free(matrix[left].mass);
				matrix[left]=matrix[right]; 
				matrix[right].mass=NULL;

				
		}left++;
		}
	for(size_t i=left;i<n;i++)
		free(matrix[i].mass);
	n=left;
	puts("res=");
        for(size_t i=0;i<n;i++) {
	        for(size_t j=0;j<matrix[i].len;j++)
			printf("%d ",matrix[i].mass[j]);
		puts("");  
	}

	for(size_t i=0;i<n;i++)
		free(matrix[i].mass);
	free(matrix);
{

	Vec f; 
	foo(&f);
	free(f.mass);
}
	return 0;

}

