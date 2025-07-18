// main.cpp

#include <Arduino.h>
//
#include <PubSubClient.h>
// Ajuda a encapsular e fazer o contrario com arquivos jsons
#include <ArduinoJson.h>
// É preciso para ter o certificado da conexao
#include <WiFiClientSecure.h>
#include "internet.h"
#include "certificados.h"

#define portaLed 2

// porta 8883 é a porta com certificado e segurança
// porta normal 1883, sem certificado de segurança

// MQTT -> Protocolo de mensagem leve (comparado com o twitter-> vc cria uma conta e lá vc escreve suas mensagens. Quem recebe? O servidor. Diferente do e-mail, no caso quem ve é somente quem te segue. O publisher, publica no BROKER (SERVIDOR MQTT)).
// Subscriber -> Quem se inscreveu no mesmo tópico.
// Existem vários brokers públicos -> Mosquito

const int mqtt_port = 8883;
// Tomar cuidado pois as vezes o aluno copia o mesmo que o seu e dá ruim rsrs cada um cria o seu
const char *mqtt_id = "idDoEsp32";
const char *mqtt_SUB = "senai134/comandos";
const char *mqtt_PUB = "senai134/sensores";

WiFiClientSecure espClient;
PubSubClient mqtt(espClient);

void conectaMQTT();
// todas as mensagens chegam no callback
void Callback(char *topic, byte *payload, unsigned int length);

void setup()
{
  Serial.begin(9600);
  // ADIDIONANDO:
  pinMode(portaLed, OUTPUT);
  conectaWiFi();

  espClient.setCACert(AWS_ROOT_CA);
  espClient.setCertificate(AWS_CERT);
  espClient.setPrivateKey(AWS_KEY);

  mqtt.setServer(AWS_BROKER, mqtt_port);
  mqtt.setCallback(Callback);
}

void loop()
{
  // verifica a conexao wifi
  checkWiFi();

  // se nao estiver conectado ao mqtt, ele conecta
  if (!mqtt.connected())
  {
    conectaMQTT();
  }

  // o callback só é chamado graças a essa chamada:
  mqtt.loop();

  bool estadoBotao = digitalRead(0);
  static bool estadoAnteriorBotao = 1;

  bool envio = 0;

  JsonDocument doc;

  // Serial.println(estadoBotao);

  if (estadoBotao != estadoAnteriorBotao)
  {
    doc["botao"] = !estadoBotao;

    envio = 1;
  }

  estadoAnteriorBotao = estadoBotao;

  if(envio){
    String msg;
    serializeJsonPretty(doc, msg);
  
    //ver no monitor serial
    Serial.println(msg);
  
    mqtt.publish(mqtt_PUB, msg.c_str());
  }

}

void Callback(char *topic, byte *payload, unsigned int length)
{
  String msg((char *)payload, length);
  Serial.printf("Mensagem recebida (topico: [%s]): %s\n\r", topic, msg.c_str());

  // Código novo
  JsonDocument doc;

  // Deserialização:
  DeserializationError erro = deserializeJson(doc, payload, length);

  if (erro)
  {
    Serial.println(erro.c_str());
  }

  if (!doc["led"].isNull())
  {
    bool estadoLed = doc["led"];

    digitalWrite(portaLed, estadoLed);
  }
}

// Função bloqueantes: Caso caia, o projeto vai direto para o ELSE. Isto é, caiu a internet, cai tudo. O ideal é que faça um ajuste para ser não bloquenate. que salve na emoria do esp e depois quando voltar ta ok.
void conectaMQTT()
{
  while (!mqtt.connected())
  {
    Serial.print("Conectando ao AWS IoT Core ...");
    if (mqtt.connect(mqtt_id))
    {
      Serial.println("conectado!");
      mqtt.subscribe(mqtt_SUB);
    }
    else
    {
      Serial.printf("falhou (%d). Tentando novamente em 5s \n\r", mqtt.state());
      delay(5000);
    }
  }
}