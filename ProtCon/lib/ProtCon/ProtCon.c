#include "MKL25Z4.h"
#include "stdio.h"
#include "ProtCon.h"

void uart_init(){
    SIM -> SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    PORT_PCR_MUX(1) | PORT_PCR_PS_MASK;
    PORT_PCR_MUX(2) | PORT_PCR_PS_MASK;
    UART0 -> C1 = 0;
    UART0 -> C2 = 0;
    UART0 -> C2 |= UART_C2_RE_MASK;
    UART0 -> C2 |= UART_C2_TE_MASK;
    UART0 -> C3 = 0;
    UART0 -> C4 = 15;
    UART0 -> BDH = 0;
    UART0 -> BDL = 26;
    
} 
void uart_send(char data){
    while(!(UART0 -> S1 & UART_S1_TDRE_MASK));
     UART0 -> D = data;
}
char uart_recieve(char data){
    while(!(UART0 -> S1 & UART_S1_RDRF_MASK));
    return UART0 -> D = data;
}