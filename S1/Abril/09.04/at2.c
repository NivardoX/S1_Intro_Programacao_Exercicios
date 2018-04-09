#include<stdio.h>
int main(){
	int i, j, soma = 0, count = 0;
	for(i=0;i<=100;i++, count = 0){
		for(j=i;j>0;j--){
			if(i%j == 0){
				count++;
			}
		}
		if(count < 3){
			soma = soma + i;
		}
	}
	printf("A soma de todos os primos entre 0 e 100 vale: %d\n", soma);	
	return 0;
}
