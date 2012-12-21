AUTOOBJS=entry.o fpu.o mm.o pic_i8259.o print_early.o realmode.o task_x86.o 
OBJS=$(AUTOOBJS)
ROOT=../..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
fpu.o: fpu.c ../../include/os/type.h ../../include/os/task.h \
 ../../arch_x86/include/os/arch_task.h ../../arch_x86/include/os/regs.h \
 ../../include/os/sem.h ../../include/lib/list.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h ../../arch_x86/include/os/mm.h \
 ../../include/os/fork.h ../../include/lib/string.h \
 ../../include/os/asm.h ../../include/os/isr.h
mm.o: mm.c ../../include/os/type.h \
 ../../arch_x86/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/os/dirent.h ../../include/os/stat.h \
 ../../include/drv/cmos.h ../../arch_x86/include/os/pic_i8259.h \
 ../../arch_x86/include/os/mm.h ../../include/os/fork.h \
 ../../include/lib/klib.h ../../include/lib/stdarg.h \
 ../../include/os/task.h ../../arch_x86/include/os/arch_task.h \
 ../../arch_x86/include/os/regs.h ../../include/lib/string.h \
 ../../include/os/asm.h ../../include/os/shm.h ../../include/os/isr.h \
 ../../include/os/waitexit.h
pic_i8259.o: pic_i8259.c ../../include/os/type.h \
 ../../arch_x86/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/os/dirent.h ../../include/os/stat.h \
 ../../include/drv/cmos.h ../../arch_x86/include/os/pic_i8259.h \
 ../../arch_x86/include/os/io.h
print_early.o: print_early.c ../../include/lib/string.h \
 ../../include/os/type.h ../../arch_x86/include/os/io.h
task_x86.o: task_x86.c ../../include/os/type.h \
 ../../arch_x86/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/os/dirent.h ../../include/os/stat.h \
 ../../include/drv/cmos.h ../../arch_x86/include/os/pic_i8259.h \
 ../../include/os/task.h ../../arch_x86/include/os/arch_task.h \
 ../../arch_x86/include/os/regs.h ../../arch_x86/include/os/protect.h \
 ../../include/lib/klib.h ../../include/lib/stdarg.h \
 ../../arch_x86/include/os/mm.h ../../include/os/fork.h \
 ../../include/os/fpu.h ../../include/lib/string.h ../../include/os/asm.h
entry.o: entry.S ../../include/os/task.h
realmode.o: realmode.S
