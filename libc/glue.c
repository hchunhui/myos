/*
 * glue.c -- all the code to make GCC and the libraries run on
 *           a bare target board. These should work with any
 *           target if inbyte() and outbyte() exist.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <_ansi.h>
#include <errno.h>

#ifdef __NO_UNDERSCORE__
#  define _end    end
#endif

extern caddr_t _end;                /* _end is set in the linker command file */
extern int  _EXFUN (outbyte, (char x));
extern char _DEFUN_VOID (inbyte);
extern int  _DEFUN_VOID (havebyte);

/* just in case, most boards have at least some memory */
#ifndef RAMSIZE
#  define RAMSIZE             (caddr_t)0x100000
#endif

typedef void (*ExceptionHook)(int);   /* pointer to function with int parm */
typedef void (*Function)();           /* pointer to a function */

ExceptionHook exceptionHook;  /* hook variable for errors/exceptions */

/*
 * read  -- read bytes from the serial port. Ignore fd, since
 *          we only have stdin.
 */
int
_DEFUN (read, (fd, buf, nbytes),
       int fd _AND
       char *buf _AND
       int nbytes)
{
  int i = 0;

  for (i = 0; i < nbytes; i++) {
    *(buf + i) = inbyte();
    if ((*(buf + i) == '\n') || (*(buf + i) == '\r')) {
      (*(buf + i)) = 0;
      break;
    }
  }
  return (i);
}

/*
 * write -- write bytes to the serial port. Ignore fd, since
 *          stdout and stderr are the same. Since we have no filesystem,
 *          open will only return an error.
 */
int
_DEFUN (write, (fd, buf, nbytes),
       int fd _AND
       char *buf _AND
       int nbytes)
{
  int i;

  for (i = 0; i < nbytes; i++) {
    if (*(buf + i) == '\n') {
      outbyte ('\r');
    }
    outbyte (*(buf + i));
  }
  return (nbytes);
}

/*
 * open -- open a file descriptor. We don't have a filesystem, so
 *         we return an error.
 */
int
_DEFUN (open, (buf, flags, mode),
       const char *buf _AND
       int flags _AND
       int mode)
{
  errno = EIO;
  return (-1);
}

/*
 * close -- close a file descriptor. We don't need
 *          to do anything, but pretend we did.
 */
int
_DEFUN (close ,(fd),
       int fd)
{
  return (0);
}

/*
 * sbrk -- changes heap size size. Get nbytes more
 *         RAM. We just increment a pointer in what's
 *         left of memory on the board.
 */
caddr_t
_DEFUN (sbrk, (nbytes),
       int nbytes)
{
  static caddr_t heap_ptr = NULL;
  caddr_t        base;

  if (heap_ptr == NULL) {
    heap_ptr = (caddr_t)&_end;
  }

  if ((RAMSIZE - heap_ptr) >= 0) {
    base = heap_ptr;
    heap_ptr += nbytes;
    return (heap_ptr);
  } else {
    errno = ENOMEM;
    return ((caddr_t)-1);
  }
}

/*
 * isatty -- returns 1 if connected to a terminal device,
 *           returns 0 if not. Since we're hooked up to a
 *           serial port, we'll say yes _AND return a 1.
 */
int
_DEFUN (isatty, (fd),
       int fd)
{
  return (1);
}

/*
 * lseek -- move read/write pointer. Since a serial port
 *          is non-seekable, we return an error.
 */
off_t
_DEFUN (lseek, (fd,  offset, whence),
       int fd _AND
       off_t offset _AND
       int whence)
{
  errno = ESPIPE;
  return ((off_t)-1);
}

/*
 * fstat -- get status of a file. Since we have no file
 *          system, we just return an error.
 */
int
_DEFUN (fstat, (fd, buf),
       int fd _AND
       struct stat *buf)
{
  errno = EIO;
  return (-1);
}

/*
 * getpid -- only one process, so just return 1.
 */
#define __MYPID 1
int
_DEFUN (getpid, (),
        )
{
  return __MYPID;
}

/*
 * kill -- assume mvme.S, and go out via exit...
 */
int
_DEFUN (kill, (pid, sig),
        int pid _AND 
        int sig)
{
  if(pid == __MYPID)
    _exit(sig);
  return 0;
}

