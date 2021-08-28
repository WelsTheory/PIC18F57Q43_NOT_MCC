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
#include "ADC_Libreria.h"

#define START_Streaming 0x03
#define END_Streaming   0xFC

uint16_t valor_adc = 0;
uint16_t valor_adc2 = 0;

void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull 
    
    UART_Init();
    ADC_Init();
    float voltaje; // 00 
    float voltaje2; // 00 
    uint8_t i;
    uint8_t dato;
    uint8_t *volt = (uint8_t*)&voltaje;
    uint8_t *volt2 = (uint8_t*)&voltaje2;
    /*
     *  & dir
     *  * valor
     *  voltaje -> 4 bytes 0 1 2 3 
     *                     x y w z
     *  *volt x y w z
     *  vol[] = { x , y , w ,z}
     *  
     */
    while(1){
        valor_adc = ADC_Conversion(0);
        voltaje = (5.0/4095)*valor_adc; // 32 bits
        printf("%c",START_Streaming);
        for(i = 0; i< sizeof(float) ;i++){
            printf("%c",volt[i]);// x y w z
        }
        //__delay_ms(100);
        valor_adc2 = ADC_Conversion(1);
        voltaje2 = (0.122*valor_adc2); // 32 bits 
        // 10mV -> 1°C
        for(i = 0; i< sizeof(float) ;i++){
            printf("%c",volt2[i]);// x y w z
        }
        
        //printf("%c",dato);
        printf("%c",END_Streaming);
        //dato++;
        
        //printf("%c%c%c%c",START_Streaming, valor_adc &0x00FF , valor_adc >> 8,END_Streaming); // %u -> int sin signo
        __delay_ms(100);
        
//        valor_adc = ADC_Conversion(0);
//        //voltaje = (5.0/4095)*valor_adc;
//        //  1111 1111
//        printf("%c%c%c%c",START_Streaming, valor_adc &0x00FF , valor_adc >> 8,END_Streaming); // %u -> int sin signo
//        __delay_ms(500);
        
//        valor_adc = ADC_Conversion(0);
//        // VALOR ADC = ADRESH Y ADRESL
//        // VIN = RESOLUCION*VALOR_ADC
//        voltaje = (5.0/4095)*valor_adc;
//        printf("El valor ADC es: %u\r\n",valor_adc);
//        printf("El Voltaje IN es: %.2f\r\n",voltaje);
//        __delay_ms(500);
    }
    return;
}
