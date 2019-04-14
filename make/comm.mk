Q ?= @
TOPDIR ?= .

# Toplevel rules
.PHONY: all clean topdir sub_all _all dep
.SUFFIXES:

all: dep
	${MAKE} sub_all
	${MAKE} _all

clean:
	${Q}rm -rf ${EXTRA_CLEAN}

topdir:
	${MAKE} -C ${TOPDIR}


# Sub rules
.PHONY: ${SUBDIRS:=.all} ${SUBDIRS:=.clean} ${SUBDIRS:=.dep}

sub_all: ${SUBDIRS:=.all}

clean: ${SUBDIRS:=.clean}

dep: ${SUBDIRS:=.dep}

${SUBDIRS:=.all}:
	${MAKE} -C ${@:.all=}
${SUBDIRS:=.clean}:
	${MAKE} -C ${@:.clean=} clean
${SUBDIRS:=.dep}:
	${MAKE} -C ${@:.dep=} dep


# Link rules
.PHONY: clean_ld
.SUFFIXES: .o
LD = CCLD="${CCLD}" ${TOPDIR}/make/scripts/gcc-ld
CCLD ?= ${CC}
AR = ar

_all: ${LIB} ${PROG}

${LIB}: ${OBJS}
	@${TOPDIR}/make/scripts/out.sh AR "${OBJS}" "$@"
	${Q}${AR} rcsT ${LIB} ${OBJS}

${PROG}: ${OBJS}
	@${TOPDIR}/make/scripts/out.sh LD "${OBJS}" "$@"
	${Q}${LD} --start-group ${OBJS} --end-group -o ${PROG} ${LDFLAGS}

clean_ld:
	${Q}rm -f ${LIB} ${PROG}
clean: clean_ld
