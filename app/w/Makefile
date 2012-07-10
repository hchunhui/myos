AUTOOBJS= draw.o kb.o mouse.o msg.o timer.o w.o wnd.o  ##auto 
INC=-I..\/..\/include
AS=as -m32
CC=gcc -m32
CPP=gcc -E -nostdinc -fno-leading-underscore $(INC)
LD=ld -melf_i386
CFLAGS=-march=i386 -fomit-frame-pointer -finline-functions -fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall $(INC) -c
OBJCOPY=objcopy
OBJS=$(AUTOOBJS) w.bin
AR=ar
.PHONY: all every everything clean dep
everything: $(OBJS)

.c.o:
	$(CC) $(CFLAGS) \
	-o $*.o $<
.s.o:
	$(CC) $(CFLAGS)	\
	-o $*.o $<

w.bin: $(AUTOOBJS)
#$(LD) --oformat binary -N -e start -Ttext 0x1000000 -o $@ ../crt.o $(AUTOOBJS) ../../libc/libc.a
	$(LD) -N -e _start -Ttext 0x1000000 -o w.x ../crt.o $(AUTOOBJS) ../../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary w.x $@
all:clean everything
clean:
	rm -f *.bin *.x
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
draw.o: draw.c draw.h bmp.h ../../include/os/type.h \
 ../../include/libc/libc.h ../../include/libc/kstru.h \
 ../../include/os/unistd.h ../../include/lib/string.h
kb.o: kb.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/libc/kstru.h ../../include/os/unistd.h \
 ../../include/lib/string.h msg.h w.h draw.h bmp.h wnd.h kb.h
mouse.o: mouse.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/libc/kstru.h ../../include/os/unistd.h \
 ../../include/lib/string.h draw.h bmp.h msg.h w.h wnd.h
msg.o: msg.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/libc/kstru.h ../../include/os/unistd.h \
 ../../include/lib/string.h draw.h bmp.h w.h
timer.o: timer.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/libc/kstru.h ../../include/os/unistd.h \
 ../../include/lib/string.h draw.h bmp.h msg.h w.h wnd.h
w.o: w.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/libc/kstru.h ../../include/os/unistd.h \
 ../../include/lib/string.h draw.h bmp.h w.h msg.h wnd.h kb.h mouse.h \
 timer.h
wnd.o: wnd.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/libc/kstru.h ../../include/os/unistd.h \
 ../../include/lib/string.h draw.h bmp.h w.h wnd.h msg.h
