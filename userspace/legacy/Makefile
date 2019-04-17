AUTOOBJS=gauss.o g.o init.o lc-emu.o sh.o supc++.o test.o 
INC=-I../../include -I.
AS=i686-myos-elf-as
CC=i686-myos-elf-gcc
CXX=i686-myos-elf-g++
CPP=i686-myos-elf-gcc -E -nostdinc -fno-leading-underscore $(INC)
LD=i686-myos-elf-ld
CFLAGS=-O2 -fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall $(INC)
CXXFLAGS=$(CFLAGS) -fpermissive -nostdlib -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti 
OBJCOPY=i686-myos-elf-objcopy
OBJS=$(AUTOOBJS) init.bin sh.bin test.bin lc-emu.bin gauss.bin
AR=ar
.PHONY: all every everything clean dep
everything: every $(OBJS)
every: cxxrt.o
	make -C libc
%.o: %.c
	$(CC) $(CFLAGS) \
	-c -g -o $@ $<
%.o: %.cpp
	$(CXX) $(CXXFLAGS) \
	-c -g -o $@ $<
%.o: %.s
	$(CC) $(CFLAGS)	\
	-c -g -o $@ $<
%.x: %.o supc++.o
	$(LD) -N -e _start -Tapp.ld -o $@ cxxrt.o $^ libc/libc.a
%.bin: %.x
	$(OBJCOPY) -j .text -j .rodata -j .eh_frame_hdr -j .eh_frame -j .data -O binary $< $@

test.bin: test.x
sh.bin: sh.x
login.bin: login.x
init.bin: init.x
lc-emu.bin: lc-emu.x
gauss.bin: gauss.x

test.x: test.o
sh.x: sh.o
login.x: login.o
init.x: init.o
lc-emu.x: lc-emu.o
gauss.x: gauss.o g.o

all:clean everything
clean:
	make -C libc clean
	rm -f *.bin *.x
	rm -f *.o
dep:
	make -C libc dep
	sed '/^AUTOOBJS=/d;/\#\#dep/q' Makefile>tmp_make
	for i in `ls *.c *.cpp *.S`;do $(CPP) -M $$i >> tmp_make;done
	echo -n "AUTOOBJS=" > tmp_make2
	for i in `ls *.c *.cpp *.S`;do echo -n $$i | sed 's/\(\.[cS]\)\|\(\.cpp\)/.o /g' >> tmp_make2;done
	echo >> tmp_make2
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2
	
##dep
gauss.o: gauss.cpp libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h
g.o: g.c libc/libc.h ../../include/os/type.h ../../include/os/unistd.h \
 ../../include/lib/string.h ../../include/drv/video.h \
 ../../include/os/dirent.h ../../include/os/stat.h
init.o: init.c libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h
lc-emu.o: lc-emu.cpp libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h
sh.o: sh.c libc/libc.h ../../include/os/type.h ../../include/os/unistd.h \
 ../../include/lib/string.h ../../include/drv/video.h \
 ../../include/os/dirent.h ../../include/os/stat.h
supc++.o: supc++.cpp libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h
test.o: test.cpp libc/libc.h ../../include/os/type.h \
 ../../include/os/unistd.h ../../include/lib/string.h \
 ../../include/drv/video.h ../../include/os/dirent.h \
 ../../include/os/stat.h ../../include/drv/input.h \
 ../../include/drv/poll.h
