/* FUNCAO PRA LER HEADER
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ABSURDOMEUDEUS 1000000 //valor absurdo pra limpar linha


int main(){

	char lixo[4];
	char c;
	fgets(lixo,ABSURDOMEUDEUS,pgm);
	y = -1;
	x = -1;
	scale = -1;
	while(scale <= 0 ){
		//printf("loop do while\n");	
		fscanf(pgm, "%c",&c);
		if(c == '#'){
			fgets(lixo,ABSURDOMEUDEUS,pgm);
			//printf("printf # encontrado\n");
		}else if(c != '#'){
			if(y == -1){
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &y);
				//printf("y definido como %d\n",y);
			}else if(x == -1){
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &x);	
				//printf("x definido\n");	
			}else if(scale == -1){	
				fseek(pgm,-1,SEEK_CUR);
				fscanf(pgm, "%d", &scale);
				//printf("x definido\n");
			}
		}	
	}

//teste

	printf("y = %d, x = %d, scale = %d", y,x,scale);

	fclose(pgm);




}
