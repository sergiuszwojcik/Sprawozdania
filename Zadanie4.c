/*
 * GccApplication2.c
 *
 * Created: 2015-11-19 08:50:03
 *  Author: Sergiusz Wojcik
 */ 

 // Zadanie 4 - program zliczajacy diody, uzywajacy blinka, sluzacy do wykorzystania interruptow
 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
// Musimy zainkludowac zeby uzywac makra ISR przerwan
#include <AVR/interrupt.h>

int licznik = 0;


// Makro na interrupt hanlder funkcje
// W tym wypadku interrupt 0
ISR(INT0_vect)
{
	// Funkcja odlicza na diodach po klikaniu przycisku
	licznik++;
	PORTA = (PORTA & 0x01) | ((licznik<<1) & 0xFE);

}

int main(void)
{
	DDRA = 0xFF;
	DDRD = 0;
	PORTD |= (1<<PD2);
	// MCUCR is the MCU Control Register.
	// konfiguracja przerwania, zbocze opadajce
	MCUCR |= (1<<ISC01);
	// Enable External Interrupt 0
	// wlaczenie przerwan int 0
	GICR |= (1<<INT0);
	
	//Sets the Global Interrupt flag (I) in SREG (status register). The instruction following SEI will be executed before any pending interrupts.
	// Enable on all Global Interrupts
	sei();
	
	// Funkcja logiczna odpowiadajaca za blinkowanie diody
    while(1)
    {
		PORTA ^= 0x01;
		_delay_ms(500);
		
        //TODO:: Please write your application code 
    }
}