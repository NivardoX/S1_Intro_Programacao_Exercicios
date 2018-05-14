#include <stdio.h>
#include <stdlib.h>

int mdcRecursao(long long int a,long long int b){
	if(a == b){
		return a;
	}else if(a > b){
		a = a - b;
		mdcRecursao(a,b);		
	}else{
		b = b -a;	
		mdcRecursao(a,b);	
	}
}

int main(int argc, char **argv){
	long long int i,j;
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	
	printf("%d\n",mdcRecursao(i,j));
	
	return 0;
}
	
	
