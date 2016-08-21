/*
 * COLORSENSOR.c
 *
 * Created: 10-08-2016 16:21:24
 * Author : HP
 */ 
#include "color_sensor.h"
#include "LCD_LIBRARY.h"

void color_sensor_test(void)
{
   unsigned int redcolorstrength=0;		
   unsigned int greencolorstrength=0;
   unsigned int bluecolorstrength=0;
   int flag1=0;
   int flag2=0;
   //pin0=output frequency,pin1=s0,pin2=s1,pin3=s2,pin4=s3
    DDRC=0b00111110;
	
   PORTC &= ~(PINC5);    //pin5.3 OE pin set to low
   TCCR1B |= 1<<CS10;    //enable 16 bit timer
   PORTC |= _BV(PINC1);      //s0 high
   PORTC &= ~_BV(PINC2);		//s1 low
  					//Prescaling sensor to 20% 
	   TCNT1=0;
	   PORTC &= ~(1<<PINC3);
	   PORTC &= ~(1<<PINC4);                   //RED color sense s2 and s3 low
	   
	   if(bit_is_clear(PINC,0))
	   {
		   while(bit_is_clear(PINC,0));
		   TCNT1=0;
		   while(bit_is_set(PINC,0));
		   redcolorstrength=TCNT1;
		   
		  
	   }
	   else
	   {
		   while(bit_is_set(PINC,0));
		   TCNT1 = 0;
		   while(bit_is_clear(PINC,0));
		   
		   redcolorstrength=TCNT1;
		
		   
	   }
	  
	   PORTC |= _BV(PINC3) | _BV(PINC4);                       //green color sense s2 and s3 high
	   
	   
	   if(bit_is_clear(PINC,0))
	   {
		   while(bit_is_clear(PINC,0));
		   TCNT1=0;
		   while(bit_is_set(PINC,0));
		   greencolorstrength=TCNT1;
	   }
	   else
	   {
		   while(bit_is_set(PINC,0));
		   TCNT1=0;
		   while(bit_is_clear(PINC,0));
		   greencolorstrength=TCNT1;
		   

	   }
	   
	   
	   PORTC &= ~_BV(PINC3);
	   PORTC |= _BV(PINC4);                       //blue color sense s2 low and s3 high
	   
	   
	   if(bit_is_clear(PINC,0))
	   {
		   while(bit_is_clear(PINC,0));
		   TCNT1=0;
		   while(bit_is_set(PINC,0));
		   bluecolorstrength=TCNT1;
	   }
	   else
	   {
		   while(bit_is_set(PINC,0));
		   TCNT1=0;
		   while(bit_is_clear(PINC,0)); 
		   bluecolorstrength=TCNT1;
		 }
	
	   if (redcolorstrength<31 && bluecolorstrength<31 && greencolorstrength<31)
	   {  flag1=1;
		    send_a_string("white");	   
	   }
	    
	   if (redcolorstrength>85 && bluecolorstrength>85 && greencolorstrength>85)
	   {   flag2=1;
		    send_a_string("black");
	   }
	 
	   if (flag1==0 && flag2==0 )
	   {
		   
		   if ((redcolorstrength<bluecolorstrength) && (redcolorstrength<greencolorstrength))
		   {
				send_a_string("red");
		   }
		   if ((greencolorstrength<bluecolorstrength) && (greencolorstrength<redcolorstrength))
		   {
			   send_a_string("green");
		   }
		   if ((bluecolorstrength<redcolorstrength) && (bluecolorstrength<greencolorstrength))
		   {
			    send_a_string("blue");
		   }
	  }
	  
}
		  
	   
	   
	   
	   
	   
   
   

