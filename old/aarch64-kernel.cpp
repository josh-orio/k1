// kernel.cpp
#include <stdint.h>
#include <stdbool.h>

#define QEMU_SHUTDOWN_PORT 0x84000008

volatile unsigned int* const UART0 = (unsigned int*)0x09000000;
#define UART_BASE 0x09000000
#define UART_DR   (*(volatile uint32_t *) (UART_BASE + 0x00))  // Data register
#define UART_FR   (*(volatile uint32_t *) (UART_BASE + 0x18))  // Flag register

extern "C" void kernel_main();


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

void shutdown() {
    register const uint64_t function_id asm("x0") = QEMU_SHUTDOWN_PORT;
    asm volatile("hvc #0" :: "r"(function_id));
}

extern "C" void kernel_main() {
    uart_puts("Hello, World!\n");
    uart_puts("\thoi\n");

    char c;
    while (c!='z') {
        c = uart_getc();
        uart_putc(c);
    }

    shutdown();
}
