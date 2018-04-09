#include<stdio.h>
int main(){
	int i, t, soma,count = 0;
	char n[110];
	int x[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	scanf("%d", &t);
	while(t--){
		soma = 0;
		scanf("%s", n);
		for(i=0;n[i];i++) {
			soma = soma + x[n[i] - '0'];1
		}
		printf("%d leds\n", soma);
	}
	return 0;
}

