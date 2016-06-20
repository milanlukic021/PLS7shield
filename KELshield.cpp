#include "Arduino.h"
#include "KELshield.h"

#define SCL_HI	(PORTC |= (1<<5))
#define SCL_LO	(PORTC &= ~(1<<5))
#define SDA		(PINC & (1 << 4))
#define SHLD_HI	(PORTB |= (1<<5))
#define SHLD_LO	(PORTB &= ~(1<<5))

byte displayBuffer[5];
unsigned long ms = 0;
byte disp = 4;

ISR(TIMER0_COMPA_vect)
{
	//prekid tajmera 0 usled dostizanja vrednosti registra OCR0A
	if (++disp > 4)
		disp = 0;
	PORTB = ~(1 << (4 - disp));		//ukljucenje tranzistora
	PORTD = ~displayBuffer[disp];	//ispis na trenutno aktivan displej
	ms++;							//sistemsko vreme
}

KELshield::KELshield()
{
	byte i;

	DDRD = 0xff;	//ceo port D izlazi
	DDRC = 0xe0;	//PC5 izlaz, PC4-PC0 ulazi
	DDRB = 0x3f;	//PB5 - PB0 izlazi

	//inicijalizacija tajmera 0:
	 TCCR0A = 0x02; //tajmer 0: CTC mod
	 TCCR0B = 0x03; //tajmer 0: fclk = fosc/64
	 OCR0A = 249;	//perioda tajmera 0: 250 Tclk (OCR0A + 1 = 250)
	 TIMSK0 = 0x02;	//dozvola prekida tajmera 0
					//usled dostizanja vrednosti registra OCR0A
	 sei(); 		//I = 1 (dozvola prekida)
}

void KELshield::writeDisplay(byte d, byte value)
{
	displayBuffer[d] = value;
}

byte KELshield::readDisplay(byte d)
{
	return displayBuffer[d];
}

byte KELshield::readSwitches()
{
	byte i, tmp = 0, mask = 0x80;

	SHLD_HI;
	SHLD_LO;
	SHLD_HI;	//impuls za punjenje bafera

	for (i=0; i<8; i++)
	{
		SCL_LO;
		SCL_HI;

		if (SDA)
			tmp |= mask;
		mask >>= 1;
	}

	return ~tmp;
}

byte KELshield::switchState(byte s)
{
	byte sw = readSwitches();
	
	if (sw & (1 << (7 - s)))
		return HIGH;
	else
		return LOW;
}

byte KELshield::buttonState(byte b)
{
	switch(b)
	{
		case LEFT:
			return !digitalRead(A0);
			break;
		case DOWN:
			return !digitalRead(A1);
			break;
		case RIGHT:
			return !digitalRead(A2);
			break;
		case UP:
			return !digitalRead(A3);
			break;
	}
	return 0;
}
