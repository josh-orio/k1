#ifndef KERNEL_H
#define KERNEL_H

#define QEMU_SHUTDOWN_PORT 0x84000008

void kernel_main();
void kernel_exit();

#endif