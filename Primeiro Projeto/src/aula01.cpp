// // Função pinMode e Digital Write estão dentro de Arduino.h
// // #include <Arduino.h>

// // Posso declarar a função e e atribuir após o loop. Ou já crio a função aqui. Independe... Criar protótipo*** Verificar se é isso mesmo rsrsrsrs 🤣

// // void setup()
// // {
//   // Configura a porta que estaremos usando e se é saida ou entrada
// //   pinMode(4, OUTPUT);
//   // Monitor serial -> Serve para saber como o esp está
//   // Iniciando o comunicador/a serial
//   // A velocidade que a porta USB se comunica
// //   Serial.begin(115200);
// // }

// // void loop()
// // {
//   //console.log()
//   // Serial.println("Led ligado!");

//   // digitalWrite(4, HIGH);
//   // delay(500);

//   // Serial.println("Led desligado!");

//   // digitalWrite(4, LOW);
//   // delay(500);

//   // funcao milis -> o microcontroloador tem um tipo de relógio,

// //   uint32_t agora = millis();
// //   u_int32_t tempoDeEspera = 500;
// //   uint32_t agoraAtualizado = agora + tempoDeEspera;

//   // inicio : 53
//   // Serial.println(agora);
//   // Serial.println(agora - tempoDeEspera);
//   // delay(500);

// //   if (agoraAtualizado < agora)
// //   {
// //     Serial.println("Led ligado!");

// //     digitalWrite(4, HIGH);
//     // delay(500);
// //   }
// //   else
// //   {
// //     Serial.println("Led desligado!");

// //     digitalWrite(4, LOW);
//     // delay(500);
// //   }

//   // O delay trava o programa
//   // delay(1000);
// // }

// // Função pinMode e Digital Write estão dentro de Arduino.h
// #include <Arduino.h>

// // Posso declarar a função e e atribuir após o loop. Ou já crio a função aqui. Independe... Criar protótipo*** Verificar se é isso mesmo rsrsrsrs 🤣

// void setup()
// {
//   // Configura a porta que estaremos usando e se é saida ou entrada
//   pinMode(2, OUTPUT);
//   // Monitor serial -> Serve para saber como o esp está
//   // Iniciando o comunicador/a serial
//   // A velocidade que a porta USB se comunica
//   Serial.begin(115200);
// }

// #define tempoEspera 1000

// unsigned long inicioEvento = 0;
// bool estadoLed = 0;

// void loop()
// {

//   //parece o unsigned long
//   uint32_t agora = millis();

//   if ((agora - inicioEvento) >= tempoEspera)
//   {
//     estadoLed = !estadoLed;

//     digitalWrite(2, estadoLed);

//     inicioEvento = agora;
//   }
// }


// //Comentários:
//? aaaaaaa
//! aaaaaaa
//TODO aaaaaaa
//? aaaaaaa
//* aaaaaaa