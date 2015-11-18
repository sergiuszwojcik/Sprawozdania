/*
 * GccApplication1.c
 *
 * Created: 2015-11-05 08:48:58
 *  Author: Sergiusz Wojcik
 */ 
// Zadanie 3 - wygaszanie diodek

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
    DDRA = 0xFF;
    //PORTA = 0xFF
    DDRB = 0x00;
    PORTB = 0b00000001;
    int t = 2001;   //zmienna pomocnicza do wygaszania diodek zeby zmieniac czas ich zapalania
    

    while(1)
    {
        
            if(PINB & 0x01){
                
                PORTA = 0b00000000;
                
            }
            else
            {
                           
                               
                    //Wygaszanie
                    
                    for(int z = 0 ; z < 2000 ; z++){
                        
                        
                        
                        _delay_us(z);
                            for(int i = 10; i < 100; i++)
                            {
                                _delay_us(z + 1);
                                PORTA = (1 << i);
                                _delay_us(t-z);
                                PORTA = (1 << i);
                                
                                    
                                
                            }
                            //PORTA = 0b11111111;
                            
                        //_delay_us(t-z);
                        
                        //    PORTA = 0b00000000;
                        
                        
                        
                    }
                    
                    
                           
            }
            
        
        
        
        
        //TODO:: Please write your application code 
    }
}