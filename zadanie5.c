/*
 * GccApplication1.c
 *
 * Created: 2015-11-26 08:42:03
 *  Author: Sergiusz Wójcik
 */ 

// Program odliczajacy sekundy na 7segmentowych wyswietlaczach led.

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int cyfra[] = {~0b00111111,~0b00000110,~0b01011011, ~0b01001111, ~0b01100110, ~0b01101101, ~0b01111101, ~0b00000111, ~0b01111111, ~0b01101111};  // deklaracja liczb do 1...9
int kolumna[] = {0,0,0,0};  // kolumny czyli dany segment wyswietlacza led
int akt = 0; // liczy aktualny wyswietlacz 
int licznik_przerwan = 0; // na ktorym przerwaniu jestesmy 1000 minela sekunda

ISR(TIMER0_COMP_vect)
{
	if (akt == 0)
	{
		PORTA = cyfra[kolumna[0]];
		PORTB = ~0b00001000;
	}
	else if (akt == 1)
	{
		PORTA = cyfra[kolumna[1]];
		PORTB = ~0b00000100;
	}
	else if (akt == 2)
	{
		PORTA = cyfra[kolumna[2]];
		PORTB = ~0b00000010;
	}
	else
	{
		PORTA = cyfra[kolumna[3]];
		PORTB = ~0b00000001;
	}
	
	akt++;
	if (akt == 4)	//kiedy kolumna 4 wyzeruj i od nowa
		akt = 0;
		
	licznik_przerwan++;
	
	if ( licznik_przerwan == 1000)
	{
		kolumna[0] ++;
		if (kolumna[0] == 10)
		{
			kolumna[0] = 0;
			kolumna[1]++;
		}
		if (kolumna[1] == 10)
		{
			kolumna[1] = 0;
			kolumna[2]++;
		}
		if (kolumna[2] == 10)
		{
			kolumna[2] = 0;
			kolumna[3]++;
		}
		if (kolumna[3] == 10)
		{
			kolumna[3] = 0;
		}
		licznik_przerwan = 0;
	}
	
}


int main(void)
{
	OCR0 = 250;
	TIMSK |= (1 << OCIE0);
	TCCR0 |= (1 << CS00 ) | (1 << CS01 );
	sei();
	
	DDRA = 0xFF;
	DDRB = 0b00001111;
	
    while(1)
    {
			
		
        //TODO:: Please write your application code 
    }
}