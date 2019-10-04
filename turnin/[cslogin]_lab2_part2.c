/*	Author: mchoi041
 *  Partner(s) Name: Alberto Bengo
 *	Lab Section:023
 *	Assignment: Lab 2  Exercise #2
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
  DDRC = 0xFF; PORTC = 0x00;

  unsigned char cntavail = 0x00;
  unsigned char tmpA = 0x00;
    
    while (1) {
      tmpA = PINA & 0x0F;

      if (tmpA == 0x00) {
	cntavail = 0x04;
      }
      else if (tmpA == 0x01) {
	cntavail = 0x03;
      }
      else if (tmpA == 0x03) {
	cntavail = 0x02;
      }
      else if (tmpA == 0x07) {
	cntavail = 0x01;
      }
      else if (tmpA == 0x0F) {
	cntavail = 0x00;
      }

      PORTC = cntavail;
    }
    return 1;
}
