
#include "EEPROM_Libreria.h"

void EEPROM_Write(uint16_t dir, char data)
{
    NVMADR = dir;
    NVMDATL = data;
    NVMCON1bits.CMD = 3;
    NVMLOCKbits.LOCK = 0x55;
    NVMLOCKbits.LOCK = 0xAA;
    NVMCON0bits.GO = 1;
    while(NVMCON0bits.GO);
    NVMCON1bits.CMD = 0;
}

char EEPROM_Read(uint16_t dir)
{
    NVMADR = dir;
    NVMCON1bits.CMD = 0;
    NVMCON0bits.GO = 1;
    while(NVMCON0bits.GO);
    return NVMDATL;
}
void EEPROM_Erase(uint16_t dir)
{
    NVMADR = dir;
    NVMDATL = 0xFF;
    NVMCON1bits.CMD = 6;
    NVMLOCKbits.LOCK = 0x55;
    NVMLOCKbits.LOCK = 0xAA;
    NVMCON0bits.GO = 1;
    while(NVMCON0bits.GO);
    NVMCON1bits.CMD = 0;
}

void EEPROM_Write_16bits(uint16_t dir, uint16_t dato){
    for(uint16_t i = 0; i < 2; i++){
        EEPROM_Write(dir+i,*((uint8_t*)(&dato)+i));
    }
}
