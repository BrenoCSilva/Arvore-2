
# Descrição do Protótipo

Trabalho desenvolvido na disciplina Projeto Integrado à Computação I, sob a orientação do professor Vinícius Mota, em parceria com o curso de Arquitetura e Urbanismo, representado pela professora Marcela Almeida. E pelos alunos:
 - Breno Silva;
 - Felipe Soares;
 - Marcela Magris;
 - Raissa Almeida.
   
O projeto tem como objetivo a criação de um cubo interativo que exibe informações sobre árvores previamente selecionadas e coleta dados ambientais do entorno, como a temperatura e a qualidade do ar. Cada face do cubo apresenta uma categoria específica de informações, como porte da árvore, floração, frutificação, dados do ambiente e dados gerais.

## Disposição das Informações  

Cada face do cubo interativo apresenta uma categoria específica de informações:  

- **Face 1:** Informações gerais da árvore (Nome, origem, bioma e copa).  
- **Face 2:** Porte da árvore (pequeno, médio, grande).  
- **Face 3:** Dados ambientais (temperatura e qualidade do ar).  
- **Face 4:** Floração (indicação de presença e meses de floração).  
- **Face 5:** Frutificação (indicação de presença e meses de frutificação).  
- **Face 6:** Face cega - utilizada para apoio, possui um mapa do percurso.  
 
# Componentes

| Componente       | Quantidade | Função |
|------------------|------------|--------|
| Módulo RC522     | 1          | Captura o UID das tags RFID. |
| Tags RFID        | 10         | Cada UID está vinculado a informações de uma árvore. |
| Display OLED SH1106 128x64    | 1          | Apresenta informações gerais sobre a árvore identificada. |
| Fita LED (3 segmentos)  | 1   | Indica o porte da árvore (pequeno, médio, grande). |
| Fita LED (10 segmentos) | 1   | Sinaliza se a árvore possui flor. |
| Fita LED (12 segmentos) | 1   | Apresenta os meses de floração. |
| Fita LED (1 segmento)  | 1   | Sinaliza se a árvore possui fruto. |
| Fita LED (12 segmentos) | 1   | Apresenta os meses de frutificação. |
| Botões            | 7         | Inicializam/desligam informações da face ou alternam os dados exibidos. |
| Fita LED (9 segmentos)  | 1   | Indica a temperatura do ambiente. |
| Fita LED (9 segmentos)  | 1   | Indica a qualidade do ar no ambiente. |
| Sensor ENS160     | 1         | Captura a qualidade do ar, CO₂ e compostos orgânicos voláteis (VOCs). |
| Sensor AHT21      | 1         | Mede temperatura e umidade do ambiente. |
| Arduino Mega     | 1          | Controla os sensores RFID, LEDs e botões, processando e exibindo informações sobre as árvores.        |
| ESP32            | 1          | Coleta dados dos sensores de temperatura e qualidade do ar e os envia para um broker MQTT. |
| PowerBank            | 1          | Alimentar o circuito e componentes. |

**Observação**: Os sensores ENS160 e AHT21 estão integrados em um único módulo.


# Processo de Montagem 

As faces do cubo foram cortadas utilizando uma máquina de corte automatizada, garantindo precisão nas dimensões e encaixes. Os componentes eletrônicos foram distribuídos de acordo com a funcionalidade de cada face e conectados ao Arduino Mega e ao ESP32 conforme necessário.

<div align="center">
<table>
 <tr>
   <td>
      <img src="imagens/arestas.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/corte.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/corte2.jpeg" alt="Integracao 1" width="200px">
   </td>
 </tr>
</table>
</div>

### Conexão do Módulo RC522 (Leitor RFID) ao Arduino Mega  

