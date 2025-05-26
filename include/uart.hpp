#ifndef UART_HPP
#define UART_HPP

#include <stdint.h>
#include <stdbool.h>

volatile unsigned int* const UART0 = (unsigned int*)0x09000000;
#define UART_BASE 0x09000000
#define UART_DR   (*(volatile uint32_t *) (UART_BASE + 0x00))  // Data register
#define UART_FR   (*(volatile uint32_t *) (UART_BASE + 0x18))  // Flag register

void uart_putc(char c);
void uart_puts(const char* str) ;

char uart_getc();
// void uart_gets() ;

#endif