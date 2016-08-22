#include <PLS7shield.h>

PLS7shield shield;

const byte symbols[] = {
  0xf3, 0x5b, 0xd8, 0x3b
}; //look-up table with symbols (A,b,C,d)

void setup()
{
  shield.writeDisplay(D1, symbols[0]); //D1 <- 'A'
  shield.writeDisplay(D2, symbols[1]); //D2 <- 'b'
  shield.writeDisplay(D3, symbols[2]); //D3 <- 'C'
  shield.writeDisplay(D4, symbols[3]); //D4 <- 'd'
}

void loop()
{
}
