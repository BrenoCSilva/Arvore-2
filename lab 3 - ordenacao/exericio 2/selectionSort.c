#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Item.h"

void sort (Item* array, int inicio, int final){

    for(int i=0; i < final;i++){

        for(int j=i+1; j < final; j++){

           if(less(array[j], array[i])){
                exch(array[i], array[j]);
           }
        }
    }

}