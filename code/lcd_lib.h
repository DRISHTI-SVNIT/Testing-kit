#ifndef lcd_lib

#define lcd_lib
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>

#define datap PORTE
#define datad DDRE
#define controlp PORTD
#define controld DDRD
#define rs PIND2
#define rw PIND3
#define e PIND4

void busy(void);
void flash(void);
void command(unsigned char x);
void data(unsigned char y);
void string(char *z);
void display_number(float j);
void startlcd(void);
void displayNum (int value);

#endif