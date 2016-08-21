/*
 * lcd_library.c
 *
 * Created: 16-08-2016 23:24:27
 * Author : HP
 */ 

#define lcdcontrol PORTE
#define DDR_lcdcontrol DDRE
#define lcdports PORTD
#define DDR_lcdports DDRD
#define enable 2
#define registerselect 4
#define readwrite 3

void check_busy ();
void lightswitch ();//check weather enable is on or not
void send_a_command (unsigned char command );//for sending a command
void send_a_character(unsigned char character);//for sending a character
void send_to_next_line(char ch[]);//for passing string of characters
void display_number(int adc);//for displaying numbers
void send_a_string(char *string_of_character);

