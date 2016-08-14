/*
 * LCD_COLOR_SENSOR.c
 *
 * Created: 11-08-2016 17:05:31
 * Author : HP
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_display_library.h"
#include "color_sensor.h"
int main(void)
{  
	
	DDR_lcdcontrol|=(1<<enable)|(1<<registerselect)|(1<<readwrite);
	_delay_ms(200);
	send_a_command(0x01);//to clear screen of lcd
	_delay_ms(2);
	send_a_command(0x38);//
	_delay_ms(50);
	send_a_command(0b00001110);
	_delay_ms(50);
	while(1)
	{  
		check_busy ();
		color_sensor_test();
	   _delay_ms(1000);
	    send_a_command(0x01);//to clear screen of lcd
	    _delay_ms(100);
    }
}
	
	
