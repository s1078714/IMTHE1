#include <avr/io.h>  //Een include voor alle info over de Microcontroller
#include <util/delay.h> //Een include waarmee we vertragingen in het programma kunnen veroorzaken

int main(void)
{
	DDRB |= 1 << PINB1;   //Output voor de led
	DDRB &= ~(1 << PINB0);
	PORTB |= 1 << PINB0;  //Input voor de pushbutton
	int Pressed = 0;

	while (1)
	{
		if (bit_is_clear(PINB, 0)) //Kijken of er op de knop is gedrukt
		{
			//Kijk eerst of de knop losgelaten is
			if (Pressed == 0)
			{
				PORTB ^= 1 << PINB1; //Zet de led op PB1 aan
				Pressed = 1;
			}
		}
		else
		{
			//Als er niet op de knop gedrukt wordt, blijft deze int op 0
			Pressed = 0;
		}
		_delay_ms(1); // dendergedrag uitsluiten
	}
}
