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
	DDRD = 0b11111111; // bit1 == output, bit0 == input
	DDRC = 0b0110000;

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

			if (patroon == 5) // laatste patroon bereikt
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
	}
	if (patroon == 2)
	{
		// multiplexen, coooode
	}
	if (patroon == 3)
	{
		// multiplexen, coooode
	}
	if (patroon == 4)
	{
		// multiplexen, coooode
	}
	if (patroon == 5)
	{
		// multiplexen, coooode
	}
}
