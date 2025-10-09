#include "crivo.h"
#include <stdio.h>

#define BITS_IN_BYTE 8

#define set_bit(arr, n) (arr[(n) / BITS_IN_BYTE] |= (1U << ((n) % BITS_IN_BYTE)));
#define is_set(arr, n)     ((arr[(n) / BITS_IN_BYTE] >> ((n) % BITS_IN_BYTE)) & 1U);

Crivo* crivo_criar(int n){


    Crivo *crivo = (Crivo*) calloc (1, sizeof(Crivo));

    if(crivo == NULL){
        printf("    ERRO DE ALOCACAO, ENCERRANDO...\n");
        exit(1);
    }

    crivo->limite = n;
    crivo->numeros = (char*) calloc (n/BITS_IN_BYTE+1, sizeof(char));


    if(crivo->numeros == NULL){
        printf("    ERRO DE ALOCACAO, ENCERRANDO...\n");
        exit(1);
    }

    return crivo;
}


void crivo_destruir(Crivo* c){

    if(c){

        if(c->numeros){
            free(c->numeros);
        }
        free(c);
    }
}


void crivo_marcar_multiplos(Crivo* c, int p){


    for(int i =p * p ; i <= c->limite; i+=p){
    
        set_bit(c->numeros, i);
        
    }

}


bool crivo_esta_marcado(Crivo* c, int i){

    return is_set(c->numeros, i);
}

void crivo_imprimir_primos(Crivo* c){


    for(int i=2; i < c->limite; i++){

        if(!crivo_esta_marcado(c, i)){
            printf("    %d é primo \n", i);
        }
    }
}