AUTOOBJS= init.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..\/..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
init.o: init.c ../../arch_linux/include/lib/klib.h \
 ../../include/os/multiboot.h
