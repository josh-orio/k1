#include "kernel.hpp"
#include "uart.hpp"

extern "C" void kernel_main() {
    uart_puts("[K1] Beginning intialization.\n");

    
    // uart_puts("Hello, World!\n");
    // uart_puts("\thoi\n");

    // char c=' ';
    // while (c!='z') {
    //     c = uart_getc();
    //     uart_putc(c);
    // }
    // uart_putc('\n');

    uart_puts("[K1] Initialization complete.\n");

//     char str1[]="Sample string";
//   char str2[40];
//   char str3[40];
//   strcpy (str2,str1);
//   strcpy (str3,"copy successful");
//   uart_puts (str1);
//   uart_puts (str2);
//   uart_puts (str3);

    kernel_exit();

}

extern "C" void kernel_exit() {
    uart_puts("[K1] Ready to exit.\n");
    register const uint64_t function_id asm("x0") = QEMU_SHUTDOWN_PORT;
    asm volatile("hvc #0" :: "r"(function_id));
}
