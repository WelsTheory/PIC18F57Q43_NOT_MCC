/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "CWG.h"
#include "NCO_Libreria.h"
#include "ADC_Libreria.h"

void main(void) {
    uint16_t adc_result;
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
    ADC_Init();
    
    NCO_Init();
    CWG1_Init();    
    while(1){
        adc_result = ADC_Conversion(0);//RA0
        NCO1INC = (uint24_t)(adc_result * 0.047) + 2;
    }
    return;
}
