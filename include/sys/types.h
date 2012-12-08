#ifndef _SYS_TYPES_H

#include <_ansi.h>

#ifndef __INTTYPES_DEFINED__
#define __INTTYPES_DEFINED__

#include <machine/_types.h>

#endif /* ! __INTTYPES_DEFINED */

#ifndef __need_inttypes

#define _SYS_TYPES_H
#include <sys/_types.h>

# include <stddef.h>
# include <machine/types.h>
# include <os/type.h>

/* To ensure the stat struct's layout doesn't change when sizeof(int), etc.
   changes, we assume sizeof short and long never change and have all types
   used to define struct stat use them and not int where possible.
   Where not possible, _ST_INTxx are used.  It would be preferable to not have
   such assumptions, but until the extra fluff is necessary, it's avoided.
   No 64 bit targets use stat yet.  What to do about them is postponed
   until necessary.  */
#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _BSDTYPES_DEFINED
/* also defined in mingw/gmon.h and in w32api/winsock[2].h */
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#define _BSDTYPES_DEFINED
#endif

typedef	unsigned short	ushort;		/* System V compatibility */
typedef	unsigned int	uint;		/* System V compatibility */
typedef	unsigned long	ulong;		/* System V compatibility */
# endif	/*!_POSIX_SOURCE */

#ifndef __clock_t_defined
typedef __clock_t clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef __time_t time_t;
#define __time_t_defined

/* Time Value Specification Structures, P1003.1b-1993, p. 261 */
struct timespec {
  time_t  tv_sec;   /* Seconds */
  long    tv_nsec;  /* Nanoseconds */
};

struct itimerspec {
  struct timespec  it_interval;  /* Timer period */
  struct timespec  it_value;     /* Timer expiration */
};

#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;



typedef __ino_t ino_t;
typedef __off_t	off_t;
typedef __dev_t dev_t;
typedef __uid_t uid_t;
typedef __gid_t gid_t;


typedef __pid_t pid_t;
typedef __ssize_t ssize_t;

typedef __mode_t mode_t;
typedef __nlink_t nlink_t;

/* We don't define fd_set and friends if we are compiling POSIX
   source, or if we have included (or may include as indicated
   by __USE_W32_SOCKETS) the W32api winsock[2].h header which
   defines Windows versions of them.   Note that a program which
   includes the W32api winsock[2].h header must know what it is doing;
   it must not call the cygwin32 select function.
*/
# if !(defined (_POSIX_SOURCE) || defined (_WINSOCK_H) || defined (__USE_W32_SOCKETS)) 
#  define _SYS_TYPES_FD_SET
#  define	NBBY	8		/* number of bits in a byte */
/*
 * Select uses bit masks of file descriptors in longs.
 * These macros manipulate such bit fields (the filesystem macros use chars).
 * FD_SETSIZE may be defined by the user, but the default here
 * should be >= NOFILE (param.h).
 */
#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	/* bits per mask */
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

/* We use a macro for fd_set so that including Sockets.h afterwards
   can work.  */
typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	/* !(defined (_POSIX_SOURCE) || defined (_WINSOCK_H) || defined (__USE_W32_SOCKETS)) */


#ifndef __clockid_t_defined
typedef __clockid_t clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef __timer_t timer_t;
#define __timer_t_defined
#endif

typedef unsigned long useconds_t;
typedef long suseconds_t;

#include <sys/features.h>

#endif  /* !__need_inttypes */

#undef __need_inttypes

#endif	/* _SYS_TYPES_H */
