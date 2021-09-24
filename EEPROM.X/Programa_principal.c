/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

char data = 0;

void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull  
    
    EEPROM_Write(800,'Z');
    data = EEPROM_Read(800);
    EEPROM_Write_16bits(100,0x55AA);
    while(1){
        if(data == 'Z'){
            LATFbits.LATF3 = ~LATFbits.LATF3;
            EEPROM_Erase(800);
            data = EEPROM_Read(800);
            __delay_ms(100);
        }
        else{
            LATFbits.LATF3 = 1;
        }
    }
    return;
}
