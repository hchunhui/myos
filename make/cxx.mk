# C++ rules
.PHONY: clean_cxx
.SUFFIXES: .cpp .cxx .cc
CXX = c++
CCLD = ${CXX}
CXXOBJS = ${CXXSRCS:.cpp=.o}
CXXOBJS := ${CXXOBJS:.cxx=.o}
CXXOBJS := ${CXXOBJS:.cc=.o}
OBJS += ${CXXOBJS}

${PROG}: ${CXXOBJS}
${LIB}: ${CXXOBJS}

.cpp.o:
	@${TOPDIR}/make/scripts/out.sh CXX "$<" "$@"
	${Q}${CXX} ${CFLAGS} ${CXXFLAGS} -c $< -o $@
.cxx.o:
	@${TOPDIR}/make/scripts/out.sh CXX "$<" "$@"
	${Q}${CXX} ${CFLAGS} ${CXXFLAGS} -c $< -o $@
.cc.o:
	@${TOPDIR}/make/scripts/out.sh CXX "$<" "$@"
	${Q}${CXX} ${CFLAGS} ${CXXFLAGS} -c $< -o $@

.depends_cxx.${SELF}: ${CXXSRCS}
	@${TOPDIR}/make/scripts/out.sh DEP "$^$>" "$@"
	${Q}${CXX} ${CFLAGS} ${CXXFLAGS} -MM $^$> 2> /dev/null > $@ || exit 0

clean_cxx:
	${Q}rm -f ${CXXOBJS} .depends_cxx.${SELF}
clean: clean_cxx

dep: .depends_cxx.${SELF}
-include .depends_cxx.${SELF}
