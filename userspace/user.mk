BINDIR = ${TOPDIR}/userspace/bin
CFLAGS += -O2 -iquote ${TOPDIR}/userspace/libkb
LDFLAGS := -L${TOPDIR}/userspace/libkb -lkb ${LDFLAGS}

include ${TOPDIR}/make/comm.mk
include ${TOPDIR}/make/c.mk

CC = i686-myos-elf-gcc
AS = i686-myos-elf-gcc
AR = i686-myos-elf-ar
