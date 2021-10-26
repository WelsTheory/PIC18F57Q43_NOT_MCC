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
    
#define START_Streaming 0x03
#define END_Streaming   0xFC
    
#define ARRAY_SAMPLE    128
    
#define _XTAL_FREQ 64000000UL// unsigned Long 32 bits

#define LOW  0
#define HIGH 1
    
#define LED_ON          LATFbits.LATF3 = 0;
#define LED_OFF         LATFbits.LATF3 = 1;
#define LED_Toggle()    LATFbits.LATF3 ^= 1 ; //xor
    

void Clock_Init(void);
    

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGURACION_H */

