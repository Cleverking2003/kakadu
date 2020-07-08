<<<<<<< HEAD
OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
 {
   . = 0x100000;
   .text : { *(.text) }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
 }
=======
OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
 {
   . = 0x100000;
   .multiboot : { *(.multiboot) }
   .text : { *(.text) }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
 }
>>>>>>> a3c7243f8d7df42f19283491a77df4451be2b518
