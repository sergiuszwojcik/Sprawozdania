/*
 * GccApplication1.c
 *
 * Created: 2015-11-05 08:48:58
 *  Author: Sergiusz Wojcik
 */ 


 // Zadanie drugie po naciśnięciu zapala falowo diody tam i spowrotem
 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
    DDRA = 0xFF;
    //PORTA = 0xFF
    DDRB = 0x00;
    PORTB = 0b00000001;
    
    

    while(1)
    {
        
            if(PINB & 0x01){
                
                PORTA = 0b00000000;
                
            }
            else
            {
                // petle z przesunieciem wraz z opoznieniem(delayem)
                for (int y = 0 ; y < 3 ; y++){
                
                    for(int i = 0; i < 7; i++)
                    {
                        PORTA = (1 << i);
                        _delay_ms(100);
                    }
                    
                    for(int i = 7; i >= 0; i--)
                    {
                        PORTA = (1 << i );
                        _delay_ms(100);
                    }
                
                    
                }
                
            
                
                
            }
            
        
        
        
        
        //TODO:: Please write your application code 
    }
}