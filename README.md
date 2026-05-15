# Módulo Simples

Dentro de `astro/src/simple_module_example` podemos encontrar um modelo básico do funcionamento de um Publisher e Subscriber. O Publisher é responsável por enviar a informação (mensagem), enquanto o Subscriber é responsável por receber esta informação.

Um subscriber normalmente tem um formato parecido com a imagem abaixo. Onde temos que passar a chave da mensagem, o formato da mensagem, um possível bloco de memória onde a mensagem será armazenada, o tamanho dessa mensagem, a função que vai funcionar como handler e subscribe_how (este parâmetro controla como a assinatura da mensagem será tratada no gerenciamento da fila de mensagens).

```
astro_subscribe_message (
    ASTRO_STRING_EXAMPLE_MESSAGE_NAME,
    ASTRO_STRING_EXAMPLE_MESSAGE_FMT,
    message,
    sizeof(astro_string_example_message),
    handler,
    subscribe_how
);
```

Já o Publisher irá variar bastante de acordo com a mensagem que deve ser enviada, ou seja, para qual módulo será a comunicação. Mas podemos ter uma noção baseada na imagem abaixo. Precisamos passar todas as informações necessárias para cada publish, principalmente contendo a mensagem em si, o host, o timestamp e a chave da mensagem (sempre analisar a tipagem da struct que irá utilizar).

```
astro_string_example_message main_message;
char *main_content;
main_content = "Mensagem enviada através do módulo publish example";

printf("Enviando mensagem: %s\n", main_content);

main_message.num_message = 1;
main_message.content_message = main_content;
main_message.timestamp = astro_get_time();
main_message.host = astro_get_host();

astro_publish_example_publish_command_message(&main_message);
```

```
void
astro_publish_example_publish_command_message(astro_string_example_message *message)
{
    IPC_RETURN_TYPE err;
    
    err = IPC_publishData((char *) ASTRO_STRING_EXAMPLE_MESSAGE_NAME, message);
    astro_test_ipc_exit(err, "Could not publish", (char *) ASTRO_STRING_EXAMPLE_MESSAGE_FMT);
}
```

Dentro de uma funcionalidade onde é necessário um Subscriber normalmente é utilizado um Handler, que é uma função responsável por realizar alguma ação após o recebimento dessa mensagem. O handler é uma função bem simples, podendo conter qualquer coisa dentro, como na imagem abaixo.

```
static void
astro_simple_handler(astro_string_example_message *current_message)
{
    printf("Mensagem recebida: %s\n", current_message->content_message);
}
```

### Anotações Bruno:

**Replicar e Simplificar**: Replique o exemplo `simple_module_example` e execute-o. Em seguida, remova qualquer parte do código que não seja necessária.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcH8jSDYp0-w1zapIaGi8dZOGH-NyjvEJK7Cjt7hVkRDIYmohCOAxoCrxYC_w9upRnnlvbxtACwm5ymoMkSLd8cHkAlpEyxdXVEtCT6mtDF9e2E1weKQn6oBz8GeUsvqXrivP28?key=z6YPq4aOMJRxIcAMJnYHJA)


## Criando um Módulo no Astro

Para criar um módulo no Astro precisamos começar criando uma pasta dentro de `astro/src`. Dentro desta basta criar os arquivos .c e .h necessários para o desenvolvimento do módulo.

Para compilação do módulo é necessário criar um arquivo Makefile (seguir o padrão de outros módulos). Vale ressaltar para o uso correto das flags que tem relação direta com todas as bibliotecas .h que estão sendo importadas diretamente nos arquivos que você criou. Por exemplo, se dentro do seu código está sendo utilizando a biblioteca:

```
#include <astro/robot_ackerman_interface.h>
```

será necessário incluir a flag:

```
-lrobot_ackerman_interface
```

## Executando um Módulo

Para compilar basta executar o comando make e, caso não tenha dado nenhum erro, rodar no terminal `./<nome_do_executavel>`

## Tarefa 1# - Criando um módulo

Para aplicar esse conhecimentos vamos criar nosso próprio módulo.

