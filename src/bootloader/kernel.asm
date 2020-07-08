bits 32
section .text
        ;grub
        align 4
        dd 0x1BADB002              
        dd 0x00                    
        dd -(0x1BADB002+0x00)

global start
extern kmain

;GRUB loads us into protected mode. Just set up the stack and jump to the kernel!

start:
  cli
  mov esp, stack_space
  call kmain
  hlt

section .bss
resb 8192
stack_space:
