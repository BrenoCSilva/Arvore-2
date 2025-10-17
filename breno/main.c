#include <stdio.h>
#include "binary_tree.h"
#include <stdlib.h>
#include <string.h>



int cmp(void *a, void *b)
{   
    char * sigla1= (char *)a;
    char * sigla2 = (char *)b;

    if(strcmp(sigla1,sigla2) > 0) return 1;
    if(strcmp(sigla1, sigla2) < 0)return -1;

    return 0;
}

void printa(void *a)
{   
    char * nome= (char *)a;

    printf("    %s\n", nome);


}



int main (){


    BinaryTree* tree = binary_tree_construct(cmp);


    for(int i=0; i < 3; i++){

        char* name = (char*)calloc(100,sizeof(char));
        scanf("%s", name);
        binary_tree_add(tree, name, name);
    }

    PrintSorted(tree, printa);

    return 0;
}