1. Crie um módulo usando o dentro da pasta astro/src usando como exemplo o simple_module_example.
2. Seu programa deve receber a mensagem (subscriber) astro_robot_ackerman_motion_command_message. Lembre-se que para isso será necessário criar um handler para recepção dessa mensagem.
3. Em seguida, deve-se publicar a mensagem (publisher): astro_base_ackerman_motion_command_message. Vale ressaltar que éssa mensagem é do obstacle_avoider.
4. Não é necessário fazer nenhum processamento com os dados recebido no item 2, apenas repasse direto via publisher no item 3. (Tome cuidado com os tipos das structs que estão sendo recebidas e enviadas).
5. Crie um makefile e compile o código. Se tudo tiver certo, podemos testar! :)

Observação I: É necessário modificar a função `handler`, pois ela será utilizada para implementar a lógica do Publish. No entanto, para o primeiro passo, você pode deixá-la vazia (ou printando algo), apenas para realizar testes iniciais com o Subscribe.

Observação II : Outros módulos já utilizam de métodos de publisher e subscriber dessas mensagens, então você deve reutilizar esses métodos já aplicados. Você pode utilizar o comando ./grep_all que fica dentro de astro/bin para encontrar outros códigos que utilizam as structs necessárias.

**Buscar Implementações Relevantes**: Use o comando `./grep_all` no terminal para localizar implementações relacionadas ao que você deseja encontrar. Por exemplo, para buscar códigos relacionados a `astro_robot_ackerman_motion_command_message`, digite:
```
./grep_all astro_robot_ackerman_motion_command_message
```

Identifique e documente em qual parte do código essa referência aparece.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdn_iGajJbQ8EoL1QApYwg3v-nrZzDCMw6k28sEZKZgwZ7mJwye4gTu-emtxzjCiuB5H2ck5Emp20Mn6pjwyfKgVdhnsYSsXgiEY3hy6T_O0h3n70_-W-YNJvS24EUgC_VvhZcwvw?key=z6YPq4aOMJRxIcAMJnYHJA)

Esta imagem ilustra o uso do comando `grep_all`. Podemos observar como ele retorna a linha e o arquivo onde o código está localizado. Assim, você pode abrir o arquivo correspondente e analisar exemplos de estruturas e o uso de cada função para auxiliar na implementação do seu código.

Dica: Examine diversos códigos para identificar um "padrão" de implementação. Para ajudar no entendimento, saiba que a struct `astro_robot_ackerman_motion_command_message` é justamente a **interface de entrada principal** do `obstacle_avoider`.  O `obstacle_avoider` é um módulo do sistema de mobilidade autonoma, que se inscreve (através da função `astro_robot_ackerman_subscribe_motion_command`) para receber mensagens do tipo `astro_robot_ackerman_motion_command_message` publicadas por módulos de alto nível (como o `navigator_ackerman` ou o `motion_planner` e agora do seu próprio módulo criado também).

**Testar o Subscribe**: Após localizar as funções necessárias para implementar o Subscribe, incorpore-as no código. Em seguida, execute o programa e verifique se ele funciona corretamente.

**Implementar o Publish**: Repita os passos 2 e 3 para implementar o Publish. Sempre que possível, mantenha todas as funcionalidades no mesmo arquivo .c, para garantir simplicidade e alinhamento com o padrão dos códigos existentes.

**Seguir a Tarefa 2**: Após concluir os passos acima, continue com a execução da tarefa 2.

## Tarefa 2# - Testando o módulo

Para testar este módulo criado você deverá seguir os passos para execução de um [Process](https://github.com/LumeRobotics/docs/blob/main/Tutorials/ASTRO/sistema_lume_mobilidade_autonoma/sistema_lume_mobilidade_autonoma_pt-BR.md) e [Simulator Mode](https://github.com/LumeRobotics/docs/blob/main/Tutorials/ASTRO/simulator_mode/simulator_mode.md). Com todo o sistema rodando perfeitamente, você deve:

1. Inserir o veículo no mapa, clicando em Place Robot
2. Marcar o destino com Place Final Goal
3. Calcular a rota
4. Executar clicando em Go

Se tudo tiver de acordo o veículo deve trafegar sem nenhum problema até o destino final marcado. Isso se dá por todas as variáveis externas ativas e funcionando adequadamente. O ProControl GUI deve estar com essa aparência:

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXd_C_Wy4JJu3HUXKBnqtTjAQMyC6oGoPj5mqMk478UNC-K6tTP5ReP_QbmjbMXB43LPB3Qy0hK1INdUO08P_cJs7h3i-YK8OPD6LazurB3afNCRSYQqPSZYjSE96r-kmNnc3aKHMDUAhIZmWLkwM12hofY?key=z6YPq4aOMJRxIcAMJnYHJA)

