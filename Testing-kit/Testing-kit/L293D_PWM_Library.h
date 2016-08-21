#ifndef PWM_Library
#define PWM_Library

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 1000000UL
#define PwmDDR  DDRE
#define PwmPort PORTE
#define PwmPin  3
#define PwmType1 COM3A1            //non inverted
#define PwmType2 COM3A0
			
#define OutputDDR	DDRC
#define OutputPort	PORTC
#define OutputPin1	0
#define OutputPin2	1
#define OutputPin3	2
#define OutputPin4	3

void InitPWM(void);
void SetDutyCycle(int n);
void SetICR(int n);




#endif