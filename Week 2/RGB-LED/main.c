/*
 * main.c
 *
 *  Created on: 26 mei 2014
 *      Author: Gunnar
 */

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

#include <avr/io.h>

#define nop() {asm("nop");}					//Functie die nodig is om de vertraging te realiseren

unsigned int i,p,pp,ms,x;

//Functie voor de vertraging
void delay_ms(int ms)
{
	for (x = ms; x > 0; x--) nop();
}

//Rode led wordt aangezet
void ledRoodAan(int ms)
{
  PORTB &= ~_BV(PB2);   delay_ms(ms);
}

//Groene led wordt aangezet
void ledGroenAan(int ms)
{
  PORTB &= ~_BV(PB3);   delay_ms(ms);
}

//Blauwe led wordt aangezet
void ledBlauwAan(int ms)
{
  PORTB &= ~_BV(PB4);   delay_ms(ms);
}

//Rode led wordt uitgezet
void ledRoodUit(int ms)
{
   PORTB |= _BV(PB2);   delay_ms(ms);
}

//Groene led wordt uitgezet
void ledGroenUit(int ms)
{
   PORTB |= _BV(PB3);   delay_ms(ms);
}

//Blauwe led wordt uitgezet
void ledBlauwUit(int ms)
{
   PORTB |= _BV(PB4);   delay_ms(ms);
}

int main( void )
{
	//Output vanaf poortB
	DDRB |= _BV(PB2);	//PB2
	DDRB |= _BV(PB3);	//PB3
	DDRB |= _BV(PB4);	//PB4

	PORTB = 0xFF;

	pp=300; //Hiermee wordt de snelheid van het branden/doven geregeld

	for(;;) //Hiermee wordt een loop gecreëerd waarmee de reeks kleuren wordt doorlopen
	{
		//Rode led geeft licht
		PORTB &= ~_BV(PB2);
		//Groene led gaat branden
		for (i = 20; i < pp; i++) 						//waarde i wordt met 1 opgehoogd, zoland i kleiner is dan 3000 (pp)
		{						  						//wanneer i de waarde 3000 heeft gekregen, is p gelijk aan 0
		  p=pp-i;   ledGroenAan(i);   ledGroenUit(p);	//i heeft de waarde 20 omdat de spanning op de led een bepaalde waarde
		}												//nodig heeft om opgemerkt te worden

		//Groene led geeft licht
		PORTB &= ~_BV(PB3);
		//Rode led dooft uit
		for (i = 20; i < pp; i++)
		{
		  p=pp-i;   ledRoodAan(p);   ledRoodUit(i);
		}

		//Groene led geeft licht
		PORTB &= ~_BV(PB3);
		//Blauwe led gaat branden
		for (i = 20; i < pp; i++)
		{
		  p=pp-i;   ledBlauwAan(i);   ledBlauwUit(p);
		}

		//Blauwe led geeft licht
		PORTB &= ~_BV(PB4);
		//Groene led dooft uit
		for (i = 20; i < pp; i++)
		{
		  p=pp-i;   ledGroenAan(p);   ledGroenUit(i);
		}
		//Blauwe led geeft licht
		PORTB &= ~_BV(PB4);
		//Rode led gaat branden
		for (i = 20; i < pp; i++)
		{
		  p=pp-i;   ledRoodAan(i);   ledRoodUit(p);
		}

		//Rode led geeft licht
		PORTB &= ~_BV(PB2);
		//Blauwe led dooft uit
		for (i = 20; i < pp; i++)
		{
		  p=pp-i;   ledBlauwAan(p);   ledBlauwUit(i);
		}
	}
}
