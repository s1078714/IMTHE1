/*
 * main.c
 *
 *  Created on: 14 jul. 2014
 *      Author: Gunnar, Jaimy, Peter
 */


#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

	int patroonTonen();
	int adc_value;		//Variable om de waarde van de ADC converter in op te slaan

int main(void)
{
	DDRD = 0b11111100; // blauw || groen
	DDRB = 0b11110000; // geel || wit

	// Prescalers voor deelconcept Geluid, Jaimy
	ADCSRA |= ((0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));  			//Prescaler at 128 so we have an 125Khz clock source
	ADMUX  |= (1<<REFS0);
	ADMUX  &= ~(1<<REFS1);               				//Avcc(+5v) as voltage reference
	ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));			//ADC in free-running mode
	ADCSRA |= (1<<ADATE);                				//Signal source, in this case is the free-running
	ADCSRA |= (1<<ADEN);                				//Power up the ADC
	ADCSRA |= (1<<ADSC);                				//Start converting



	uint8_t secs = 0; // teller
	int patroon = 1; // reset naar eerste patroon, voor het leesgemak begint patroon bij 1 (patroon 1, patroon 2 enz enz)
	int patroonAantal = 4;
	int i; // snelheid teller

	while(1)
	{
		adc_value = ADCW;

//		for( i=0;i<1;i++) // i verhogen, betekent snelheid afwisseling vertragen
//		{

			if(adc_value < 200)
			{
				//PORTB = 0b00000001;
				patroonTonen(patroon);
			}
			else
			{
				PORTB = 0b11111111;
				//			patroonTonen(null);
			}

//		}

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
	unsigned int langsteTijd = 80; // in microseconden (us)

	int loop; // for-loop patroon 1
	int loop2; // for-loop patroon 4

	if (patroon == 1)
	{
		// alle leds branden

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

	return 0;
}
