
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


// 100 US -> GO ADC
void Timer0_8bit(void){
    T0CON1bits.CS = 0b011; // HFINTOSC
    T0CON0bits.MD16 = 0; // 8 bits
    //T0CON1bits.CKPS = 0b1000; // 256 prescaler
    T0CON1bits.CKPS = 0b1001; // 512 prescaler
    T0CON0bits.OUTPS = 0; // 1:1 POSTSCALER
    T0CON1bits.ASYNC = 1; // NO ESTA SINCRONIZADO
    //TMR0H = 0x18; 
    TMR0H = 0x7C;// -> 1ms
    TMR0L = 0x00;
    T0CON0bits.EN = 1;
}

void Stop_Timer0(void){
    T0CON0bits.EN = 0;
}

void Start_Timer0(void){
    T0CON0bits.EN = 1;
}