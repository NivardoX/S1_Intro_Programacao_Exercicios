#include <stdio.h>

int mdc(int *a,int *b);

int main(){

	int a, b;

	while(1){	

		printf("Digite os valores >> ");

		scanf("%d %d", &a,&b);
		
		printf("\n%d %d\n", a,b);

		printf("o mdc eh : %d\n",mdc(&a,&b) );

	}

	return 0;
}


int mdc(int *a, int *b){

	if(*a == *b)
		return *a;
	else if(*a > *b){
		*a = *a - *b;
		return mdc(a,b);
	}else{
		*b = *b - *a;
		return mdc(a,b);
	}
}
