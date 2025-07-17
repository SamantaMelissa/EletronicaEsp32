// #include <Arduino.h>

// // void setup()
// // {
// //! INPUT_PULLUP E
// //! INPUT não tem p pullup. Mas se você POR O HIGH depois, ele ativa o pull up

// // pinMode(0, INPUT_PULLUP);

// // pinMode(0, INPUT);

// // digitalWrite(0, HIGH);
// // }

// // void loop()
// // {
// //     digitalWrite(13, HIGH);
// //     delay(500);
// //     digitalWrite(13, LOW);
// //     delay(500);

// // }

// void setup()
// {
//     pinMode(23, INPUT_PULLUP);
//     Serial.begin(115200);
// }

// unsigned int count = 0;

// bool estadoBotaoAnterior = 1;

// #define tempoEspera 30

// unsigned long tempoAnterior = 0;

// void loop()
// {
//     uint32_t tempoAtual = millis();

//     // Serial.println("aaaaa");
//     // Serial.println(tempoAtual);
//     // Serial.println("aaaaa");

//     // delay(500);

//     bool estadoBotaoAtual = digitalRead(23);
//     // Serial.println(estadoBotaoAtual);

//     if (estadoBotaoAnterior != estadoBotaoAtual)
//     {
//         if ((tempoAtual - tempoAnterior) >= tempoEspera)
//         {
//             if (estadoBotaoAnterior == 1 && estadoBotaoAtual == 0)
//             {
//                 count++;

//                 // Serial.println(estadoBotao);
//                 Serial.println(count);
//                 // delay(500);
//             }

//             tempoAnterior = tempoAtual;

//             // Serial.println("entrou");
//         }
//     }
//     estadoBotaoAnterior = estadoBotaoAtual;
// }

// // debounce - ajustar ruido do botao