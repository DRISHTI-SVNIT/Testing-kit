#ifndef USART_128
#define USART_128

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#define new_line() USART_Transmit_char(0x0A);
void USART_Init( unsigned int ubrr );
void USART_Transmit_char( unsigned char data );
unsigned char USART_Receive( void );
void USART_Flush( void );


#endif