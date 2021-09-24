

#include <pic18f57q43.h>

#include "Interrupcion_Libreria.h"
#include "Configuracion.h"

extern uint8_t x; // Sólo se usa .C 
// variable ya ha sido declarada en otro archivo .c

void INT_Init(void){
    // INT0 
    INT0PPS = 0b00001100;
    
    PIE1bits.INT0IE = 1; // Habilitando INT0
    PIR1bits.INT0IF = 0; // Limpiar la alerta
    INTCON0bits.IPEN = 1; // Habilitar Prioridades
    INTCON0bits.GIEH = 1; // Habilitar INT Globales
    INTCON0bits.GIEL = 1; // Habilitar INT Prioridad Baja
    IPR1bits.INT0IP  = 1; // Habiliar Prioridad Alta
    
    
//    IOCBNbits.IOCBN4 = 1; // Negativo Detecta 0
//    IOCBPbits.IOCBP4 = 0; // Deshabilitado POSITIVO FLANCO
//    IOCBFbits.IOCBF4 = 0; // Limpiamos Flag
//    
//    PIE0bits.IOCIE = 1; // Habilitar Int IOC
//    PIR0bits.IOCIF = 0; // Limpiar Flag Int IOC
//    IPR0bits.IOCIP = 1; // Baja Prioridad
    
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

void __interrupt(irq(IRQ_INT0), base(0x200), high_priority) INT0_ISR(void)
{
    if(PIR1bits.INT0IF == 1){
        LED_Toggle();
        LATC = 0X06;
        PIR1bits.INT0IF = 0;
    }
}

void __interrupt(irq(default), base(0x200), low_priority) IOC_ISR(void)
{
     //
}
