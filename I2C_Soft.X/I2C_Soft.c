
#include "I2C_Soft.h"

void I2C_Init(void)
{
    SDA_TRIS = 0; // salida
    SCL_TRIS = 0; // salida
    ANSELB = 0x00; // Digital
    WPUBbits.WPUB0 = 1; // PULL UP
    WPUBbits.WPUB1 = 1; // PULL UP
    INLVLB = 0x00; // TTL
    SLRCONB = 0xFF; // Limitado
    ODCONB = 0x00; // Push Pull  
}

void I2C_SCL_Low(void){
    SCL_PIN = 0;
    SCL_TRIS = 0;
    __delay_us(5);
}

void I2C_SCL_High(void){
    SCL_TRIS = 1;
    __delay_us(5);
}

void I2C_SDA_Low(void){
    SDA_PIN = 0;
    SDA_TRIS = 0;
    __delay_us(5);
}

void I2C_SDA_High(void){
    SDA_TRIS = 1;
    __delay_us(5);
}

void I2C_Start(void){
    I2C_SCL_Low();
    I2C_SDA_High();
    I2C_SCL_High();
    I2C_SDA_Low();
    I2C_SCL_Low();
}

void I2C_Stop(void){
    I2C_SCL_Low();
    I2C_SDA_Low();
    I2C_SCL_High();
    I2C_SDA_High();
}

void I2C_Write(char data){
    for(uint8_t i = 0; i< 8 ; i++){
        if(data & 0x80){
            I2C_SDA_High();
        }
        else{
            I2C_SDA_Low();
        }
        I2C_SCL_High();
        I2C_SCL_Low();
        data <<= 1;
    }
    I2C_SDA_High();
}

char I2C_Read(void){
    char data;
    I2C_SDA_High();
    for(uint8_t i =0; i <8 ; i++){
        I2C_SCL_High();
        if(SDA_PIN){
            data = (data << 1) | 0x01;
        }
        else{
            data <<= 1;
        }
        I2C_SCL_Low();
    }
    return data;
}

void I2C_ACK(void){
    I2C_SDA_Low();
    I2C_SCL_High();
    I2C_SCL_Low();
    I2C_SDA_High();
}

void I2C_NACK(void){
    I2C_SCL_High();
    I2C_SCL_Low();
}
