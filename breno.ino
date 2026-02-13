#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//const char* ssid = "PIC2-2.4G";
//const char* password = "engcomp@ufes";

const char* ssid = "ERUS 2.4GHz";
const char* password = "ultrabots3";

// Coloque a URL "Raw" PERMANENTE do seu arquivo JSON (sem o token!)
//String url_base_dados = "https://raw.githubusercontent.com/BrenoCSilva/Arvore-2/refs/heads/main/thieberson/arvore.json";

// 1. Descubra o IP do seu PC no terminal (ipconfig ou ifconfig)
const char* ip_do_servidor = "192.168.0.100"; // Substitua pelo IP real do seu computador

// 2. No seu loop ou função de leitura:
String url_base_dados = "http://";
String uid_lido = "CF877841"; 

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print("oiiiiiiiiiiiiiiiiiiii: ");

  // --- 1. Conectando ao Wi-Fi ---
  Serial.print("Conectando ao Wi-Fi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());


  url_base_dados += ip_do_servidor;
  url_base_dados += ":3000/api/arvore/";

    // --- Simulação: UID lido pelo sensor RFID ---
  Serial.print("Simulando leitura do UID: ");
  Serial.println(uid_lido);
  url_base_dados += uid_lido;


}

void loop() {


  // --- 2. Fazendo a Requisição HTTP GET ---
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;


    Serial.print("Chamando API em: ");
    Serial.println(url_base_dados);

    // Inicia a conexão com a URL
    http.begin(url_base_dados); 
    
    // Faz a requisição GET e guarda o código da resposta (ex: 200 para sucesso, 404 para não encontrado)
    int httpCode = http.GET(); 

    if (httpCode > 0) { // Se a requisição foi bem-sucedida
      Serial.printf("Código de resposta HTTP: %d\n", httpCode);

      if (httpCode == HTTP_CODE_OK) {
        // Pega o corpo da resposta (o conteúdo do seu arquivo JSON) como uma String
        String payload = http.getString();
        
        // --- 3. Processando o JSON (Parsing) ---
        // Aloca memória para o documento JSON. Ajuste o valor se seu JSON for muito grande.
        DynamicJsonDocument doc(2048);

        // Converte a String 'payload' para um objeto JSON que o código pode entender
        DeserializationError error = deserializeJson(doc, payload);

        if (error) {
          Serial.print("Falha ao processar o JSON: ");
          Serial.println(error.c_str());
        } else {
          Serial.println("JSON processado com sucesso!");

          // --- 4. Extraindo e Usando os Dados ---
          // Agora você pode acessar os dados como se fossem um objeto
          
         if (doc.isNull()) {
              Serial.println("ERRO: Resposta vazia da API!");
          } else {
            const char* nome = doc["nome"]; // Pega direto do objeto principal
            const char* porte = doc["porte"];
            const char* copa = doc["copa"];
            const char* origem = doc["origem"];
            const char* bioma = doc["bioma"];
              bool tem_flor = doc["temFrutos"]; // Use o nome exato do seu Schema!

             // Mostra os resultados no Monitor Serial
             Serial.println("--- DADOS DA ÁRVORE ENCONTRADA ---");
             Serial.printf("Nome: %s\n", nome);
             Serial.printf("Porte: %s\n", porte);
             Serial.printf("Copa: %s\n", copa);
             Serial.printf("Origem: %s\n", origem);
             Serial.printf("Bioma: %s\n", bioma);
             Serial.printf("Tem flor? %s\n", tem_flor ? "Sim" : "Não");
             
          }
        }
      }
    } else {
      Serial.printf("Falha na requisição HTTP. Erro: %s\n", http.errorToString(httpCode).c_str());
    }

    // Libera os recursos da conexão
    http.end(); 
  } else {
    Serial.println("Erro: Desconectado do Wi-Fi.");
  }

  // Espera 10 segundos antes de tentar de novo
  delay(10000); 
}
