#include "CWG.h"

// Modo Half
//void CWG1_Init(void){
//    //PIN RB4
//    TRISBbits.TRISB0 = 1; // entrada
//    ANSELBbits.ANSELB0 = 0; // Digital
//    WPUBbits.WPUB0 = 0; // habilitado pull up
//    INLVLBbits.INLVLB0 = 0; // TTL
//    SLRCONBbits.SLRB0 = 0; // Limitado
//    ODCONBbits.ODCB0 = 0; // Push Pull
//    RC0PPS = 0x09;  //CWG1 A
//    RD1PPS = 0x0A;  //CWG1 B
//    RD2PPS = 0x0B;  //CWG1 C
//    RD3PPS = 0x0C;  //CWG1 D
//    CWG1CON0bits.EN = 0; //  OFF
//    CWG1CON0bits.MODE = 0b100; // MODO HALF BRIDGE
//    CWG1CON1bits.POLA = 0;// POLARIDAD NORMAL
//    CWG1CON1bits.POLB = 0;
//    CWG1CON1bits.POLC = 0;
//    CWG1CON1bits.POLD = 0;
//    CWG1ISM = 0b01100;// NCO -> 1MHz
//    CWG1CLKbits.CS = 1; // HFINTOSC
////    CWG1DBFbits.DBF = 0; // No hay tiempo en 
////    CWG1DBRbits.DBR = 0; // banda muerta
//    CWG1DBFbits.DBF = 10; // 
//    CWG1DBRbits.DBR = 50; // banda muerta
//    /*
//     * AUTOSHUTDOWN
//     */
//    CWG1AS1bits.AS0E = 1;// PIN externo
//    CWG1PPS = 0B00001000; // RB0
//    CWG1AS0bits.LSAC = 0b10;
//    CWG1AS0bits.LSDBD = 0b10; 
//    CWG1AS0bits.SHUTDOWN = 1; // Autoshutdown
//    CWG1AS0bits.REN = 1; // Re-start
//    CWG1CON0bits.EN = 1;
//
//    TRISD = 0x00;
//    TRISD = 0x00; // salida
//    ANSELD = 0x00; // Digital
//    WPUD = 0x00; // deshabilitado pull up
//    INLVLD = 0x00; // TTL
//    ODCOND = 0x00; // Push Pull  
//    SLRCOND = 0x00;
//    TRISC = 0x00; // salida
//    ANSELC = 0x00; // Digital
//    WPUC = 0x00; // deshabilitado pull up
//    INLVLC = 0x00; // TTL
//    ODCONC = 0x00; // Push Pull  
//    SLRCONC = 0x00;
//}

void CWG1_Init(void){
    //PIN RB4
    TRISBbits.TRISB0 = 1; // entrada
    ANSELBbits.ANSELB0 = 0; // Digital
    WPUBbits.WPUB0 = 0; // habilitado pull up
    INLVLBbits.INLVLB0 = 0; // TTL
    SLRCONBbits.SLRB0 = 0; // Limitado
    ODCONBbits.ODCB0 = 0; // Push Pull
    RC0PPS = 0x09;  //CWG1 A
    RD1PPS = 0x0A;  //CWG1 B
    RD2PPS = 0x0B;  //CWG1 C
    RD3PPS = 0x0C;  //CWG1 D
    CWG1CON0bits.EN = 0; //  OFF
    CWG1CON0bits.MODE = 0b011; // MODO Puente H Reversa
    CWG1CON1bits.POLA = 0;// POLARIDAD NORMAL
    CWG1CON1bits.POLB = 0;
    CWG1CON1bits.POLC = 0;
    CWG1CON1bits.POLD = 0;
    CWG1ISM = 0b01100;// NCO -> 1MHz
    CWG1CLKbits.CS = 1; // HFINTOSC
//    CWG1DBFbits.DBF = 0; // No hay tiempo en 
//    CWG1DBRbits.DBR = 0; // banda muerta
    CWG1DBFbits.DBF = 10; // 
    CWG1DBRbits.DBR = 50; // banda muerta
    /*
     * AUTOSHUTDOWN
     */
    CWG1AS1bits.AS0E = 1;// PIN externo
    CWG1PPS = 0B00001000; // RB0
    CWG1AS0bits.LSAC = 0b10;
    CWG1AS0bits.LSDBD = 0b10; 
    CWG1AS0bits.SHUTDOWN = 1; // Autoshutdown
    CWG1AS0bits.REN = 1; // Re-start
    CWG1CON0bits.EN = 1;

    TRISD = 0x00;
    TRISD = 0x00; // salida
    ANSELD = 0x00; // Digital
    WPUD = 0x00; // deshabilitado pull up
    INLVLD = 0x00; // TTL
    ODCOND = 0x00; // Push Pull  
    SLRCOND = 0x00;
    TRISC = 0x00; // salida
    ANSELC = 0x00; // Digital
    WPUC = 0x00; // deshabilitado pull up
    INLVLC = 0x00; // TTL
    ODCONC = 0x00; // Push Pull  
    SLRCONC = 0x00;
}
