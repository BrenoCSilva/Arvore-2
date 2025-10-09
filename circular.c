#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma pessoa (um nó na lista)
typedef struct Pessoa {
    int id;
    struct Pessoa* proxima;
} Pessoa;

// Função para resolver o problema de Josephus usando simulação
int resolver_josephus_simulacao(int n, int k) {
    if (n <= 0 || k <= 0) {
        return -1; // Valores inválidos
    }
    if (n == 1) {
        return 1;
    }

    // 1. Criar a lista circular de N pessoas
    Pessoa* cabeca = (Pessoa*)malloc(sizeof(Pessoa));
    cabeca->id = 1;
    Pessoa* atual = cabeca;

    for (int i = 2; i <= n; i++) {
        atual->proxima = (Pessoa*)malloc(sizeof(Pessoa));
        atual = atual->proxima;
        atual->id = i;
    }
    // Fechar o círculo
    atual->proxima = cabeca;

    // 2. Simular as eliminações
    // O ponteiro 'anterior' vai apontar para a pessoa ANTES da que será eliminada
    Pessoa* anterior = atual; // Começamos com o último a apontar para o primeiro

    while (anterior->proxima != anterior) { // Enquanto houver mais de uma pessoa
        // 3. Andar k-1 passos para encontrar a pessoa a ser eliminada
        for (int i = 0; i < k - 1; i++) {
            anterior = anterior->proxima;
        }

        // 'anterior->proxima' é a pessoa a ser eliminada
        Pessoa* pessoa_eliminada = anterior->proxima;
        //printf("Pessoa %d foi eliminada.\n", pessoa_eliminada->id);

        // Remover a pessoa do círculo
        anterior->proxima = pessoa_eliminada->proxima;

        // Liberar a memória da pessoa eliminada
        free(pessoa_eliminada);
    }

    // O nó restante é o sobrevivente
    int id_sobrevivente = anterior->id;
    free(anterior); // Liberar o último nó
    return id_sobrevivente;
}


int main() {
    int n, k;
    printf("--- Problema de Josephus (Simulação) ---\n");
    printf("Digite o número de pessoas (N): ");
    scanf("%d", &n);
    printf("Digite o tamanho do passo (K): ");
    scanf("%d", &k);

    printf("\nIniciando simulação para N=%d e K=%d...\n", n, k);
    int sobrevivente = resolver_josephus_simulacao(n, k);

    if (sobrevivente != -1) {
        printf("\nO sobrevivente está na posição: %d\n", sobrevivente);
    } else {
        printf("Valores de entrada inválidos.\n");
    }

    return 0;
}
