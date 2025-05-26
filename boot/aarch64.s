// boot.s
.global _start
.section .text

_start:
    // Set up the stack pointer
    ldr x0, =_stack_top
    mov sp, x0

    // Call the main C++ function
    bl kernel_main

    // Halt (infinite loop)
1:  wfe
    b 1b

// Stack (8 KB)
.section .bss
.balign 16
_stack:
    .skip 8192
_stack_top:
