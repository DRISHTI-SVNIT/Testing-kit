/*
 * GccApplication5.c
 *
 * Created: 02-08-2016 18:18:12
 * Author : HP
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>

#define lcdcontrol PORTE
#define DDR_lcdcontrol DDRE
#define lcdports PORTD
#define DDR_lcdports DDRD
#define enable 4
#define registerselect 5
#define readwrite 6

void check_busy ();
void lightswitch ();//check weather enable is on or not
void send_a_command (unsigned char command );//for sending a command
void send_a_character(unsigned char character);//for sending a character
void send_a_string(char *string_of_character);//for passing string of characters

