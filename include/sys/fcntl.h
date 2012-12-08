#ifndef	_SYS_FCNTL_H_
#ifdef __cplusplus
extern "C" {
#endif
#define	_SYS_FCNTL_H_
#include <os/fcntl.h>

#ifndef	_POSIX_SOURCE
/*
 * Flags that work for fcntl(fd, F_SETFL, FXXXX)
 */
#define	FAPPEND		_FAPPEND
#define	FSYNC		_FSYNC
#define	FASYNC		_FASYNC
#define	FNBIO		_FNBIO
#define	FNONBIO		_FNONBLOCK	/* XXX fix to be NONBLOCK everywhere */
#define	FNDELAY		_FNDELAY

/*
 * Flags that are disallowed for fcntl's (FCNTLCANT);
 * used for opens, internal state, or locking.
 */
#define	FREAD		_FREAD
#define	FWRITE		_FWRITE
#define	FMARK		_FMARK
#define	FDEFER		_FDEFER
#define	FSHLOCK		_FSHLOCK
#define	FEXLOCK		_FEXLOCK

/*
 * The rest of the flags, used only for opens
 */
#define	FOPEN		_FOPEN
#define	FCREAT		_FCREAT
#define	FTRUNC		_FTRUNC
#define	FEXCL		_FEXCL
#define	FNOCTTY		_FNOCTTY

#endif	/* !_POSIX_SOURCE */

struct flock {
	short	l_type;		/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	l_whence;	/* flag to choose starting offset */
	long	l_start;	/* relative offset, in bytes */
	long	l_len;		/* length, in bytes; 0 means lock to EOF */
	short	l_pid;		/* returned with F_GETLK */
	short	l_xxx;		/* reserved for future use */
};

#ifndef	_POSIX_SOURCE
/* extended file segment locking set data type */
struct eflock {
	short	l_type;		/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	l_whence;	/* flag to choose starting offset */
	long	l_start;	/* relative offset, in bytes */
	long	l_len;		/* length, in bytes; 0 means lock to EOF */
	short	l_pid;		/* returned with F_GETLK */
	short	l_xxx;		/* reserved for future use */
	long	l_rpid;		/* Remote process id wanting this lock */
	long	l_rsys;		/* Remote system id wanting this lock */
};
#endif	/* !_POSIX_SOURCE */


#include <sys/types.h>
#include <sys/stat.h>		/* sigh. for the mode bits for open/creat */

extern int open _PARAMS ((const char *, int, ...));
extern int creat _PARAMS ((const char *, mode_t));
extern int fcntl _PARAMS ((int, int, ...));

/* Provide _<systemcall> prototypes for functions provided by some versions
   of newlib.  */
#ifdef _COMPILING_NEWLIB
extern int _open _PARAMS ((const char *, int, ...));
extern int _fcntl _PARAMS ((int, int, ...));
#ifdef __LARGE64_FILES
extern int _open64 _PARAMS ((const char *, int, ...));
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif	/* !_SYS_FCNTL_H_ */
