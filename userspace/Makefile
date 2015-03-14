AS=i686-myos-elf-as
CC=i686-myos-elf-gcc
LD=i686-myos-elf-ld
OBJCOPY=i686-myos-elf-objcopy
AR=i686-myos-elf-ar
INSTALL=install
DESTDIR ?= ../toolchain/install/i686-myos-elf

CFLAGS=-O2 -iquote libkb 
O=obj

.PHONY: all clean install everything

%.o: | obj
	$(CC) $(CFLAGS) -c -o $@ $<
%: | bin
	$(CC) $(CFLAGS) -o $@ $^ -lm

everything: bin/init bin/tty bin/login bin/sh bin/ls bin/cat bin/w bin/snake bin/task2 bin/wterm obj/libw.a
all: clean everything
clean:
	rm -rf bin obj
bin:
	mkdir -p bin
obj:
	mkdir -p obj
	mkdir -p obj/w

install: everything
	$(INSTALL) -m 644 $(O)/libw.a $(DESTDIR)/lib
	$(INSTALL) -d $(DESTDIR)/include/w
	$(INSTALL) -m 644 libkb/* $(DESTDIR)/include/w
	$(INSTALL) -m 644 window/w/*.h $(DESTDIR)/include/w

#kb
$(O)/kb_trans.o: libkb/kb_trans.c

#base
P=$(O)
vpath %.c base
vpath %.h base libkb
vpath %.o $(O) $(P)
$(P)/init.o: init.c
$(P)/tty.o: tty.c kb_state.h
$(P)/login.o: login.c
$(P)/sh.o: sh.c
$(P)/ls.o: ls.c
$(P)/cat.o: cat.c
bin/init: init.o
bin/tty: tty.o kb_trans.o
bin/login: login.o
bin/sh: sh.o
bin/ls: ls.o
bin/cat: cat.o

#window/w
P=$(O)/w
vpath %.c window/w
vpath %.h window/w libkb
vpath %.o $(O) $(P)
$(P)/cursor.o: cursor.c cursor.h wtype.h draw.h bmp.h w.h
$(P)/draw.o: draw.c draw.h bmp.h wtype.h
$(P)/msg.o: msg.c msg.h
$(P)/w.o: w.c draw.h bmp.h wtype.h cursor.h w.h wnd.h msg.h kb_state.h
$(P)/wnd.o: wnd.c draw.h bmp.h wtype.h w.h wnd.h msg.h
bin/w: cursor.o draw.o msg.o w.o wnd.o kb_trans.o
$(O)/libw.a: $(O)/kb_trans.o msg.o draw.o
	$(AR) rcs $@ $^

#window
P=$(O)
vpath %.c window
vpath %.h window/w libkb
vpath %.o $(O) $(P) $(P)/w
$(P)/snake.o: snake.c
$(P)/task2.o: task2.c
$(P)/wterm.o: wterm.c
bin/snake: snake.o draw.o msg.o
bin/task2: task2.o draw.o msg.o
bin/wterm: wterm.o draw.o msg.o
