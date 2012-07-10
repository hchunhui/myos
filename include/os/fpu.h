#ifndef _FPU_H_
#define _FPU_H_
struct s_fpu;
struct s_task;

void fpu_fork(struct s_task *child, struct s_task *father);

void fpu_exit(struct s_task *ptask);

void fpu_init(struct s_task *ptask);

void fpu_switch(struct s_task *prev, struct s_task *next);

#endif
