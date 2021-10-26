#include "ADC_Libreria.h"

void ADC_Init(void){
    TRISAbits.TRISA0 = 1; // Entrada RA0
    ANSELAbits.ANSELA0 = 1; // Analógico RA0
    TRISAbits.TRISA1 = 1; // Entrada RA0
    ANSELAbits.ANSELA1 = 1; // Analógico RA0
    ADCON0bits.CS = 0; // Clock Fosc
    ADCLK = 64;//0b001111; // 1us -> TAD
//    ADCON2bits.MD = 0; // Modo Básico ADC 
//    ADCON2bits.MD = 1; // Modo Acumulador
    ADCON2bits.MD = 4; // Modo FPB
    ADCON0bits.FM = 1; // 4 bits ADRESH MSB - ADRESL LSB 8 bits
    ADREFbits.NREF = 0; // VSS
    ADREFbits.PREF = 0; // VDD
    ADACT = 0b00000010; // TMR0 Fuente Conversión
    ADCON2bits.CRS = 5; // 2^5
    ADRPT = 32; 
    IPR1bits.ADIP = 1;// Habilitar INT ADC
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    //ADPCH = 0; // AN0
    ADCON0bits.ON = 0; // ADC ON
}

void ADC_Start_Conversion(uint8_t canal){
    ADPCH = canal;
    ADCON0bits.ADGO = 1; // Comenzar conversión
    ADCON0bits.ADON = 1; // ADC ON
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