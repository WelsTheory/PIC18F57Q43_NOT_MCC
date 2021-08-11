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
    
#define _XTAL_FREQ 64000000UL// unsigned Long 32 bits

#define LOW  0
#define HIGH 1

void Clock_Init(void);
    

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGURACION_H */

