#include "PWM_16.h"

void PWM16_Init(void){
    PWM1CPRE = 99; //Prescaler 100
    PWM1CLK = 0b00010; // Seleccionamos Fosc
    //Periodo 12799 -> 20ms
    // 0x31 0xFF
//    PWM1PRH = 0x31;
//    PWM1PRL = 0xFF;
    // Duty Cycle 1ms 
    // 640 -> 0x280
//    PWM1S1P1H = 0x05;
//    PWM1S1P1L = 0x00;
    //PWMPRL 49; 1khZ
    PWM1PRL = 0x31;

    //PWMPRH 0; 
    PWM1PRH = 0x00;
    
    // Duty cycle 2ms
    // 1280 -> 0x500;
//    PWM1S1P2H = 0x05;
//    PWM1S1P2L = 0x00;
    
    //PWMS1P1L 25; 
    PWM1S1P1L = 0x19;

    //PWMS1P1H 0; 
    PWM1S1P1H = 0x00;

    //PWMS1P2L 25; 
    PWM1S1P2L = 0x19;

    //PWMS1P2H 0; 
    PWM1S1P2H = 0x00;
    
    // Alineación IZQ
    PWM1S1CFGbits.MODE = 0;
    
    PWM1CONbits.EN = 1;
    
    RF2PPS = 0x19; // PWM1 sal 2
    RF5PPS = 0x18; // PWM1 sal 1
}

void PWM_ChangeDuty(uint16_t duty){
    // duty 
    // 
    PWM1S1P1H = duty>>8;
    PWM1S1P1L = duty; // 0000 1100 0000 0000
    PWM1CONbits.LD = 1;
}

