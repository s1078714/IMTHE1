/*
 * HelloWorld.cpp
 *
 *  Created on: 18 mei 2014
 *      Author: Gunnar
 */

#include <HelloWorld.h>
#include<avr/io.h>       // Header file for basic avr input/output
     #include<util/delay.h>   // header file for delay generation
     #define BV(x) (1<<x)     // See text below

     int main(void)
     {
	DDRC=0xFF;      // PORTC declared as output
	PORTC=0xFF;     // PORTC is initially high to off the led initially
	while(1==1)     // infinite loop as 1 is always equals 1
	{
		PORTC=~(BV(5));     // led glow here, Making 5th bit of PORTC LOW
		_delay_ms(1000);    // one second delay
		PORTC=BV(5);        // led do not glow here
		_delay_ms(1000);
	}
	return 0;

    }

