AUTOOBJS= klibc.o kmalloc.o printk.o string.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
klibc.o: klibc.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/lib/string.h \
 ../include/drv/kdev.h
kmalloc.o: kmalloc.c ../include/os/type.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/vfs.h \
 ../include/os/sem.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/lib/string.h
printk.o: printk.c ../include/lib/string.h ../include/lib/stdarg.h \
 ../include/lib/klib.h
string.o: string.c ../include/lib/string.h
