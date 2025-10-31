#include "Item.h"

// assumindo inicio sempre = 0.
void sort (Item* array, int inicio, int final){

    for(int i=0; i < final;i++){ // nao precisa analisar o ultimo <= pois por consequencia ele estara ordenado

        int index_min = i;
        for(int j=i+1; j <= final; j++){

           if(less(array[j], array[index_min])){
                index_min = j;
           }
        }

        exch(array[i], array[index_min]); // coloca na posicao i o menor elemento da lista atual
    }
}