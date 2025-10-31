# MAKEFILE DO CLIENTE DE ORDENAÇÃO

# O comando 'make' ou 'make all' executa a regra 'all'.
# Esta regra gera 4 executáveis diferentes, um para cada
# método de ordenação, ligando o MESMO main.c com
# implementações de 'sort' diferentes.

# Na execucacao, por exemplo: "./prog_insertion 100"
# O programa vai esperar 100 números da entrada padrão (stdin)
# Exemplo de uso com um arquivo:
#     ./prog_insertion 100

all: prog_insertion prog_selection prog_bubble prog_shaker

# Regra para criar o executável com Insertion Sort.
prog_insertion: main.c inserctionSort.c 
	gcc -Wall -o prog_insertion main.c inserctionSort.c

# Regra para criar o executável com Selection Sort.
prog_selection: main.c selectionSort.c 
	gcc -Wall -o prog_selection main.c selectionSort.c

# Regra para criar o executável com Bubble Sort.
prog_bubble: main.c bubbleSort.c 
	gcc -Wall -o prog_bubble main.c bubbleSort.c

# Regra para criar o executável com shaker Sort.
prog_shaker: main.c shakerSort.c
	gcc -Wall -o prog_shaker main.c shakerSort.c

# Regra 'clean' para apagar os executáveis gerados
clean:
	rm -f prog_insertion prog_selection prog_bubble prog_shaker

