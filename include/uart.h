#ifndef UART_H
#define UART_H

// #include <cstdint>
#include <stdbool.h>
#include <stdint.h>

#define UART_BASE 0x09000000
#define UART_DR (*(volatile uint32_t *)(UART_BASE + 0x00)) // data register
#define UART_FR (*(volatile uint32_t *)(UART_BASE + 0x18)) // flag register

void uart_putc(char c);
void uart_puts(const char *str);

char uart_getc();
void uart_gets(char *str, uint32_t max_len) ;

#endif