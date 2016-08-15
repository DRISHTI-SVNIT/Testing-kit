#ifndef test_servo
#define test_servo


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL


#define PwmDDR DDRB
#define PwmPin 5
#define PwmType1 COM1A1

void pwm_init(void);
void move_to_angle(int n);

#endif