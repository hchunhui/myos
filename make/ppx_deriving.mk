# ppx deriving
PPXD = ${LIBDIR}/ppx_deriving
MLFLAGS += -ppx "${PPXD}/ppx_deriving ${PPXD}/ppx_deriving_show.cma ${PPXD}/ppx_deriving_ord.cma ${PPXD}/ppx_deriving_eq.cma" -I ${PPXD} -I ${LIBDIR}/result
MLMODS += result.cma ppx_deriving_runtime.cma
