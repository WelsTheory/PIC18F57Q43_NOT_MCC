/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "Interrupcion_Libreria.h"

uint8_t x = 0;

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
    
    TRISC = 0x00; // salida
    ANSELC = 0x00; // Digital
    WPUC = 0x00; // deshabilitado pull up
    INLVLC = 0x00; // TTL
    SLRCONC = 0xFF; // Limitado
    ODCONC = 0x00; // Push Pull  
    
    INT_Init();
    
    LATC = 0x06;
    //__delay_ms(100);
    while(1){
        if(x == 1){
            LATC = 0X01;
        }
        else{
            LATC = 0X02;
        }// control + shift + c
    }
    return;
}
