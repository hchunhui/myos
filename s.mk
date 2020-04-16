# S rules
.PHONY: clean_s
.SUFFIXES: .s .S
AS = cc
SOBJS = ${SSRCS:.s=.o}
SOBJS := ${SOBJS:.S=.o}
OBJS += ${SOBJS}

${LIB}: ${SOBJS}
${PROG}: ${SOBJS}

.s.o:
	@${TOPDIR}/make/scripts/out.sh AS "$<" "$@"
	${Q}${AS} -D__ASSEMBLY__ ${CFLAGS} ${SFLAGS} -c $< -o $@
.S.o:
	@${TOPDIR}/make/scripts/out.sh AS "$<" "$@"
	${Q}${AS} -D__ASSEMBLY__ ${CFLAGS} ${SFLAGS} -c $< -o $@

.depends_s.${SELF}: ${SSRCS} ${SELF}
	@${TOPDIR}/make/scripts/out.sh DEP "$^$>" "$@"
	${Q}${AS} -D__ASSEMBLY__ ${CFLAGS} ${SFLAGS} -MM $^$> 2> /dev/null > $@ || exit 0

clean_s:
	${Q}rm -f ${SOBJS} .depends_s.${SELF}
clean: clean_s

dep: .depends_s.${SELF}
-include .depends_s.${SELF}
