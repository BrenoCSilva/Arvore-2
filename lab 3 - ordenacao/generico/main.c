#include <stdio.h>
#include "Item.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>


extern void sort(Item *a, int lo, int hi);


void testar_arquivo(char* caminho, int N) {
    

    Item *array = malloc(N * sizeof(Item));

    if (array == NULL) {
        printf("Erro: Falha ao alocar memoria para %d itens.\n", N);
        return;
    }

    FILE *arquivo = fopen(caminho, "r");

    if (!arquivo) {
        printf("Erro ao ler o arquivo %s\n", caminho);
        free(array); 
        return;
    }


    int number, i = 0;
    while(i < N && fscanf(arquivo, "%d", &number) == 1) {
        array[i] = number;
        i++;
    }
    fclose(arquivo);

    clock_t start = clock();

    sort(array, 0, i - 1);

    clock_t end = clock();
    double seconds = ((double) end - start) / CLOCKS_PER_SEC;

    printf("      (%d itens): %lf s\n", i, seconds);

    free(array);
}


void entrada_padrao(char* caminho1, char* caminho2, char* caminho3, char* tipo_ordenacao){

    printf("Análise de tempo para entrada - %s:\n", tipo_ordenacao);

    // Chama a função auxiliar para cada tamanho
    testar_arquivo(caminho1, 1000);
    testar_arquivo(caminho2, 10000);
    testar_arquivo(caminho3, 100000);
    
    printf("----------------------------------------------------------\n");
}

int main(int argc, char *argv[]){

    if (argc == 2 && strcmp(argv[1], "padrao")==0) {

        entrada_padrao("../unif_rand/1Kunif_rand.txt", "../unif_rand/10Kunif_rand.txt", "../unif_rand/100Kunif_rand.txt", "Aleatória");

        entrada_padrao("../reverse_sorted/1Kreverse_sorted.txt","../reverse_sorted/10Kreverse_sorted.txt", "../reverse_sorted/100Kreverse_sorted.txt", "Invertida");

        entrada_padrao("../nearly_sorted/1Knearly_sorted.txt","../nearly_sorted/10Knearly_sorted.txt", "../nearly_sorted/100Knearly_sorted.txt", "Quase Ordenada");

        entrada_padrao("../sorted/1Ksorted.txt","../sorted/10Ksorted.txt", "../sorted/100Ksorted.txt", "Ordenada");
        
    }

    else if (argc == 3){

        int n = atoi(argv[1]);
        char *caminho = argv[2]; 

        testar_arquivo(caminho, n);

    }

    else if(argc == 2){

        int n = atoi(argv[1]);


        Item *array = malloc(n * sizeof(Item));


        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }


        clock_t start = clock();
        sort(array, 0, n - 1); 
        clock_t end = clock();
        double seconds = ((double) end - start) / CLOCKS_PER_SEC;
        
        printf("Tempo gasto: %lf s\n", seconds); 

        printf("Lista ordenada:\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        
        printf("\n");

        free(array);
        
    }else {
        
        printf("Erro: Uso invalido.\n\n");
        printf("Modo 1 (Teste Padrao): %s padrao\n", argv[0]);
        printf("Modo 2 (Arquivo Unico): %s <N> <caminho_arquivo>\n", argv[0]);
        printf("Modo 3 (Entrada Manual): %s <N>\n", argv[0]);
        
    }




    return 0;
}   