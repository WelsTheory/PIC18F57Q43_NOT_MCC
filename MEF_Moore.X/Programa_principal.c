/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 10 de agosto de 2021, 07:51 PM
 */

/*
 * AL PRESIONAR UN BOTON POR UN TIEMPO EL LED DEBE APAGARSE
 * SI NO SE MANTIENE PRESIONADO NO SE APAGA EL LED
 */

#include <xc.h>
#include "Configuracion.h"
#include "Interrupcion_Libreria.h"
#include "Timer0_Libreria.h"

/*
 * orientado a objetos
 * objeto -> beat
 * ATRIBUTOS
 * id = 1012313
 * driver = Wels
 * marca = toyota
 * color = verde
 * 
 */

//beat.id 

//typedef struct{
//    uint8_t id;
//    char driver[];
//    char marca[];
//    char color[];
//}uber_t;
//
//uber_t uber;

//uint8_t estado = 0;

void main(void) {
    estados = ESTADO_SUS;
    Clock_Init();
    //PIN RF3
    TRISFbits.TRISF3 = 0; // salida
    ANSELFbits.ANSELF3 = 0; // Digital
    WPUFbits.WPUF3 = 0; // deshabilitado pull up
    INLVLFbits.INLVLF3 = 0; // TTL
    SLRCONFbits.SLRF3 = 1; // Limitado
    ODCONFbits.ODCF3 = 0; // Push Pull 
    
    TRISBbits.TRISB4 = 1; // salida
    ANSELBbits.ANSELB4 = 0; // Digital
    WPUBbits.WPUB4 = 1; //  pull up
    INLVLBbits.INLVLB4 = 0; // TTL
    SLRCONBbits.SLRB4 = 1; // Limitado
    ODCONBbits.ODCB4 = 0; // Push Pull 
    INT_Init();
    Timer0_8bit();// 20ms
    //estado = 1;
    LED_OFF; // Enciendo
    while(1){      
        switch(estados)
        {
            case ESTADO_SUS:
                LED_ON;
                break;
            case ESTADO_ON:// Estado 1
                T0CON0bits.EN = 1; // INT -> TIMER ON
                estados = ESTADO_ESP;
                break;
            case ESTADO_ESP:
                break;
            case ESTADO_OFF:// Estado 2
                LED_ON;
                break;
            default:
                break;              
        }
    }
    return;
}



/*
 * TIMER 0 - INT
 * TEMPORIZAR  1MS
 *   switch(estados)
        {
            case ESTADO_ON:// Estado 1
                LED_ON;
                if(PORTBbits.RB4 == 0)
                {
                    //__delay_ms(40);
                    estados = ESTADO_OFF;
                    //estado = 2;
                }
                break;
            case ESTADO_OFF:// Estado 2
                LED_OFF;
                if(PORTBbits.RB4 == 0){
                    //__delay_ms(40);
                    estados = ESTADO_ON;
                    //estado = 1;
                }
                break;
            default:
                //estado = 1;
                break;              
        }
 * 
 */
