AUTOOBJS= cmos.o drv.o pit_i8253.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
cmos.o: cmos.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_linux/include/lib/user.h
drv.o: drv.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/type.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/lib/string.h ../include/drv/i8042.h \
 ../include/drv/input.h ../include/drv/video.h
pit_i8253.o: pit_i8253.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h \
 ../arch_linux/include/lib/user.h
