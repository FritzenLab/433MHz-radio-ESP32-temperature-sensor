
#include <Wire.h>
#include <RCSwitch.h>

RCSwitch rfsense = RCSwitch();

int analogvalue;

void setup()
{
	Serial.begin(9600);

  rfsense.enableTransmit(5);
  delay(1000);
  analogReadResolution(10);

}

void loop()
{	
  analogvalue= analogRead(A0);
  rfsense.send(analogvalue, 12);
  Serial.println(analogvalue);
  delay(1000);

}