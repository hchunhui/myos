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

.depends_cxx: ${CXXSRCS}
	@${TOPDIR}/make/scripts/out.sh DEP "${CXXSRCS}" "$@"
	${Q}${CXX} ${CFLAGS} ${CXXFLAGS} -MM ${CXXSRCS} 2> /dev/null > $@ || exit 0

clean_cxx:
	${Q}rm -f ${CXXOBJS} .depends_cxx
clean: clean_cxx

dep: .depends_cxx
-include .depends_cxx
