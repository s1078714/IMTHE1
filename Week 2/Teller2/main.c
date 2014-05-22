/*
 * main.c
 *
 *  Created on: 21 mei 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <avr/delay.h>
int x = 100;
int main(void)
{
	DDRD = 0b11111111; // Signaal op PortD0 (is nu output)
	//PORTD = 0b00000001; // 5 Volt op PortD0
	DDRC = 0b0110000;



	while (1)
	{
		displayLinks();
		displayRechts();
	}


}

displayLinks()
{
	PORTC = 0b0100000;

	PORTD = 0b00000110; // 1
	_delay_ms(x);
	PORTD = 0b11011011; // 2
	_delay_ms(x);
	PORTD = 0b01001111; // 3
	_delay_ms(x);
	PORTD = 0b01100110; // 4
	_delay_ms(x);
	PORTD = 0b01101101; // 5
	_delay_ms(x);
	PORTD = 0b01111101; // 6
	_delay_ms(x);
	PORTD = 0b00000111; // 7
	_delay_ms(x);
	PORTD = 0b11111111; // 8
	_delay_ms(x);
	PORTD = 0b11101111; // 9
	_delay_ms(x);
	PORTD = 0b00111111; // 0
	_delay_ms(x);
}

displayRechts()
{
	PORTC = 0b0010000;

	PORTD = 0b00000110; // 1
	_delay_ms(x);
	PORTD = 0b11011011; // 2
	_delay_ms(x);
	PORTD = 0b01001111; // 3
	_delay_ms(x);
	PORTD = 0b01100110; // 4
	_delay_ms(x);
	PORTD = 0b01101101; // 5
	_delay_ms(x);
	PORTD = 0b01111101; // 6
	_delay_ms(x);
	PORTD = 0b00000111; // 7
	_delay_ms(x);
	PORTD = 0b11111111; // 8
	_delay_ms(x);
	PORTD = 0b11101111; // 9
	_delay_ms(x);
	PORTD = 0b00111111; // 0
	_delay_ms(x);
}
