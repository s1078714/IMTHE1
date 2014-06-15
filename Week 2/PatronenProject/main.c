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
	int i; // snelheid teller

	while(1)
	{
		for( i=0;i<3;i++) // i = 3, == 1 seconden realtime
		{

			// patroon tonen, methode ophalen
			patroonTonen(patroon);
		}

		if (secs == 15) // aantal seconden voordat patroon veranderd.
		{
			secs = 0;

			if (patroon >= 7) // laatste patroon bereikt
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
	int langsteTijd = 3;

	if (patroon == 1)
	{
		// multiplexen, coooode
		// vierkant (leeg)
		PORTD = 0b11111000;
		PORTB = 0b01110000; // 2 randen langs groene draden
		_delay_ms(1);

		PORTD = 0b10001000;
		PORTB = 0b00000000; // 2 randen langs witte draden
		_delay_ms(2);
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
		// lijnen parallel aan groen, startend op rand
		PORTD = 0b11111000;
		PORTB = 0b01010000;
		_delay_ms(langsteTijd);
	}
	if (patroon == 4)
	{
		// lijnen parallel aan groen, niet startend op rand
		PORTD = 0b11111000;
		PORTB = 0b10101000;
		_delay_ms(langsteTijd);
	}
	if (patroon == 5)
	{
		// multiplexen, coooode
		// lijnen parallel aan wit, startend op rand
		PORTD = 0b10101000;
		PORTB = 0b00000000;
		_delay_ms(langsteTijd);		// 50 ms staat gelijk aan 2min, 8seconden
	}
	if (patroon == 6)
	{
		// lijnen parallel aan wit, niet startend op rand
		PORTD = 0b01010000;
		PORTB = 0b00000000; // NIET startend op rand
		_delay_ms(langsteTijd);
	}
	if (patroon == 7)
	{
		// multiplexen, coooode
		// vierkantje (gevuld)
		PORTD = 0b01110000;
		PORTB = 0b10001000;
		_delay_ms(langsteTijd); // tijd rekken voor tonen van patroon
	}
}
