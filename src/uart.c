#include "uart.h"
#include <stdint.h>

void uart_putc(char c) {
  while ((UART_FR & (1 << 5))) {
  } // Wait until TX FIFO is not full
  UART_DR = c;
}

char uart_getc() {
  while (UART_FR & (1 << 4)) {
  } // Wait for UART FIFO to be not empty
  return (char)UART_DR;
}

void uart_puts(const char *str) {
  while (*str) {
    uart_putc(*str++);
  }
}

void uart_gets(char *str, uint32_t max_len) {
  char c;
  uint32_t len = 0;
  do {
    while (UART_FR & (1 << 4)) {} // Wait for UART FIFO to be not empty
    c = (char)UART_DR;
    str[len] = c;
    len++;
  } while (c != '\n' && len <= max_len);
}
