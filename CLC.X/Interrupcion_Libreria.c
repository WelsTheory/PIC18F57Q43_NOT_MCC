

#include <pic18f57q43.h>

#include "Interrupcion_Libreria.h"
#include "Configuracion.h"

uint8_t x; // Sólo se usa .C 
// variable ya ha sido declarada en otro archivo .c

void INT_Init(void){
    // INT0 
    INT0PPS = 0b00001000;
    TRISBbits.TRISB0 = 1; // entrada
    ANSELBbits.ANSELB0 = 0; // Digital
    WPUBbits.WPUB0 = 1; // habilitado pull up
    INLVLBbits.INLVLB0 = 0; // TTL
    SLRCONBbits.SLRB0 = 1; // Limitado
    ODCONBbits.ODCB0 = 0; // Push Pull
    
    PIE1bits.INT0IE = 1; // Habilitando INT0
    PIR1bits.INT0IF = 0; // Limpiar la alerta
    INTCON0bits.INT0EDG = 0;
    PIE3bits.TMR0IE = 1; // Habilita INT Timer0
    PIR3bits.TMR0IF = 0; // Flag del Timer0
    IPR3bits.TMR0IP = 1; // Prioridad Alta
    
    INTCON0bits.IPEN = 1; // Habilitar Prioridades
    INTCON0bits.GIEH = 1; // Habilitar INT Globales
    INTCON0bits.GIEL = 1; // Habilitar INT Prioridad Baja
    IPR1bits.INT0IP  = 1; // Habiliar Prioridad Alta
    
    //IVTBASE = 200;
    //INTCON0bits.GIEH = 0;
    di();
    //di()
    IVTBASEU = 0x0;  //5 bits
    IVTBASEH = 0x02; //8 bits
    IVTBASEL = 0x00; //8 bits
    // 00200
    // IVTBASE = IVTBASEU + IVTBASEH + IVTBASEL
    ei();
    //INTCON0bits.GIEH = 1;
    
}

void __interrupt(irq(IRQ_TMR0, IRQ_INT0), base(0x200), high_priority) Timer0_ISR(void)
{
    if(PIR3bits.TMR0IF){
        TMR0H = 0xE7;
        TMR0L = 0x95;
        PIR3bits.TMR0IF = 0;
    }
    if(PIR1bits.INT0IF == 1){
        LATC = 0X06;
        PIR1bits.INT0IF = 0;
    }
}

//void __interrupt(irq(IRQ_INT0), base(0x200), high_priority) INT0_ISR(void)
//{
//    if(PIR1bits.INT0IF == 1){
//        LATC = 0X06;
//        PIR1bits.INT0IF = 0;
//    }
//}

void __interrupt(irq(default), base(0x200), low_priority) IOC_ISR(void)
{
     //
}
