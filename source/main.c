/*	Author: mchoi041
 *  Partner(s) Name: Alberto Bengo
 *	Lab Section:023
 *	Assignment: Lab 2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    
  DDRA = 0x00; PORTA = 0xFF;
  DDRB = 0x00; PORTB = 0xFF;
  DDRC = 0x00; PORTC = 0xFF;
  DDRD = 0xFF; PORTD = 0x00;

  unsigned char shiftedWeight = 0x00;
  unsigned char totalWeight = 0x00;
  unsigned char tmpA = 0x00;
  unsigned char tmpB = 0x00;
  unsigned char tmpC = 0x00;
  unsigned char tmpD = 0x00;

    while (1) {
      tmpA = PINA;
      tmpB = PINB; 
      tmpC = PINC;
      tmpD = 0x00;

      totalWeight = tmpA + tmpB + tmpC;
      
      if(tmpA > tmpC) {
	shiftedWeight = tmpA - tmpC;
      }
      else if(tmpC > tmpA) {
	shiftedWeight = tmpC - tmpA;
      }
      
      if(totalWeight > 140) {
	tmpD = 0x01;
      }
      if(shiftedWeight > 80) {
	tmpD = tmpD | 0x02;
      }
      tmpD = tmpD + (totalWeight & 0xFC);
      PORTD = tmpD;
      
    }
    return 1;
}
