#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n,i;
    float *nt;
    

    printf("Digite n\n");    
    scanf("%d", &n);
    nt = malloc(n * sizeof(float));
    
    
    for(i = 0; i < n; i++){
        scanf("%f", nt+i);// + tamanho de inteiro
    }
    printf("Notas: \n");
    for(i = 0 ; i < n; i++){
        printf("%.2f ", nt[i]);
    }
    free(nt);

    char **nm;
    
    printf("\nDigite n\n");
    scanf("%d", &n);
    nm = malloc(n * sizeof(char));
    
    for(i = 0; i < n; i++){
        *(nm+i) = (char*)malloc(80* sizeof(char));  
        scanf("%s", *(nm+i));
    }
    for(i = 0; i < n; i++){
        printf("%s\n", *(nm+i));
    
    }



    return 0;
}
