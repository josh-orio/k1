#include "kernel.hpp"
#include "uart.hpp"

extern "C" void kernel_main() {
    
    uart_puts("Hello, World!\n");
    uart_puts("\thoi\n");

    char c=' ';
    while (c!='z') {
        c = uart_getc();
        uart_putc(c);
    }
    uart_putc('\n');

    kernel_exit();
}

extern "C" void kernel_exit() {
    register const uint64_t function_id asm("x0") = QEMU_SHUTDOWN_PORT;
    asm volatile("hvc #0" :: "r"(function_id));
}
