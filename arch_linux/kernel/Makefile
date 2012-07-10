AUTOOBJS= entry.o fpu.o mm.o pic.o task_x86.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..\/..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
entry.o: entry.c ../../include/os/asm.h \
 ../../arch_linux/include/os/regs.h ../../arch_linux/include/lib/klib.h
