AUTOOBJS= cmos.o drv.o klog.o null.o pipe.o pit_i8253.o poll.o speaker.o tty.o video.o  ##auto 
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
 ../include/os/vfs.h ../include/os/sem.h ../include/drv/cmos.h
drv.o: drv.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/type.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/lib/string.h \
 ../include/drv/i8042.h ../include/drv/input.h ../include/drv/video.h
klog.o: klog.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/lib/string.h ../include/os/task.h \
 ../arch_linux/include/os/arch_task.h ../arch_linux/include/os/regs.h \
 ../include/libc/kstru.h ../include/os/sem.h ../include/lib/list.h \
 ../include/os/devfs.h ../include/os/vfs.h ../include/drv/klog.h
null.o: null.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h
pipe.o: pipe.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/asm.h
pit_i8253.o: pit_i8253.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h
poll.o: poll.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/task.h \
 ../arch_linux/include/os/arch_task.h ../arch_linux/include/os/regs.h \
 ../include/libc/kstru.h ../include/os/sem.h ../include/lib/list.h \
 ../include/os/devfs.h ../include/os/vfs.h ../include/drv/poll.h
speaker.o: speaker.c
tty.o: tty.c ../include/os/type.h
video.o: video.c ../include/lib/klib.h ../include/lib/stdarg.h
