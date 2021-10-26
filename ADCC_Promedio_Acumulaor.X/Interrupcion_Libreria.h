/* 
 * File:   Interrupcion_Libreria.h
 * Author: Wels
 *
 * Created on 17 de agosto de 2021, 07:18 PM
 */

#ifndef INTERRUPCION_LIBRERIA_H
#define	INTERRUPCION_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>

void INT_Init(void);
void __interrupt(irq(IRQ_AD), base(0x200), high_priority) ADC_ISR(void);
void __interrupt(irq(IRQ_IOC), base(0x200), low_priority) IOC_ISR(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPCION_LIBRERIA_H */

