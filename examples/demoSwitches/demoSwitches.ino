#include <KELshield.h>

KELshield shield;

void setup()
{
}

void loop()
{
  byte sw = shield.readSwitches();  //read switches
  shield.writeDisplay(LEDS, sw);    //display switch sttes on LEDs
}
