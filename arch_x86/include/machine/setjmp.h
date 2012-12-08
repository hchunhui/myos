
_BEGIN_STD_C

# define _JBLEN	9

#ifdef _JBLEN
#ifdef _JBTYPE
typedef	_JBTYPE jmp_buf[_JBLEN];
#else
typedef	int jmp_buf[_JBLEN];
#endif
#endif

_END_STD_C

#include <signal.h>

#ifdef __cplusplus
extern "C" {
#endif

/* POSIX sigsetjmp/siglongjmp macros */
#ifdef _JBTYPE
typedef _JBTYPE sigjmp_buf[_JBLEN+1+(sizeof (sigset_t)/sizeof (_JBTYPE))];
#else
typedef int sigjmp_buf[_JBLEN+1+(sizeof (sigset_t)/sizeof (int))];
#endif

#define _SAVEMASK	_JBLEN
#define _SIGMASK	(_JBLEN+1)

#define __SIGMASK_FUNC sigprocmask

#if defined(__GNUC__)

#define sigsetjmp(env, savemask) \
            __extension__ \
            ({ \
              sigjmp_buf *_sjbuf = &(env); \
              ((*_sjbuf)[_SAVEMASK] = savemask,\
              __SIGMASK_FUNC (SIG_SETMASK, 0, (sigset_t *)((*_sjbuf) + _SIGMASK)),\
              setjmp (*_sjbuf)); \
            })

#define siglongjmp(env, val) \
            __extension__ \
            ({ \
              sigjmp_buf *_sjbuf = &(env); \
              ((((*_sjbuf)[_SAVEMASK]) ? \
               __SIGMASK_FUNC (SIG_SETMASK, (sigset_t *)((*_sjbuf) + _SIGMASK), 0)\
               : 0), \
               longjmp (*_sjbuf, val)); \
            })

#else /* !__GNUC__ */

#define sigsetjmp(env, savemask) ((env)[_SAVEMASK] = savemask,\
               __SIGMASK_FUNC (SIG_SETMASK, 0, (sigset_t *) ((env) + _SIGMASK)),\
               setjmp (env))

#define siglongjmp(env, val) ((((env)[_SAVEMASK])?\
               __SIGMASK_FUNC (SIG_SETMASK, (sigset_t *) ((env) + _SIGMASK), 0):0),\
               longjmp (env, val))

#endif


#ifdef __cplusplus
}
#endif

