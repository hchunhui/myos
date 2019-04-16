TOPDIR = ..
SUBDIRS = libkb base window

.PHONY: top install
top: bin
	${MAKE} all

include ${TOPDIR}/userspace/user.mk

base.all window.all: libkb.all

bin:
	mkdir -p bin

INSTALL=install
DESTDIR ?= ../toolchain/install/i686-myos-elf

install:
	$(INSTALL) -m 644 window/w/libw.a $(DESTDIR)/lib
	$(INSTALL) -d $(DESTDIR)/include/w
	$(INSTALL) -m 644 libkb/*.h $(DESTDIR)/include/w
	$(INSTALL) -m 644 window/w/*.h $(DESTDIR)/include/w
