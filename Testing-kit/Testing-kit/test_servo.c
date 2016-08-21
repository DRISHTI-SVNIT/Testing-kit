#include "test_servo.h"

void pwm_init(void)
{
	PwmDD	= (1<<PwmPin1);
	TCCR1A  = (1<<WGM11) | (1<<PwmType);					//non inverting mode
	TCCR1B	= (1<<WGM12) | (1<<WGM13) | (1<<CS11);		   //fast pwm, prescaler=8.
	ICR1	= 19999;
}

int move_to_angle(int n)
{
	
	if(n>=0 && n<=180)
	{
		OCR1A=555+11.356*n;
	}
	return(OCR1A);
}
