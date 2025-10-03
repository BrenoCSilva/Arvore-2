#include <stdio.h>
#include <stdbool.h>

static int id[1000];
static int N;

void UF_init(int size) 
{
  N = size;
  for (int i = 0; i < N; i++)
  {
    id[i] = 1;  // Cada objeto comeca na sua propria componente.
  }             // N acessos ao array.
}


int main( ){

    int n = 100;
    UF_init(n);

    int j;
    int fator = 0;
    for(int i=2; i < n; i++){

        //printf("\n\nMULTIPLO DE %d \n\n", i);

        //if(id[i]){ // tem que pegar o indice que tem marcacao true, se ele for false quer dizer que ele ja nao é primo

            for(int fator =0; fator < n; fator++){

                if(i * i + (fator+1)*i > n){
                    break;
                }
                //i2, i2+i, i2+2i, i2+3i,
                j = i * i + fator*i;
                id[j] = 0;
               // printf(" sou o fator %d . E o seu elemento é %d \n", fator, j);

            
            }
      //  }
    }


    for(int i=2; i < n; i++){


        if(id[i]){
            printf("    %d é primo \n", i);
        }
    }


}
