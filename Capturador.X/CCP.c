
#include "CCP.h"


void CCP_Init(void){
    RF5PPS = 0x15;
    TRISFbits.TRISF5 = 1;
    // Periodo
    // 250us
    T2PR = 0xF9;
    CCP1CONbits.MODE = 0b1100; // PWM
    CCP1CONbits.FMT = 0; // alineación a la derecha
    CCPR1H = 0x01;
    CCPR1L = 0xF4;
    PIR3bits.TMR2IF = 0;
    T2CONbits.CKPS = 4;
    T2CLKCONbits.CS = 0b00001;
    CCP1CONbits.EN = 1;
    TRISFbits.TRISF5 = 0;
    T2CONbits.ON = 1;
    // // RF3
    
}
