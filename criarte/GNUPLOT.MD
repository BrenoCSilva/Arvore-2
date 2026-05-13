
O Gnuplot é um software utilitário de terminal para geração de gráficos 2D e 3D. Podendo ser utilizado em diferentes plataformas: Windows, Linux, Mac, Android etc. 

Os gráficos podem ser gerados diretamente via terminal, por um arquivo externo e até mesmo através de um executável em C. 

Para confirmar se o programa do Gnuplot está instalado na sua máquina execute o comando abaixo no seu terminal:

````bash
                                                                    gnuplot

````

Caso o seu retorno seja algo parecido com isso, significa que sim:


[FOTO]


 O texto gnuplot> no início da linha indica que o gnuplot está pronto para receber comandos, que devem ser digitados após o gnuplot>. Por exemplo: gnuplot> plot cos(x).

Alguns comandos básicos do gnuplot:



| Característica           | Lista Encadeada              | 
|--------------------------|------------------------------|
| **Nomear eixos**         | gnuplot> set xlabel "eixo X" |                    
| **Inserir título**       | gnuplot> set title "meu título"  | 
| **Inserir grade**        | gnuplot> set grid                        |
| **Uso de memória**       | Mais (overhead de ponteiros) | 
| **Cache-Friendly**       | Não                          | 
| **Encerra gnuplot**         |  gnuplot> quit               | 
