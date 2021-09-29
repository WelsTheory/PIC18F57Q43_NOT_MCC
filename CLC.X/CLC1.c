
#include <pic18f57q43.h>

#include "CLC1.h"

void CLC1_init(void)
{
    CLCSELECTbits.SLCT = 0;// 1 ra instancia
    CLCnCONbits.EN = 0;
    // 4 ENTRADAS POR INSTANCIA
    CLCnSEL0 = 0x00; // CLCIN0
    CLCnSEL1 = 0x01; // CLCIN1
    CLCnSEL2 = 0b00010010; //-> TMR0 - //0x02; // CLCIN2 
    CLCnSEL3 = 0x03; // CLCIN3
    
    CLCIN2PPS = 0b00001001; // RB1
    CLCIN3PPS = 0b00001100; // RB4
    
    //PIN RB4
    TRISBbits.TRISB4 = 1; // entrada
    ANSELBbits.ANSELB4 = 0; // Digital
    WPUBbits.WPUB4 = 1; // habilitado pull up
    INLVLBbits.INLVLB4 = 0; // TTL
    SLRCONBbits.SLRB4 = 1; // Limitado
    ODCONBbits.ODCB4 = 0; // Push Pull
    
    //PIN RB1
    TRISBbits.TRISB1 = 1; // entrada
    ANSELBbits.ANSELB1 = 0; // Digital
    WPUBbits.WPUB1 = 1; // habilitado pull up
    INLVLBbits.INLVLB1 = 0; // TTL
    SLRCONBbits.SLRB1 = 1; // Limitado
    ODCONBbits.ODCB1 = 0; // Push Pull
    
    // La entrada 3 de la compuerta 3 no sea negada
    CLCnGLS0bits.G1D1T = 0; 
    CLCnGLS0bits.G1D1N = 0;
    CLCnGLS1bits.G2D2T = 0; 
    CLCnGLS1bits.G2D2T = 0; 
    
    // La entrada 3 de la compuerta 3 no sea negada
    CLCnGLS2bits.G3D3T = 0; 
    CLCnGLS2bits.G3D3N = 1; 
    
    // La entrada 4 de la compuerta 4 no sea negada
    CLCnGLS3bits.G4D4T = 0;
    CLCnGLS3bits.G4D4N = 1;
    
    CLCnPOLbits.POL = 1;
    CLCnPOLbits.G3POL = 0;
    CLCnPOLbits.G4POL = 0;
    
    CLCnCONbits.MODE = 0; // AND - OR
    
    CLCnCONbits.EN = 1;
}