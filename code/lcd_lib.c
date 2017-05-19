#include "lcd_lib.h"
int len=0;

void displayNum (int value){
	char number1[100];
	itoa(value,number1,10);
	//command(0x80);//set cursor at first line
	string(number1);//displaying number
}
void display_number (float j)
{
	char number[100];
	dtostrf(j,6,2, number);
	string(number);
}
void startlcd()
{
	controld |= 1<<rs | 1<<rw | 1<<e;
	_delay_ms(15);
	command(0x01);
	command(0x38);
	command(0b00001110);
	
}
void flash()
{
	controlp |= 1<<e;
	asm volatile ("nop");
	asm volatile ("nop");
	controlp &= ~(1<<e);
}
void busy()
{
	datad = 0;
	controlp |= 1<<rs;
	controlp &= ~(1<<rw);
	while (PORTB >= 80)
	{
		flash();
	}
	datad = 0b11111111;
}
void command(unsigned char x)
{
	busy();
	datap = x;
	controlp &= ~(1<<rs|1<<rw);
	flash();
	datap = 0;
	_delay_ms(2);
}
void data(unsigned char y)
{
	
	busy();
	datap = y;
	controlp |= 1<<rs;
	controlp &= ~(1<<rw);
	flash();
	datap = 0;
	_delay_ms(2);
	len++;
	if(len == 16)
	{
		command(0xC0);
	}
}
void string (char *z)
{
	while (*z > 0)
	{
		data(*z++);
	}
	len =0;
}