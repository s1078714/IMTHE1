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
	DDRB |= 1 << PINB0; // Data Direction Register output for only
						// pin 0 on port B

	while (1)
	{
		PORTB ^= 1 << PINB0;	// XOR (^) to toggle only pin 0 on Port B
		_delay_ms(100);			// Delay between the toggling on and onff of 100 ms
	}
}
