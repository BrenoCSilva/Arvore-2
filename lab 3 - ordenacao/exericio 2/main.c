#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"


//extern diz ao compilador: "Esta função existe, mas está definida em OUTRO arquivo. 
//o 'linker' vai encontrá-la depois."
extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[]) {
    

    int N = atoi(argv[1]);


    Item *meu_array = malloc(N * sizeof(Item));


    for(int i = 0; i < N; i++) {
        scanf("%d", &meu_array[i]);
    }


    sort(meu_array, 0, N ); 
    
    printf("Lista ordenada:\n");
    for(int i = 0; i < N; i++) {
        printf("%d ", meu_array[i]);
    }
    printf("\n");

 
    free(meu_array);

    return 0;
}