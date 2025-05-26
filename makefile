PROJECT_NAME := k1

INCLUDE := $(wildcard include/*.hpp)
SOURCE := $(wildcard src/*.cpp)

.PHONY: all build

all: aarch64-build # place your default(s) here

x86_64-build:
	@i686-elf-as boot.s -o boot.o
	@i686-elf-gcc -c kernel.c -o kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	@i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

aarch64-build:
	@echo "[G++] boot/aarch64.s -> boot/aarch64.o"
	@as boot/aarch64.s -o boot/aarch64.o

	@for f in $(SOURCE); \
	do \
		echo "[G++] $${f} -> $${f%.cpp}.o"; \
		g++ -c $${f} -Iinclude -o $${f%.cpp}.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti; \
	done

	@ld -Ttext=0x80000 boot/*.o src/*.o -o aarch64-$(PROJECT_NAME).elf
	@objcopy -O binary aarch64-$(PROJECT_NAME).elf aarch64-$(PROJECT_NAME).img
	@qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel aarch64-$(PROJECT_NAME).img

clean:
	@rm *.o */*.o *.elf *.img

