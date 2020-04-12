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
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    /* Insert your solution below */
    while (1) {
        unsigned char cntavail = 0x0l;
        tmpA = PINA & 0x0F;

        while(tmpA) {
            tmpA = tmpA & ((tmpA << 1) + (~tmpA));
            cntavail = cntavail + 1;
        }
        PORTC = cntavail;
    }
    return 0;
}

