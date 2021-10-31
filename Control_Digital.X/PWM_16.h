/* 
 * File:   PWM_16.h
 * Author: Wels
 *
 * Created on September 2, 2021, 7:22 PM
 */

#ifndef PWM_16_H
#define	PWM_16_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Configuracion.h"
    
void PWM16_Init(void);
void PWM_ChangeDuty(uint16_t duty);


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_16_H */

