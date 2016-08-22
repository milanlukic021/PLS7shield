#include <PLS7shield.h>

PLS7shield shield;

void setup()
{
}

void loop()
{
  shield.writeDisplay(LEDS, shield.readSwitches());
  
  if (shield.buttonState(LEFT) == HIGH)
    shield.writeDisplay(D1, 0xf3); //'A'
  else
    shield.writeDisplay(D1, 0x01);  //'-'
    
  if (shield.buttonState(UP) == HIGH)
    shield.writeDisplay(D2, 0x5b); //'b'
  else
    shield.writeDisplay(D2, 0x01);  //'-'
    
  if (shield.buttonState(DOWN) == HIGH)
    shield.writeDisplay(D3, 0xd8); //'C'
  else
    shield.writeDisplay(D3, 0x01);  //'-'
    
  if (shield.buttonState(RIGHT) == HIGH)
    shield.writeDisplay(D4, 0x3b); //'d'
  else
    shield.writeDisplay(D4, 0x01);  //'-'
}
