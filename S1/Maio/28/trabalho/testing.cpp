#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ABSURDOMEUDEUS 1000000

	
using namespace std;

FILE *pgm;
FILE *newPgm;

unsigned char** criarMatriz(int x,int y);
unsigned char** lerImagem(unsigned char **M,int x,int y);
void bordear(unsigned char **M,int x,int y);
unsigned char pos(unsigned char **M,int x,int y);
void criarArquivoBorda(unsigned char **M, int x, int y, int scale);


int main(int argc, char *argv[]){

	int i,j;
	int x,y;
	
	unsigned char **M;

	cout << "inicio de main\n" ;

	char pgmNome[30];
	int scale, element,limite;
	//cout << "Digite o nome do arquivo : \n";
	//scanf("%s", pgmNome);

	pgm = fopen(argv[1], "r");
	if(pgm == NULL){
		cout << "Arquivo invalido\n";
		exit(1);
	}

	cout << "arquivo aberto\n";

	char lixo[1000];
	unsigned char c;
	fgets(lixo,ABSURDOMEUDEUS,pgm);
	y = -1;
	x = -1;
	scale = -1;
	while(scale <= 0 ){
		printf("loop do while\n");	
		fscanf(pgm, "%c",&c);
		if(c == '#'){
			fgets(lixo,ABSURDOMEUDEUS,pgm);
			printf("printf # encontrado\n");
		}else if(c != '#'){
			if(y == -1){
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &y);
				printf("y definido como %d\n",y);
			}else if(x == -1){
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &x);	
				printf("x definido\n");	
			}else if(scale == -1){	
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &scale);
				printf("x definido\n");
			}
		}	
	}

	cout << "header lido\n";
	printf("y = %d, x = %d, scale = %d\n", y,x,scale);


	M = criarMatriz(x+2, y+2);
	bordear(M,x,y);			
	lerImagem(M,x+1,y+1);
	criarArquivoBorda(M,x+2,y+2, scale);

	///////////////////////////////////////////////////////////////////////////////////
	//teste matriz
	//
/*	for(i = 1 ; i < x+1; i++){
		cout << "teste matriz 1\n";
		for(j = 1; j < y+1; j++){
			M[i][j] = 'Z';
		}
		
	}
*/
/*
	for(i = 0; i < x+2; i++){
		//cout << "teste matriz 2\n";
		for(j = 0; j < y+2; j++){
			printf("%d\t",M[i][j]);
		}
		cout << endl;
	}
	//
	//
	////////////////////////////////////////////////////////////////////////////////////
*/
	fclose(pgm);

	return 0;
}


unsigned char** criarMatriz(int x, int y){
	unsigned char **temp;

	cout << "criando ini\n";

	temp = (unsigned char**)malloc(x* sizeof(char*));
	
	int i;

	for(i = 0; i < x; i++){
		temp[i] = (unsigned char*)malloc(y*sizeof(char));
	}

	cout << "criando fim\n";
	
	return temp;
}


void bordear(unsigned char **M, int x, int y){

	int i;

	cout << "borda ini\n";

	for(i = 0; i <= y+1;i++){
		M[0][i] = 255;
		M[x+1][i] = 255;
	}

	cout << "borda meio\n";

	for(i = 0; i <= x+1;i++){
		M[i][0] = 255;
		M[i][y+1] = 255;
	}
	
	cout << " borda fim\n";

}


unsigned char** lerImagem(unsigned char **M, int x, int y){

	int i,j;
	char lixo[1000];
	unsigned char temp;

	cout << "lendo imagem\n";
	
	for(i = 1; i < x; i++){
		for(j = 1; j < y; j++){

			fscanf(pgm, "%hhu", &temp);
			if(temp == '#'){
			//if(temp == '#'){
				fgets(lixo, ABSURDOMEUDEUS, pgm);
				j--;
			}else if(temp == ' '|| temp == '\n'){
						j--;
			}else{
				M[i][j] = temp;	
			}		
		}
	}
	
	cout << "lendo fim\n";

	return M;
}



void criarArquivoBorda(unsigned char **M, int x, int y, int scale){

	int i,j;
	

	newPgm = fopen("bordas.pgm", "w");

	if(newPgm == NULL){
		cout << "impossivel criar arquivo\n";
		exit(1);
	}

	fprintf(newPgm,"P2\n");
	fprintf(newPgm,"%d %d\n", y, x);
	fprintf(newPgm,"%d\n", scale);

	printf("X = %d e Y = %d na funcao de escrever\n",x,y );
	for(i = 0; i < x ; i++){
		for(j = 0; j < y ; j++){
			if(j%12 == 0)
				fprintf(newPgm,"\n");
			fprintf(newPgm,"%.3hhu ", M[i][j]);
		}
		
	}
	fclose(newPgm);
	cout << "arquivo criado com sucesso\n";
}