/*
 * GccApplication5.c
 *
 * Created: 02-08-2016 18:18:12
 * Author : HP
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "LCD_LIBRARY.h"


void set_pin(){
	
	DDR_lcdcontrol|=(1<<enable)|(1<<registerselect)|(1<<readwrite);
	_delay_ms(100);
	send_a_command(0x01);//to clear screen of lcd
	_delay_ms(2);
	send_a_command(0x38);//setting lcd for 8 bit mode
	_delay_ms(50);
	send_a_command(0b00001110);
	_delay_ms(50);
	send_a_command(0x80);//set the cursor to first line
	_delay_ms(2);
}

void check_busy ()
{
	DDR_lcdports=0;
	lcdcontrol|=(1<<readwrite);//enabling PORTD pins
	lcdcontrol&=~(1<<registerselect);//making registerselect off to accept commands
    //lightswitch();//providing enable
	while(lcdports>=0x80) //0b1000 0000  //0x80 
	{
		lightswitch();
	}
	DDR_lcdports=0xFF;
}

void lightswitch ()
{
	lcdcontrol|=(1<<enable);//enabling enable pin
	asm volatile("nop");//giving time to lcd to gather info
	asm volatile("nop");//giving time to lcd to gather info
	lcdcontrol&=~(1<<enable);//making off enable pin	
}

void send_a_command (unsigned char command )
{
	check_busy();
	lcdports=command;
	lcdcontrol&=~((1<<registerselect)|(1<<readwrite));//enabling rs and rw
    lightswitch();//enabling enable pin
	lcdports=0;
}

void send_a_character(unsigned char character)
{ 
	check_busy();
	lcdports=character;
	lcdcontrol|=(1<<registerselect);
	lcdcontrol&=~(1<<readwrite);
	lightswitch();
	lcdports=0;
	
}

void send_to_next_line(char ch[])
{
    int	len = strlen(ch);

		for(int x=0;x<len;x++)
		{
			if(x < 16){
				send_a_character(ch[x]);
			}
			else{
				if (x == 16)
				{
					send_a_command(0xC0);
				}
				
				send_a_character(ch[x]);
			}
		}
			
}
void display_number(int adc)
{
	char value[10];
	itoa(adc,value,10);//changing number into character or string
	//send_a_command(0x80);//set cursor at first line
	send_a_string(value);//displaying number
	_delay_ms(50);
}
void send_a_string(char *string_of_character){
	while (*string_of_character > 0)
	{
		send_a_character(*string_of_character);
		string_of_character++;
	}
	
	}