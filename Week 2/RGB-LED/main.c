/*
 * main.c
 *
 *  Created on: 26 mei 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0b00001111;

	while(1)
	{
		PORTD = 0b00000100; // lichtblauw/wit
		_delay_ms(100);
		PORTD = 0b00000101; // geel
		_delay_ms(100);
		PORTD = 0b00000110; // paars, roze
		_delay_ms(100);
		PORTD = 0b00000111; // rood
		_delay_ms(100);
		PORTD = 0b00001100; // lichtblauw,turquiose
		_delay_ms(100);
		PORTD = 0b00001101; // groen
		_delay_ms(100);
		PORTD = 0b00001110; // blauw
		_delay_ms(100);

/*
		PORTD = 0b00001111; // uit, er moet een uitgang zijn (0)
		PORTD = 0b00001000; // uit, PIN3 moet altijd 1 zijn!
*/
	}
}
