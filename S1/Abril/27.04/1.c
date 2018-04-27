#include <stdio.h>

long long int fib(long long int x);

long long int vtFib[10000];

int main(){
	
	long long int x;
	
	for(x = 0; x < 100; vtFib[x] = 0,x++){
	}
	
	while(1){
	
		printf("qual fib de ");
		scanf("%lli", &x);
		
		
		printf("é %lli\n", fib(x));
	}


	return 0;
}


long long int fib(long long int x){
	long long int i;

	if(vtFib[x-1] != 0){
		printf("%lli, memoria usada\n",x);
		return vtFib[x-1];
	}else{ 
		if(x <= 2){
			return 1;
		}else{
			vtFib[x-1] = fib(x-1) + fib(x-2);
			return vtFib[x-1];
		}
	}

	return x;
}
