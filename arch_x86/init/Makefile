AUTOOBJS= desc.o init.o multiboot.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..\/..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
desc.o: desc.c ../../include/os/type.h \
 ../../arch_x86/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/drv/cmos.h \
 ../../arch_x86/include/os/pic_i8259.h \
 ../../arch_x86/include/os/protect.h
init.o: init.S
multiboot.o: multiboot.S
