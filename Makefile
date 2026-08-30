CC = x86_64-elf-gcc
LD = x86_64-elf-ld
AS = nasm

BUILD = build

CFLAGS = -ffreestanding -mno-red-zone -m64 -Wall -Wextra -O2 -Iinclude
LDFLAGS = -nostdlib

all: $(BUILD)/kernel.elf

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/boot.o: kernel/boot.asm | $(BUILD)
	$(AS) -f elf64 $< -o $@

$(BUILD)/kernel.o: kernel/kernel.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/kernel.elf: $(BUILD)/boot.o $(BUILD)/kernel.o
	$(LD) $(LDFLAGS) -T linker.ld $^ -o $@

clean:
	rm -rf $(BUILD)