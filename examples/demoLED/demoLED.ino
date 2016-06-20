#include <KELshield.h>

KELshield shield; //instanciranje klase KELshield

void setup()
{
  shield.writeDisplay(LEDS, B01010101); //ukljucuju se LED diode
  //na parnim pozicijama
}
void loop()
{
  byte stanje_LED = shield.readDisplay(LEDS); //ocitavanje sadrzaja bafera
  shield.writeDisplay(LEDS, ~stanje_LED); //upis invertovane vrednosti
  delay(1000); //pauza 1s
}
