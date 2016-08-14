
#include "lcd_display_library.h"


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
void send_a_string(char *string_of_character)
{
	while(*string_of_character>0)
	{
		send_a_character(*string_of_character);
		string_of_character++;
	}

}
