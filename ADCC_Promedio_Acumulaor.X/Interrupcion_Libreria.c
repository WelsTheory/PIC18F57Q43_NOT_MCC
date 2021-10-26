#include "Interrupcion_Libreria.h"
#include "Configuracion.h"
#include "Timer0_Libreria.h"

volatile uint16_t resultado[ARRAY_SAMPLE];//ADRESH
volatile uint16_t acc_resul[ARRAY_SAMPLE];//ADRESH
volatile uint16_t corr_resu[ARRAY_SAMPLE];//ADFLTR
volatile uint16_t average_d[ARRAY_SAMPLE];//ADFLTR
volatile uint16_t muestras;

void INT_Init(void){   
    //IVTBASE = 200;
    //INTCON0bits.GIEH = 0;
    INTCON0bits.IPEN = 1;
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

void __interrupt(irq(IRQ_AD), base(0x200), high_priority) ADC_ISR(void)
{
    if(PIR1bits.ADIF == 1){
        resultado[muestras] = ((uint16_t)((ADRESH<<8) | ADRESL));
        acc_resul[muestras] = ((uint16_t)((ADACCH<<8) | ADACCL));
        corr_resu[muestras] = ((uint16_t)((ADFLTRH<<8) | ADFLTRL));//
        average_d[muestras] = ((uint16_t)((ADFLTRH<<8) | ADFLTRL));
        muestras++;
        if(muestras >= ARRAY_SAMPLE){//128 muestras
            Stop_Timer0();
        }
        PIR1bits.ADIF = 0;
    }
}

void __interrupt(irq(default), base(0x200), low_priority) IOC_ISR(void)
{
     //
}
