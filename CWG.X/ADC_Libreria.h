/* 
 * File:   ADC_Libreria.h
 * Author: Wels
 *
 * Created on 26 de agosto de 2021, 07:35 PM
 */

#ifndef ADC_LIBRERIA_H
#define	ADC_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
#include "Configuracion.h"

void ADC_Init(void);
uint16_t ADC_Conversion(uint8_t canal);


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_LIBRERIA_H */

