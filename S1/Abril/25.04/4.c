#include <stdio.h>
#include <string.h>

char string[101];
int n,i = 0;

void troca();

int main(){

	scanf("%s", string);
	n = strlen(string)-1;
	troca();
	
	return 0;
}


void troca(){
	char aux;
	if(i == n || i > n){
		printf("%s\n", string);
	}else{
		aux = string[i];
		string[i] = string[n];
		string[n] = aux;
		i++;
		n--;
		troca(i,n);
	}

	return;	
}
