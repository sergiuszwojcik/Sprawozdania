/*
 * GccApplication1.c
 *
 * Created: 2015-11-05 08:48:58
 *  Author: Sergiusz Wojcik
 */ 


 // Zadanie pierwsze po naciśnięciu przycisku zapala wszystkie diody .
 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{

// deklaracje portow
    DDRA = 0xFF;
    //PORTA = 0xFF
    DDRB = 0x00;
    PORTB = 0b00000001;
    
    

    while(1)
    {
        
            if(PINB & 0x01){    // jesli przycisk 0 nic nie zaswiecaj
                
                PORTA = 0b00000000;
                
            }
            else    // w innym razie 1 zaswiec diody
            {
                
                
                        PORTA = 0b11111111;
                        
                   
                
                    
                }
                
            
                
                
            }
            
        
        
        
        
        //TODO:: Please write your application code 
    }
}