/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "SPI_Libreria.h"
#include "ff.h"

FATFS FatFs;	/* FatFs work area needed for each volume */
FIL Fil;		/* File object needed for each open file */

void main(void) {
    UINT bw;
    //PIN RB4
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 0;
    ANSELB = 0x00;
    WPUB = 0x00; // deshabilitado pull up
    INLVLB = 0x00; // TTL
    SLRCONB = 0xFF; // Limitado
    ODCONB = 0x00; // Push Pull  
    Clock_Init();
    SPI_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull  
    //SS -> RA5
    TRISAbits.TRISA5 = 0; // salida
    ANSELAbits.ANSELA5 = 0; // Digital
    WPUAbits.WPUA5 = 0; // deshabilitado pull up
    INLVLAbits.INLVLA5 = 0; // TTL
    SLRCONAbits.SLRA5 = 1; // Limitado
    ODCONAbits.ODCA5 = 0; // Push Pull 
    
    if (f_mount(&FatFs, "", 1) == FR_OK) {	/* Mount SD */
		if (f_open(&Fil, "QUEMO.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {	/* Open or create a file */
			if ((Fil.fsize != 0) && (f_lseek(&Fil, Fil.fsize) != FR_OK)) goto endSD;	/* Jump to the end of the file */
            f_write(&Fil, "JEJEJE !!!\r\n", 10, &bw);
            
			endSD: f_close(&Fil);								/* Close the file */
		}
	}

    while(1){
        LATFbits.LATF3 = 0;
//        SPI_Open();
//        SS_LAT = 0;
//        SPI_Exchange(0xAA);
//        SS_LAT = 1;
//        SPI_Close();
//        __delay_ms(100);
    }
    return;
}
