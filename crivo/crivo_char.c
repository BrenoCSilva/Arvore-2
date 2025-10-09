#include "crivo.h"
#include <stdio.h>


Crivo* crivo_criar(int n){


    Crivo *crivo = (Crivo*) calloc (1, sizeof(Crivo));

    if(crivo == NULL){
        printf("    ERRO DE ALOCACAO, ENCERRANDO...\n");
        exit(1);
    }

    crivo->limite = n;
    crivo->numeros = (char*) calloc (n+1, sizeof(char));


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
    
        c->numeros[i] = 1;
        
    }

}


bool crivo_esta_marcado(Crivo* c, int i){

     return c->numeros[i];
}

void crivo_imprimir_primos(Crivo* c){


    for(int i=2; i < c->limite; i++){


         if(c->numeros[i]==0){
             printf("    %d é primo \n", i);
         }

    }
}