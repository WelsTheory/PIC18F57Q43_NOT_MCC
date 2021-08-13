
#include <xc.h>
#include "LCD_libreria.h"
#include "Configuracion.h"

void LCD_Init(void){
    TRISD = 0x00; //Salida Puerto D
    ANSELD = 0x00; // Digital
    WPUD = 0x00; // deshabilitado pull up
    INLVLD = 0x00; // TTL
    SLRCOND = 0xFF; // Limitado
    ODCOND = 0x00; // Push Pull  
    //__delay_ms(100);
    LCD_Comando(0x30);
    //__delay_ms(5);
    LCD_Comando(0x30);
    //__delay_us(100);
    LCD_Comando(0x32); // Configuración de 4 bits
    LCD_Comando(0x28); // 2 Líneas y 5x8
    LCD_Comando(0x0C); // Display ON
    LCD_Comando(0x01); // Limpiar LCD
    LCD_Comando(0x06); // Incremento
}

void LCD_Comando(char cmd){
    LCD_PORT &= 0x0F;    // SON IDENTICOS LCD_PORT = LCD_PORT & 0x0F; 
    /*
     * 1   1  0  1  0  1  0  1
     * 0   0  0  0  1  1  1  1
     * 0   0  0  0  0  1  0  1
     */        
    LCD_PORT |= (cmd & 0xF0);//LCD_PORT = LCD_PORT | (cmd & 0xF0);
    // 0011 0010
    // 1111 0000
    // 0011 0000
    // 0000 0101 OR
    // 0011 0000
    // 0011 0101
    RS = 0; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    //El 0
    LCD_PORT &= 0x0F; 
    LCD_PORT |= ((cmd & 0x0F)<<4); // cmd = 0x02
    // 00100000 << 4 
    RS = 0; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    //LCD_PORT = cmd;//LATD = 0x30
    //D7 D6 D5 D4 D3 D2 D1 D0 
    //D7 D6 D5 D4 D3 D2 D1 D0
    // 0  0 1  1  0   0  1  0 = 0x30      
}

void LCD_XY(char x,char y){ 
    /*
     * LINEA 1 = 0
     * LINEA 2 = 1
     */
    if(x == 1){ //linea 2
        LCD_Comando(0xC0 + y);
    }
    else{
        LCD_Comando(0x80 + y);
    }
}

void LCD_Caracter(char data){
    LCD_PORT &= 0x0F;    // SON IDENTICOS LCD_PORT = LCD_PORT & 0x0F;    
    LCD_PORT |= (data & 0xF0);//LCD_PORT = LCD_PORT | (cmd & 0xF0);

    RS = 1; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    //El 0
    LCD_PORT &= 0x0F; 
    LCD_PORT |= ((data & 0x0F)<<4); // cmd = 0x02
    RS = 1; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;

}

void LCD_Cadena(char *datos){
    // "hola\0"
    while(*datos != '\0'){
        LCD_Caracter(*datos);//h o l a 
        datos++;// o \0
    }            
}

void LCD_CGRAM_ADDR(char addr_cgram){
    LCD_PORT &= 0x0F;
    LCD_PORT |= ((0b01000000 | addr_cgram) & 0xF0);
    RS = 0; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0F;
    LCD_PORT |= (((0b01000000 | addr_cgram) << 4) & 0xF0);
    RS = 0; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
}

void LCD_CGRAM(const char *buffer, char address){ //wels,0
    unsigned char i = 0;
    LCD_CGRAM_ADDR(address*8);
    /* 
     * 1 caracter 8 bytes
     */
    for(i = 0; i <8; i++){
        LCD_Caracter(*buffer);
        ++buffer;
    }
}