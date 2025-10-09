#include <stdio.h>

//* @brief Encontra o sobrevivente no Problema de Josephus usando a fórmula matemática.
// * Esta é a solução mais eficiente, com complexidade de tempo O(N) e espaço O(1).


// n: número de pessoas no círculo
// k: cada k-ésima pessoa é eliminada
int josephus(int n, int k) {
  
    int sobrevivente = 0; 


    for (int i = 1; i <= n; i++) {

        // A fórmula recursiva: (sobrevivente + k) % i
        // Adiciona 'k' (o próximo a ser eliminado) e usa o módulo 'i'
        // porque a cada rodada o tamanho do círculo diminui e o ponto de partida muda.
        // O 'sobrevivente' aqui é a posição do sobrevivente *no círculo anterior*
        // quando o círculo tinha (i-1) pessoas.
        sobrevivente = (sobrevivente + k) % i;
    }

    // Como o índice é baseado em na posiocao 0, adicionamos 1 ao resultado para retornar
    // a posição baseada em 1 (que é a convenção mais comum).
    return sobrevivente + 1;
}

int main() {
    int n = 7; // Número de pessoas
    int k = 3; // Cada 3ª pessoa é eliminada

    printf("Para %d pessoas e pulando %d, o sobrevivente está na posição %d\n", n, k, josephus(n, k)); // Saída: Para 7 pessoas e pulando 3, o sobrevivente está na posição 4

    n = 5;
    k = 2;
    printf("Para %d pessoas e pulando %d, o sobrevivente está na posição %d\n", n, k, josephus(n, k)); // Saída: Para 5 pessoas e pulando 2, o sobrevivente está na posição 3

    return 0;
}