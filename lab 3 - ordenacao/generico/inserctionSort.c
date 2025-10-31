#include "Item.h"


// assumindo inicio sempre = 0.
void sort (Item* array, int inicio, int final){

    for(int i = inicio; i < final; i++){
        
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

}
