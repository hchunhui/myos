#ifndef _MM_H_
#define _MM_H_
#include <os/type.h>
#include <os/task.h>
typedef struct s_pde pde_t;
typedef unsigned long pte_t;

unsigned long mm_get_free_page();/* 返回页号 */
void mm_recycle_page(unsigned long pg_no);
void mm_fork(struct s_task *task_new, struct s_task *task_old, unsigned int flags);
void mm_exit(struct s_task *ptask);
void mm_share_page(unsigned long phy_pg, unsigned long logi_pg, int flag);
void mm_remove_share_page(unsigned long phy_pg, unsigned long logi_pg);
void mm_set_page_info_attr(unsigned long phy_pg, u16 flags);
#define MM_PI_SHARE	1
void mm_change_page(int pid);
void mm_refresh_page();
void mm_switch(struct s_task *prev, struct s_task *next);

#define MM_RW 1
#endif
