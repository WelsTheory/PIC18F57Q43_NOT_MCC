/* 
 * File:   LCD_libreria.h
 * Author: Wels
 *
 * Created on 12 de agosto de 2021, 07:26 PM
 */

#ifndef LCD_LIBRERIA_H
#define	LCD_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LCD_PORT    LATD  
#define RS          LATDbits.LATD2
#define E           LATDbits.LATD3
    
void LCD_Init(void);
void LCD_Comando(char cmd);
void LCD_XY(char x,char y);
void LCD_Caracter(char data);
void LCD_Cadena(char *datos);
void LCD_CGRAM_ADDR(char addr_cgram);
void LCD_CGRAM(const char *buffer, char address);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIBRERIA_H */

