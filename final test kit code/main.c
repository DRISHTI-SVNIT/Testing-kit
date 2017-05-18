/*
 * TESTING kit code.c
 *
 * Created: 25-03-2017 09:19:35
 * Author : HP
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "servo.h"
#include "USART_128.h"
#include "encoder.h"
#include <stdbool.h>
#include <avr/sfr_defs.h>

int count1 = 0;
//int counter = 0;
bool  encoderEnable;
int angle =0;
int repeatCount = 0;
//int repeatCount2 = 0;

int main(void)
{
	DDRD &=~(1<<PIND5);
	PORTD|=(1<<PIND5);
	pwmInit();
	interruptInit();
	startlcd();
	string("LCD is working");
	_delay_ms(2000);
	command(0x01);
	string("instructions");
	_delay_ms(2000);
	command(0x01);
	string("modules to test");
	_delay_ms(2000);
	command(0x01);
	string("1.servo testing");
	_delay_ms(1000);
	command(0x01);
	string("2.encoder testing");
	_delay_ms(1000);
	command(0x01);
	string("3.relay testing");
	_delay_ms(1000);
	command(0x01);
	string("1.want to test servo");
	_delay_ms(2000);
	command(0x01);
	string("if yes, press reset button");
	_delay_ms(2000);
	command(0x01);
	if(bit_is_clear(PIND,5)){
			string("start servo");
			_delay_ms(2000);
			command(0x01);
			string("starting angle 0");
			func(angle);
			func(angle+90);
			func(angle+180);
			repeatCount=1;	
	}
	else{
			string("2.want to test encoder");
			_delay_ms(2000);
			command(0x01);
			string("if yes, press reset button");
			_delay_ms(2000);
			command(0x01);
			if(bit_is_clear(PIND,5)){
				sei();
				repeatCount = 1;
			}		
	}
	if(repeatCount == 0){	
		string("3.want to test relay");
		_delay_ms(2000);
		command(0x01);
		string("test relay");
		_delay_ms(2000);
		command(0x01);
	}
	
    /* Replace with your application code */
    while (1)
    {
	
	}
}
ISR(INT1_vect)
{
	//countFunc(count1,count2);
		count1++;
		displayNum(count1);
		string(" ");	
}
