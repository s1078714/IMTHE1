/*
 * main.c
 *
 *  Created on: 26 mei 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <util/delay.h>

//Aliassen voor de PWM kanalen
//PWM kanaal OCR0B wordt niet gebruikt
#define PWM_RED   OCR0A
#define PWM_GREEN OCR1AL
#define PWM_BLUE  OCR1BL

void delay_ms(unsigned int t)
{
	while(t)
	{
		t--;
		_delay_ms(1);
	}
}

void fade_in(volatile uint8_t *pwm_channel)
{
	unsigned int i;
	for(i = 0; i < 255; i++)
	{
		*pwm_channel = i;
		delay_ms(100);
	}
}

void fade_out(volatile uint8_t *pwm_channel)
{
	unsigned int i;
	for(i = 0; i < 255; i++)
	{
		*pwm_channel = ~i;
		delay_ms(100);
	}
}

int main(void)
{
	// TIMER 0 Fast PWM, clear OC0A on match
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
	// TIMER 0 Prescaler ck/8
	TCCR0B = (1 << CS01);

	// TIMER 1 Fast PWM 8-bit, clear OC1A, OC1B on match
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
	// TIMER 1 Prescaler ck/8
	TCCR1B = (1 << CS11) | (1 << WGM12);

	//PWM kanalen als uitgang
	DDRB = (1 << PB2) | (1 << PB3) | (1 << PB4); //0C0A, 0C1A, OC1B

	DDRD = 0b00000111;

	while(1)
	{
		delay_ms(1000);
		fade_in(&PWM_GREEN);  // langzaam groen aan
		fade_out(&PWM_RED);   // langzaam rood uit
		delay_ms(1000);
		fade_in(&PWM_BLUE);   // langzaam blauw aan
		fade_out(&PWM_GREEN); // langzaam groen uit
		delay_ms(1000);
		fade_in(&PWM_RED);    // langzaam rood aan
		fade_out(&PWM_BLUE);  // langzaam blauw uit

		/*
		PORTD = 0b00000000; // lichtblauw/wit
		_delay_ms(100);
		PORTD = 0b00000001; // geel
		_delay_ms(100);
		PORTD = 0b00000010; // magenta
		_delay_ms(100);
		PORTD = 0b00000011; // rood
		_delay_ms(100);
		PORTD = 0b00000101; // groen
		_delay_ms(100);
		PORTD = 0b00000110; // blauw
		_delay_ms(100);
		PORTD = 0b00000100; // cyaan
		_delay_ms(100);
		 */
/*
		PORTD = 0b00000111; // uit, er moet minimaal één uitgang op nul staan.
 */
	}

	return 0;
}
