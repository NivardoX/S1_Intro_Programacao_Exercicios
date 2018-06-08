#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "funcoes.h"
#include "codigoYves.h"


using namespace std;

int main(){

	int i,j;
	int x,y;
	
	unsigned char **M;

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
	}
    
   //Verifica por casos impossiveis.
    if(janela <= 1 || janela%2 == 0){
        printf("A janela dever um número ímpar maior que 1.\n");
        setbuf(stdin,NULL);

        return main();

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
