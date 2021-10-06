#include "ADC_Libreria.h"

void ADC_Init(void){
    TRISAbits.TRISA0 = 1; // Entrada RA0
    ANSELAbits.ANSELA0 = 1; // Analógico RA0
    TRISAbits.TRISA1 = 1; // Entrada RA0
    ANSELAbits.ANSELA1 = 1; // Analógico RA0
    ADCON0bits.CS = 0; // Clock Fosc
    ADCLK = 0b001111; // 500ns = 0.5us -> TAD
    ADCON2bits.MD = 0; // Modo ADC
    ADCON0bits.FM = 1; // 4 bits ADRESH MSB - ADRESL LSB 8 bits
    ADREFbits.NREF = 0; // VSS
    ADREFbits.PREF = 0; // VDD
    //ADPCH = 0; // AN0
    ADCON0bits.ON = 1; // ADC ON
}

uint16_t ADC_Conversion(uint8_t canal){
    ADPCH = canal;
    ADCON0bits.GO = 1; // Comenzar conversión
    while(ADCON0bits.GO == 1); // Conversión en proceso
    return((uint16_t)((ADRESH<<8) + ADRESL));
    // VAR = (ADRESH<<8 + ADRESL)
    // ADRESH -> 1111111100000000  <<8 
    // ADRESL ->         11111111
    //        -> 1111111111111111
}