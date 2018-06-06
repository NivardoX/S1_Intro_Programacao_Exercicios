#include <stdio.h>
#include <stdlib.h>
#define ABSURDOMEUDEUS 1000000

unsigned char **M;

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

void printMatriz(int x,int y){
  for (int i = 0; i < x; i++) {
    printf("\n", );
    for (size_t j = 0; j < y; j++) {
      printf("%3.d ", M[i][j] );
    }
  }
}

int main(int argc, char const *argv[]) {
  int z,x,y;
  printf("Digite o tamaho da matriz (x,y)\n");
  scanf("%d %d \n",&x,&y );

  printf("Digite o tamanho da janela\n" );
  scanf("%d\n",&z );

  int temp = (z/2);
  temp *= 2;

  M = criarMatriz(x + temp,y + temp);
  printMatriz(x + temp,y + temp);
  return 0;
}
