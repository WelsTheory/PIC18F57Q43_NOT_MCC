/* 
 * File:   Timer0_Libreria.h
 * Author: Wels
 *
 * Created on 19 de agosto de 2021, 07:26 PM
 */

#ifndef TIMER0_LIBRERIA_H
#define	TIMER0_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Configuracion.h"    
    
void Timer0_Init(void);
void Timer0_8bit(void);
void Stop_Timer0(void);
void Start_Timer0(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER0_LIBRERIA_H */

