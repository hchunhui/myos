#ifndef _FORK_H_
#define _FORK_H_

long do_fork(unsigned long pc, unsigned int flags);
#define FORK_SHARE_MM 1
#define FORK_WAIT_EXEC_EXIT 2
#define FORK_VFORK (FORK_SHARE_MM | FORK_WAIT_EXEC_EXIT)

#endif /* _FORK_H_ */
