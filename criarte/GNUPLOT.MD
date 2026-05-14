
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

 O texto `gnuplot>` no início da linha indica que o gnuplot está pronto para receber comandos, que devem ser digitados após o gnuplot>. Por exemplo: 

````bash
                                                                plot cos(x)

````

Alguns comandos básicos do gnuplot:



| Característica           | Lista Encadeada              | 
|--------------------------|------------------------------|
| **Nomear eixos**         | gnuplot> set xlabel "eixo X" |                    
| **Inserir título**       | gnuplot> set title "meu título"  | 
| **Inserir grade**        | gnuplot> set grid                        |
| **Gerar gráfico 2D**       | gnuplot> plot x | 
| **Gerar gráfico 3D**       | gnuplot> splot x*y                          | 
| **Encerra gnuplot**         |  gnuplot> quit               | 

Obs: Para executar as alteracões realizadas com set é necessário usar o comando `gnuplot> replot` para que aconteça uma atualização. Algo parecido vale para caso se deseja gerar dois ou mais gráficos ao mesmo tempo, após o comando plot(2D) ou splot(3D) o próximo gráfico exige o replot. Exemplo: gnuplot> splot sin(x) / gnuplot> replot cos(x). 







Por ser um software independente (um programa instalado no seu PC). O C não importa uma biblioteca específica para utiliza-lo, ele utiliza a próprio stdio.h para abrir um "cano" (pipe) e conversar com o programa.
