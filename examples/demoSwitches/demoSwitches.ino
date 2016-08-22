#include <PLS7shield.h>

PLS7shield shield;

void setup()
{
}

void loop()
{
  byte sw = shield.readSwitches();  //read switches
  shield.writeDisplay(LEDS, sw);    //display switch sttes on LEDs
}
