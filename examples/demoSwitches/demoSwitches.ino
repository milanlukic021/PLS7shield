#include <KELshield.h>

KELshield shield;

void setup()
{
}

void loop()
{
  byte sw = shield.readSwitches();  //citanje stanja prekidaca
  shield.writeDisplay(LEDS, sw);    //prikaz ocitanog stanja prekidaca
                                    //na LED diodama
}
