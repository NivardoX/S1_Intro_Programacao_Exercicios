#include <stdio.h>

void fib(int x);

int main(){

	int n;
	
	while(1){	

		printf("Quantos numeros da serie de fibonacci deseja ver?\n");
		scanf("%d", &n);

		fib(n);
	}

	return 0;
}



void fib(int x){
	long int a,b,f,i;
	
	if(x <= 2){
		printf("\n");
		while(x--){
			printf("1\n");
		}	
	}else {
		printf("\n1\n1\n");
		a = 1;
		b = 1;		
		for(i = 0; i < x; i++){
			f = a + b;
			b = a;			
			a = f;
			printf("%li\n", f);					
		}

	}


	return;
}
