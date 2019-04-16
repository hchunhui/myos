TOPDIR = ../../..
CSRCS = cursor.c w.c wnd.c
OBJS += libw.a
PROG = ${BINDIR}/w

include ${TOPDIR}/userspace/user.mk
