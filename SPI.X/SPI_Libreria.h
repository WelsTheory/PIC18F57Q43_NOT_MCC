/* 
 * File:   SPI_Libreria.h
 * Author: Wels
 *
 * Created on October 21, 2021, 7:42 PM
 */

#ifndef SPI_LIBRERIA_H
#define	SPI_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Configuracion.h"

void SPI_Init(void);
uint8_t SPI_Exchange(char data);
void SPI_Open(void);
void SPI_Close(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_LIBRERIA_H */

