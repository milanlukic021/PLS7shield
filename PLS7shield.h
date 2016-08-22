#include "Arduino.h"

#ifndef _PLS7shield_h
#define _PLS7shield_h
#endif

#define LEDS	0
#define D1	1
#define D2	2
#define D3	3
#define D4	4

#define DOWN	0
#define RIGHT	1
#define UP	2
#define LEFT	3

#define S1	0
#define S2	1
#define S3	2
#define S4	3
#define S5	4
#define S6	5
#define S7	6
#define S8	7

class PLS7shield
{
  public:
  	PLS7shield();
	void writeDisplay(byte d, byte value);
	byte readDisplay(byte d);
	byte readSwitches();
	byte switchState(byte s);
	byte buttonState(byte b);
};
