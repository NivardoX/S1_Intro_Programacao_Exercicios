#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){


	int i,j;
	char lixo[1000];
	unsigned char temp;

	cout << "lendo imagem\n";

	for(i = 1; i < x; i++){
		for(j = 1; j < y; j++){
			
			fscanf(pgm, "%hhu ", &temp);
			M[i][j] = temp;

		}
	}

}

//fazer leitura com tipo int, pois ao encontrar o valor inteiro referente a '#', a linha eh pulada
