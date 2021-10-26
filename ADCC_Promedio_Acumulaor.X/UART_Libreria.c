#include <pic18f57q43.h>

#include "UART_Libreria.h"

void UART_Init(void){
    // UART1
    U1CON0bits.BRGS = 0; // Formula 16
    U1BRG = 416;//138;//115200 Baudios   |416 -> 9600 Baudios
    
    U1CON0bits.MODE = 0; // Modo 8 bits UART
    U1CON1bits.ON = 1;   //Habilitar Puerto Serial
    
    U1CON0bits.TXEN = 1; // Tx Habilitado
    
    U1CON0bits.RXEN = 1; // Rx Habilitado
    
    RF0PPS = 0x20; // RF0 -> TX
    TRISFbits.TRISF1 = 1; // ENTRADA
    ANSELFbits.ANSELF1 = 0; // Digital
    WPUFbits.WPUF1 = 0; // habilitado pull up
    INLVLFbits.INLVLF1 = 0; // TTL
    SLRCONFbits.SLRF1 = 1; // Limitado
    ODCONFbits.ODCF1 = 0; // Push Pull 
    
    U1RXPPS = 0x29; // RF1 -> RX 
    //U1TXB = 'A'; //->> TSR
}

//U1TXB = 'A'; ->> TSR
void UART_Tx(char dato){
    while(U1ERRIRbits.TXMTIF == 0); // SE está enviando un dato
    //while(0 == PIR4bits.U1TXIF);
    //U3TXB -> uart1 uart 2 
    U1TXB = dato; // 
}

void putch(char txData){
    UART_Tx(txData);
}

char UART_Rx(void){
    return U1RXB; // 8 bits 
}

char getch(void)
{
    return UART_Rx();
}


