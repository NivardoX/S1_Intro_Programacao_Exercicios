#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char nomeBanco[80];
int tam = 1;
char **pontPont;
FILE *fp;

void alocar();
void getDoArq();
void printNoArq();
void iniciar();
void menu();
void stream(char *file ,char *type);
void adicionar();
void printBanco();

int main(int argc, char const *argv[])
{
	iniciar();
	
	printf("Digite o nome do arquivo de pseudo banco.\n");
	scanf("%s",nomeBanco);

	strcat(nomeBanco,".txt");
	stream(nomeBanco,"a+");

	getDoArq();
	menu(fp);


	return 0;
}

void stream(char *file ,char *type){
	

	fp = fopen (file,type);
	if (fp == NULL)
	{
		printf("Erro na abertura do arquivo.\n");
	}
}

void menu(){
	printf("\n-----------------------------------\n");
	printf("----------------MENU---------------\n");
	printf("-----------------------------------\n\n");
	printf("Escolha uma das opcoes.\n\n");
	printf("L - Listar banco.\n");
	printf("A - Adicionar no banco.\n");
	printf("E - Sair.\n\n");
	
	

	char ch;
	setbuf(stdin,NULL);
	ch = getchar();

	
	switch(ch){

		case 'A':
			adicionar();
			menu();
		break;

		case 'L':
			printBanco();
			menu();
			
		break;

		case 'E':
			exit(1);
		break;
	}

}

//Printa oque esta alocado no Vetor pontPont
void printBanco(){
	printf("\n");
	int i;
	for( i = 0; i < tam ; i++){
		printf("%s",pontPont[i]);		
	}
	printf("\n");
}

//Tanto adiciona uma string lida no arquivo quanto no vetor pontPont, utiliza a funcao printNoArq.
void adicionar(){
	fclose(fp);
	fp = fopen(nomeBanco,"a");
	
	char str[80];
	scanf("%s",str);

	pontPont = (char **) realloc(pontPont,(tam +1)*sizeof(char *));
	pontPont[tam] = (char *)malloc(80*sizeof(char));
	strcpy(pontPont[tam],str);

	printNoArq(str);
	
	tam++;
}

//Inicia o vetor, alocando somente uma posicao.
void iniciar(){

	pontPont =(char **) malloc(1*sizeof(char *));
	pontPont[0] = (char *)malloc(80*sizeof(char));
}

//Adiona uma string no arquivo, utilizada na funcao adicionar.
void printNoArq(char *str){
	
	fclose(fp);
	fp = fopen(nomeBanco,"a");

	strcat(str,"\n");
	fputs(str,fp);
}

//Roda no inicio do programa e le oque ja estava no arquivo, adicionando no vetor pontPont.
void getDoArq(){
	fclose(fp);
	fp = fopen(nomeBanco,"r");

	int i = 0;
	while(!feof(fp)){

		alocar();
		fgets(pontPont[i++],80000,fp);
	}


}

void alocar(){
	pontPont = (char **) realloc(pontPont,(tam +1)*sizeof(char *));
	pontPont[tam++] = (char *)malloc(80*sizeof(char));
}