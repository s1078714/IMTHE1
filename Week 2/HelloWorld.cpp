/*
 * HelloWorld.cpp
 *
 *  Created on: 18 mei 2014
 *      Author: Gunnar
 */

#include<avr/io.h>       // Header file for basic avr input/output

void main(void)
{
	DDRB = 0b00000001; // Signaal op PortB0 (is nu output)
	PORTB = 0b00000001; // 5 Volt op PortB0

	while (1)
	{

	}
}
