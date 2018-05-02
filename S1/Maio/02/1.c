#include <stdio.h>

int main(){
    
    int *p1, *p2;
    int x1, x2;
        
    scanf("%d %d", &x1, &x2);
    
    p1 = &x1;
    p2 = &x2;
 
    printf("a soma eh %d e suas posicoes sao %p e %p\n", *p1 + *p2, &p1,&p2);

    return 0;
}
