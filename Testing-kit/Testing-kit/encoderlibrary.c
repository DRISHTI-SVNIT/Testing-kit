#include "encoderlibrary.h"
 


void InitEncoder(int ShowTime)
{
	
	
	sei();
	
	DDRD &= ~(1<<PinNumber);
	//InputDDR &= ~(1<<InputPinNumber);
	
	EIMSK = 1<<IntPin;							//use INT0
	EICRA = ( 1<<IntType1 | 1<<IntType0 );		//rising edge
	
	TCCR1B = ( 1<<WGM12 | 1<<CS12 );			//CTC //scaler 256
	TIMSK = 1<<OCIE1A;							//timer interrupt
	
	OCR1A = (F_CPU*ShowTime)/256;
}
