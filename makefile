LIB_SOURCES := $(shell find src/lib -name '*.c')
LIB_HEADERS := $(shell find src/lib/include -name '*.h' | sed 's/.*/-include &/')

CFLAGS := -Wno-builtin-declaration-mismatch -fno-stack-protector -m32
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -g
else
	CFLAGS += -O2
endif

OBJS = kernel.o idt.o keyb.o
ASM_OBJS = start.o irq.o

#Append asm bootloader and libraries to kernel
kernel: $(OBJS) $(ASM_OBJS) lib.a
	mkdir -p target
	ld -m elf_i386 -T src/link.ld -o target/kernel bin/*.o bin/lib.a

$(ASM_OBJS):
	nasm -f elf32 src/kernel/$*.asm -o bin/$@

#Kernel without libraries linked
$(OBJS):
	mkdir -p bin/
	gcc $(CFLAGS) -I src/lib/include -o bin/$@ -c src/kernel/$*.c
#Libraries
lib.a: src/lib/*
	mkdir -p bin/lib
	gcc $(CFLAGS) -I src/lib/include -c ${LIB_SOURCES} && mv *.o bin/lib/
	ar rcs bin/lib.a bin/lib/*

clean: 
	rm -r target/ bin/
