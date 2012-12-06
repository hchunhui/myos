SECTIONS
{
	. = 0x1000000;

	.text ALIGN(4096) :
	{
		*(.text*)
		*(.init)
		*(.fini)
	}

	.rodata ALIGN(4096) :
	{
		__start_ctors = .;
		*(.ctor*)
		__end_ctors = .;

		__start_dtors = .;
		*(.dtor*)
		__end_dtors = .;

		*(.rodata*)
	}
	
	.data ALIGN(4096) :
	{
		*(.data*)
	}

	.bss ALIGN(4096) :
	{
		__bss_start = .;
		*(.bss*)
	}
	_end = .;

}

