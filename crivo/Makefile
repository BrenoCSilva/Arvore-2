# Makefile simples para o projeto Crivo de Eratóstenes

# A primeira regra num Makefile é a padrão.
# Ao executar 'make' no terminal, ele tentará construir 'all'.
# A regra 'all' depende dos três executáveis, então o make irá construí-los.
all: crivo_int_exec crivo_char_exec crivo_bit_exec

# Regra para criar o executável da versão com 'int'.
# Para criar 'crivo_int_exec', ele precisa dos ficheiros 'main.c', 'crivo_int.c', e 'crivo.h'.
# Se algum desses ficheiros mudar, esta regra será executada novamente.
crivo_int_exec: main.c crivo.c crivo.h
	gcc -Wall -o crivo_int_exec main.c crivo.c -lm

# Regra para criar o executável da versão com 'char'.
crivo_char_exec: main.c crivo_char.c crivo.h
	gcc -Wall -o crivo_char_exec main.c crivo_char.c -lm

# Regra para criar o executável da versão com 'bit'.
crivo_bit_exec: main.c crivo_bit.c crivo.h
	gcc -Wall -o crivo_bit_exec main.c crivo_bit.c -lm

# Regra para 'limpar' o diretório.
# Executar 'make clean' irá remover todos os ficheiros executáveis.
.PHONY: clean
clean:
	rm -f crivo_int_exec crivo_char_exec crivo_bit_exec

