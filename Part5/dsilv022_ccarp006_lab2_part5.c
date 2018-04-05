/*
 * Part5.cpp
 *
 * Created: 4/4/2018 8:36:11 PM
 * Author : Connor
 */ 

#include <avr/io.h>


int main(void)
{
    DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	unsigned short weight = 0x00;
	unsigned char airbag = 0x00;
    while (1) 
    {
		weight = PIND;
		weight = (weight << 1) + PINB & 0x01;
		if (weight > 0x05){
			airbag = weight > 0x46 ? 0x01 : 0x00;	
			PORTB |= (airbag << 1);
			PORTB |= ( !airbag << 2);
		}
		else{
			PORTB &= 0b00000001; 	
		}
    }
}

