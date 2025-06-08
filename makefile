PROJECT_NAME := k1

INCLUDE := $(wildcard include/*.h)
SOURCE := $(wildcard src/*.c)

TOOL_DIR := $(PWD)/cc/bin
CC := $(TOOL_DIR)/aarch64-none-elf-gcc          # (your gcc here)
LD := $(TOOL_DIR)/aarch64-none-elf-ld           # (your GNU ld here)
AS := $(TOOL_DIR)/aarch64-none-elf-as           # (your GNU as here)
OBJCOPY := $(TOOL_DIR)/aarch64-none-elf-objcopy # (your GNU objcopy here)

.PHONY: all build

all: aarch64-build # place your default(s) here

aarch64-build:
	@echo "[AS] boot/aarch64.s -> boot/aarch64.o"
	@$(AS) boot/aarch64.s -o boot/aarch64.o

	@for f in $(SOURCE); \
	do \
		echo "[GCC $${f} -> $${f%.c}.o"; \
		$(CC) -c $${f} -Iinclude -o $${f%.c}.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti; \
	done

	@$(LD) -Ttext=0x80000 boot/*.o src/*.o -o aarch64-$(PROJECT_NAME).elf
	@$(OBJCOPY) -O binary aarch64-$(PROJECT_NAME).elf aarch64-$(PROJECT_NAME).img
	@qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel aarch64-$(PROJECT_NAME).img

clean:
	@rm *.o */*.o *.elf *.img
