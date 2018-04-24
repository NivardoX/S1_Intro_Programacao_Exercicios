#include <stdio.h>

long double fat(long double x);
long double calc(long double x);

int main(){
	
	while(1){
		long double n;
		
		printf("Digite o valor N a ser calculado!\n");
		scanf("%Lf",&n);

		n = calc(n);
		
		printf("E de N = %Lf\n", n);
	}
	return 0;
}



long double fat(long double x){
	long double f = 1;

	while(x > 0){
		f *= x;
		x--;
	}	

	return f;
}

long double calc(long double x){

	long double e = 2;
	long double i;
	
	for(i = 1; i <= x;i++){
		e += i/(i+fat(i+1));
	}

	return e;
}
