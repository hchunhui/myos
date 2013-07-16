AUTOOBJS=ctype.o libc.o libc_init.o malloc.o printf.o scanf.o string.o 
INC=-I../../../include -I..
AS=as -m32
CC=gcc -m32
CPP=gcc -E -nostdinc -fno-leading-underscore $(INC)
LD=ld -melf_i386
CFLAGS=-fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall $(INC) -c
OBJCOPY=objcopy
AR=ar
OBJS=$(AUTOOBJS)
.PHONY: all everything clean

everything: libc.a

.c.o:
	$(CC) $(CFLAGS) \
	-g -o $*.o $<
.S.o:
	$(CC) $(CFLAGS) \
	-o $*.o $<
	
libc.a: $(OBJS)
	$(AR) r libc.a $(OBJS)
all:clean everything
clean:
	rm -f *.o
	rm -f *.a

dep:
	sed '/^AUTOOBJS=/d;/\#\#dep/q' Makefile>tmp_make
	for i in `ls *.c *.cpp *.S`;do $(CPP) -M $$i >> tmp_make;done
	echo -n "AUTOOBJS=" > tmp_make2
	for i in `ls *.c *.cpp *.S`;do echo -n $$i | sed 's/\(\.[cS]\)\|\(\.cpp\)/.o /g' >> tmp_make2;done
	echo >> tmp_make2
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2

##dep
ctype.o: ctype.c ../../../include/os/type.h ../../../include/os/unistd.h \
 ../libc/libc.h ../../../include/lib/string.h \
 ../../../include/drv/video.h ../../../include/os/dirent.h \
 ../../../include/os/stat.h
libc.o: libc.c ../../../include/os/type.h ../../../include/os/unistd.h \
 ../libc/libc.h ../../../include/lib/string.h \
 ../../../include/drv/video.h ../../../include/os/dirent.h \
 ../../../include/os/stat.h
libc_init.o: libc_init.c
malloc.o: malloc.c ../../../include/os/type.h ../libc/libc.h \
 ../../../include/os/unistd.h ../../../include/lib/string.h \
 ../../../include/drv/video.h ../../../include/os/dirent.h \
 ../../../include/os/stat.h
printf.o: printf.c ../../../include/os/type.h \
 ../../../include/os/unistd.h ../libc/libc.h \
 ../../../include/lib/string.h ../../../include/drv/video.h \
 ../../../include/os/dirent.h ../../../include/os/stat.h
scanf.o: scanf.c ../../../include/os/type.h ../../../include/os/unistd.h \
 ../libc/libc.h ../../../include/lib/string.h \
 ../../../include/drv/video.h ../../../include/os/dirent.h \
 ../../../include/os/stat.h
string.o: string.c ../libc/libc.h ../../../include/os/type.h \
 ../../../include/os/unistd.h ../../../include/lib/string.h \
 ../../../include/drv/video.h ../../../include/os/dirent.h \
 ../../../include/os/stat.h
