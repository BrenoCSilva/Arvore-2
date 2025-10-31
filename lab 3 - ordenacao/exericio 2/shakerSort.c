#include "Item.h"
/**
 * @brief Ordena um array de Itens usando o Shaker Sort (Bubble Sort Bidirecional).
 *
 * O algoritmo "empurra" o maior elemento para o final (direita) e, em seguida,
 * "empurra" o menor elemento para o começo (esquerda), repetidamente,
 * diminuindo a "janela" de ordenação a cada passada completa.
 *
 * @param array Ponteiro para o array de Itens.
 * @param inicio Índice do primeiro elemento (inclusive).
 * @param final Índice do último elemento (inclusive).
 */
void sort(Item* array, int inicio, int final) {

    // 'left' e 'right' definem a "janela" de elementos
    // que ainda precisam ser ordenados.
    int left = inicio;
    int right = final;
    
    // Usamos 'swapped' como um 'int' (1 para true, 0 para false)
    // para otimização: se em uma passada completa (ida e volta)
    // nenhuma troca for feita, o array está ordenado.
    int swapped = 1;

    while (swapped) { // Continua enquanto houver trocas
        
        // No início de cada "grande passada" (ida + volta),
        // assumimos que não haverá trocas.
        swapped = 0;

        // --- Passada 1: Esquerda -> Direita (Bubble Up) ---
        // Move o MAIOR elemento da janela para a posição 'right'.
        for (int i = left; i < right; i++) {
            
            // Compara o elemento atual com o próximo
            // Se array[i] > array[i+1] (ou seja, array[i+1] < array[i])
            if (less(array[i + 1], array[i])) {
                
                // Em C, passamos o *endereço* dos elementos para 'exch'
                exch(array[i], array[i + 1]);
                swapped = 1; // Marca que uma troca ocorreu
            }
        }
        
        // Após a passada 1, o maior elemento da janela [left...right]
        // está garantidamente na posição 'right'.
        // Podemos "encolher" a janela pela direita.
        right--;

        // Se a passada 1 (subida) não fez nenhuma troca,
        // o array já estava ordenado. Podemos parar.
        if (!swapped) {
            break;
        }

        // --- Passada 2: Direita -> Esquerda (Bubble Down) ---
        // Move o MENOR elemento da janela para a posição 'left'.
        // Nota: 'swapped' *não* é resetado aqui. Se a passada 1
        // fez uma troca, 'swapped' já é 1, e se a passada 2
        // também fizer, ele continua 1.
        for (int i = right; i > left; i--) {

            // Compara o elemento atual com o anterior
            // Se array[i] < array[i-1]
            if (less(array[i], array[i - 1])) {
                exch(array[i], array[i - 1]);
                swapped = 1; // Marca que uma troca ocorreu
            }
        }

        // Após a passada 2, o menor elemento da janela [left...right]
        // (agora reduzida) está garantidamente na posição 'left'.
        // Podemos "encolher" a janela pela esquerda.
        left++;
        
        // O loop 'while(swapped)' irá re-avaliar. Se 'swapped'
        // for 0 (nem a subida nem a descida trocaram ninguém),
        // o loop termina.
    }
}
