# K1 - Experimental Microkernel

## Requirements:

- GNU tools {g++, ld, as, objcopy}
- QEMU

## Building & Running

If compiling the kernel from scratch, use the build-toolchain.sh scripts to build GCC and binutils.

Then use the makefile, specifying the architecture, to run the kernel on a specified architecture using QEMU.

## System

For more information on the kernel itself, including design, APIs for resource management and inter-process communication, see [whitepaper.md](whitepaper.md)
