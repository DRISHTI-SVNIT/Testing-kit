#include "PWM_Library.h"

void InitPWM(void)
{
	sei();
	
	PwmDDR = 1<<PwmPin;
	OutputDDR =(1<<OutputPin1 | 1<<OutputPin2 | 1<<OutputPin3 | 1<<OutputPin4 );
	
	 
	TCCR3A = (1<<PwmType1 |1<<PwmType2 | 1<<WGM31);			//fast pwm mode
	TCCR3B =(1<<WGM33 | 1<<WGM32 | 1<<CS32);    //prescaller 256
	
	
}

void SetICR(float n)
{
	ICR3= (n*31250)/1000;
}

void SetDutyCycle(float n)
{
	
	

		OCR3A = ICR3 - (n*31250)/1000;
}