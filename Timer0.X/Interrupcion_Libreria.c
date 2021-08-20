

#include <pic18f57q43.h>

#include "Interrupcion_Libreria.h"
#include "Configuracion.h"

//extern uint8_t x; // Sólo se usa .C 
// variable ya ha sido declarada en otro archivo .c

void INT_Init(void){
    
    INTCON0bits.IPEN = 1; // Habilitar Prioridades
    INTCON0bits.GIEH = 1; // Habilitar INT Globales
    INTCON0bits.GIEL = 1; // Habilitar INT Prioridad Baja
    
    PIE3bits.TMR0IE = 1; // Habilita INT Timer0
    PIR3bits.TMR0IF = 0; // Flag del Timer0
    IPR3bits.TMR0IP = 1; // Prioridad Alta
    
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

// 8 bits
void __interrupt(irq(IRQ_TMR0), base(0x200), high_priority) Timer0_ISR(void)
{
    LATFbits.LATF3 = T0CON0bits.T0OUT; //
    PIR3bits.TMR0IF = 0;
}

// 16 bits
//void __interrupt(irq(IRQ_TMR0), base(0x200), high_priority) Timer0_ISR(void)
//{
//    LATFbits.LATF3 = T0CON0bits.T0OUT; //
//    //T0CON0 -> T0OUT Read Lectura
//    // 100ms T0OUT -> 1
//    // 100ms T0OUT -> 0
//    TMR0H = 0xE7;
//    TMR0L = 0x95;
//    PIR3bits.TMR0IF = 0;
//}

void __interrupt(irq(default), base(0x200), low_priority) IOC_ISR(void)
{
     //
}
