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

.depends_s: ${SSRCS}
	@${TOPDIR}/make/scripts/out.sh DEP "${SSRCS}" "$@"
	${Q}${AS} -D__ASSEMBLY__ ${CFLAGS} ${SFLAGS} -MM ${SSRCS} 2> /dev/null > $@ || exit 0

clean_s:
	${Q}rm -f ${SOBJS} .depends_s
clean: clean_s

dep: .depends_s
-include .depends_s
