/*
 * Part1.cpp
 *
 * Created: 4/4/2018 3:05:45 PM
 * Author : Connor
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char count = 0x00;
    while (1) 
    {
		tempA = PINA;
		tempB = PINB;
		count = 0x00;
		while(tempA || tempB){
			if(PINA & 0x01) 
				count++;
				
			if(PINB & 0x01) 	
				count++;
			
			tempA = tempA >> 1;
			tempB = tempB >> 1;
		}
		PORTC = count;
    }
}

