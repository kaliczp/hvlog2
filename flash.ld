MEMORY
{
    rom : ORIGIN = 0x08000000, LENGTH = 16K
    ram : ORIGIN = 0x20000000, LENGTH = 2K
}
SECTIONS
{
    .text : { *(.text*) } > rom
    .rodata : { *(.rodata*) } > rom
    .bss : { *(.bss*) } > ram
}
