/*
 * main.c
 *
 *  Created on: 14 jul. 2014
 *      Author: Gunnar, Jaimy
 */


#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

	int patroonTonen();
	int adc_value;		//Variable om de waarde van de ADC converter in op te slaan

int main(void)
{
	DDRD = 0b11111111; // paars
	DDRB = 0b11111111; // geel

	// Prescalers voor deelconcept Geluid, Jaimy
	ADCSRA |= ((0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));  			//Prescaler at 8 so we have an 125Khz clock source
	ADMUX  |= (1<<REFS0);
	ADMUX  &= ~(1<<REFS1);               				//Avcc(+5v) as voltage reference
	ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));			//ADC in free-running mode
	ADCSRA |= (1<<ADATE);                				//Signal source, in this case is the free-running
	ADCSRA |= (1<<ADEN);                				//Power up the ADC
	ADCSRA |= (1<<ADSC);                				//Start converting



	uint8_t secs = 0; // teller
	int patroon = 1; // reset naar eerste patroon, voor het leesgemak begint patroon bij 1 (patroon 1, patroon 2 enz enz)
	int patroonAantal = 7;
	int i; // snelheid teller

	while(1)
	{
		adc_value = ADCW;

		if(adc_value < 325) // 335
		{
			patroon = rand() % patroonAantal + 1; // random volgend patroon (1 - patroonAantal, ipv 0 - 3)

//			if (patroon == 2 || patroon == 3)
//			{
//				patroon = 4;
//			}
				patroonTonen(patroon);
			}
			else
			{
				PORTB = 0b00000000;
				PORTD = 0b00000000;
			}
	}
}

int patroonTonen(patroon)
{
	if (patroon == 1)
	{
		// alle leds branden
			PORTD = 0b11111111;
			PORTB = 0b11111111;
			_delay_ms(16);
	}
	if (patroon == 2)
	{
		// vliegend led, linksom met afwisselende brandende hoeken

		int snelheid = 1300;

		PORTD = 0b00000000; // reset port d
		PORTB = 0b00000001;
		_delay_us(snelheid);
		PORTB = 0b00000010;
		_delay_us(snelheid);
		PORTB = 0b00000100;
		_delay_us(snelheid);
		PORTB = 0b00001000;
		_delay_us(snelheid);
		PORTB = 0b00010000;
		_delay_us(snelheid);
		PORTB = 0b00100000;
		_delay_us(snelheid);
		PORTB = 0b01000000;
		_delay_us(snelheid);
		PORTB = 0b10000000;
		_delay_us(snelheid);

		PORTB = 0b00000000; // reset port b
		PORTD = 0b10000000;
		_delay_us(snelheid);
		PORTD = 0b01000000;
		_delay_us(snelheid);
		PORTD = 0b00100000;
		_delay_us(snelheid);
		PORTD = 0b00010000;
		_delay_us(snelheid);
		PORTD = 0b00001000;
		_delay_us(snelheid);
		PORTD = 0b00000100;
		_delay_us(snelheid);
		PORTD = 0b00000010;
		_delay_us(snelheid);
		PORTD = 0b00000001;
		_delay_us(snelheid);
	}
	if (patroon == 3)
	{
		// vliegend led, volledig rechtsom (geen brandende hoeken)

		int snelheid = 1300;

		PORTD = 0b00000000; // reset port d
		PORTB = 0b10000000;
		_delay_us(snelheid);
		PORTB = 0b01000000;
		_delay_us(snelheid);
		PORTB = 0b00100000;
		_delay_us(snelheid);
		PORTB = 0b00010000;
		_delay_us(snelheid);
		PORTB = 0b00001000;
		_delay_us(snelheid);
		PORTB = 0b00000100;
		_delay_us(snelheid);
		PORTB = 0b00000010;
		_delay_us(snelheid);
		PORTB = 0b00000001;
		_delay_us(snelheid);

		PORTB = 0b00000000; // reset port b
		PORTD = 0b00000001;
		_delay_us(snelheid);
		PORTD = 0b00000010;
		_delay_us(snelheid);
		PORTD = 0b00000100;
		_delay_us(snelheid);
		PORTD = 0b00001000;
		_delay_us(snelheid);
		PORTD = 0b00010000;
		_delay_us(snelheid);
		PORTD = 0b00100000;
		_delay_us(snelheid);
		PORTD = 0b01000000;
		_delay_us(snelheid);
		PORTD = 0b10000000;
		_delay_us(snelheid);
	}
	if (patroon == 4)
	{
		// kruisje
		PORTD = 0b01100110;
		PORTB = 0b01100110;
		_delay_ms(16);
	}
	if (patroon == 5)
	{
		// hoekjes
		PORTD = 0b10011001;
		PORTB = 0b10011001;
		_delay_ms(16);
	}
	if(patroon == 6)
	{
		PORTD = 0b00110011;
		PORTB = 0b11001100;
		_delay_ms(16);
	}
	if(patroon == 7)
	{
		PORTD = 0b11001100;
		PORTB = 0b00110011;
		_delay_ms(16);
	}

	return 0;
}
