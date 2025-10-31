#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Item.h"

void sort (Item* array, int inicio, int final){

    clock_t start_bubleSort = clock();
    for(int i = inicio; i < final; i++){
        
        int swap = 0;
        for(int j = 0; j < final - 1 - i; j++){ 

           if(less(array[j+1], array[j])){ 
                exch(array[j], array[j+1]); 
                swap = 1;
           }

        }

        if(!swap){
            break;
        }
    }

   clock_t end_bubleSort = clock();
    
    double seconds_buble = ((double) end_bubleSort - start_bubleSort) / CLOCKS_PER_SEC;

    printf("\ntempo gasto para ordenar %d elementos com o bubleSort: %lf s\n", final, seconds_buble);
}
