
#include "SPI_Libreria.h"

void SPI_Init(void)
{
    SPI1CON0 = 0x02; // Master - Contador - SPI OFF
    SPI1CON1 = 0x40; // SMP = 0 - CKE CKP
    SPI1CON2 = 0x03; // TXR RXR Full Duplex
    SPI1CLK = 0; // FOSC -> 16MHz: 8MHz
    SPI1BAUD = 31; // 125KHz
    RB0PPS = 0x31; // RB0 -> CLK
    SPI1SCKPPS = 0b00001000;// RB0 -> CLK ENTRAD
    RB2PPS = 0x32;
    SPI1SDIPPS = 0b00001001;// RB1 -> SDI ENTRAD
    SPI1CON0bits.EN = 1;
}

void SPI_Open(void){
    SPI1CON0bits.EN = 1;
}

void SPI_Close(void){
    SPI1CON0bits.EN = 0;
}

uint8_t SPI_Exchange(char data){
    SPI1TCNTL = 1;
    SPI1TXB = data;
    while(!PIR3bits.SPI1RXIF);
    return SPI1RXB;
}