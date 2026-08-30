ENTRY(_start)

SECTIONS
{
    . = 0x100000;

    .text :
    {
        *(.text*)
    }

    .rodata :
    {
        *(.rodata*)

        . = ALIGN(8);
        __limine_requests_start = .;
        KEEP(*(.limine_requests_start))
        KEEP(*(.limine_requests))
        KEEP(*(.limine_requests_end))
        __limine_requests_end = .;
    }

    .data :
    {
        *(.data*)
    }

    .bss :
    {
        *(COMMON)
        *(.bss*)
    }
}