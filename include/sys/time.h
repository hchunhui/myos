/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <_ansi.h>
#include <sys/types.h>
#include <os/type.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _TIMEVAL_DEFINED

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};


#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};


/* Convenience macros for operations on timevals.
   NOTE: `timercmp' does not work for >= or <=.  */
#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)

int _EXFUN(gettimeofday, (struct timeval *__p, void *__tz));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, const struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif /* _SYS_TIME_H_ */
