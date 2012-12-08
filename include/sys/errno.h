/* errno is not a global variable, because that would make using it
   non-reentrant.  Instead, its address is returned by the function
   __errno.  */

#ifndef _SYS_ERRNO_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYS_ERRNO_H_

#include <sys/reent.h>

#ifndef _REENT_ONLY
#define errno (*__errno())
extern int *__errno _PARAMS ((void));
#endif

/* Please don't use these variables directly.
   Use strerror instead. */
extern __IMPORT _CONST char * _CONST _sys_errlist[];
extern __IMPORT int _sys_nerr;

#define __errno_r(ptr) ((ptr)->_errno)

#include <os/errno.h>
#define	ENOMSG 35	/* No message of desired type */
#define	EIDRM 36	/* Identifier removed */
#define	EDEADLK 45	/* Deadlock condition */
#define	ENOLCK 46	/* No record locks available */
#define ENOSTR 60	/* Device not a stream */
#define ENODATA 61	/* No data (for no delay io) */
#define ETIME 62	/* Timer expired */
#define ENOSR 63	/* Out of streams resources */
#define ENOLINK 67	/* The link has been severed */
#define EPROTO 71	/* Protocol error */
#define	EMULTIHOP 74	/* Multihop attempted */
#define EBADMSG 77	/* Trying to read unreadable message */
#define EFTYPE 79	/* Inappropriate file type or format */
#define ENOSYS 88	/* Function not implemented */
#define ENOTEMPTY 90	/* Directory not empty */
#define ENAMETOOLONG 91	/* File or path name too long */
#define ELOOP 92	/* Too many symbolic links */
#define EOPNOTSUPP 95	/* Operation not supported on transport endpoint */
#define EPFNOSUPPORT 96 /* Protocol family not supported */
#define ECONNRESET 104  /* Connection reset by peer */
#define ENOBUFS 105	/* No buffer space available */
#define EAFNOSUPPORT 106 /* Address family not supported by protocol family */
#define EPROTOTYPE 107	/* Protocol wrong type for socket */
#define ENOTSOCK 108	/* Socket operation on non-socket */
#define ENOPROTOOPT 109	/* Protocol not available */
#define ECONNREFUSED 111	/* Connection refused */
#define EADDRINUSE 112		/* Address already in use */
#define ECONNABORTED 113	/* Connection aborted */
#define ENETUNREACH 114		/* Network is unreachable */
#define ENETDOWN 115		/* Network interface is not configured */
#define ETIMEDOUT 116		/* Connection timed out */
#define EHOSTDOWN 117		/* Host is down */
#define EHOSTUNREACH 118	/* Host is unreachable */
#define EINPROGRESS 119		/* Connection already in progress */
#define EALREADY 120		/* Socket already connected */
#define EDESTADDRREQ 121	/* Destination address required */
#define EMSGSIZE 122		/* Message too long */
#define EPROTONOSUPPORT 123	/* Unknown protocol */
#define EADDRNOTAVAIL 125	/* Address not available */
#define ENETRESET 126
#define EISCONN 127		/* Socket is already connected */
#define ENOTCONN 128		/* Socket is not connected */
#define ETOOMANYREFS 129
#define EDQUOT 132
#define ESTALE 133
#define ENOTSUP 134		/* Not supported */
#define EILSEQ 138
#define EOVERFLOW 139	/* Value too large for defined data type */
#define ECANCELED 140	/* Operation canceled */
#define ENOTRECOVERABLE 141	/* State not recoverable */
#define EOWNERDEAD 142	/* Previous owner died */
#define EWOULDBLOCK EAGAIN	/* Operation would block */

#define __ELASTERROR 2000	/* Users can add values starting here */

#ifdef __cplusplus
}
#endif
#endif /* _SYS_ERRNO_H */
