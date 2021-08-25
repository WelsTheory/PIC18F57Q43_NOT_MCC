/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include <stdio.h> // Librería
#include "Configuracion.h"
#include "UART_Libreria.h"

#define START_Streaming 0x03
#define END_Streaming   0xFC

uint8_t cuenta = 0;
uint8_t doble = 0;

char valor = 0;

void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull 
    
    TRISBbits.TRISB4 = 1; // ENTRADA
    ANSELBbits.ANSELB4 = 0; // Digital
    WPUBbits.WPUB4 = 1; // habilitado pull up
    INLVLBbits.INLVLB4 = 0; // TTL
    SLRCONBbits.SLRB4 = 1; // Limitado
    ODCONBbits.ODCB4 = 0; // Push Pull 
    UART_Init();

    while(1){
        valor = getch();
        if(valor == '1'){
            //printf("Hola\r\n");
            printf("%c%c%c%c",START_Streaming, cuenta, doble,END_Streaming); // %u -> int sin signo
            cuenta++;
            doble = cuenta * 2;
            __delay_ms(100);
        }
        
        
         
        //UART_Tx('1');
//        if(PORTBbits.RB4 == 0){
//           printf("cuenta =%u y doble =%u\r\n",cuenta, doble); // %u -> int sin signo
//           LATFbits.LATF3 = 1;
//           cuenta++;
//           doble = cuenta * 2;
//           __delay_ms(500);
//        }
//        else{
//            LATFbits.LATF3 = 0;
//            
//        }  
    }
    return;
}
