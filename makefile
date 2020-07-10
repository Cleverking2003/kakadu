LIB_SOURCES := $(shell find src/lib -name '*.c')
LIB_HEADERS := $(shell find src/lib/include -name '*.h' | sed 's/.*/-include &/')

CFLAGS := -Wno-builtin-declaration-mismatch -fno-stack-protector -m32 -O2

#Append asm bootloader and libraries to kernel
kernel: kernel.o kasm.o
	mkdir -p target
	ld -m elf_i386 -T src/link.ld -o target/kernel bin/kasm.o bin/kernel.o bin/lib.a

kasm.o: src/bootloader/kernel.asm
	nasm -f elf32 src/bootloader/kernel.asm -o bin/kasm.o

#Kernel without libraries linked
kernel.o: src/kernel/kernel.c lib.a
	mkdir -p bin/
	gcc $(CFLAGS) -I src/lib/include -o bin/kernel.o -c src/kernel/kernel.c
#Libraries
lib.a: src/lib/*
	mkdir -p bin/lib
	gcc $(CFLAGS) -I src/lib/include -c ${LIB_SOURCES} && mv *.o bin/lib/
	ar rcs bin/lib.a bin/lib/*

clean: 
	rm -r target/ bin/
