#include <Arduino.h>
#define pinButton 23
#define tempoFiltroBotao 30

unsigned int count = 0;

void setup()
{
    pinMode(pinButton, INPUT_PULLUP);
}

void loop()
{
    bool leituraAtual = digitalRead(pinButton);
    static bool ultimoEstadoBotao = 1;
    static bool leituraAnteriorBotao = 1;
    static unsigned long tempoUltimaTroca = 0;
    unsigned long agora = millis();

    if (leituraAtual != ultimoEstadoBotao)
    {
        tempoUltimaTroca = agora;
    }

    if (agora - tempoUltimaTroca > tempoFiltroBotao)
    {
        if (leituraAtual != leituraAnteriorBotao)
        {
            leituraAnteriorBotao = leituraAtual;

            if (!leituraAtual)
            {
                count++;

                // Serial.println(estadoBotao);
                Serial.println(count);
            }
        }
    }
    ultimoEstadoBotao = leituraAtual;
}
