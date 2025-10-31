# --- MAKEFILE PARA COMPILAÇÃO E TESTE DE ALGORITMOS DE ORDENAÇÃO ---
#
#
# O objetivo deste Makefile é criar quatro executáveis separados.
# Cada executável conterá o *mesmo* programa principal (main.c),
# mas será "ligado" (compilado junto) a um algoritmo de 
# ordenação (função sort()) diferente.
#
# Isso permite testar cada algoritmo individualmente.
#

all: prog_bubble prog_shaker prog_selection prog_insertion

# Regra para criar o executável com Bubble Sort.
prog_bubble: main.c bubbleSort.c 
	gcc -Wall -o prog_bubble main.c bubbleSort.c

# Regra para criar o executável com shaker Sort.
prog_shaker: main.c shakerSort.c
	gcc -Wall -o prog_shaker main.c shakerSort.c

# Regra para criar o executável com Insertion Sort.
prog_insertion: main.c inserctionSort.c 
	gcc -Wall -o prog_insertion main.c inserctionSort.c

# Regra para criar o executável com Selection Sort.
prog_selection: main.c selectionSort.c 
	gcc -Wall -o prog_selection main.c selectionSort.c


clean:
	rm -f prog_bubble prog_shaker prog_selection prog_insertion


# 	PARA EXECUTAR (Análise detalhada dos 3 modos):

#    O 'argv[0]' será o nome do executável que você chamou
#    (ex: ./prog_bubble). O 'main.c' usa os outros argumentos (argv[1], 
#    argv[2], ...) para decidir o que fazer.
#
#    ---------------------------------------------------------------------
#    * Modo 1: Teste Padrão (ex: resultados do laboratório)
#    ---------------------------------------------------------------------
#      COMANDO: $ ./prog_bubble padrao
#
#      O QUE ACONTECE:
#      - O 'main.c' recebe 'argc = 2' (contando o nome do programa).
#      - Ele vê que 'argv[1]' é a string "padrao".
#      - Dentro do 'main.c', isso ativa a sua lógica de "Teste Padrão",
#        que:
#        1. Gera entradas de teste (Aleatória, Ordenada, Invertida, parcialmente ordenada.)
#        2. Para cada entrada, chama a função 'sort()' 
#        3. Neste exemplo, a 'sort()' chamada é a do 'bubbleSort.c'.
#        4. Imprime os tempos de execução.

#		OBS: Será utilizado os arquivos de testes fornecidos no classroom, coloque eles no diretório anterior ao diretorio
# 		onde o arquivo executavel se encontra.
#
#    ---------------------------------------------------------------------
#    * Modo 2: Leitura de Arquivo Único
#    ---------------------------------------------------------------------
#      COMANDO: $ ./prog_selection 10000 meu_arquivo_teste.txt
#
#      O QUE ACONTECE:
#      - O 'main.c' recebe 'argc = 3'.
#      - Ele vê que 'argv[1]' é "10000" (N) e 'argv[2]' é 
#        "meu_arquivo_teste.txt" (caminho_arquivo).
#      - O programa aloca um vetor de 10.000 posições.
#      - Ele abre 'meu_arquivo_teste.txt' e lê os 10.000 itens para o vetor.
#      - Ele chama a função 'sort()'.
#      - Neste exemplo, a 'sort()' chamada é a do 'selectionSort.c'.
#
#    ---------------------------------------------------------------------
#    * Modo 3: Entrada Manual (Entrada Padrão / stdin)
#    ---------------------------------------------------------------------
#      COMANDO: $ ./prog_insertion 5
#
#      O QUE ACONTECE:
#      - O 'main.c' recebe 'argc = 2'.
#      - Ele vê que 'argv[1]' é "5" (N) e não há 'argv[2]'.
#      - O programa aloca um vetor de 5 posições.
#      - Ele fica esperando você digitar 5 números no terminal 
#        (isso é a 'entrada padrão' ou 'stdin').
#      - Após ler os 5 números, ele chama a função 'sort()'.
#      - Neste exemplo, a 'sort()' chamada é a do 'inserctionSort.c'.
#
#

