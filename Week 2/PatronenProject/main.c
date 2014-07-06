/*
 * main.c
 *
 *  Created on: 11 jun. 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

	int patroonTonen();

int main(void)
{
	DDRD = 0b11111100; // blauw || groen
	DDRB = 0b11110000; // geel || wit


	uint8_t secs = 0; // teller
	int patroon = 1; // reset naar eerste patroon, voor het leesgemak begint patroon bij 1 (patroon 1, patroon 2 enz enz)
	int patroonAantal = 4;
	int i; // snelheid teller

	while(1)
	{
		for( i=0;i<1;i++) // i verhogen, betekent snelheid afwisseling vertragen
		{

			// patroon tonen, methode ophalen
			patroonTonen(patroon);
		}

		if (secs == 15) // aantal seconden voordat patroon veranderd. met i<1 geldt het volgende: int secs == XX is in werkelijkheid 2/3 van XX aantal seconden.
		{
			secs = 0;
			patroon = rand() % patroonAantal + 1; // random volgend patroon (1 - patroonAantal, ipv 0 - 3)
		}
		else
		{
			secs++;
		}
	}
}

int patroonTonen(patroon)
{
	unsigned int langsteTijd = 80000; // in microseconden (us)

	int loop; // for-loop patroon 1
	int loop2; // for-loop patroon 4

	if (patroon == 1)
	{
//		// alle leds branden
//		PORTD = 0b11111100;
//		PORTB = 0b00000000;
//		_delay_us(langsteTijd);

		for(loop = 0;loop<=(langsteTijd/280);loop++)
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
		// --
		for(loop2 = 0;loop2<=(langsteTijd/280);loop2++)
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

