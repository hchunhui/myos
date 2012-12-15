AUTOOBJS= cursor.o draw.o msg.o w.o wnd.o  ##auto 
INC=-I../../include
AS=as -m32
CC=gcc -m32
CPP=gcc -E -nostdinc -fno-leading-underscore $(INC)
LD=ld -melf_i386
CFLAGS=-march=i386 -O3 -fomit-frame-pointer -finline-functions -fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall $(INC) -c
OBJCOPY=objcopy
OBJS=$(AUTOOBJS) w.bin ../kb_trans.o
AR=ar
.PHONY: all every everything clean dep
everything: $(OBJS)

.c.o:
	$(CC) $(CFLAGS) \
	-o $*.o $<
.s.o:
	$(CC) $(CFLAGS)	\
	-o $*.o $<

w.bin: $(AUTOOBJS) ../kb_trans.o
	$(LD) -T../app.ld -o w.x ../crt.o $(AUTOOBJS) ../kb_trans.o ../../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary w.x $@
all:clean everything
clean:
	rm -f *.bin *.x
	rm -f *.o
dep:
	sed '/\#\#auto/d;/\#\#dep/q' Makefile>tmp_make
	for i in `ls *.c`;do `echo '$(CPP) -MM' $$i`>>tmp_make;done
	for i in `ls *.S`;do `echo '$(CPP) -MM -D__ASSEMBLY__' $$i`>>tmp_make;done 
	echo AUTOOBJS=|tr "\n" " ">tmp_make2
	ls -m *.c *.S|sed 's/\.[cS]/.o/g;s/,//g'|tr "\n" " "| \
	sed '/$$/a\#\#auto'|tr "\n" " "|sed '/$$/a\'>>tmp_make2
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2
##dep
cursor.o: cursor.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h cursor.h draw.h bmp.h w.h
draw.o: draw.c draw.h bmp.h ../../include/libc/libc.h \
 ../../include/os/type.h ../../include/os/unistd.h \
 ../../include/lib/string.h ../../include/drv/video.h \
 ../../include/os/dirent.h ../../include/os/stat.h
msg.o: msg.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h ../../include/drv/pipe.h msg.h
w.o: w.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h ../../include/drv/input.h \
 ../../include/drv/poll.h ../../include/drv/pipe.h draw.h bmp.h cursor.h \
 w.h wnd.h msg.h ../kb_state.h
wnd.o: wnd.c ../../include/libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h draw.h bmp.h w.h wnd.h msg.h
