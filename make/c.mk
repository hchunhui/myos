# C rules
.PHONY: clean_c check-syntax
.SUFFIXES: .c
CC = cc
COBJS = ${CSRCS:.c=.o}
OBJS += ${COBJS}

${LIB}: ${COBJS}
${PROG}: ${COBJS}

.c.o:
	@${TOPDIR}/make/scripts/out.sh CC "$<" "$@"
	${Q}${CC} ${CFLAGS} -c $< -o $@

.depends_c.${SELF}: ${CSRCS}
	@${TOPDIR}/make/scripts/out.sh DEP "$^$>" "$@"
	${Q}${CC} ${CFLAGS} -MM $^$> 2> /dev/null > $@ || exit 0

clean_c:
	${Q}rm -f ${COBJS} .depends_c.${SELF}
clean: clean_c

check-syntax:
	${CC} ${CFLAGS} -Wall -Wextra -fsyntax-only ${CHK_SOURCES}

dep: .depends_c.${SELF}
-include .depends_c.${SELF}
