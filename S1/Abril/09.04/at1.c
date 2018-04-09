#include<stdio.h>
int main(){
	int vt[10], i, j, M, m;
	float med;
	
	printf("digite os 10 valores\n");
	
	for(i = 0; i < 10; i++){
		scanf("%d", &vt[i]);
	}
		
	M = vt[0];
	m = vt[0];
	med = 0;
	
	for(j = 0; j < 10; j++){
		if(vt[j] > M){
			M = vt[j];
		}
		if(vt[j] < m){
			m = vt[j];
		}
		med = med + vt[j];	
	}
	
	
	
	
	
	
	
	for(i = 0; i < 10; i++){
		printf("%d ", vt[i]); 
	}
	printf("\n");
	
	printf("Maior = %d\n", M); 
	printf("Menor = %d\n", m);
	printf("Media = %f\n", med/10);
	
	return 0;
}
