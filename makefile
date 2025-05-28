PROJECT_NAME := k1

INCLUDE := $(wildcard include/*.hpp)
SOURCE := $(wildcard src/*.cpp)

CC := g++
LD := ld
AS := as

.PHONY: all build

all: aarch64-build # place your default(s) here

aarch64-build:
	@echo "[G++] boot/aarch64.s -> boot/aarch64.o"
	@$(AS) boot/aarch64.s -o boot/aarch64.o

	@for f in $(SOURCE); \
	do \
		echo "[G++] $${f} -> $${f%.cpp}.o"; \
		$(CC) -c $${f} -Iinclude -o $${f%.cpp}.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti; \
	done

	@$(LD) -Ttext=0x80000 boot/*.o src/*.o -o aarch64-$(PROJECT_NAME).elf
	@objcopy -O binary aarch64-$(PROJECT_NAME).elf aarch64-$(PROJECT_NAME).img
	@qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel aarch64-$(PROJECT_NAME).img

clean:
	@rm *.o */*.o *.elf *.img

