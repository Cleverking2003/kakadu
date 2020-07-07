kernel: kc.o kasm.o
	mkdir -p target
	ld -m elf_i386 -T src/link.ld -o target/kernel bin/kasm.o bin/kc.o

kasm.o: src/kernel.asm
	nasm -f elf32 src/kernel.asm -o bin/kasm.o

kc.o: src/kernel.c src/kb_map.h
	mkdir -p bin/
	gcc -fno-stack-protector -m32 -c src/kernel.c -o bin/kc.o

clean: 
	rm -r target/ bin/
