AUTOOBJS= devfs.o exec.o fork.o isr.o kmain.o message.o ramfs.o sem.o shm.o syscall.o task.o time.o timer.o vfs.o waitexit.o  ##auto 
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
 ../include/os/devfs.h ../include/lib/list.h ../include/os/vfs.h \
 ../include/os/sem.h ../include/lib/string.h
exec.o: exec.c ../arch_x86/include/os/protect.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/type.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/asm.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/libc/kstru.h \
 ../arch_x86/include/os/mm.h ../include/os/fork.h ../include/lib/klib.h \
 ../include/lib/string.h ../include/os/i386-elf.h
fork.o: fork.c ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/sem.h ../include/lib/list.h \
 ../include/os/fork.h ../include/os/waitexit.h \
 ../arch_x86/include/os/mm.h ../include/os/fpu.h ../include/os/message.h \
 ../include/lib/klib.h ../include/lib/string.h
isr.o: isr.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/drv/cmos.h ../arch_x86/include/os/pic_i8259.h \
 ../include/os/asm.h ../include/lib/klib.h ../arch_x86/include/os/regs.h \
 ../include/lib/string.h ../include/os/isr.h
kmain.o: kmain.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/drv/cmos.h ../arch_x86/include/os/pic_i8259.h \
 ../include/lib/klib.h ../include/os/multiboot.h
message.o: message.c ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/type.h ../include/libc/kstru.h ../include/os/sem.h \
 ../include/lib/list.h ../include/lib/klib.h ../include/lib/string.h \
 ../include/os/unistd.h ../include/os/asm.h ../include/os/message.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/os/devfs.h ../include/os/vfs.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h
ramfs.o: ramfs.c ../include/os/type.h ../include/lib/klib.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/libc/kstru.h \
 ../include/os/sem.h ../include/lib/list.h ../include/lib/string.h \
 ../include/os/vfs.h
sem.o: sem.c ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/os/type.h \
 ../include/libc/kstru.h ../include/os/sem.h ../include/lib/list.h \
 ../include/os/asm.h ../include/lib/klib.h
shm.o: shm.c ../include/os/type.h ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../arch_x86/include/os/mm.h \
 ../include/os/fork.h ../include/lib/klib.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/libc/kstru.h ../include/lib/string.h ../include/os/asm.h \
 ../include/os/shm.h
syscall.o: syscall.c ../arch_x86/include/os/protect.h \
 ../arch_x86/include/os/hz.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/type.h ../include/libc/kstru.h ../include/os/sem.h \
 ../include/lib/list.h ../arch_x86/include/os/mm.h ../include/os/fork.h \
 ../include/os/devfs.h ../include/os/vfs.h ../include/lib/klib.h \
 ../include/lib/string.h ../include/os/unistd.h ../include/os/asm.h
task.o: task.c ../include/os/type.h ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/vfs.h ../include/os/sem.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/libc/kstru.h ../include/os/fork.h ../include/lib/klib.h \
 ../arch_x86/include/os/mm.h ../include/lib/string.h \
 ../include/os/unistd.h ../include/os/asm.h ../include/os/message.h \
 ../include/os/fpu.h ../include/os/isr.h
time.o: time.c ../arch_x86/include/os/arch_config.h \
 ../include/drv/pit_i8253.h ../include/os/devfs.h ../include/lib/list.h \
 ../include/os/type.h ../include/os/vfs.h ../include/os/sem.h \
 ../include/drv/cmos.h ../arch_x86/include/os/pic_i8259.h \
 ../arch_x86/include/os/hz.h ../include/lib/klib.h
timer.o: timer.c ../include/os/type.h ../include/os/asm.h \
 ../arch_x86/include/os/arch_config.h ../include/drv/pit_i8253.h \
 ../include/os/devfs.h ../include/lib/list.h ../include/os/vfs.h \
 ../include/os/sem.h ../include/drv/cmos.h \
 ../arch_x86/include/os/pic_i8259.h ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/libc/kstru.h ../arch_x86/include/os/protect.h \
 ../arch_x86/include/os/hz.h ../include/lib/klib.h \
 ../include/os/message.h ../include/os/isr.h
vfs.o: vfs.c ../include/os/type.h ../include/lib/klib.h \
 ../include/os/task.h ../arch_x86/include/os/arch_task.h \
 ../arch_x86/include/os/regs.h ../include/libc/kstru.h \
 ../include/os/sem.h ../include/lib/list.h ../include/lib/string.h \
 ../include/os/vfs.h ../include/os/devfs.h ../include/os/asm.h \
 ../include/os/multiboot.h
waitexit.o: waitexit.c ../include/os/task.h \
 ../arch_x86/include/os/arch_task.h ../arch_x86/include/os/regs.h \
 ../include/os/type.h ../include/libc/kstru.h ../include/os/sem.h \
 ../include/lib/list.h ../arch_x86/include/os/mm.h ../include/os/fork.h \
 ../include/os/fpu.h ../include/os/waitexit.h ../include/os/message.h \
 ../include/lib/klib.h ../include/lib/string.h
