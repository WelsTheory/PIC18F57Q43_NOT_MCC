
#include <pic18f57q43.h>

#include "Timer0_Libreria.h"

void Timer0_Init(void){
    T0CON1bits.CS = 0b010; // FOSC // HFINTOSC
    T0CON0bits.MD16 = 1; // 16 bits
    T0CON1bits.CKPS = 0b1000; // 256 prescaler
    T0CON0bits.OUTPS = 0; // 1:1 POSTSCALER
    T0CON1bits.ASYNC = 0;
    TMR0H = 0xE7;
    TMR0L = 0x95;
    /*
     * TMR0H = 0x00; TMR0L = 0x00;
     * TMR0OUT = 0 -> 1
     * TMR0H = 0xE7;
     * TMR0L = 0x95;
     * TMR0H = 0x00  TMR0L = 0x= 0x95;00;
     *  
     */
    T0CON0bits.EN = 1;
}

void Timer0_8bit(void){
    T0CON1bits.CS = 0b010; // FOSC // HFINTOSC
    T0CON0bits.MD16 = 0; // 8 bits
    T0CON1bits.CKPS = 0b1110; // 16384 prescaler
    T0CON0bits.OUTPS = 0; // 1:1 POSTSCALER
    T0CON1bits.ASYNC = 0;
    //19.53 -> 13
    TMR0H = 0x13; 
    T0CON0bits.EN = 1;
}