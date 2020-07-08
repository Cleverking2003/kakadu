<<<<<<< HEAD
bits 32
section .text
        ;grub
        align 4
        dd 0x1BADB002              
        dd 0x00                    
        dd -(0x1BADB002+0x00)
  gdtr: dd 0x0

global start
extern kmain

; Protected mode entry
cli
lgdt [gdtr]
mov eax, cr0 
or al, 1
mov cr0, eax
 
jmp 08h:start
 
start:
  cli
  mov esp, stack_space
  call kmain
  hlt

section .bss
resb 8192
stack_space:
=======
bits 32
; Put the Multiboot header into a different section because it always comes first
section .multiboot
        align 4
        dd 0x1BADB002              
        dd 0x00                    
        dd -(0x1BADB002+0x00)

section .text
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
>>>>>>> a3c7243f8d7df42f19283491a77df4451be2b518
