#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fp;
	char ch;
	
	fp = fopen("testPonteiros.txt", "r");

	do{
		ch = getc(fp);
		printf("%c", ch);
		
	}while(ch != EOF);
	
	if(fp == NULL){
		printf("o arquivo nao pode ser criado\n");
		exit(1);
	}
	printf("\n");

	fclose(fp);
	return 0;
}
