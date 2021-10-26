/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include <stdio.h> // Librería
#include "Configuracion.h"
#include "I2C_Soft.h"

void main(void) {
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull  
    I2C_Init();
    char valor;
    while(1){
        I2C_Start();
        I2C_Write(0b01000001);
        I2C_ACK();
        valor = I2C_Read();
        I2C_NACK();
        I2C_Stop();
        if(valor & 0x80){
            LATFbits.LATF3 = 0;
        }
        else{
            LATFbits.LATF3 = 1;
        }
        __delay_ms(100);
//        I2C_Start();
//        I2C_Write(0b01000000);// 0x40 Dirección
//        I2C_ACK();
//        I2C_Write(0xAA);// 0xAA Dato 10101010
//        I2C_ACK();
//        I2C_Stop();
//        __delay_ms(100);
//        I2C_Start();
//        I2C_Write(0b01000000);// 0x40 Dirección
//        I2C_ACK();
//        I2C_Write(0x55);// 0xAA Dato 01010101
//        I2C_ACK();
//        I2C_Stop();
        __delay_ms(100);
    }
    return;
}
