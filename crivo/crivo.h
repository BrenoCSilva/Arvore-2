#ifndef CRIVO_H 
#define CRIVO_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {

    char *numeros;
    int limite;

}Crivo;


/**
 * @brief Cria e inicializa uma nova instância do Crivo de Eratóstenes.
 *
 * Aloca memória para a estrutura do crivo e inicializa todos os números
 * até o limite 'n' como não marcados (potenciais primos).
 *
 * @param n O limite superior (inclusive) para encontrar os números primos.
 * @return Um ponteiro para a estrutura Crivo criada, ou NULL se houver erro.
 */
Crivo* crivo_construct(int n);

/**
 * @brief Libera toda a memória alocada para a estrutura do Crivo.
 *
 * @param c Um ponteiro para o Crivo que será destruído.
 */
void crivo_destroy(Crivo* c);

/**
 * @brief Marca todos os múltiplos de um dado número primo 'p'.
 *
 * A partir de p*p, marca todos os múltiplos de 'p' até o limite do crivo.
 *
 * @param c O ponteiro para a estrutura Crivo.
 * @param p O número primo cujos múltiplos serão marcados.
 */
void crivo_marcar_multiplos(Crivo* c, int p);

/**
 * @brief Verifica se um número está marcado no crivo.
 *
 * @param c O ponteiro para a estrutura Crivo.
 * @param i O número a ser verificado.
 * @return 'true' se o número 'i' estiver marcado , 'false' caso contrário.
 */
bool crivo_esta_marcado(Crivo* c, int i);

/**
 * @brief Imprime na tela todos os números primos encontrados.
 *
 * Percorre a estrutura e imprime todos os números que não foram marcados.
 *
 * @param c O ponteiro para a estrutura Crivo.
 */
void crivo_imprimir_primos(Crivo* c);


#endif 