AUTOOBJS= addr.o crt.o cxxrt.o g.o init.o login.o pai.o sh.o snake.o task2.o tty.o  ##auto 
INC=-I..\/include
AS=as -m32
CC=gcc -m32 -march=i386
CPP=gcc -E -nostdinc -fno-leading-underscore $(INC)
LD=ld -melf_i386
CFLAGS=-fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall  $(INC) -c
OBJCOPY=objcopy
OBJS=$(AUTOOBJS) init.bin task2.bin sh.bin pai.bin addr.bin gauss.bin lc-emu.bin snake.bin test.bin tty.bin login.bin
AR=ar
.PHONY: all every everything clean dep
everything: every $(OBJS)
every: crt.o cxxrt.o
	make -C w
.c.o:
	$(CC) $(CFLAGS) \
	-g -o $*.o $<
.s.o:
	$(CC) $(CFLAGS)	\
	-g -o $*.o $<
supc++.o: supc++.cpp
	g++ -m32 -fpermissive $(CFLAGS) -nostdlib --no-exceptions -o $@ $<
gauss.o: gauss.cpp
	g++ -m32 -fpermissive $(CFLAGS) -nostdlib --no-exceptions -o $@ $<
lc-emu.o: lc-emu.cpp
	g++ -m32 -fpermissive $(CFLAGS) -nostdlib --no-exceptions -o $@ $<
test.o: test.cpp
	g++ -m32 -fpermissive -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector -Wall -fno-strict-aliasing -fno-leading-underscore $(INC) -c -o $@ $<
test.bin: test.o cxxrt.o supc++.o
#$(LD) --oformat binary -N -e start -Tapp.ld -o $@ cxxrt.o supc++.o $< ../libc/libc.a
	$(LD) -N -e _start -Tapp.ld -o test.x cxxrt.o supc++.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary test.x $@
lc-emu.bin: lc-emu.o
	$(LD) -N -e _start -Ttext 0x1000000 -o lc-emu.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary lc-emu.x $@
gauss.bin: gauss.o g.o
	$(LD) -N -e _start -Ttext 0x1000000 -o gauss.x crt.o g.o gauss.o ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary gauss.x $@
task2.bin: task2.o
	$(LD) -N -e _start -Ttext 0x1000000 -o task2.x crt.o $< ../libc/libc.a w/draw.o
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary task2.x $@
snake.bin: snake.o
	$(LD) -N -e _start -Ttext 0x1000000 -o snake.x crt.o $< ../libc/libc.a w/draw.o
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary snake.x $@
sh.bin: sh.o
	$(LD) -N -e _start -Ttext 0x1000000 -o sh.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary sh.x $@
pai.bin: pai.o
	$(LD) -N -e _start -Ttext 0x1000000 -o pai.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary pai.x $@
addr.bin: addr.o
	$(LD) -N -e _start -Ttext 0x1000000 -o addr.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary addr.x $@
tty.bin: tty.o
	$(LD) -N -e _start -Ttext 0x1000000 -o tty.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary tty.x $@
login.bin: login.o
	$(LD) -N -e _start -Ttext 0x1000000 -o login.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary login.x $@
init.bin: init.o
#$(LD) --oformat binary -N -e start -Ttext 0x1000000 -o $@ crt.o $< ../libc/libc.a 
	$(LD) -N -e _start -Ttext 0x1000000 -o init.x crt.o $< ../libc/libc.a
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary init.x $@
all:clean everything
clean:
	make -C w clean
	rm -f *.bin *.x
	rm -f *.o
dep:
	make -C w dep
	sed '/\#\#auto/d;/\#\#dep/q' Makefile>tmp_make
	for i in *.c *.S;do `echo $$i|sed '/^/s//$(CPP) -M /;/*/d'`>>tmp_make;done
	echo AUTOOBJS=|tr "\n" " ">tmp_make2
	
	ls -m *.c *.s|sed 's/\.[cs]/.o/g;s/,//g'|tr "\n" " "|\
	sed '/$$/a\#\#auto'|tr "\n" " "|sed '/$$/a\'>>tmp_make2
	
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2
	
##dep
addr.o: addr.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
g.o: g.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
init.o: init.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
login.o: login.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
pai.o: pai.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
sh.o: sh.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
snake.o: snake.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h \
 w/draw.h w/bmp.h
task2.o: task2.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h \
 w/draw.h w/bmp.h
tty.o: tty.c ../include/libc/libc.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h \
 ../include/drv/input.h ../include/drv/poll.h ../include/drv/video.h \
 ../include/drv/klog.h
