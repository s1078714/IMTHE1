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
	DDRD = 0b11111100; // blauw || groen
	DDRB = 0b11110000; // geel || wit

	uint8_t secs = 0; // teller
	int patroon = 1; // reset naar eerste patroon, voor het leesgemak begint patroon bij 1 (patroon 1, patroon 2 enz enz)
	int i; // snelheid teller

	while(1)
	{
		for( i=0;i<1;i++) // i verhogen, betekent snelheid afwisseling vertragen
		{

			// patroon tonen, methode ophalen
			patroonTonen(patroon);
		}

		if (secs == 15) // aantal seconden voordat patroon veranderd.
		{
			secs = 0;

			if (patroon >= 4) // laatste patroon bereikt
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
	int langsteTijd = 80000; // in microseconden (us)

	if (patroon == 1)
	{
//		// alle leds branden
//		PORTD = 0b11111100;
//		PORTB = 0b00000000;
//		_delay_us(langsteTijd);

		for(int loop;loop<=(langsteTijd/70);loop++)
		{
			PORTD = 0b01111000;
			PORTB = 0b00000000;
			_delay_us(750);
			PORTD = 0b10000100;
			PORTB = 0b00000000;
			_delay_us(750);
		}
	}
	if (patroon == 2)
	{
		int draaiSnelheid = 5;
		// racer leds (cirkel beweging)
		PORTD = 0b10000000;
		PORTB = 0b01110000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b10000000;
		PORTB = 0b10110000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b10000000;
		PORTB = 0b11010000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b10000000;
		PORTB = 0b11100000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);

		PORTD = 0b01000000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00100000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00010000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00001000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);

		PORTD = 0b00000100;
		PORTB = 0b11100000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00000100;
		PORTB = 0b11010000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00000100;
		PORTB = 0b10110000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00000100;
		PORTB = 0b01110000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);

		PORTD = 0b00001000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00010000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00100000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b01000000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
	}
	if (patroon == 3)
	{
		int draaiSnelheid = 5;
		// racer leds (cirkel beweging) 		tegengestelde richting
		PORTD = 0b01000000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00100000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00010000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00001000;
		PORTB = 0b00010000; // meest rechtse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);

		PORTD = 0b00000100;
		PORTB = 0b01110000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00000100;
		PORTB = 0b10110000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00000100;
		PORTB = 0b11010000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00000100;
		PORTB = 0b11100000; // meest linkse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);

		PORTD = 0b00001000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00010000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b00100000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b01000000;
		PORTB = 0b10000000; // meest linkse strip leds, langs witte draad (4)
		_delay_ms(draaiSnelheid);

		PORTD = 0b10000000;
		PORTB = 0b11100000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b10000000;
		PORTB = 0b11010000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b10000000;
		PORTB = 0b10110000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
		PORTD = 0b10000000;
		PORTB = 0b01110000; // meest rechtse strip leds, langs groene draad (4)
		_delay_ms(draaiSnelheid);
	}
	if (patroon == 4)
	{
		// lijnen parallel aan groen, niet startend op rand
		for(int loop;loop<=(langsteTijd/70);loop++)
		{
		PORTD = 0b00110000;
		PORTB = 0b01100000;
		_delay_us(750);
		PORTD = 0b10000100;
		PORTB = 0b10010000;
		_delay_us(750);
		}
	}
//	if (patroon == 5)
//	{
//		// multiplexen, coooode
//		// lijnen parallel aan wit, startend op rand
//		// 		met potmeter: geen leds
//		PORTD = 0b10101000;
//		PORTB = 0b00000000;
//		_delay_us(langsteTijd);		// 50 ms staat gelijk aan 2min, 8seconden
//	}
//	if (patroon == 6)
//	{
//		// lijnen parallel aan wit, niet startend op rand
//		// 		met potmeter: geen leds
//		PORTD = 0b01010000;
//		PORTB = 0b00000000; // NIET startend op rand
//		_delay_us(langsteTijd);
//	}
//	if (patroon == 7)
//	{
//		// multiplexen, coooode
//		// vierkantje (gevuld)
//		// 		met potmeter: toont alleen 2x3 leds parallel aan de groene draden,
//		// 		ter hoogte van oorspronkelijk klein vierkantje
//		PORTD = 0b01110000;
//		PORTB = 0b10001000;
//		_delay_us(langsteTijd); // tijd rekken voor tonen van patroon
//	}
}
