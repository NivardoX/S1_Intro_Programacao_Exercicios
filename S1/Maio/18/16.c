#include <stdio.h>

int fat(int x);

int main(){

    int x;
    
    printf("Digite o X\n");

    scanf("%d", &x);

    if(x %2 == 0)
        printf("valor invalido\n");
    else
        printf("%d\n", fat(x));

}

int fat(int x){
    
    if(x == 0 || x == 1){
        return 1;
    }else if(x == 3){
        return x;
    }else {
        return x * fat(x-2);
    }

}
