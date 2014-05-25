/*
 * main.c
 *
 *  Created on: 21 mei 2014
 *      Author: Gunnar
 */

#include <avr/io.h>
#include <avr/delay.h>

//int secs = 0;
int i;

int main(void)
{
	DDRD = 0b11111111; // Signaal op PortD0 (is nu output)
	//PORTD = 0b00000001; // 5 Volt op PortD0
	DDRC = 0b0110000;

	uint8_t secs = 0;

	while (1)
	{
		for( i=0;i<10;i++)
		{

			displayLinks(secs/10);
			_delay_ms(1);
			displayRechts(secs%10);
			_delay_ms(1);


		}
		if (secs == 100)
		{
			secs = 0;
		}
		else
		{
			secs++;
		}

		//		displayLinks();
		//		displayRechts();
	}


}

displayRechts(cijferRechts)
{
	char cijfer[10];
	cijfer[1] = 0b00000110; // 1
	cijfer[2] = 0b11011011; // 2
	cijfer[3] = 0b01001111; // 3
	cijfer[4] = 0b01100110; // 4
	cijfer[5] = 0b01101101; // 5
	cijfer[6] = 0b01111101; // 6
	cijfer[7] = 0b00000111; // 7
	cijfer[8] = 0b11111111; // 8
	cijfer[9] = 0b11101111; // 9
	cijfer[0] = 0b00111111; // 0

	PORTC = 0b0100000;
	PORTD = cijfer[cijferRechts];




	//	for (i=0;i<10;i++)
	//	{
	//		PORTD = cijfer[i];
	//	}
}

displayLinks(cijferLinks)
{
	char cijfer[10];
	cijfer[1] = 0b00000110; // 1
	cijfer[2] = 0b11011011; // 2
	cijfer[3] = 0b01001111; // 3
	cijfer[4] = 0b01100110; // 4
	cijfer[5] = 0b01101101; // 5
	cijfer[6] = 0b01111101; // 6
	cijfer[7] = 0b00000111; // 7
	cijfer[8] = 0b11111111; // 8
	cijfer[9] = 0b11101111; // 9
	cijfer[0] = 0b00000000; // 0

	PORTC = 0b0010000;
	PORTD = cijfer[cijferLinks];



	//	for (i=0;i<10;i++)
	//		cijfer[i];
}
