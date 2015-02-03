AUTOOBJS= entry.o fpu.o mm.o pic.o task_linux.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=../..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
entry.o: entry.c ../../arch_linux/include/os/regs.h \
 ../../include/os/task.h ../../arch_linux/include/os/arch_task.h \
 ../../include/lib/klib.h ../../include/lib/stdarg.h \
 ../../arch_linux/include/lib/user.h ../../include/os/sem.h \
 ../../include/lib/list.h ../../include/os/type.h
fpu.o: fpu.c ../../include/os/type.h ../../include/os/task.h \
 ../../arch_linux/include/os/arch_task.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h ../../arch_linux/include/os/regs.h \
 ../../arch_linux/include/lib/user.h ../../include/os/sem.h \
 ../../include/lib/list.h
mm.o: mm.c ../../include/os/type.h \
 ../../arch_linux/include/os/arch_config.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/os/dirent.h ../../include/os/stat.h \
 ../../include/drv/cmos.h ../../arch_linux/include/os/pic.h \
 ../../arch_linux/include/os/mm.h ../../include/os/task.h \
 ../../arch_linux/include/os/arch_task.h \
 ../../arch_linux/include/os/regs.h ../../arch_linux/include/lib/user.h \
 ../../include/lib/string.h ../../include/os/shm.h ../../include/os/isr.h
pic.o: pic.c
task_linux.o: task_linux.c ../../include/os/type.h \
 ../../arch_linux/include/os/arch_config.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/os/dirent.h ../../include/os/stat.h \
 ../../include/drv/cmos.h ../../arch_linux/include/os/pic.h \
 ../../include/os/task.h ../../arch_linux/include/os/arch_task.h \
 ../../arch_linux/include/os/regs.h ../../arch_linux/include/lib/user.h \
 ../../arch_linux/include/os/protect.h ../../arch_linux/include/os/mm.h \
 ../../include/lib/string.h ../../include/os/unistd.h \
 ../../include/os/fork.h
