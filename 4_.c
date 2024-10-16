#include<stdio.h>
#include"4.h"

int task1213(FILE *in, int *res){
	int cur,n=0;
	*res=0;
	while(fscanf(in,"%d",&cur)==1){
		switch(cur){
			case 1:  
				if(n==2)
					n=3;
				else
					n=1;
				break;
			case 2:
				if(n==1||n==3)
					n=2;
				else
					n=0;
				break;
			case 3:
				if(n==3)
					n=4;
				else
					n=0;
				break;

			default: 
				n=0;
		}
		if(n==4){
			(*res)++;
			n=0;
		}
	}
	return 0;
}
