#include <stdio.h>
#include "Item.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>


void selectionSort (Item* array, int n,  char* string){

    clock_t start_selectionSort = clock();

    for(int i=0; i < n;i++){

        for(int j=i+1; j < n; j++){

           if(less(array[j], array[i])){
                exch(array[i], array[j]);
           }
        }
    }

    clock_t end_selectionSort = clock();
    
    double seconds_selectionSort = ((double) end_selectionSort - start_selectionSort) / CLOCKS_PER_SEC;

    printf("    \n%s %lf s\n", string, seconds_selectionSort);
}



void entrada(char* caminho1, char* caminho2, char* caminho3, char* tipo){

    printf("Análise de tempo do selectionSort para entrada - %s:\n", tipo);

    FILE *arquivo1k, *arquivo10k, *arquivo100k;

    arquivo1k = fopen(caminho1, "r");
    arquivo10k = fopen(caminho2, "r");
    arquivo100k = fopen(caminho3, "r");

    if(!arquivo1k || !arquivo10k  || !arquivo100k){
        printf("Erro ao ler o arquivo\n");
        exit(1);
    }

    srand(time(NULL));

    Item array1k[1000];
    Item array10k[10000];
    Item array100k[100000];

    int number, i=0;
    while(fscanf(arquivo1k, "%d", &number) == 1){

        array1k[i] = number;
        i++;
    }
    fclose(arquivo1k);
    selectionSort(array1k, i, "Tempo selectionSort array 1k:");

    i=0;
    while(fscanf(arquivo10k, "%d", &number) == 1){

        array10k[i] = number;
        i++;
    }
    fclose(arquivo10k);
    selectionSort(array10k, i, "Tempo selectionSort array 10k:");

    i=0;
    while(fscanf(arquivo100k, "%d", &number) == 1){

        array100k[i] = number;
        i++;
    }
    fclose(arquivo100k);

    selectionSort(array100k, i, "Tempo selectionSort array 100k:");


    printf("----------------------------------------------------------\n");

}

int main(){


    entrada("../unif_rand/1Kunif_rand.txt", "../unif_rand/10Kunif_rand.txt", "../unif_rand/100Kunif_rand.txt", "Aleatória");

    entrada("../reverse_sorted/1Kreverse_sorted.txt","../reverse_sorted/10Kreverse_sorted.txt", "../reverse_sorted/100Kreverse_sorted.txt", "Invertida");

    entrada("../nearly_sorted/1Knearly_sorted.txt","../nearly_sorted/10Knearly_sorted.txt", "../nearly_sorted/100Knearly_sorted.txt", "Quase Ordenada");

    entrada("../sorted/1Ksorted.txt","../sorted/10Ksorted.txt", "../sorted/100Ksorted.txt", "Ordenada");

    return 0;
}   