O módulo RC522 é responsável pela leitura das tags RFID que identificam as árvores cadastradas. Ele se comunica com o Arduino Mega por meio do protocolo SPI. Abaixo estão as conexões utilizadas:  
<div align="center">
<table>
  <tr>
    <td>
      <img src="imagens/RC522.jpeg" alt="Conexão RC522 com Arduino Mega" width="400px">
    </td>
    <td>
      <table>
        <tr><th>Pino do RC522</th><th>Pino do Arduino Mega</th></tr>
        <tr><td><b>3.3V</b></td><td><b>3.3V</b></td></tr>
        <tr><td><b>GND</b></td><td><b>GND</b></td></tr>
        <tr><td><b>RESET</b></td><td><b>Porta digital 5</b></td></tr>
        <tr><td><b>SDA</b></td><td><b>Porta digital 53</b></td></tr>
        <tr><td><b>SCL</b></td><td><b>Porta digital 52</b></td></tr>
        <tr><td><b>MOSI</b></td><td><b>Porta digital 51</b></td></tr>
        <tr><td><b>MISO</b></td><td><b>Porta digital 50</b></td></tr>
      </table>
    </td>
  </tr>
</table>
</div>

### Conexão do DISPLAY OLED (SH1106 128x64) ao Arduino Mega  

O display é responsável por apresentar as informações gerais cadastradas. Como nome, origem, bioma e copa. Ele se comunica com o Arduino Mega por meio do protocolo I2C. Abaixo estão as conexões utilizadas:  
<div align="center">
 <table>
 <tr>
   <td>
      <img src="imagens/displayOLED.jpeg" alt="Conexão DISPLAY com o Arduino Mega" width="400px">
   </td>
   <td>
      <table>
        <tr><th>Pino do Display Oled </th><th>Pino do Arduino Mega</th></tr>
        <tr><td><b>3.3V</b></td><td><b>3.3V</b></td></tr>
        <tr><td><b>GND</b></td><td><b>GND</b></td></tr>
        <tr><td><b>SDA</b></td><td><b>Porta digital 20</b></td></tr>
        <tr><td><b>SCL</b></td><td><b>Porta digital 21</b></td></tr>
      </table>
   </td>
 </tr>
</table>
</div>

### Distribuição de Tensão e Terra  

Como vários componentes começaram a utilizar as mesmas portas do Arduino, foi necessário organizar melhor as conexões. Para isso, utilizamos uma placa de fenolite, criando trilhas para as portas mais utilizadas:  

<div align="center">
<table>
 <tr>
   <td>
      <img src="imagens/plaquinha.png" alt=" placa de fenolite" width="400px">
   </td>
   <td>
      <img src="imagens/aranha1.jpeg" alt="Distribuição de trilhas na placa de fenolite" width="400px">
   </td>
   <td>
     <table>
        <tr><th>Porta</th><th>Cor</th></tr>
        <tr><td><b>GND</b></td><td>⚪ Branco</td></tr>
        <tr><td><b>5V</b></td><td>🔴 Vermelho</td></tr>
        <tr><td><b>3.3V</b></td><td>🟡 Amarelo</td></tr>
      </table>
   </td>
 </tr>
</table>
</div>

### Integração: Módulo RFID e Display OLED  

 Integração entre o **módulo RFID** e o **display OLED (SH1106 128x64)**, conectados ao **Arduino Mega**. O display foi configurado para exibir mensagens conforme a interação com o RFID.  

A imagem abaixo mostra a configuração do hardware, onde os componentes estão interligados por meio de uma placa de fenolite, responsável por distribuir as tensões corretamente.  

<div align="center">
  <img src="imagens/integrado1.jpeg" alt="Integração do módulo RFID com Display OLED" width="400px">
</div>

> **Mensagem no Display:** "Aproxime-se de uma árvore...!"  
> Essa mensagem é um indicativo de que o sistema está aguardando um cartão RFID.

# Conexão da Fita LED  

A imagem abaixo ilustra a configuração da conexão:  

<div align="center">
<table>
 <tr>
   <td>
      <img src="imagens/fitaled.jpeg" alt="Fita LED" width="350px">
   </td>
   <td>
     <table>
        <tr><th>ESP32</th><th>Fita LED</th></tr>
        <tr><td><b>GND</b></td><td>GND</td></tr>
        <tr><td><b>5V</b></td><td>5V</td></tr>
        <tr><td><b>Porta digital</b></td><td>Conexão de dados</td></tr>
      </table>
   </td>
 </tr>
