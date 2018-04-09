#include<stdio.h>
int main(){
	int i, n, x[8];
	for(i=0;i<8;i++){
		x[i] = 0;
	}
	scanf("%d", &n);
	for(i=0;i<sizeof(n)*2;i++, n = n>>1){
		if(n & 1){
			x[i] = 1;
		}else{
			x[i]= 0;
		}
	}
	for(i=7;i>=0;i--){
		printf("%d ", x[i]);
	}
	printf("\n%d\n", sizeof(n));
	return 0;
}
