#include "uart.hpp"

void uart_putc(char c) {
    while ((UART_FR & (1 << 5))) {} // Wait until TX FIFO is not full
    UART_DR = c;
}

char uart_getc() {
    while (UART_FR & (1 << 4)) {} // Wait for UART FIFO to be not empty
    return (char)UART_DR;
}

void uart_puts(const char* str) {
    while (*str) {
        uart_putc(*str++);
    }
}

// char uart_gets() {
//     // fetch n chars or until \n ?
// }
