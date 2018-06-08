#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "funcoes.h"
#include "codigoYves.h"

<<<<<<< HEAD
using namespace std;

FILE *pgm;
FILE *newPgm;
int janela;

unsigned char** criarMatriz(int x, int y){
	unsigned char **temp;

	temp = (unsigned char**)malloc(x* sizeof(char*));
	
	int i;

	for(i = 0; i < x; i++){
		temp[i] = (unsigned char*)malloc(y*sizeof(char));
	}

	return temp;
}



unsigned char** lerImagem(unsigned char **M, int x, int y){

	int i,j;
	char lixo[1000];
	unsigned char temp;

	for(i = janela/2; i < x + janela/2 -1; i++){
		for(j = janela/2; j < y + janela/2 -1; j++){
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

	return M;
}
=======
>>>>>>> 427e4d593725b71ca6c2312cca3b4c11c19d1ebf

using namespace std;

int main(){

	int i,j;
	int x,y;
	
	unsigned char **M;

<<<<<<< HEAD
	newPgm = fopen(nome, "w");

	if(newPgm == NULL){
		cout << "impossivel criar arquivo\n";
		exit(1);
	}

	fprintf(newPgm,"P2\n");
	fprintf(newPgm,"%d %d\n", y, x);
	fprintf(newPgm,"%d\n", scale);

	int count = 1;
	for(i = janela/2; i < x+janela/2  ; i++){
		count = 1;
		for(j = janela/2; j < y+janela/2 ; j++,count++){
			
			fprintf(newPgm,"%.3d ", M[i][j]);
			if(count%10==0 && j > janela/2)
				fprintf(newPgm, " #Linha %d.\n", i - janela/2 +1);
		}
		fprintf(newPgm,"\n");
=======
    char pgmSaida[30];
	char pgmNome[30];
	int scale, element,limite;
	char op;
	
	//Entra com os valores necessarios.
	printf("Digite o nome do arquivo.\n");
    scanf("%s", pgmNome);
    strcat(pgmNome,".pgm");
    printf("Digite o nome do arquivo de saída.\n");
    scanf("%s", pgmSaida);
    strcat(pgmSaida,".pgm");
	printf("Voce quer Suavizar(S) ou convoluir(C).\n");
    setbuf(stdin,NULL);
    scanf("%c", &op);
    setbuf(stdin,NULL);


	if(op == 'S'){
    printf("Digite o tamanho da janela.\n");
		scanf("%d",&janela);
	}else if(op == 'C'){
		janela = 3;		
>>>>>>> 427e4d593725b71ca6c2312cca3b4c11c19d1ebf
	}
    
   //Verifica por casos impossiveis.
    if(janela <= 1 || janela%2 == 0){
        printf("A janela dever um número ímpar maior que 1.\n");
        setbuf(stdin,NULL);

<<<<<<< HEAD
    int aux = jan/2;
            
    unsigned char** M = criarMatriz(x + 2*aux, y + 2*aux);
	for(int i = 0; i < x + 2*aux; i++){
    	for(int j = 0; j < y + 2*aux; j++){
    		M[i][j] = 0;
    	}
    }
    for(int i = aux; i < x + aux; i++){
    	for(int j = aux; j < y + aux; j++){
    		M[i][j] = original[i][j];
    	}
    }

	int soma = 0;
	for(int linha = aux; linha < x + aux; linha++){
		for(int coluna = aux; coluna < y + aux; coluna++){
			for(int i = linha - aux; i < linha + aux + 1; i++){
				for(int j = coluna - aux; j < coluna + aux + 1; j++){
					soma += M[i][j];

				}
			}
			M[linha][coluna] = soma / (jan*jan);
			soma = 0;
		}
=======
        return main();

>>>>>>> 427e4d593725b71ca6c2312cca3b4c11c19d1ebf
	}

	//Tenta fazer a conexao com o arquivo.	
	pgm = fopen(pgmNome, "r");
	if(pgm == NULL){
		cout << "Arquivo invalido.\nDigite somente o nome do arquivo sem a extensao.\n";
		setbuf(stdin,NULL);

		exit(1);
	}

	//le o cabecalho do arquivo
	lerCabecalho(&x,&y,&scale);
	
    int temp = (janela/2)*2;

    //Aloca matriz do tamanho passado.
	M = criarMatriz(x+temp, y+temp);
	//Le imagem e atribui a matriz alocada.
	lerImagem(M,x+1,y+1);
	//Aplica o filtro de media e atribui a matriz ou chama a funcao que faz o laplace.
   	if( op == 'S'){
   		M = filtro(M,x,y,janela);
   	}else if(op == 'C'){
   		bordear(M,x,y);
   		M = cat_shadow(M,x+1,y+1);
   	}
    //M = bordear();
    //Escreve o arquivo de saida a partir da matriz suavizada.
	criarArquivoBorda(M,x,y, scale,pgmSaida);

	//fecha o streaming e desaloca matriz;
	fclose(pgm);
    free(M,x);

	return 0;
}
<<<<<<< HEAD
void lerCabecalho(int *x,int *y,int *scale){

	char lixo[1000];
	unsigned char c;
	fgets(lixo,ABSURDOMEUDEUS,pgm);
	*y = -1;
	*x = -1;
	*scale = -1;
	while(*scale <= 0 ){
	    
	    char k;
		k = fgetc(pgm);
        
        if( k == '#'){
			fgets(lixo,ABSURDOMEUDEUS,pgm);
            continue;	
        }     
        
        fseek(pgm,-1,SEEK_CUR);
		
        fscanf(pgm, "%c",&c);
        
		
			if(*y == -1){
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &(*y));

			}else if(*x == -1){
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &(*x));	

			}else if(*scale == -1){	
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &(*scale));
			
		}	
	}
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
=======
>>>>>>> 427e4d593725b71ca6c2312cca3b4c11c19d1ebf
