/* 
 * File:   UART_Libreria.h
 * Author: Wels
 *
 * Created on 24 de agosto de 2021, 07:18 PM
 */

#ifndef UART_LIBRERIA_H
#define	UART_LIBRERIA_H

#ifdef	__cplusplus
extern "C" {
#endif

void UART_Init(void);
void UART_Tx(char dato);
char UART_Rx(void);
char getch(void);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_LIBRERIA_H */

