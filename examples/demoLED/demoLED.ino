#include <KELshield.h>

KELshield shield;

void setup()
{
  shield.writeDisplay(LEDS, B01010101); //turn ON LEDs on even positions
}
void loop()
{
  byte stanje_LED = shield.readDisplay(LEDS); //read LED buffer
  shield.writeDisplay(LEDS, ~stanje_LED);     //invert
  delay(1000);
}
