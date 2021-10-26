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
#include "Interrupcion_Libreria.h"
#include "Timer0_Libreria.h"

extern volatile uint16_t resultado[ARRAY_SAMPLE];// 16 bits
extern volatile uint16_t acc_resul[ARRAY_SAMPLE];//ADRESH
extern volatile uint16_t corr_resu[ARRAY_SAMPLE];//ADFLTR
extern volatile uint16_t average_d[ARRAY_SAMPLE];//ADFLTR
extern volatile uint16_t filtro_pb[ARRAY_SAMPLE];//ADFLTR
extern volatile uint16_t muestras;

        // resultado -> 16 bits
        // uart -> 8 bits 
        // 8bits 8bits
void Envio_Muestras(void){
    for(uint16_t i = 0; i < ARRAY_SAMPLE; i++){
        UART_Tx(START_Streaming);// 03
        UART_Tx(resultado[i]& 0x00FF); 
        UART_Tx((resultado[i]& 0xFF00)>>8);
        UART_Tx(END_Streaming); // FE
        for(uint16_t k = 0; k<10000;k++);
    }
}

void Envio_FPB(void){
    for(uint16_t i = 0; i < ARRAY_SAMPLE; i++){
        UART_Tx(START_Streaming);// 03
        UART_Tx(filtro_pb[i]& 0x00FF); 
        UART_Tx((filtro_pb[i]& 0xFF00)>>8);
        UART_Tx(END_Streaming); // FE
        for(uint16_t k = 0; k<10000;k++);
    }
}

void Envio_Promedio(void){
    for(uint16_t i = 0; i < ARRAY_SAMPLE; i++){
        if(i == 31){
            UART_Tx(START_Streaming);// 03
            UART_Tx(average_d[i]& 0x00FF); 
            UART_Tx((average_d[i]& 0xFF00)>>8);
            UART_Tx(END_Streaming); // FE
            for(uint16_t k = 0; k<10000;k++);
        }
        if(i == 63){
            UART_Tx(START_Streaming);// 03
            UART_Tx(average_d[i]& 0x00FF); 
            UART_Tx((average_d[i]& 0xFF00)>>8);
            UART_Tx(END_Streaming); // FE
            for(uint16_t k = 0; k<10000;k++);
        }
        if(i == 95){
            UART_Tx(START_Streaming);// 03
            UART_Tx(average_d[i]& 0x00FF); 
            UART_Tx((average_d[i]& 0xFF00)>>8);
            UART_Tx(END_Streaming); // FE
            for(uint16_t k = 0; k<10000;k++);
        }
        if(i == 127){
            UART_Tx(START_Streaming);// 03
            UART_Tx(average_d[i]& 0x00FF); 
            UART_Tx((average_d[i]& 0xFF00)>>8);
            UART_Tx(END_Streaming); // FE
            for(uint16_t k = 0; k<10000;k++);
        } 
    }
}

void Envio_Corr_Acc(void){
    for(uint16_t i = 0; i < ARRAY_SAMPLE; i++){
        UART_Tx(START_Streaming);// 03
        UART_Tx(corr_resu[i]& 0x00FF); 
        UART_Tx((corr_resu[i]& 0xFF00)>>8);
        UART_Tx(END_Streaming); // FE
        for(uint16_t k = 0; k<10000;k++);
    }
}

void Envio_Acc(void){
    for(uint16_t i = 0; i < ARRAY_SAMPLE; i++){
        UART_Tx(START_Streaming);// 03
        UART_Tx(acc_resul[i]& 0x00FF); //L
        UART_Tx((acc_resul[i]& 0xFF00)>>8); //H
        UART_Tx(END_Streaming); // FE
        for(uint16_t k = 0; k<10000;k++);
    }
}

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
    INT_Init();
    ADC_Init();
    Timer0_8bit();
    ADC_Start_Conversion(0);
    while(1){
        if(muestras >= ARRAY_SAMPLE){
            //Envio_Muestras();
            //Envio_Acc();
            //Envio_Corr_Acc();
            //Envio_Promedio();
            Envio_FPB();
            muestras = 0;
            Start_Timer0();
        }    
    }
    return;
}
