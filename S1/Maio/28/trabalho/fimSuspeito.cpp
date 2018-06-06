#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ABSURDOMEUDEUS 1000000

	
using namespace std;

FILE *pgm;
FILE *newPgm;
int janela;
short int laplace[3][3] = {{0, -1, 0},
                              {-1, 4, -1},
                              {0, -1, 0}};

unsigned char** criarMatriz(int x,int y);
unsigned char** lerImagem(unsigned char **M,int x,int y);
void criarArquivoBorda(unsigned char **M, int x, int y, int scale);
unsigned char** filtro(unsigned char **original, int x, int y, int jan);
int Bordar(int i, int j, short int laplace[][3], unsigned char **pgm);


int main(){

	int i,j;
	int x,y;
	
	unsigned char **M;

	cout << "inicio de main\n" ;

    char pgmSaida[30];
	char pgmNome[30];
	int scale, element,limite;
	
	printf("Digite o nome do arquivo.\n");
    scanf("%s", pgmNome);
    strcat(pgmNome,".pgm");
    printf("Digite o nome do arquivo de saída.\n");
    scanf("%s", pgmSaida);
    strcat(pgmSaida,".pgm");
	
	
	printf("Digite o tamanho da janela.\n");
	scanf("%d",&janela);
    
    if(janela <= 1 || janela%2 == 0){
        printf("A janela dever um número ímpar maior que 1.\n");
        return main();
        
    }

	pgm = fopen(pgmNome, "r");
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
	    
	    char k;
		k = fgetc(pgm);
        
        if( k == '#'){
            j--;
            fgets(lixo,ABSURDOMEUDEUS,pgm);
            continue;	
        }     
        
        fseek(pgm,-1,SEEK_CUR);
		
        fscanf(pgm, "%c",&c);
        
		
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

	cout << "header lido\n";
	printf("y = %d, x = %d, scale = %d\n", y,x,scale);

    int temp = (janela/2)*2;

	M = criarMatriz(x+temp, y+temp);
	lerImagem(M,x+1,y+1);
    M = filtro(M,x,y,janela);
	criarArquivoBorda(M,x,y, scale);

	fclose(pgm);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //funcao free

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



unsigned char** lerImagem(unsigned char **M, int x, int y){

	int i,j;
	char lixo[1000];
	unsigned char temp;

	cout << "lendo imagem\n";
	
	for(i = janela/2; i < x + janela/2 - 1; i++){
		for(j = janela/2; j < y + janela/2 - 1; j++){
	        char k;
	        
	        k = fgetc(pgm);
	        if( k == '#'){
	            j--;
	            fgets(lixo,ABSURDOMEUDEUS,pgm);
	            continue;	
            }
            fseek(pgm,-1,SEEK_CUR);
		    fscanf(pgm, "%hhu ", &temp);
			M[i][j] = temp;	
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

	for(i = janela/2; i < x+janela/2 ; i++){
		for(j = janela/2; j < y+janela/2 ; j++){
			fprintf(newPgm,"%d ", M[i][j]);
		}
		fprintf(newPgm,"\n");
	}
	fclose(newPgm);
	cout << "arquivo criado com sucesso\n";
}

unsigned char** filtro(unsigned char **original, int x, int y, int jan){

    int aux = jan/2;
            
    unsigned char** M = criarMatriz(x + 2*aux, y + 2*aux);
	for(int i = 0; i < x + 2*aux; i++){
    	for(int j = 0; j < y + 2*aux; j++){
    		M[i][j] = 0;
    	}
    }
    for(int i = aux; i < x + 1; i++){
    	for(int j = aux; j < y + 1; j++){
    		M[i][j] = original[i][j];
    	}
    }

	int soma = 0;
	for(int linha = aux; linha < x + 1; linha++){
		for(int coluna = aux; coluna < y + 1; coluna++){
			for(int i = linha - aux; i < linha + aux + 1; i++){
				for(int j = coluna - aux; j < coluna + aux + 1; j++){
					soma += M[i][j];

				}
			}
			M[linha][coluna] = soma / (jan*jan);
			soma = 0;
		}
	}
	return M;
}

int Bordar(int i, int j, short int laplace[][3], unsigned char **pgm){
    int p, q, temp;
    int element = 0;
    i = i - 1;
    j = j - 1;
    temp = j;
    while(p < 3){
        while(q < 3){
            element += pgm[i][j] * laplace[p][q];
            j++;
        }
	p++;
        j = temp;
        i++;
    }
    return element;
}
