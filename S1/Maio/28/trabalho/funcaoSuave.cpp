#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){

    for(i = 1; i < y; i++){
        for(j = 1; j < x; j++){
            M[i][j] = ((M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1])/9);
        }
    }



    return 0;
}
