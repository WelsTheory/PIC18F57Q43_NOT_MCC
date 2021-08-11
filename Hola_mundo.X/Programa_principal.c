/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"

#define LED_ON  LATFbits.LATF3 = 0;
#define LED_OFF LATFbits.LATF3 = 1;
#define SW_OFF  !PORTBbits.RB4

void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull
    
    //PIN RB4
    TRISBbits.TRISB4 = 1; // entrada
    ANSELBbits.ANSELB4 = 0; // Digital
    WPUBbits.WPUB4 = 1; // habilitado pull up
    INLVLBbits.INLVLB4 = 0; // TTL
    SLRCONBbits.SLRB4 = 1; // Limitado
    ODCONBbits.ODCB4 = 0; // Push Pull
    
    while(1){
        if(SW_OFF){
            LED_ON; // enciendo el led
        }
        else{
            LED_OFF;
        }
        
//        LATFbits.LATF3 = ~LATFbits.LATF3; //neg 0
//        __delay_ms(100);
//        LATFbits.LATF3 = 0;
//        __delay_ms(100);
//        LATFbits.LATF3 = 1;
//        __delay_ms(100);
    }
    return;
}
