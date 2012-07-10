AUTOOBJS= ctype.o libc.o libc_init.o malloc.o printf.o scanf.o string.o  ##auto 
INC=..\/include
AS=as -m32
CC=gcc -m32
CPP=gcc -E -nostdinc -fno-leading-underscore -I$(INC)
LD=ld -melf_i386
CFLAGS=-fno-strict-aliasing -fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall  -I $(INC) -c
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
	sed '/\#\#auto/d;/\#\#dep/q' Makefile>tmp_make
	for i in *.c *.S;do `echo $$i|sed '/^/s//$(CPP) -M /;/*/d'`>>tmp_make;done
	echo AUTOOBJS=|tr "\n" " ">tmp_make2
	
	ls -m *.c *.S|sed 's/\.[cS]/.o/g;s/,//g'|tr "\n" " "|\
	sed '/$$/a\#\#auto'|tr "\n" " "|sed '/$$/a\'>>tmp_make2
	
	cat tmp_make2 tmp_make>Makefile
	rm -f tmp_make tmp_make2

##dep
ctype.o: ctype.c ../include/os/type.h ../include/os/unistd.h \
 ../include/libc/libc.h ../include/libc/kstru.h ../include/lib/string.h
libc.o: libc.c ../include/os/type.h ../include/os/unistd.h \
 ../include/libc/libc.h ../include/libc/kstru.h ../include/lib/string.h
libc_init.o: libc_init.c
malloc.o: malloc.c ../include/os/type.h ../include/libc/libc.h \
 ../include/libc/kstru.h ../include/os/unistd.h ../include/lib/string.h
printf.o: printf.c ../include/os/type.h ../include/os/unistd.h \
 ../include/libc/libc.h ../include/libc/kstru.h ../include/lib/string.h
scanf.o: scanf.c ../include/os/type.h ../include/os/unistd.h \
 ../include/libc/libc.h ../include/libc/kstru.h ../include/lib/string.h
string.o: string.c ../include/lib/string.h
