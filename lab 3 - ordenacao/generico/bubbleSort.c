#include "Item.h"


// assumindo inicio sempre = 0.

void sort (Item* array, int inicio, int final){

    for(int i = inicio; i < final; i++){ // nao precisa analisar o ultimo <= pois por consequencia ele estara ordenado
        
        int swap = 0;
        for(int j = 0; j < final - i; j++){ 

           if(less(array[j+1], array[j])){ 
                exch(array[j], array[j+1]); 
                swap = 1;
           }

        }

        if(!swap){
            break;
        }
    }

}