[!WARNING] perigo

De maneira geral, quando o sistema de mobilidade autonoma está sendo executado através de um processo, módulos são executados. Esses módulos enviam e recebem mensagens de feedback para quem estiver escutando o seu tipo de mensagem. Então você não precisa publicar uma mensagem do tipo `astro_robot_ackerman_motion_command_message` para escutar seus valores sendo atualizados, desde que o sistema esteja atualizando ele.

É isso que acontece com o módulo `obstacle-avoider` do process-navigate_primeiros_passos_sensorbox-6_mss.ini(tem que ser o mss!) . Quando o simulador navigate está executando, constantemente ele envia mensagens do tipo astro_robot_ackerman_motion_command_message (veja isso através do seu subscribe, você irá identificar que a sua publicação manual anterior não será  mais necessária). 

Agora vamos expandir o módulo que foi criado na Tarefa #1, para entender a justificativa para a nova implementação você deve parar o processo do obstacle_avoider dentro do Proccontrol GUI. Para isso, basta clicar no processo obstacle_avoider no ProControl GUI e depois clicar em Stop. Assim o processo de ficar vermelho, como na imagem abaixo.

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeYfgm8T6wlQOiuQjk4js-Gtk_8sBX3sZe7K6LSjhWrwKjEgRJUNdjuJr2axojwtpFcc2dWzk07IY38KiDh_o8Ih-pDINTPCIpL5UaVrF7gIUTyN24up1nDsyHSV_NJAfLfQjIfLHDnjcoYBSM9PHy7850U?key=z6YPq4aOMJRxIcAMJnYHJA)

Ao fazer isso, e tentar trafegar com o veículo novamente, você irá observar que o mesmo não irá andar. 

### Por que o veículo para quando o `obstacle_avoider` é interrompido?

Isso acontece devido a uma medida de segurança implementada no módulo. O fluxo de comunicação funciona em cascata: o planejador envia as rotas para o `obstacle_avoider`, que as processa e as repassa continuamente para o simulador (através da mensagem `ASTRO_BASE_ACKERMAN_MOTION_COMMAND_NAME`).

O astro_robot_ackerman_motion_command_message possui o atributo `astro_robot_and_trailers_motion_command_t *motion_command` para descrever a trajetória **futura** e **desejada** que o planejador quer que o veículo faça . Assim que o `obstacle_avoider` recebe essa struct, baseado nos procedimentos de validação, se a trajetória causará uma colisão ou uma aceleração perigosa, ele **altera os comandos originais da struct** (recalculando *v* para frear o carro, por exemplo).

Depois dessa modificação de segurança, ele pega esses dados já filtrados e os empacota em **outra** mensagem (`astro_base_ackerman_motion_command_message`), enviando-a finalmente para as rodas do carro ou para o simulador executarem.

O `base_ackerman` possui um mecanismo interno que monitora o tempo decorrido desde o último comando de movimento recebido (um parâmetro chamado `motion_timeout`). Quando você mata o processo do `obstacle_avoider` no Proccontrol, ele para de enviar essas mensagens de controle. Assim que o tempo limite é excedido, o simulador assume que houve uma falha crítica de comunicação e, por segurança, ele limpa a fila de comandos e zera a velocidade do veículo (`target_v = 0`), forçando-o a parar imediatamente. O sistema nunca permite que o veículo continue andando "às cegas" se parar de receber comandos.

Então, o grande problema é que o obstacle_avoider parou de publicar informações ASTRO_BASE_ACKERMAN_MOTION_COMMAND_NAME e o sistema (por segurança) parou o veículo. Então agora você deve compilar e rodar o seu código da Tarefa #1 atualizado para que o veículo volte a andar. Sua tarefa é forçar o envio dessas informações que obstacle_avoider não faz mais.

Dica: use o ./grep_all

Se tudo der certo, ao rodar seu arquivo executável, seu veículo começará a andar novamente.

## Próximo Tutorial

Para continuar seu aprendizado, siga para o próximo tutorial: [Implementando Parâmetros em seu Módulo](./implementing_parameters_in_modules.md)


// Observação: Atente-se para o fato de que <variable> é o nome do parametro nomeado em {"<module_name>", "<param_name>", ASTRO_PARAM_ONOFF, &var, 1, NULL}.


