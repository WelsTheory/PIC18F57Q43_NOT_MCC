#include "Interrupcion_Libreria.h"



void INT_Init(void){
    
    
}

void __interrupt(irq(IRQ_INT0, IRQ_IOC, IRQ_INT1), base(0x200), high_priority) INT0_ISR(void)
{

}

void __interrupt(irq(default), base(0x200), low_priority) IOC_ISR(void)
{
     //
}
