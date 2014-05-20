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
	DDRB |= 1 << PINB0; // Signaal op PortB0 (is nu output)

	while (1)
	{
		PORTB ^= 1 << PINB0; // 5 Volt op PortB0
		_delay_ms(100);
	}
}
