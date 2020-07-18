section .text

global paging_enable
global load_page_dir

load_page_dir:
    mov eax, [esp + 4]
    mov cr3, eax
    ret

paging_enable:
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    ret
