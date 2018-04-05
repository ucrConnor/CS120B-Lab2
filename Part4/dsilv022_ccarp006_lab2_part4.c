/*
 * Part4.cpp
 *
 * Created: 4/4/2018 5:52:37 PM
 * Author : Connor
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; 
    DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char upper = 0x00;
	unsigned char lower = 0x00;
    while (1) 
    {
		upper = PINA & 0xF0;
		lower = PINA & 0x0F;
		
		upper = upper >> 4;
		lower = lower << 4;
		
		PORTB = upper;
		PORTC = 0xFF;
		
    }
}

