#ifndef test_servo
#define test_servo


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL


#define PwmDD DDRB
#define PwmPin1 5
#define PwmType COM1A1

void pwm_init(void);
int move_to_angle(int n);

#endif