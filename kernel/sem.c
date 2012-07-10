#include <os/task.h>
#include <os/sem.h>
#include <os/asm.h>
#include <lib/list.h>
#include <lib/klib.h>

struct s_tq
{
	struct list_head list;
	struct s_task *task;
	volatile int up;
};

void sem_init(sem_t *sem, int val)
{
	sem->val = val;
	INIT_LIST_HEAD(&sem->wait);
}

void sem_up(sem_t *sem)
{
	struct s_tq *tq;
	sem->val++;
	if(sem->val <= 0)
	{
		tq = list_entry(sem->wait.next, struct s_tq, list);
		list_del(sem->wait.next);
		tq->up = 1;
		tq->task->state = TASK_STAT_READY;
		current->resched = 1;
	}
}

void sem_down(sem_t *sem)
{
	struct s_tq *tq;
	disable_irq();
	sem->val--;
	if(sem->val < 0)
	{
		tq = kmalloc(sizeof(struct s_tq));
		tq->task = current;
		tq->up = 0;
		list_add_tail(&tq->list, &sem->wait);
		while(!tq->up) {
			current->state = TASK_STAT_BLOCK;
			task_sched();
		}
		//printk("i am up, pid=%d\n", current->pid);
		kfree(tq);
	}
	enable_irq();
}

int sem_trydown(sem_t *sem)
{
	if(sem->val <= 0)
		return 0;
	sem_down(sem);
	return 1;
}

/* buggy */
void sem_force_down(sem_t *sem)
{
	disable_irq();
	if(sem->val > 0)
		sem->val = 0;
	enable_irq();
	sem_down(sem);
}
