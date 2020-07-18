section .text

global load_gdt
global reload_regs

gdtr:
    dw 0
    dd 0

load_gdt:
    mov eax, [esp + 4]
    mov [gdtr + 2], eax
    mov ax, [esp + 8]
    mov [gdtr], ax
    lgdt [gdtr]
    call reload_segs
    ret

reload_segs:
    jmp 0x08:.reload_cont
.reload_cont:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret
