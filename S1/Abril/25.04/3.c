#include <stdio.h>

int sum(int vt[10], int i, int f, int soma);

int vt[10] = {1,2,3,4,5,6,7,8,9,10};
int i;
int soma;

int main(){

	printf("O vetor eh ");
	
	for(i = 0; i < 10; i++){
		printf("%d ", vt[i]);	
	}printf("\n");

	printf("A soma de seus valores eh %d\n", sum(vt,0,10,0));

	return 0;
}


int sum(int vt[10], int inicio, int fim, int soma){	

	if(inicio == fim){
		return soma+vt[inicio];
	}else{
		sum(vt,inicio+1,fim,soma+vt[inicio]);
	}

	return;
}
