#ifndef _WAITEXIT_H_
#define _WAITEXIT_H_
#define WNOHANG		(1<<0)
#define WUNTRACED	(1<<1)

int do_waitpid(int pid, int *status, int options);
int do_exit(int exit_code);

#endif /* _WAITEXIT_H_ */
