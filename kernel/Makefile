AUTOOBJS= devfs.o exec.o fork.o isr.o klog.o kmain.o null.o pipe.o poll.o ramfs.o sem.o shm.o syscall.o task.o time.o timer.o vfs.o waitexit.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
devfs.o: devfs.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/lib/string.h
exec.o: exec.c ../arch_x86/include/os/protect.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/asm.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../arch_x86/include/os/mm.h \
 ../include/os/fork.h ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/lib/string.h ../include/os/i386-elf.h ../include/os/errno.h
fork.o: fork.c ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/os/type.h ../include/os/sem.h \
 ../include/lib/list.h ../include/os/fork.h ../include/os/waitexit.h \
 ../arch_x86/include/os/mm.h ../include/os/fpu.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/lib/string.h ../include/os/asm.h \
 ../include/os/vfs.h ../include/os/dirent.h ../include/os/stat.h
isr.o: isr.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/asm.h \
 ../include/lib/klib.h ../include/lib/stdarg.h \
 ../arch_x86/include/os/regs.h ../include/lib/string.h \
 ../include/os/isr.h
klog.o: klog.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/lib/string.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/sem.h ../include/lib/list.h ../include/os/devfs.h \
 ../include/os/vfs.h ../include/os/dirent.h ../include/os/stat.h \
 ../include/drv/klog.h
kmain.o: kmain.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/multiboot.h
null.o: null.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h
pipe.o: pipe.c ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/os/asm.h ../include/drv/pipe.h \
 ../include/os/errno.h
poll.o: poll.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/sem.h ../include/lib/list.h ../include/os/devfs.h \
 ../include/os/vfs.h ../include/os/dirent.h ../include/os/stat.h \
 ../include/drv/poll.h
ramfs.o: ramfs.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/sem.h ../include/lib/list.h ../include/lib/string.h \
 ../include/os/vfs.h ../include/os/dirent.h ../include/os/stat.h \
 ../include/os/errno.h
sem.o: sem.c ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/os/type.h ../include/os/sem.h \
 ../include/lib/list.h ../include/os/asm.h ../include/lib/klib.h \
 ../include/lib/stdarg.h
shm.o: shm.c ../include/os/type.h ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../arch_x86/include/os/mm.h \
 ../include/os/fork.h ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/lib/string.h \
 ../include/os/asm.h ../include/os/shm.h
syscall.o: syscall.c ../arch_x86/include/os/protect.h \
 ../arch_x86/include/os/hz.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/type.h ../include/os/sem.h ../include/lib/list.h \
 ../arch_x86/include/os/mm.h ../include/os/fork.h ../include/os/devfs.h \
 ../include/os/vfs.h ../include/os/dirent.h ../include/os/stat.h \
 ../include/lib/klib.h ../include/lib/stdarg.h ../include/lib/string.h \
 ../include/os/unistd.h ../include/os/asm.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/drv/cmos.h ../arch_x86/include/os/pic_i8259.h \
 ../include/os/errno.h
task.o: task.c ../include/os/type.h ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/os/dirent.h \
 ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/fork.h ../include/lib/klib.h ../include/lib/stdarg.h \
 ../arch_x86/include/os/mm.h ../include/lib/string.h \
 ../include/os/unistd.h ../include/os/asm.h ../include/os/fpu.h \
 ../include/os/isr.h
time.o: time.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../arch_x86/include/os/hz.h \
 ../include/lib/klib.h ../include/lib/stdarg.h ../include/os/asm.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h
timer.o: timer.c ../include/os/type.h ../include/os/asm.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/vfs.h \
 ../include/os/sem.h ../include/os/dirent.h ../include/os/stat.h \
 ../include/drv/cmos.h ../arch_x86/include/os/pic_i8259.h \
 ../include/lib/klib.h ../include/lib/stdarg.h ../include/lib/string.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../arch_x86/include/os/protect.h \
 ../arch_x86/include/os/hz.h ../include/os/isr.h ../include/os/errno.h
vfs.o: vfs.c ../include/os/type.h ../include/lib/klib.h \
 ../include/lib/stdarg.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/sem.h ../include/lib/list.h ../include/lib/string.h \
 ../include/os/vfs.h ../include/os/dirent.h ../include/os/stat.h \
 ../include/os/devfs.h ../include/os/asm.h ../include/os/multiboot.h \
 ../include/os/errno.h
waitexit.o: waitexit.c ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/type.h ../include/os/sem.h ../include/lib/list.h \
 ../arch_x86/include/os/mm.h ../include/os/fork.h ../include/os/fpu.h \
 ../include/os/waitexit.h ../include/lib/klib.h ../include/lib/stdarg.h \
 ../include/lib/string.h ../include/os/asm.h ../include/os/vfs.h \
 ../include/os/dirent.h ../include/os/stat.h ../include/os/errno.h
