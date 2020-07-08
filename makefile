kernel: kc.o kasm.o
	mkdir -p target
	ld -m elf_i386 -T src/link.ld -o target/kernel bin/kasm.o bin/kc.o

kasm.o: src/bootloader/kernel.asm
	nasm -f elf32 src/bootloader/kernel.asm -o bin/kasm.o

kc.o: src/kernel/kernel.c
	mkdir -p bin/
	gcc -fno-stack-protector -m32 -c src/kernel/kernel.c -o bin/kc.o

clean: 
	rm -r target/ bin/
