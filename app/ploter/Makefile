AUTOOBJS= ploter.o  ##auto 
INC=..\/..\/include
AS=as -m32
CC=gcc -m32
CPP=gcc -E -nostdinc -fno-leading-underscore -I$(INC)
LD=ld -melf_i386
CFLAGS=-fomit-frame-pointer -finline-functions -fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall  -I $(INC) -c
OBJCOPY=objcopy
OBJS=$(AUTOOBJS) ploter.bin
AR=ar
.PHONY: all every everything clean dep
everything: $(OBJS)

.c.o:
	$(CC) $(CFLAGS) \
	-o $*.o $<
.s.o:
	$(CC) $(CFLAGS)	\
	-o $*.o $<

ploter.bin: $(AUTOOBJS)
	$(LD) --oformat binary -N -e start -Ttext 0x1000000 -o $@ ../crt.o $(AUTOOBJS) ../../libc/libc.a

all:clean everything
clean:
	rm -f *.bin
	rm -f *.o
dep:
	sed '/\#\#auto/d;/\#\#dep/q' Makefile>tmp_make
	for i in *.c *.S;do `echo $$i|sed '/^/s//$(CPP) -M /;/*/d'`>>tmp_make;done
	echo AUTOOBJS=|tr "\n" " ">tmp_make2
	
	ls -m *.c *.s|sed 's/\.[cs]/.o/g;s/,//g'|tr "\n" " "|\
	sed '/$$/a\#\#auto'|tr "\n" " "|sed '/$$/a\'>>tmp_make2
	
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2
	
##dep