</table>
</div>

---

## Integração: Fita LED e Módulo RFID  

A integração entre o **módulo RFID**, **Fita LED** e **botão de interação** é realizada utilizando um **Arduino Mega**.  

A imagem abaixo apresenta a configuração do hardware, onde os componentes estão conectados por meio de uma **placa de fenolite**, responsável por distribuir corretamente as tensões e conexões.  

O sistema funciona da seguinte forma:  
- Ao aproximar uma **tag RFID** do módulo, o botão permite a interação.  
- O LED verde acende caso a árvore vinculada ao UID contenha frutos, e vermelho caso contrário.  
- Outra Fita LED indica, em **amarelo**, os meses de frutificação. Na imagem, a configuração abrange os **12 meses do ano**.  

<div align="center">
 <td>
      <img src="imagens/FACE1e5-Integrada.jpeg" alt="Integracao 1" width="300px">
 </td>
<table>
 <tr>
   <td>
     <table>
        <tr><th>Arduino Mega</th><th>Placa de Fenolite</th></tr>
        <tr><td><b>GND</b></td><td>Trilha 1</td></tr>
        <tr><td><b>5V</b></td><td>Trilha 2</td></tr>
        <tr><td><b>3.3V</b></td><td>Trilha 3</td></tr>
      </table>
   </td>
     <td>
     <table>
        <tr><th>Componente</th><th>Conexão</th></tr>
        <tr><td><b>GND - Fita LED</b></td><td>Placa - Trilha 1</td></tr>
        <tr><td><b>Terminal 1 - GND Botão</b></td><td>Placa - Trilha 1</td></tr>
        <tr><td><b>GND - RC522</b></td><td>Placa - Trilha 1</td></tr>
        <tr><td><b>GND - Display</b></td><td>Placa - Trilha 1</td></tr>
        <tr><td><b>5V - Fita LED</b></td><td>Placa - Trilha 2</td></tr>
        <tr><td><b>3.3V - RC522</b></td><td>Placa - Trilha 3</td></tr>
        <tr><td><b>3.3V - Display</b></td><td>Placa - Trilha 3</td></tr>
        <tr><td><b>Terminal 2 - Botão</b></td><td>Porta digital</td></tr>
        <tr><td><b>Demais conexões do Display e RC522</b></td><td>Se repetem</td></tr>
      </table>
   </td>
 </tr>
</table>
</div>

---

## Integração: Fita LED, Módulo RFID e Display OLED  

Integração **módulo RFID**, **Display OLED (SH1106 128x64)**, **Fita LED** e **botões de interação**, todos conectados ao **Arduino Mega**.  

O link abaixo é um pequeno vídeo onde explico o funcionamento das **Faces 1 (Informações Gerais)** e **Face 5 (Frutificação)**, que estão integradas ao sistema.  

