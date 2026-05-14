
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

O comando de abertura `popen` (Pipe Open) cria um canal de comunicação entre seu programa e o Gnuplot.
- O argumento "gnuplot" é o nome do executável que o sistema operacional vai procurar e rodar em segundo plano.
- O “modo” representa a operação que se deseja efetuar e define a direção do fluxo de dados entre o seu programa e o Gnuplot. Na prática, existem dois modos principais: 

| Modo           | Arquivo Comum (stdio.h)              | Gnuplot (Pipe)  |
|--------------------------|------------------------------|--------------------------|
| **"w"(Write)** |Abre o Gnuplot e permite que o seu programa C envie comandos | Enviar comandos como `set title`, `plot 'arquivo.txt'` ou os próprios dados via `plot '-'`|
| **"r"(Read)** | Abre o Gnuplot e permite que o seu programa C leia o que o Gnuplot imprime via terminal |Capturar informações de erro ou coordenadas que o Gnuplot calculou|

## Como enviar informações para o gnuplot?

Existem duas principais maneiras de enviar ao gnuplot os valores que se deseja plotar, você pode mandar diferetamente enviando dados da memória RAM para o gráfico, ou salvando na memória secundária através de um arquivo.txt por exemplo. A depender da sua escolha você deve sinalizar ao gnuplot de maneira diferente:

fprintf(gnuplot_pipe, "seu_arquivo.txt"); pegue os dados desse arquivo
fprintf(gnuplot_pipe, "-");pegue os dados da RAM 

obs: todo comando enviando ao gnuplot deve terminar com '\n'os

Na situação em que está se utilizando o arquivo.txt

O Pipe recebe as informações as projeta em colunas. O primeiro valor lido vai para coluna 1 e portanto é plotado no eixo_x por exemplo. Tanto no contexto que ele recebe do seu código diretamente os valores ou puxa do arquivo.txt ele organiza as informações desse modo: primeiro valor lido vai para o eixo_X. Caso se deseja alterar sem modificar a ordem em que os dados estão indo, é possível usar o comando `using`, em um exemplo 2D você poderia enviar a 2º coluna para o eixo_X e a 1º coluna para o eixo_Y desse modo:

fprintf(gnuplot_pipeMP, "plot '-'");
fprintf(gnuplot_pipeMP, " using 2:1  \n");





Assim que o Gnuplot recebe o \n após o plot '-', ele para de aceitar comandos e só aceita números (ou o e para sair desse modo).









----------------------------------------------------------------------------

Por que usar o Histórico é essencial?
O Gnuplot é um programa de "redesenho". Toda vez que você envia o comando plot, ele apaga o gráfico anterior e faz um novo.

Se você enviar apenas o ponto atual, o gráfico anterior some e fica apenas um ponto novo.

Se você enviar o histórico inteiro a cada vez, o gráfico parece "crescer" e formar uma linha contínua na tela.

Dica para o Tutorial: Você pode explicar que o plot '-' funciona como se você estivesse "re-escrevendo" o livro inteiro a cada nova página para que o leitor (usuário) veja a história completa desde o início.

Respondendo suas dúvidas:
"Não posso configurar o setup em duas linhas diferentes?"

Pode configurar o set title, set grid, etc, em linhas diferentes (antes do plot). Mas o using, o with lines e o title fazem parte do comando plot. Eles são "sobrenomes" do plot e devem ir juntos com ele.

"Depois de mandar o plot - tenho que mandar os dados?"

Exatamente. Assim que o Gnuplot recebe o \n após o plot '-', ele para de aceitar comandos e só aceita números (ou o e para sair desse modo).


