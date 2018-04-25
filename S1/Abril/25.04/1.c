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
		a = 1;
		b = 1;		
		for(i = 2; i < x; i++){
			f = a + b;
			b = a;			
			a = f;					
		}

	}


	return f;
}
