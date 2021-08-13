/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "LCD_libreria.h"

const char wels[]={ 0b00000110,
                    0b00001110,
                    0b00000101,
                    0b00011111,
                    0b00000100,
                    0b00001010,
                    0b00010001,
                    0b00000000,0};


void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull  
    LCD_Init();
    LCD_XY(0,8);
    LCD_Caracter('x');
    LCD_XY(1,0);
    LCD_Cadena("Umaker");
    LCD_CGRAM(wels,0);
    LCD_XY(1,10);
    LCD_Caracter(0);
    __delay_ms(100);
    while(1){
    }
    return;
}
