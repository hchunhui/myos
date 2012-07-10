AS=as
CC=gcc
CPP=gcc -E -nostdinc -fno-leading-underscore
LD=ld
CFLAGS=-fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall -c
OBJCOPY=objcopy
.PHONY: all everything clean
everything: boot.bin setup.bin

boot.bin:boot.S comm.h
	$(CC) $(CFLAGS) boot.S -o boot.o
	$(LD) --oformat binary -N -e start -Ttext 0x7c00 -o boot.bin boot.o
setup.bin:setup.S comm.h
	$(CC) $(CFLAGS) setup.S -o setup.o
	$(LD) --oformat binary -N -e start -Ttext 0x0 -o setup.bin setup.o
clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.map
all:clean everything
