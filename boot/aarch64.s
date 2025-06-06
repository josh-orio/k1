// boot.s
.global _start
.section .text

_start:
    // set up stack pointer
    ldr x0, =_stack_top
    mov sp, x0

    // branch to entry point
    bl kernel_main

    // halt loop
1:  wfe
    b 1b

// stack (8 KB)
.section .bss
.balign 16
_stack:
    .skip 8192
_stack_top:
