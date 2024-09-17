#include<stdio.h>  //(-1)^n, где n -- количество элементов, не  меньших предыдущего
int main(void){ 
	FILE *in=fopen("1.txt","r");
	int res=1,count=0,cur,prev,max;
	while(fscanf(in, "%d",&cur)==1){
		count+=1;
        	if(count>1 && prev<=cur)
	        	res=-res;
//        printf("result=%d prev=%d cur=%d count=%d\n",res,prev,cur,count);//
  	      	if(count==1 || cur>max)
                	max=cur;
        	prev=cur;
	}
	printf("result=%d  max=%d\n",res,max);
	fclose(in);
	return 0;
}
	
