#include <stdio.h>

long int fib(int x);

int main(){

	int n;
	
	while(1){	

		printf("Qual fib deseja ver?\n");
		scanf("%d", &n);

		printf("%d fib eh %li\n",n,fib(n));
		
	}

	return 0;
}



long int fib(int x){
	long int a,b,f,i;
	
	if(x <= 2){
		return 1;	
	}else {
		return fib(x-1) + fib(x-2);
	}


	return f;
}
