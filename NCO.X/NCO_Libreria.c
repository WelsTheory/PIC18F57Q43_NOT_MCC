
#include "NCO_Libreria.h"

/*Parte 1
void NCO_Init(void)
{
    NCO1CLKbits.CKS = 1; // HFINTOSC = 64MHZ -> 32MHz
    NCO1CONbits.PFM = 0; // FDC 
    //NCO1INC -> NCO1INCU NCO1INCH NCO1INCL
    // 20 bits->     4       8        8 
    NCO1INC = 1015808;//1;//327680; 1.96 -> 60Hz - 30 Hz mínimo
    RD0PPS = 0x3F; // NCO1 -> Salida
    TRISDbits.TRISD0 = 0; // salida
    ANSELDbits.ANSELD0 = 0; // Digital
    WPUDbits.WPUD0 = 0; // deshabilitado pull up
    INLVLDbits.INLVLD0 = 0; // TTL
    ODCONDbits.ODCD0 = 0; // Push Pull  
    SLRCONDbits.SLRD0 = 0;
    NCO1CONbits.POL = 0; // No invertido
    NCO1CONbits.EN = 1;
}*/


/* Parte 2 */
void NCO_Init(void)
{
    NCO1CLKbits.CKS = 1; // HFINTOSC = 64MHZ -> 32MHz
    NCO1CONbits.PFM = 0; // FDC 
    //NCO1INC -> NCO1INCU NCO1INCH NCO1INCL
    // 20 bits->     4       8        8 
    /*
     * 1.96   -> 60Hz
     * 196.60 -> 6KHz
     * 
     * (197-2)/ 2^12 = 0.047 
     * 
     *  0.047 x 4095 -> 192.4 + 2
     *  0.047 x 0    -> 2
     * 
     */
    NCO1INC = 2; //-> 60Hz - 30 Hz mínimo
    RD0PPS = 0x3F; // NCO1 -> Salida
    TRISDbits.TRISD0 = 0; // salida
    ANSELDbits.ANSELD0 = 0; // Digital
    WPUDbits.WPUD0 = 0; // deshabilitado pull up
    INLVLDbits.INLVLD0 = 0; // TTL
    ODCONDbits.ODCD0 = 0; // Push Pull  
    SLRCONDbits.SLRD0 = 0;
    
    NCO1CONbits.POL = 0; // No invertido
    NCO1CONbits.EN = 1;
}