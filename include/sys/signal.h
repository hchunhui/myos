/* sys/signal.h */

#ifndef _SYS_SIGNAL_H
#define _SYS_SIGNAL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "_ansi.h"
#include <sys/features.h>
#include <sys/types.h>
#include <os/signal.h>
typedef unsigned long sigset_t;
typedef void (*_sig_func_ptr)(int);
struct sigaction 
{
	_sig_func_ptr sa_handler;
	sigset_t sa_mask;
	int sa_flags;
};

#define SIG_SETMASK 0	/* set mask with sigprocmask() */
#define SIG_BLOCK 1	/* set of signals to block */
#define SIG_UNBLOCK 2	/* set of signals to, well, unblock */

#define sigaddset(what,sig) (*(what) |= (1<<(sig)), 0)
#define sigdelset(what,sig) (*(what) &= ~(1<<(sig)), 0)
#define sigemptyset(what)   (*(what) = 0, 0)
#define sigfillset(what)    (*(what) = ~(0), 0)
#define sigismember(what,sig) (((*(what)) & (1<<(sig))) != 0)

int _EXFUN(sigprocmask, (int how, const sigset_t *set, sigset_t *oset));
int _EXFUN(kill, (pid_t, int));
int _EXFUN(killpg, (pid_t, int));
int _EXFUN(sigaction, (int, const struct sigaction *, struct sigaction *));
int _EXFUN(sigpending, (sigset_t *));
int _EXFUN(sigsuspend, (const sigset_t *));
int _EXFUN(sigpause, (int));

#ifdef __cplusplus
}
#endif

#ifndef _SIGNAL_H_
/* Some applications take advantage of the fact that <sys/signal.h>
 * and <signal.h> are equivalent in glibc.  Allow for that here.  */
#include <signal.h>
#endif
#endif /* _SYS_SIGNAL_H */
