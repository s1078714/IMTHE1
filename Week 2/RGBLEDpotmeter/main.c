#include <avr/io.h>
#include <util/delay.h>

int adc_value;        //Variable om de waarde van de ADC converter in op te slaan

int main(void)
{
//	DDRB |= (1<<PB7);    ///PB5 is output
	DDRB = 0b11100000;

	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));  		//Prescaler at 128 so we have an 125Khz clock source
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);               				//Avcc(+5v) as voltage reference
	//ADCSRA &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));    //ADC in free-running mode
	//ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));    //ADC in free-running mode
	ADCSRA |= (1<<ADATE);                				//Signal source, in this case is the free-running
	ADCSRA |= (1<<ADEN);                				//Power up the ADC
	ADCSRA |= (1<<ADSC);                				//Start converting

	while(1)
	{
		 adc_value = ADCW;
		 if(adc_value >= 0 && adc_value < 126)
		 {

			 _delay_ms(5);PORTB &= ~(1<<PB7);
			 PORTB ^= 1 << PB6;
			 PORTB |= (0<<PB5);
		 }
		 else if(adc_value >= 127 && adc_value < 254)
		 {

				_delay_ms(5);PORTB |= (0<<PB7);
			 PORTB &= ~(1<<PB6);
			 PORTB ^= 1 << PB5;
		 }
		 else if(adc_value >= 255 && adc_value < 512)
		 {

				_delay_ms(5);PORTB ^= 1 << PB7;
			 PORTB |= (0<<PB6);
			 PORTB &= ~(1<<PB5);
		 }
		 else
		 {

			 _delay_ms(5);PORTB |= (0<<PB7);
			 PORTB |= (0<<PB6);
			 PORTB |= (0<<PB5);
		 }
	}
	return 0;
}

