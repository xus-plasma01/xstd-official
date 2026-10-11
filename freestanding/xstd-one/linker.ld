ENTRY(_start)

PHDRS
{
    headers PT_PHDR PHDRS;
    text     PT_LOAD FILEHDR PHDRS FLAGS(5);
    rodata   PT_LOAD FLAGS(4);
    data     PT_LOAD FLAGS(6);
    stack    PT_GNU_STACK FLAGS(6);
}

SECTIONS
{
    . = 0x400000 + SIZEOF_HEADERS;

.text :
    {
        *(.text .text.*)
} :
    text

    . = ALIGN(0x1000);

.rodata :
    {
        *(.rodata .rodata.*)
        *(.eh_frame_hdr)
        *(.eh_frame)
} :
    rodata

    . = ALIGN(0x1000);

.data :
    {
        *(.data .data.*)
} :
    data

.bss :
    {
        *(COMMON)
        *(.bss .bss.*)
} :
    data
}
