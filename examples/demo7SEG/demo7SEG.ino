#include <KELshield.h>

KELshield shield;

const byte symbols[] = {
  0xf3, 0x5b, 0xd8, 0x3b
}; //look-up table with symbols (A,b,C,d)

void setup()
{
  shield.writeDisplay(D1, simboli[0]); //D1 <- 'A'
  shield.writeDisplay(D2, simboli[1]); //D2 <- 'b'
  shield.writeDisplay(D3, simboli[2]); //D3 <- 'C'
  shield.writeDisplay(D4, simboli[3]); //D4 <- 'd'
}

void loop()
{
}
