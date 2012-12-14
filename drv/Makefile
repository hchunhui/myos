AUTOOBJS= cmos.o drv.o i8042.o input.o input_kbd.o input_mouse.o pit_i8253.o speaker.o video.o  ##auto 
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
 ../include/os/stat.h ../arch_x86/include/os/io.h ../include/drv/cmos.h
drv.o: drv.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/lib/string.h ../include/drv/i8042.h \
 ../include/drv/input.h ../include/drv/video.h
i8042.o: i8042.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/isr.h \
 ../arch_x86/include/os/regs.h ../arch_x86/include/os/io.h \
 ../include/drv/i8042.h ../include/os/fork.h ../include/drv/input.h
input.o: input.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/isr.h \
 ../arch_x86/include/os/regs.h ../arch_x86/include/os/io.h \
 ../include/os/fork.h ../include/lib/string.h ../include/drv/input.h \
 ../include/os/asm.h
input_kbd.o: input_kbd.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/isr.h \
 ../arch_x86/include/os/regs.h ../arch_x86/include/os/io.h \
 ../include/drv/i8042.h ../include/drv/input.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h
input_mouse.o: input_mouse.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/isr.h \
 ../arch_x86/include/os/regs.h ../arch_x86/include/os/io.h \
 ../include/drv/i8042.h ../include/drv/input.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h
pit_i8253.o: pit_i8253.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../arch_x86/include/os/io.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h
speaker.o: speaker.c ../include/drv/speaker.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/asm.h ../arch_x86/include/os/io.h \
 ../include/os/type.h
video.o: video.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/lib/klib.h ../include/lib/stdarg.h \
 ../arch_x86/include/os/mm.h ../include/os/fork.h ../include/lib/string.h \
 ../arch_x86/include/os/io.h ../include/drv/video.h
