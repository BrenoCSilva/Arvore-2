#include <stdio.h>
#include "crivo.h"
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {

    bool imprime = false;

    if (argc > 2 && strcmp(argv[2], "imprime") == 0) {
        imprime = true;
    }
    
    if (argc < 2) {
        printf("Erro: Forneça o valor de N como argumento.\n");
        printf("Exemplo: %s 1000\n", argv[0]);
        return 1; 
    }

    
    int n = atol(argv[1]);

    Crivo *crivo = crivo_criar(n);
    int raiz = sqrt(crivo->limite);

    for(int i=2; i <= raiz; i++){


        if(crivo_esta_marcado(crivo, i)==0){ 


            crivo_marcar_multiplos(crivo, i);
        }

    }


    if(imprime){
        crivo_imprimir_primos(crivo);
    }


    crivo_destruir(crivo);
}
