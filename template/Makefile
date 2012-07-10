AUTOOBJS=   ##auto 
INC=..\/include
AS=as
CC=gcc
CPP=gcc -E -nostdinc -fno-leading-underscore -I$(INC)
LD=ld
CFLAGS=-fno-leading-underscore -fno-builtin -fno-stack-protector -nostdinc -Wall  -I $(INC) -c
OBJCOPY=objcopy
AR=ar
OBJS=$(AUTOOBJS)
.PHONY: all everything clean

everything: x.a

.c.o:
	$(CC) $(CFLAGS) \
	-o $*.o $<
.S.o:
	$(CC) $(CFLAGS) \
	-o $*.o $<
	
x.a: $(OBJS)
	$(AR) r x.a $(OBJS)
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

