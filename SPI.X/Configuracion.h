/* 
 * File:   Configuracion.h
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:54 PM
 */

#ifndef CONFIGURACION_H
#define	CONFIGURACION_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include <xc.h>
    
//#define _XTAL_FREQ 64000000UL// unsigned Long 32 bits
#define _XTAL_FREQ 16000000UL// unsigned Long 32 bits
    
#define LOW  0
#define HIGH 1
    
#define LED_ON          LATFbits.LATF3 = 0;
#define LED_OFF         LATFbits.LATF3 = 1;
#define LED_Toggle()    LATFbits.LATF3 ^= 1 ; //xor

#define SS_LAT          LATAbits.LATA5
#define SD_CS_SetLow()  LATAbits.LATA5 = 0;
#define SD_CS_SetHigh()  LATAbits.LATA5 = 1;

void Clock_Init(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGURACION_H */

