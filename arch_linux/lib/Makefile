AUTOOBJS= klibc.o user.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=../..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
klibc.o: klibc.c ../../include/lib/klib.h ../../include/lib/stdarg.h
user.o: user.c ../../arch_linux/include/lib/user.h
