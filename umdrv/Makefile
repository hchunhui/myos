AUTOOBJS= cmos.o drv.o null.o pit_i8253.o speaker.o tty.o video.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
drv.o: drv.c ../arch_linux/include/lib/klib.h
null.o: null.c ../arch_linux/include/lib/klib.h ../include/os/devfs.h \
 ../include/os/vfs.h
pit_i8253.o: pit_i8253.c ../arch_linux/include/lib/klib.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/os/vfs.h
speaker.o: speaker.c
tty.o: tty.c ../include/os/type.h
video.o: video.c ../arch_linux/include/lib/klib.h
