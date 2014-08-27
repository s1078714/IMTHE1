/*
 * main.c
 *
 *  Created on: 22 aug. 2014
 *      Author: Gunnar
 */

#include <avr/io.h>       // Header file for basic avr input/output
#include <util/delay.h>

int main(void)
{
	DDRB = 0b11111111;

	int snelheid = 150;

	while(1)
	{
		PORTB = 0b00000001; // poort 2 hoog
		_delay_ms(snelheid);
		PORTB = 0b00000010; // poort 1 hoog
		_delay_ms(snelheid);
		PORTB = 0b00000100; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00001000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00010000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00100000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b01000000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b10000000; // beide hoog
		_delay_ms(snelheid);

		PORTB = 0b01000000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00100000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00010000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00001000; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00000100; // beide hoog
		_delay_ms(snelheid);
		PORTB = 0b00000010; // poort 1 hoog
		_delay_ms(snelheid);
		PORTB = 0b00000001; // poort 2 hoog
		_delay_ms(snelheid);
	}
}
