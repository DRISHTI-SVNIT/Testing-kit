#ifndef encoderlibrary
#define encoderlibrary

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 1000000UL
#define Encoder_InputDDR		DDRD
#define Encoder_InputPort		PORTD		//another input
#define Encoder_InputPinNumber	0
#define Encoder_InputPin		PIND

#define PinNumber	1			//pin for external interrupt (1-4)
#define IntPin		INT1
#define IntType1	ISC11

#define Ppr			1000.0

//volatile int16_t Counter=0;

#define TimeToShow 1.0	//must be <=2

//float rpm=0;

#define IntType0	ISC10


void InitEncoder(int ShowTime);

#endif