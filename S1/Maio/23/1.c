#include <stdio.h>

int main(){

	FILE *fp;
	
	fp = fopen("testPonteiros.txt", "w");

	if(fp == NULL){
		printf("o arquivo nao pode ser criado\n");
		exit(1);
	}

	return 0;
}
