#include <KELshield.h>

KELshield shield;

void setup()
{
  byte i;
  for (i = D1; i <= D4; i++)
  shield.writeDisplay(i, 0x01); //'-'
}

void loop()
{
  if (shield.buttonState(LEFT) == HIGH)
    shield.writeDisplay(D1, 0xf3); //'A'
  else
    shield.writeDisplay(D1, 0x01); //'-'
  if (shield.buttonState(UP) == HIGH)
    shield.writeDisplay(D2, 0x5b); //'b'
  else
    shield.writeDisplay(D2, 0x01); //'-'
  if (shield.buttonState(DOWN) == HIGH)
    shield.writeDisplay(D3, 0xd8); //'C'
  else
    shield.writeDisplay(D3, 0x01); //'-'
  if (shield.buttonState(RIGHT) == HIGH)
    shield.writeDisplay(D4, 0x3b); //'d'
  else
    shield.writeDisplay(D4, 0x01); //'-'
}
