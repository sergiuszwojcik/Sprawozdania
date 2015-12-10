/*
 * Zadanie6.c
 *
 * Created: 2015-12-03 08:41:55
 *  Author: Sergiusz Wojcik
 */ 

//--------------------------------------------------------------------------------------------------------------------------
//Zadanie niedokonczone
// *wszystkie przyciski z klawiatury 4x4 sa rozpoznawane, pozostala kwestia ustawienia odpowiedniego wyswietlania liczb
// Próbowalem to zrobic na symulatorze  w  Atmel Studio 7 jednak nie potrafie sobie tego wyobrazic
// Sprawozdanie dokoncze (oczywiscie jesli bedzie taka mozliwosc) jak tylko przyjdzie 
// mi klawiatura 4x4 i 4 sztuki 7-segmentowege wyświetlacze led z aliexpress,
// prawdopodobnie po swietach bozo narodzeniowych zostanie poprawiona wersja wrzucona na repozytorium
//--------------------------------------------------------------------------------------------------------------------------


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int cyfra[] = {0b00111111,0b00000110,0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
int kolumna[] = {0,0,0,0};
int akt = 0;

char Read_W()
{
	DDRB = 0b00001111;
	PORTB = 0b11110000;
	for(int i = 0 ; i < 10; i++);
	uint8_t data = ~(PINB | 0x0f);
	data = -(data-4);
	return data;
}

char Read_K()
{
	DDRB = 0b11110000;
	PORTB = 0b00001111;
	for(int i = 0 ; i < 10; i++);
	uint8_t data = ~(PINB | 0xf0);
	data = -(data-8);
	return data;
}

void show()
{
	if (akt == 0)
	{
		PORTC = cyfra[kolumna[0]];
		PORTA = 0b00001000;
	}
	else if (akt == 1)
	{
		
		PORTC = cyfra[kolumna[1]];
		PORTA = 0b00000100;
	}
	else if (akt == 2)
	{
		PORTC = cyfra[kolumna[2]];
		PORTA = 0b00000010;
	}
	else
	{
		PORTC = cyfra[kolumna[3]];
		PORTA = 0b00000001;
	}
	akt++;
	akt = akt%4;
	
}

ISR(TIMER0_COMP_vect)
{
	//if po nacisnieciu odpal 6 nizsze liniki
	uint8_t w = Read_W();
	uint8_t k = Read_K();
	int run = 4*k + w + 1;
	kolumna[1] = run%10;
	int ost = run - run/10;
	kolumna[0] = ost;
	
	show();
	
}



int main(void)
{	
	OCR0 = 250;
	TIMSK |= (1 << OCIE0);
	TCCR0 |= (1 << CS00 ) | (1 << CS01 );
	sei();
	
	// wyswietlacz
	DDRA = 0b00001111;
	DDRC = cyfra[0];
	
	//klawiatura
	
	
    while(1)
    {	
        //TODO:: Please write your application code 
    }
}