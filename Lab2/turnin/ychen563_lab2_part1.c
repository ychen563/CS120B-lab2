/*Author: ychen563
 *Lab Section:
 *Assignment: Lab #  Exercise #
 *Exercise Description: [optional - include for your own benefit]
 *	
 *I acknowledge all content contained herein, excluding template or example
 *code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of 
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    /* Insert your solution below */
    while (1) {
        tmpA = PINA & 0x03;

        if (tmpA == 0x00){//if a1a0 = 00
            tmpB = (tmpB & 0xFE) | 0x00; //set b0 = 0
        }
        else if (tmpA == 0x01){//if a1a0 = 01
            tmpB = (tmpB & 0xFE) | 0x01; //set b0 = 1
        }
        else if (tmpA == 0x02){//if a1a0 = 10
            tmpB = (tmpB & 0xFE) | 0x00; //set b0 = 0
        }
        else if (tmpA == 0x03){//if ala0 = 11
            tmpB = (tmpB & 0xFE) | 0x00; //set b0 = 0
        }
        PORTB = tmpB;
    }
    return 0;
}

