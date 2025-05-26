#include "uart.hpp"

void uart_putc(char c) {
    while ((UART0[0x18 / 4] & (1 << 5))) {} // Wait until TX FIFO is not full
    UART0[0] = c;
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
