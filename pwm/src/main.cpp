#include <Arduino.h>

#define canalPWM 0 //*Canal de 0 a 15
#define frequenciaPWM 50 //*50Hz para servo motores
#define resolucaoBitsPWM 16 //*Dev Kit o máximo é 16. Ardunio é 10. Seria o número da precisão dele.


#define pinServo 5


void setup() {
  //configuração do canal 0 do PWM em 50Hz e resolucao de 16 bits
  ledcSetup(canalPWM, frequenciaPWM, resolucaoBitsPWM);
  //ATRELANDO O LED AO PINO
  //Ligar no canal 0 ao pino 5 do Esp32
  ledcAttachPin(pinServo, canalPWM);
}

void loop() {

}
