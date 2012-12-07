AUTOOBJS= entry.o fpu.o mm.o pic.o task_x86.o  ##auto 
OBJS=$(AUTOOBJS)
ROOT=../..
everything: build.a
include $(ROOT)/Makefile.arch
.PHONY: all every everything clean dep
build.a:$(OBJS)
	$(AR) r $@ $(OBJS)
all:clean everything

##dep
entry.o: entry.c ../../include/os/asm.h \
 ../../arch_linux/include/os/regs.h ../../include/os/task.h \
 ../../arch_linux/include/os/arch_task.h /usr/include/ucontext.h \
 /usr/include/features.h /usr/include/stdc-predef.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/include/sys/ucontext.h /usr/include/signal.h \
 /usr/include/bits/sigset.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/include/stddef.h \
 /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/sigthread.h ../../include/libc/kstru.h \
 ../../include/os/type.h ../../include/os/sem.h ../../include/lib/list.h \
 ../../include/lib/klib.h ../../include/lib/stdarg.h
fpu.o: fpu.c ../../include/os/type.h ../../include/os/task.h \
 ../../arch_linux/include/os/arch_task.h \
 ../../arch_linux/include/os/regs.h /usr/include/ucontext.h \
 /usr/include/features.h /usr/include/stdc-predef.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/include/sys/ucontext.h /usr/include/signal.h \
 /usr/include/bits/sigset.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/include/stddef.h \
 /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/sigthread.h ../../include/libc/kstru.h \
 ../../include/os/sem.h ../../include/lib/list.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h
mm.o: mm.c ../../include/os/type.h \
 ../../arch_linux/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/drv/cmos.h \
 ../../arch_linux/include/os/pic.h ../../arch_linux/include/os/mm.h \
 ../../include/os/task.h ../../arch_linux/include/os/arch_task.h \
 ../../arch_linux/include/os/regs.h /usr/include/ucontext.h \
 /usr/include/features.h /usr/include/stdc-predef.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/include/sys/ucontext.h /usr/include/signal.h \
 /usr/include/bits/sigset.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/include/stddef.h \
 /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/sigthread.h ../../include/libc/kstru.h \
 ../../include/lib/klib.h ../../include/lib/stdarg.h \
 ../../include/lib/string.h ../../include/os/asm.h ../../include/os/shm.h \
 ../../include/os/isr.h
pic.o: pic.c ../../include/os/type.h \
 ../../arch_linux/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/drv/cmos.h \
 ../../arch_linux/include/os/pic.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/include/stddef.h \
 /usr/include/signal.h /usr/include/features.h /usr/include/stdc-predef.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/include/bits/sigset.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h
task_x86.o: task_x86.c ../../include/os/type.h \
 ../../arch_linux/include/os/arch_config.h ../../include/drv/pit_i8253.h \
 ../../include/os/devfs.h ../../include/lib/list.h ../../include/os/vfs.h \
 ../../include/os/sem.h ../../include/drv/cmos.h \
 ../../arch_linux/include/os/pic.h ../../include/os/task.h \
 ../../arch_linux/include/os/arch_task.h \
 ../../arch_linux/include/os/regs.h /usr/include/ucontext.h \
 /usr/include/features.h /usr/include/stdc-predef.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/include/sys/ucontext.h /usr/include/signal.h \
 /usr/include/bits/sigset.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/bits/signum.h \
 /usr/include/time.h /usr/include/bits/siginfo.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/include/stddef.h \
 /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/sigthread.h ../../include/libc/kstru.h \
 ../../arch_linux/include/os/protect.h ../../include/lib/klib.h \
 ../../include/lib/stdarg.h ../../arch_linux/include/os/mm.h \
 ../../include/lib/string.h ../../include/os/unistd.h \
 ../../include/os/asm.h
