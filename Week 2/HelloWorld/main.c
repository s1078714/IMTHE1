/*
 * HelloWorld.cpp
 *
 *  Created on: 18 mei 2014
 *      Author: Gunnar
 */

#include <avr/io.h>       // Header file for basic avr input/output
#include <util/delay.h>

int main(void)
{
	DDRB |= 1 << PINB0; 	// Data Direction Register output PINB0
	DDRB &= ~(1 << PINB1); 	// Data Direction Register input PINB1
	PORTB |= 1 << PINB1; 	// Set PINB1 to a high reading

	while (1)
	{
		PORTB ^= 1 << PINB0;	// XOR (^) to toggle only pin 0 on Port B
		_delay_ms(1000);		// Delay between the toggling on and off of 100 ms

		if (bit_is_clear(PINB, 1))
		{
			_delay_ms(10);
		}
		else
		{
			_delay_ms(100);
		}
	}
}
