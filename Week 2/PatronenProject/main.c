/*
 * main.c
 *
 *  Created on: 11 jun. 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b11111000; // blauw || groen
	DDRB = 0b11111000; // geel || wit

	uint8_t secs = 0; // teller
	int patroon = 1; // reset naar eerste patroon, voor het leesgemak begint patroon bij 1 (patroon 1, patroon 2 enz enz)
	int i;

	while(1)
	{
		for( i=0;i<10;i++)
		{

			// patroon tonen, methode ophalen
			patroonTonen(patroon);
		}

		if (secs == 15) // aantal seconden voordat patroon veranderd.
		{
			secs = 0;

			if (patroon == 6) // laatste patroon bereikt
			{
				patroon = 1; // opnieuw beginnen met patroonsequentie
			}
			else
			{
				patroon++; // volgende patroon
			}
		}
		else
		{
			secs++;
		}
	}
}

patroonTonen(patroon)
{
	if (patroon == 1)
	{
		// multiplexen, coooode
		// vierkant (leeg)
		PORTD = 0b11111000;
		PORTB = 0b01110000; // 2 randen langs groene draden
		_delay_ms(1);

		PORTD = 0b10001000;
		PORTB = 0b00000000; // 2 randen langs witte draden
		_delay_ms(1);
	}
	if (patroon == 2)
	{
		// multiplexen, coooode
		// ruit
		PORTD = 0b01010000;
		PORTB = 0b10101000; // 4 stippen (vierkantje)
		_delay_ms(1);

		PORTD = 0b00100000;
		PORTB = 0b01110000; // 2 stippen buitenste rand, horizontaal langs witte strip draden
		_delay_ms(1);

		PORTD = 0b10001000;
		PORTB = 0b11011000; // 2 stippen buitenste rand, verticaal langs witte strip draden
		_delay_ms(1);
	}
	if (patroon == 3)
	{
		// multiplexen, coooode
		// lijnen parallel aan groen
		PORTD = 0b11111000;
		PORTB = 0b01010000;
		_delay_ms(10);
		PORTD = 0b11111000;
		PORTB = 0b10101000;
		_delay_ms(10);
	}
	if (patroon == 4)
	{
		// multiplexen, coooode
		// lijnen parallel aan wit
		PORTD = 0b10101000;
		PORTB = 0b00000000; // startend op rand
		_delay_ms(10);		// 50 ms staat gelijk aan 2min, 8seconden
		PORTD = 0b01010000;
		PORTB = 0b00000000; // NIET startend op rand
		_delay_ms(10);
	}
	if (patroon == 5)
	{
		// multiplexen, coooode
		// vierkantje (gevuld)
		PORTD = 0b01110000;
		PORTB = 0b10001000;
		_delay_ms(2); // tijd rekken voor tonen van patroon
	}
}
