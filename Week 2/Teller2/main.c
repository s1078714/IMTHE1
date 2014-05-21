/*
 * main.c
 *
 *  Created on: 21 mei 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRD = 0b11111111; // Signaal op PortD0 (is nu output)
	//PORTD = 0b00000001; // 5 Volt op PortD0

	while (1)
	{
		PORTD = 0b00000010; // pd1 rechtsboven segment
		_delay_ms(50);
		PORTD = 0b00000011; // pd1 rechtsboven segment + pd0 bovenmidden segment
		_delay_ms(50);
	}
}
