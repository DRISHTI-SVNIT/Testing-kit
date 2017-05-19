#include "servo.h"
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"

void func(int angle)
{	
	ICR1 = 19999;
	switch(angle){
		case 0 ://command(0x01);	
				while(angle<180){
					OCR1A = 388 + (angle*(9.733));
					_delay_ms(2000);
					angle+=10;
				}
				command(0x01);
				break;
		case 90 :command(0x01);
				string("starting angle 90");
				while(angle<180){
					OCR1A = 388 + (angle*(9.733));
					_delay_ms(2000);
					angle+=10;
				}
				command(0x01);
				break;
		case 180 :command(0x01);
				  string("starting angle 180");
				  while(angle > 0){
						OCR1A = 388 + (angle*(9.733));
						_delay_ms(2000);
						angle-=10;
				}
				command(0x01);
				break;						
	}
}
		



void pwmInit(void)
{
	DDRB|=(1<<PINB5);
	PORTB|=(1<<PINB5);
	
	TCCR1A |= (1<<WGM11 )| (1<<COM1A1) ;
	TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11) ;
}


