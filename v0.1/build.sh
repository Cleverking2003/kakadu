nasm -f elf32 source/kernel.asm -o bin/building/kasm.o
gcc -fno-stack-protector -m32 -c source/kernel.c -o bin/building/kc.o
ld -m elf_i386 -T source/link.ld -o kernel bin/building/kasm.o bin/building/kc.o
