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
