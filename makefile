kernel: kasm.o kc.o
	ld -m elf_i386 -T source/link.ld -o kernel bin/kasm.o bin/kc.o

kasm.o: source/kernel.asm
	nasm -f elf32 source/kernel.asm -o bin/kasm.o

kc.o: source/kernel.c source/kb_map.h
	gcc -fno-stack-protector -m32 -c source/kernel.c -o bin/kc.o

clean: 
	rm kernel bin/*
