#include "test_servo.h"

void pwm_init(void)
{
	PwmDDR	= (1<<PwmPin);
	TCCR1A  = (1<<WGM11) | (1<<PwmType1);					//non inverting mode
	TCCR1B	= (1<<WGM12) | (1<<WGM13) | (1<<CS11);		   //fast pwm, prescaler=8.
	ICR1	= 19999;
}

void move_to_angle(int n)
{
	
	if(n>=0 && n<=180)
	{
		OCR1A=555+11.356*n;
	}
}
