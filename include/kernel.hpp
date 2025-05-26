#ifndef KERNEL_HPP
#define KERNEL_HPP

#define QEMU_SHUTDOWN_PORT 0x84000008

extern "C" void kernel_main();
extern "C" void kernel_exit();

#endif