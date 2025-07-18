// #include <Arduino.h>
// // #include <LiquidCrystal_I2C.h>

// // LiquidCrystal_I2C lcd(0x27, 20, 4);

// // void setup()
// // {
// //   // Serial.begin(9600);

// //   // inicializa o lcd
// //   lcd.init();
// //   lcd.backlight();
// //   // primeiro posiona e deois escreve.
// //   lcd.setCursor(0, 0);
// //   lcd.print("Ola mundooo!");
// // }

// // unsigned int count = 0;

// // void loop()
// // {
// //   bool estadoBotaoAtual = digitalRead(0);

// //   uint32_t tempoAtual = millis();
// //   static unsigned long tempoAnterior = 0;
// //   // lcd.setCursor(0, 2);
// //   // lcd.printf("Tempo: %d", count);

// //   if (tempoAtual - tempoAnterior > 1000)
// //   {
// //     count++;
// //     tempoAnterior = tempoAtual;

// //     lcd.setCursor(0, 2);
// //     lcd.printf("Tempo: %d", count);
// //   }

// //   if (estadoBotaoAtual == 1)
// //   {
// //     lcd.setCursor(0, 1);
// //     lcd.print("botao solto      ");
// //   }
// //   else
// //   {
// //     lcd.setCursor(0, 1);
// //     lcd.print("botao pressionado");
// //     count = 0;
// //   }
// // }

// // // LiquidCrystal_12C


// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 20, 4); 
// //https://chareditor.com/
// byte coracao[] = {B00000, B00000, B01010, B11111, B01110, B00100, B00000, B00000};

// void setup() 
// {
//   pinMode(0, INPUT_PULLUP);
//   lcd.init();

//   lcd.createChar(0, coracao);
//   lcd.backlight();
//   lcd.setCursor(0,0);
//   lcd.print("OLA MUNDO CRUEL!");
//   lcd.write(0);
//   lcd.setCursor(0,1);
//   lcd.print("botao solto");
//   lcd.setCursor(0,2);
//   lcd.print("Tempo: 0");
//   }

// void loop() 
// {
//  unsigned long agora = millis();
//  static unsigned long tempoAnterior = 0;
//  static int contagem = 0;

//   bool estadoAtualBotao = digitalRead(0);
//   static bool estadoAnteriorBotao = 1;

//  if(agora - tempoAnterior > 1000)
//  {
//   contagem ++;
//   tempoAnterior = agora;
//   lcd.setCursor(7,2);
//   lcd.print(contagem);
//  }

//   if(!estadoAtualBotao && estadoAnteriorBotao)
//   {
//     contagem = 0;
//     lcd.setCursor(7,2);
//     lcd.print("0      ");
//     lcd.setCursor(6,1);
//     lcd.print("pressionado");
//   }

//   else if(estadoAtualBotao && !estadoAnteriorBotao)
//   {
//     lcd.setCursor(6,1);
//     lcd.print("solto      ");
//   }

//   estadoAnteriorBotao = estadoAtualBotao;
// }