/*
 * tester_kit.c
 *
 * Created: 16-08-2016 16:08:21
 * Author : HP
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#include "color_sensor.h"
#include "L293D_PWM_Library.h"
#include "LCD_LIBRARY.h"
#include "test_servo.h"
#include "encoderlibrary.h"
unsigned int count=0;
unsigned int k=0;

int main(void)
{
    DDRB=0b00000000;
	DDRC=0b00000000;
	//DDRD=0b00000000;
	DDRA=0b00000000;
	//DDRE=0b00000000;
	DDRF=0b00000000;
	set_pin();
	send_a_string("LCD is working");

	while(1)
	{    
		 if(bit_is_set(PINE,5))
		 {
			 _delay_ms(150);
			if(bit_is_set(PINE,5))
			 {
				count++;
				if(count>=8)                  //if we have 8 modules
				 {
					count=1;
				 }
			 }
		 }
		  switch(count)
		  {
			  
			  case 1:
			  send_a_command(0x01);
			  _delay_ms(10);
			  //send_a_command(0xC0);
			  send_to_next_line("check_color_test");
			  send_a_command(0xc0);
			  color_sensor_test();//color sensor test
			  _delay_ms(50);
			  break;
			  
			  case 2:
			  send_a_command(0x01);
			  _delay_ms(10);
			  pwm_init();
			  send_a_string("servo_test");
			  move_to_angle(90);  //servo motor
			  send_a_command(0xC0);
			  send_a_string("OCR1A:"); //to display the value of OCR1A
			  display_number(OCR1A);
			//  send_a_command(0x01); // to clear the screen
			 // send_to_next_line("servo is working");
			  //_delay_ms(5000);
			  _delay_ms(50);
			  //send_a_command(0xC0);
			  break;
			  
			  case 3:
			  send_a_command(0x01);
			  _delay_ms(10);
			  send_a_string("L293D_TEST");
			  send_a_command(0xC0);
			  //InitPWM();                   //L293D TEST
			 // SetICR(10);
			 // SetDutyCycle(100);
			  send_a_string("OCR3A: ");
			   _delay_ms(50);
			  break;
			  
			  case 4:
			  send_a_command(0x01);
			  _delay_ms(10);
			  send_a_string("encoder test");
			  send_a_command(0xC0);
			 // InitEncoder(100);     
			  //ENCODER TEST
			  //display_number(OCR1A);
			  _delay_ms(50);
			  break;
			  
			  case 5:
			  send_a_command(0x01);
			  _delay_ms(10);
			  send_a_string("proximity sensor");
			  send_a_command(0xC0);
			  _delay_ms(50);
			  break;
			  
			  case 6:
			  send_a_command(0x01);
			  _delay_ms(10);
			  send_a_string("seven segment");
			  _delay_ms(50);
			  //send_a_command(0xC0);
			  break;
			  
			  case 7:
			  send_a_command(0x01);
			  _delay_ms(10);
			  send_a_string("USART test");
			  _delay_ms(50);
			  //send_a_command(0xC0);
			  break;
			  }
		 }
}
	
