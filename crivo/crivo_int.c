#include "crivo.h"
#include <stdio.h>



Crivo* crivo_construct(int n){

    Crivo *crivo = (Crivo*) calloc (1, sizeof(Crivo));

    if(crivo == NULL){
        printf("    ERRO DE ALOCACAO, ENCERRANDO...\n");
        exit(1);
    }

    crivo->limite = n;
    crivo->numeros = (int*) calloc (n+1, sizeof(int));


    if(crivo->numeros == NULL){
        printf("    ERRO DE ALOCACAO, ENCERRANDO...\n");
        exit(1);
    }

    return crivo;
}


void crivo_destroy(Crivo* c){

    if(c){

        if(c->numeros){
            free(c->numeros);
        }
        free(c);
    }
}


// por que comecar com p*p? Como p é o primo atual deveriamos comecar a varrer seus multiplos por:
// Ex: 5*2 = 10 , 5*3 =15, 5*4=20. Então qual a razao de iniciar em p*p = 5*5 = 25? Por que pular os múltiplos anteriores de 
// p? A razão seria porque eles já foram marcados por primos menores, o 10 pelo 2, o 15 pelo 3 ...
// Para numeros muito grande esses verificacoes redudantes fariam muita diferença.
// e porque incrementar i de p em p? Porque depois do i=25=5*5 o proximo multiplo é 5*6=20=25+5, ou seja, 25+p

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