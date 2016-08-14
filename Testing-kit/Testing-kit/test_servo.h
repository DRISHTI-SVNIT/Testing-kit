#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL

void pwm_init(void)
{
	DDRB	= (1<<PB5);
	TCCR1A	= (1<<WGM11) | (1<<COM1A1);					//non inverting mode
	TCCR1B  = (1<<WGM12) | (1<<WGM13) | (1<<CS11);		//fast pwm, prescaler=8.
	ICR1    = 19999;
}

void move_to_angle(int n)
{
	
	if(n>=0 && n<=180)
	{
		OCR1A=555+11.356*n;
	}
}
