//Programa: Circuito Receptor RF 433 MHz
//Autor: Arduino e Cia

#include <RCSwitch.h>

RCSwitch rfsense = RCSwitch();

void setup()
{
  Serial.begin(9600);
  //Pino do led
  //pinMode(6, OUTPUT);

  //interrupt pin defined with help from https://forum.arduino.cc/t/solved-rf433-transmitter-on-esp32-rcswitch/681005
  rfsense.enableReceive(digitalPinToInterrupt(D2));

  Serial.println("Receptor RF 433 MHz");
  Serial.println("Iniciando.....................");
  delay(2000);
}

void loop()
{
  if (rfsense.available())
  {
    //Verifica o valor recebido pelo receptor
    //int valor = rfsense.getReceivedValue();
    float value = rfsense.getReceivedValue() / 100.0;
    Serial.println(value);
    
  }
  rfsense.resetAvailable();
    
}