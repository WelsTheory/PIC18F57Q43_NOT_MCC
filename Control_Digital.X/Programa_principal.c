/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on October 28, 2021, 3:16 PM
 */


#include <xc.h>
#include <stdio.h>
#include "Configuracion.h"
#include "ADC_Libreria.h"
#include "Interrupcion_Libreria.h"
#include "UART_Libreria.h"
#include "PWM_16.h"

#define KP 5.0
#define KI 0.0
#define KD 2.0
float TAU = 3.0;
double LIM_MIN = -1023.0;
double LIM_MAX = 1023.0; //2^12
float T = 0.01;
float P = 0.0;
float I = 0.0;
float D = 0.0;
float E_ANT = 0.0;
float Y_ANT = 0.0;
float U_t = 0.0;
float ERROR = 0.0;

int contador = 0;
float angulo;

void main(void) {
    float referencia = 90.0;
    
    Clock_Init();
    TRISBbits.TRISB1 = 1; // ENTRADA
    ANSELBbits.ANSELB1 = 0; // Digital
    WPUBbits.WPUB1 = 0; // habilitado pull up
    INLVLBbits.INLVLB1 = 0; // TTL
    SLRCONBbits.SLRB1 = 1; // Limitado
    ODCONBbits.ODCB1 = 0; // Push Pull 
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull 
    
    TRISFbits.TRISF5 = 0; // salida
    ANSELFbits.ANSELF5 = 0; // Digital
    WPUFbits.WPUF5 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF5 = 0; // TTL
    SLRCONFbits.SLRF5 = 1; // Limitado
    ODCONFbits.ODCF5 = 0; // Push Pull
    
    TRISFbits.TRISF2 = 0; // salida
    ANSELFbits.ANSELF2 = 0; // Digital
    WPUFbits.WPUF2 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF2 = 0; // TTL
    SLRCONFbits.SLRF2 = 1; // Limitado
    ODCONFbits.ODCF2 = 0; // Push Pull
    
    TRISDbits.TRISD0 = 0; // salida
    ANSELDbits.ANSELD0 = 0; // Digital
    WPUDbits.WPUD0 = 0; // deshabilitado pull up
    INLVLDbits.INLVLD0 = 0; // TTL
    SLRCONDbits.SLRD0 = 1; // Limitado
    ODCONDbits.ODCD0 = 0; // Push Pull
    
    TRISDbits.TRISD1 = 0; // salida
    ANSELDbits.ANSELD1 = 0; // Digital
    WPUDbits.WPUD1 = 0; // deshabilitado pull up
    INLVLDbits.INLVLD1 = 0; // TTL
    SLRCONDbits.SLRD1 = 1; // Limitado
    ODCONDbits.ODCD1 = 0; // Push Pull
    PWM16_Init();
    UART_Init();
    ADC_Init();
    INT_Init();
    while(1){
        referencia = ADC_Conversion(0)*360.0/4095.0-180;
        //referencia = 1024*360.0/4095.0-180;
        angulo = contador/4.45;
        ERROR = referencia-angulo;
        
        P = KP*ERROR;
        
        if(U_t>LIM_MAX){
            I = I;
        }
        else if(U_t<LIM_MIN){
            I = I;
        }
        else{
            I = I + 0.5*KI*T*(ERROR+E_ANT);
        }
        D = -(2.0*KD*(angulo-Y_ANT)+(2.0*TAU-T)*D)/(2.0*TAU+T);
        
        U_t = P+I+D;
        // Add your application code
        if(U_t<0){
            U_t=-U_t+140;
            LATDbits.LATD0 = 1;
            LATDbits.LATD1 = 0;
            LATFbits.LATF3 = 1;
        }
        else{
            if(U_t>=0){
                U_t+=140;
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 1;
                LATFbits.LATF3 = 0;
            }
        }
        if(U_t>1023){
            U_t = 1023;
        }
        
        UART_Tx(START_Streaming);// 03
        UART_Tx(((uint16_t)angulo)& 0x00FF); 
        UART_Tx((((uint16_t)angulo)& 0xFF00)>>8);
        //UART_Tx(((uint16_t)referencia)& 0x00FF); 
        //UART_Tx((((uint16_t)referencia)& 0xFF00)>>8);
        UART_Tx(END_Streaming); // FE
        PWM_ChangeDuty((uint16_t)U_t);
        
        __delay_ms(100);
        // 1MS 0°
        
    }
    return;
}