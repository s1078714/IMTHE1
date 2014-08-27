#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

//#define UART_BAUD_RATE 2400
//#include "uart/uart.h"

#include "bmp085/bmp085.h"

// code LCD 44780
//Gebruikte poorten op poortD
#define LCD_DB4 0   //PD0
#define LCD_DB5 1   //PD1
#define LCD_DB6 2   //PD2
#define LCD_DB7 3   //PD3
#define LCD_E  4    //PD4
#define LCD_RS 5    //PD5

//LCD commands
#define LCD_CLR 		0x01    // clear display
#define LCD_HOME 		0x02    // return home
#define LCD_INC 		0x06    // Increment, display freeze
#define LCD_MOV 		0x10    // Cursor move, not shift
#define LCD_OFF         0x08    // lcd off
#define LCD_ON          0x0C    // lcd on
#define LCD_BLINK_ON	0x0D    // blink on
#define LCD_CURSOR_ON	0x0E    // cursor on
#define LCD_ALL_ON	    0x0F    // cursor on /  blink on
#define LCD_LINE1  		0x80    // cursor Pos on line 1 (or with column)
#define LCD_LINE2  		0xC0    // cursor Pos on line 2 (or with column)

unsigned char chr,data,pos;

//Hiermee wordt een karakter naar het LCD geschreven
void LCD_char(unsigned char data)
{
	PORTD = (data&0b11110000) >> 4; //high nibble
	PORTD |= 1<<LCD_RS;
	PORTD |= 1<<LCD_E;
	_delay_ms(2);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(2);

	PORTD = (data&0b00001111); //low nibble
	PORTD |= 1<<LCD_RS;
	PORTD |= 1<<LCD_E;
	_delay_ms(2);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(2);
}

//Hiermee wordt een instructie naar de LCD geschreven
void LCD_inst(unsigned char inst)
{
	PORTD = (inst&0b11110000) >> 4; //send high nibble
	PORTD &= ~(1<<LCD_RS); // set RS to instructions
	PORTD |= 1<<LCD_E;
	_delay_ms(2);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(2);

	PORTD = (inst&0b00001111); //send low nibble
	PORTD |= 1<<LCD_E;
	_delay_ms(2);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(2);
}

// clear display
void LCDclr(void)
{
	LCD_inst (LCD_CLR);
}

// return home
void LCDhome(void)
{
	LCD_inst (LCD_HOME);
}

// LCD off
void LCDoff(void)
{
	LCD_inst (LCD_OFF);
}

// LCD on
void LCDon(void)
{
	LCD_inst (LCD_ON);
}

// cursor on
void LCDcursor(void)
{
	LCD_inst (LCD_CURSOR_ON);
}

// blink on
void LCDblink(void)
{
	LCD_inst (LCD_BLINK_ON);
}

// cursor all on
void LCDall(void)
{
	LCD_inst (LCD_ALL_ON);
}

//go to first line
void LCDline1 (void)
{
	LCD_inst (0b10000000);
}

//go to second line
void LCDline2 (void)
{
	LCD_inst (0b11000000);
}

// goto position x,y
void LCDgoto (char x,char y)
{
	if (y == 0)
	{
	pos = 0b00000000 + x;
	}

	else if (y == 1)
	{
	pos = 0b01000000 + x;
	}
	LCD_inst (0b10000000 | pos);
}

//write text to the LCD
void LCDtext(char *data)
{
	while (*data)
		{
			LCD_char(*data);
			data++;
		}
}

// init LCD
void LCD_init(void)
{
	DDRD = 0xFF;  //PoortD = output
	_delay_ms(40);

	// set 4-bit mode
	PORTD = 1<<2;
	PORTD |= 1<<LCD_E;
	_delay_ms(1);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(1);

	PORTD = 1<<2;
	PORTD |= 1<<LCD_E;
	_delay_ms(1);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(1);

	PORTD = 1<<2;
	PORTD |= 1<<LCD_E;
	_delay_ms(1);
	PORTD &= ~(1<<LCD_E);
	_delay_ms(1);

	//set 4-bit mode and 2-line
	LCD_inst (0b00101000);

	//turn on display and cursor
	LCD_inst (0b00001100);

	//clr display
	LCD_inst (LCD_CLR);
}
// einde code LCD 44780

int main(void) {
	long l;
	double d;
	char printbuff[10];

	//init uart
//	uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );

	//init interrupt
	sei();

	//init bmp085
	bmp085_init();

	// code LCD 44780
	LCD_init();
	LCD_init();
	//	LCDgoto (0,0);
	LCDtext("Gunnar Kelders");
	LCDgoto (0,1);
	LCDtext("IMTHE1 LCD");
	//	LCDall();
	//	LCDhome();

	// einde code LCD 44780

	//main loop
	while(1)
	{


		//get temperature
		d = bmp085_gettemperature();
		dtostrf(d, 10, 2, printbuff);
		LCDtext("temperature: "); LCDtext(printbuff);  LCDtext(" C deg"); LCDtext("\r\n");

		// testen
		if (printbuff == "")
		{
			// led branden
			PINC1 << 1;
		}

		//get pressure
		l = bmp085_getpressure();
		ltoa(l, printbuff, 10);
		LCDtext("pressure: "); LCDtext(printbuff); LCDtext(" Pa"); LCDtext("\r\n");

		//get altitude
		d = bmp085_getaltitude();
		dtostrf(d, 10, 2, printbuff);
		LCDtext("altitude: "); LCDtext(printbuff); LCDtext(" M"); LCDtext("\r\n");

		LCDtext("\r\n");
		_delay_ms(1500);
	}

}
