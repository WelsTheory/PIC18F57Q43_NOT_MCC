/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "Interrupcion_Libreria.h"
#include "Timer0_Libreria.h"

void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull 
    INT_Init();
    Timer0_8bit();
    while(1){
        // SONDEO
//        if(PIR3bits.TMR0IF == 1){
//            // Se generaron los 100ms
//            LATFbits.LATF3 = T0CON0bits.T0OUT;
//            TMR0H = 0xE7;
//            TMR0L = 0x95;
//            PIR3bits.TMR0IF = 0;
//        } 
    }
    return;
}
