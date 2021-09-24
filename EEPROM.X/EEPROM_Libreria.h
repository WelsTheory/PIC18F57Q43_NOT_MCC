/* 
 * File:   EEPROM_Libreria.h
 * Author: Wels
 *
 * Created on 24 de septiembre de 2021, 10:51 AM
 */

#ifndef EEPROM_LIBRERIA_H
#define	EEPROM_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Configuracion.h"
    
void EEPROM_Write(uint16_t dir, char data);
char EEPROM_Read(uint16_t dir);
void EEPROM_Erase(uint16_t dir);
void EEPROM_Write_16bits(uint16_t dir, uint16_t dato);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_LIBRERIA_H */

