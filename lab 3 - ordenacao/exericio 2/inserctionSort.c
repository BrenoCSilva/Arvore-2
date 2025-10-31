#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Item.h"

void sort (Item* array, int inicio, int final){

    clock_t start_insertionSort = clock();

    for(int i = 0; i < final - 1; i++){
        
        if(less(array[i+1], array[i])){
            
            exch(array[i+1], array[i]);

            for(int j=i; j > 0; j--){

                if(!less(array[j], array[j-1])){
                    break;
                }
                exch(array[j], array[j-1]);
            }

        }

    }

    clock_t end_insertionSort = clock();
    
    double seconds_insertion = ((double) end_insertionSort - start_insertionSort) / CLOCKS_PER_SEC;

    printf("\ntempo gasto para ordenar %d elementos com o inserctionSort: %lf s\n", final, seconds_insertion);
}
