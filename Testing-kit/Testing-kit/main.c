/*
 * Testing-kit.c
 *
 * Created: 03-08-2016 17:27:48
 * Author : Drishti
 */ 

#define F_CPU 8000000UL					//CPU frequency - 8 MHz

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include "USART_128.h"


int main(void)
{
	USART_Init(51,0);
	USART_Init(51,1);
    /* Replace with your application code */
    while (1) 
    {
    }
}