👉 [Acesse aqui a explicação detalhada](https://www.youtube.com/shorts/Pyn25ikelZ8)

---

## Distribuição de Tensão e Terra Completa

<div align="center">

<img src="imagens/AranhaCompleta.jpeg" alt="Placa de fenolite completa" width="600px">

<table border="1" cellspacing="0" cellpadding="6">
  <tr>
    <th>Trilha</th>
    <th>Cor</th>
    <th>Uso</th>
  </tr>
  <tr>
    <td><b>GND</b></td>
    <td>⚪ Branco</td>
    <td>
      Display, RC522, Arduino, button_F2, led_F2, button_F4, led_F4,<br>
      led1_F4, led_mes_F4, button_F5, led1_F5, led_mes_F5,<br>
      temperatura, qualidade_ar, button_F1, button_F2, button_F3, button_F4
    </td>
  </tr>
  <tr>
    <td><b>5V</b></td>
    <td>🔴 Vermelho</td>
    <td>
      Arduino, led_F2, led1_F4, led_mes_F4,<br>
      led1_F5, led_mes_F5, temperatura, qualidade_ar
    </td>
  </tr>
  <tr>
    <td><b>3.3V</b></td>
    <td>🟡 Amarelo</td>
    <td>Arduino, Display, RC522</td>
  </tr>
</table>

</div>

---
## Face 3 - Temperatura e Qualidade do Ar

A imagem abaixo mostra a configuração do hardware, onde duas fitas LED de 9 segmentos (representadas por apenas 1 segmento na imagem) estão conectadas ao ESP32, juntamente com os sensores ENS160 e AHT21.

Observação: Na imagem, foi utilizado um DHT21, porém as conexões são as mesmas utilizadas no protótipo com o AHT21 & ENS160 (estão no mesmo módulo).

<div align="center"> 
 <img src="imagens/esp32.jpeg" alt="Integração 1" width="200px"> 
</div> 

<div align="center"> 
  <table>
  <tr>
    <td>
      <img src="imagens/AHT21sensorfrente.jpg" alt="sensor AHT21" width="200px">
       <p>AHT21 & ENS160 </p>
    </td>
    <td>
     <img src="imagens/AHT21sensorlateral.jpg" alt="sensor AHT21 lateral" width="200px">
      <p>AHT21 & ENS160 </p>
   </td>
    <td>
     <img src="imagens/esp.jpg" alt="esp 32" width="200px">
     <p>ESP32 + AHT21 & ENS160 </p>
   </td>
    <td>
     <img src="imagens/esp_vertical.jpg" alt="esp vertical" width="200px">
   </td>
  </tr>
  </table>
</div> 

# Processo de Montagem II e testes 

<div align="center">
  <table>
 <tr>
   <td>
      <img src="imagens/testeLed1.jpeg" alt="Integracao 1" width="200px">
       <p>Testes iniciais com led simples.</p>
   </td>
    <td>
     <img src="imagens/testeLed2.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/leitura.jpeg" alt="Integracao 1" width="200px">
     <p>Teste do raio de ação da leitura</p>
   </td>
   <td>
     <img src="imagens/corte3.jpeg" alt="Integracao 1" width="200px">
   </td>
 </tr>
</table>
<table>
 <tr>
   <td>
      <img src="imagens/FitaLED1.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/FitaLED2.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/teste1.jpeg" alt="Integracao 1" width="200px">
   </td>
   <td>
     <img src="imagens/corte-temp.jpeg" alt="Integracao 1" width="200px">
      <p>face 3</p>
   </td>
 </tr>
</table>
 <table>
 <tr>
   <td>
      <img src="imagens/teste.jpeg" alt="Integracao 1" width="200px">
       <p>Integração da face 4 - Floração.</p>
   </td>
    <td>
     <img src="imagens/teste2.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/porte.png" alt="Integracao 1" width="200px">
     <p>face 2 - Porte</p>
   </td>
   <td>
     <img src="imagens/porte2.jpeg" alt="Integracao 1" width="200px">
   </td>
 </tr>
</table>
</div>

<div align="center">
 <img src="imagens/mesaAberta.jpeg" alt="Integracao 1" width="400px">
 </div>
<div align="center">
  <table>
 <tr>
   <td>
      <img src="imagens/cubo.png" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/cuboConexao.jpeg" alt="Integracao 1" width="200px">
   </td>
    <td>
     <img src="imagens/cubo2.jpeg" alt="Integracao 1" width="200px">
   </td>
   <td>
     <img src="imagens/cubo3.jpeg" alt="Integracao 1" width="200px">
   </td>
 </tr>
</table>
</div>
<div align="center">
  <table>
 <tr>
   <td>
      <img src="imagens/cubo_aberto.jpg" alt="cubo_aberto" width="200px">
   </td>
    <td>
     <img src="imagens/copa.jpg" alt="copa" width="200px">
   </td>
    <td>
     <img src="imagens/cubo_flash.jpg" alt="cubo_flash" width="200px">
   </td>
   <td>
     <img src="imagens/campo.jpg" alt="Integracao 1" width="200px">
   </td>
 </tr>
</table>
</div>


# Dificuldades e Expectativas

<div >
<p>O protótipo foi desenvolvido ao longo da disciplina, embora não desde o início. Na primeira metade do semestre, foram apresentados conceitos e noções de hardware, como módulos e sistemas embarcados, com o objetivo de capacitar os alunos a desenvolverem seus próprios projetos. Como o CIA foi realizado em parceria com o curso de Arquitetura e Urbanismo, o tema foi proposto por eles: arborização.</p>

<p>Desde muito cedo, mesmo sem o conhecimento técnico consolidado, tivemos vários encontros para discutir o que seria projetado e como isso poderia ser feito. E foi aí que enfrentei uma das primeiras dificuldades: no início, foi complicado alinhar o que se desejava com o que era possível realizar. Como eu fazia parte do grupo responsável pela parte eletrônica do dispositivo, cabia a mim comunicar se determinada ideia era viável ou não. Mas, na época, eu tinha pouca noção técnica, o que limitou minha capacidade de ser mais assertivo tanto ao propor quanto ao validar ideias.</p>

<p>Como eram dois grupos distintos trabalhando com o mesmo tema, decidiu-se interligar ambos em algum ponto. O CIA seria o protótipo móvel, e o [repositório], o fixo. Como o projeto seria exposto ao público em uma sala no CT12 do campus, optou-se por definir um percurso nas proximidades do local. Na “face de apoio”, foi projetado o mapa com a localização das árvores cadastradas no programa, permitindo que os visitantes se orientassem individualmente pelo percurso. A imagem abaixo mostra esse mapa fixado:</p>

<div align="center"> 
  <table>
  <tr>
    <td>
      <img src="imagens/mapa.png" alt="maps_cubo" width="400px">
    </td>
    <td>
     <img src="imagens/maps_cubo.jpg" alt="maps_cubo" width="400px">
   </td>
  </tr>
  </table>
</div>

<p>Sem dúvida, o maior desafio que enfrentei foi fazer as conexões. Quando finalmente recebemos todas as faces do cubo, faltava menos de uma semana para a entrega final. Embora tudo estivesse bem alinhado teoricamente, subestimei a dificuldade de alojar todos os componentes eletrônicos dentro do cubo com tantas conexões. Não previ que isso se tornaria um grande problema. O espaço era extremamente justo, e era difícil conectar os fios sem esbarrar em outros ou alcançar certos pontos internos.</p>

<p>Mesmo que todas as faces funcionassem individualmente, ou mesmo juntas com o cubo estático, isso ainda não era suficiente. A maior provação seria colocar o dispositivo na mão de outra pessoa e ainda assim tudo funcionar. E esse era meu maior receio. Pela experiência de montagem, sabia que a movimentação poderia facilmente causar o desligamento de alguma conexão. Se isso ocorresse, encontrar o erro em meio ao emaranhado de fios seria um pesadelo. Provavelmente seria necessário remover uma das faces para realizar a manutenção. Então tudo que eu pensava era: “Quais são os passos que devo executar se algo der errado?”</p>

<p>No dia da apresentação, o percurso foi realizado apenas uma vez, e fui eu quem guiou o grupo com o cubo em mãos. Meus movimentos foram comedidos e conscientes. No fim, o protótipo demonstrou ser bastante estável, mesmo com movimentos mais bruscos. Acredito que, se outra pessoa o tivesse manuseado, o sistema teria se comportado da mesma forma. Durante toda a exposição, que ocorreu em uma sala junto aos demais projetos, não precisei abrir o cubo nenhuma vez sequer🙌.</p>

<p>Os únicos contratempos aconteceram na programação e em um botão físico. Em um momento, o programa travou na tela de busca, e consegui contornar a situação com uma caneta, acionando o botão de reset do Arduino. Em outro, um botão se soltou, e improvisei uma gambiarra difícil até de explicar. Mas, no fim das contas, o programa, as conexões e a proposta funcionaram – e muito bem!</p>

</div>


# 🎥 Vídeo do Protótipo
Você pode conferir o vídeo completo clicando no link abaixo:</p>
👉 [Vídeo do protótipo finalizado](https://youtu.be/VTNj8Cz4gfk) </p>
👉 [Vídeo curto](https://youtube.com/shorts/Ozqm23LIcGA)


