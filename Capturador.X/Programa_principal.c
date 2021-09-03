/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "CCP.h"

void main(void) {
    Clock_Init();
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
    CCP_Init();
    while(1){
        // 1MS 0°
//        PWM_ChangeDuty(0x0280);
//        __delay_ms(1000);
//        // 2MS 180°
//        PWM_ChangeDuty(0x0500);
//        __delay_ms(1000);
    }
    return;
}
