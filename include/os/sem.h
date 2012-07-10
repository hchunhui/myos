#ifndef _SEM_H_
#define _SEM_H_

#include <lib/list.h>

struct s_sem
{
	int val;
	struct list_head wait;
};

typedef struct s_sem sem_t;

#define SEM_INIT(_val) { \
   .val = _val, \
   .wait = LIST_HEAD_INIT(.wait) }

void sem_init(sem_t *sem, int val);
void sem_up(sem_t *sem);
void sem_down(sem_t *sem);
int sem_trydown(sem_t *sem);
void sem_force_down(sem_t *sem);
#endif /* _SEM_H_ */
