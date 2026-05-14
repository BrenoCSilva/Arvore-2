
# Gnuplot tutorial

O Gnuplot é um software utilitário de terminal para geração de gráficos 2D e 3D. Podendo ser utilizado em diferentes plataformas: Windows, Linux, Mac, Android etc. 

Os gráficos podem ser gerados diretamente via terminal, por um arquivo externo e até mesmo através de um executável em C. 

Para confirmar se o programa do Gnuplot está instalado na sua máquina execute o comando abaixo no seu terminal:

````bash
                                                                    gnuplot

````

Caso o seu retorno seja algo parecido com isso, significa que a instalação já foi realizada:


[FOTO]


Em caso contrário, execute o comando sugerido no terminal:

[FOTO]

 O texto `gnuplot>` no início da linha indica que o gnuplot está pronto para receber comandos. Por exemplo: 

````bash
                                                                plot cos(x)

````

## Alguns comandos básicos do gnuplot

| Descrição           | Comando              | 
|--------------------------|------------------------------|
| **Nomear eixos**         | gnuplot> set xlabel "eixo X" |                    
| **Inserir título**       | gnuplot> set title "meu título"  | 
| **Inserir grade**        | gnuplot> set grid                        |
| **Gerar gráfico 2D**       | gnuplot> plot x | 
| **Gerar gráfico 3D**       | gnuplot> splot x*y                          | 
| **Encerra gnuplot**         |  gnuplot> quit               | 

Obs: Para executar as alteracões realizadas com set é necessário usar o comando `gnuplot> replot` para que aconteça uma atualização. Algo parecido vale para caso se deseja gerar dois ou mais gráficos ao mesmo tempo. Após o comando plot(2D) ou splot(3D) o próximo gráfico exige o uso do replot. Exemplo: gnuplot> splot sin(x) / gnuplot> replot cos(x). 

- Exemplo de sinalização.

## Gnuplot em C

Por ser um software independente (um programa instalado no seu PC) o C não importa uma biblioteca específica para usa-lo, ocorre a  utilização da própria stdio.h para fazer a abertura de um "cano/tubulação" (pipe) que através do seu código C envia comandos de texto que o Gnuplot executa e renderiza em tempo real.


A manipulação do Gnuplot em C é quase idêntica à manipulação de um arquivo comum, mudando apenas as funções de sistema:



| Operação           | Arquivo Comum (stdio.h)              | Gnuplot (Pipe)  |
|--------------------------|------------------------------|--------------------------|
| **Declaração**         |FILE *arquivo; |                    FILE *gnuplot_pipe; |
| **Abertura**       | fopen("arquivo.txt", "w");  | popen("gnuplot", "modo"); |
| **Escrita**        | fprintf(arquivo, "texto");| fprintf(gnuplot_pipe, "plot..."); |
| **Fechamento**       | fclose(arquivo); | pclose(gnuplot_pipe);|
| **Gerar gráfico 3D**       | gnuplot> splot x*y                          | 
| **Encerra gnuplot**         |  gnuplot> quit               | 

O comando popen (Pipe Open) cria um canal de comunicação entre processos. O argumento "gnuplot" invoca o executável do software, e o modo "w" (write) define que o seu programa C é o "mestre" que envia as ordens.

O popen (Pipe Open) não abre um arquivo comum, ele abre um programa.
- O argumento "gnuplot" é o nome do executável que o sistema operacional vai procurar e rodar em segundo plano.
- O “modo” representa a operação que se deseja efetuar e definem a direção do fluxo de dados entre o seu programa e o Gnuplot. Na prática, existem dois modos principais: 

| Modo           | Arquivo Comum (stdio.h)              | Gnuplot (Pipe)  |
|--------------------------|------------------------------|--------------------------|
| **"w" (Write)** |Abre o Gnuplot e permite que o seu programa C envie comandos | Enviar comandos como `set title`, `plot 'arquivo.txt'` ou os próprios dados via `plot '-'`|
| **"r" (Read)** | Abre o Gnuplot e permite que o seu programa C leia o que o Gnuplot imprime via terminal |Capturar informações de erro ou coordenadas que o Gnuplot calculou|

