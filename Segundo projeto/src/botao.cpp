// #include <Arduino.h>

// #include <Bounce2.h>

// //cada botao precisa de um obj
// Bounce botao = Bounce();

// void setup()
// {
//   // attach -> configurando o pino que o botao está conectado
//   botao.attach(23, INPUT_PULLUP);
//   botao.interval(30);
// }

// void loop()
// {
//   //sem o update, não funciona nada...
//   botao.update();
//   // rose -> verifica se o botao sofreu modifica;áo, ex: De 0 para 1
//   // botao clicado
//   if (botao.rose())
//   {
//   }
//   // rose -> verifica se o botao sofreu modifica;áo, ex: De 1 para
//   // botao solto
//   if (botao.fell())
//   {

//   }

//   if(botao.changed()){
//     if(botao.read() == LOW){ //Botao pressionado

//     }
//   }

//   //currentDurante -> enquanto o botao esta sendo pressionado, vai retornar o quanto tempo está sendo.
//   //previousDurante -> enquanto o botao ficou pressionado, após ser solto.
//   unsigned long ultimaDuracao = botao.previousDuration();
// }
