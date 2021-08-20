/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

/*
 * AL PRESIONAR UN BOTON POR UN TIEMPO EL LED DEBE APAGARSE
 * SI NO SE MANTIENE PRESIONADO NO SE APAGA EL LED
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
    Timer0_8bit();// 20ms
    LED_ON; // Enciendo
    while(1){
        
    }
    return;
}
