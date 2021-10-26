/* 
 * File:   I2C_Soft.h
 * Author: Wels
 *
 * Created on October 19, 2021, 8:10 PM
 */

#ifndef I2C_SOFT_H
#define	I2C_SOFT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Configuracion.h"   
    
#define SDA_TRIS    TRISBbits.TRISB1
#define SCL_TRIS    TRISBbits.TRISB0
    
#define SDA_PIN     PORTBbits.RB1
#define SCL_PIN     PORTBbits.RB0
    
void I2C_Init(void);
void I2C_SCL_Low(void);
void I2C_SCL_High(void);
void I2C_SDA_Low(void);
void I2C_SDA_High(void);

void I2C_Start(void);
void I2C_Stop(void);

void I2C_Write(char data);
char I2C_Read(void);

void I2C_ACK(void);
void I2C_NACK(void);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_SOFT_H */

