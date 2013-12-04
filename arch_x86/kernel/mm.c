#include <os/type.h>
#include <os/arch_config.h>
#include <os/mm.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/asm.h>
#include <os/shm.h>
#include <os/isr.h>
#include <os/waitexit.h>

/* 386 PDE && PTE */
struct s_pde
{
	unsigned long addr_attr[PDE_COUNT];
}__attribute__((packed));

struct s_mm
{
	pde_t *pd;
	int ref;
};

/* struct s_mm */
/* { */
/* 	pde_t *pd; */
/* 	struct s_vma *vma; */
/* }; */

/* struct s_vma */
/* { */
/* 	char name[16]; */
/* 	struct s_vma *next; */
/* 	unsigned long vaddr; */
/* 	unsigned long paddr; */
/* 	unsigned long len; */
/* 	unsigned int flag; */
/* 	int count; */
/* }; */
/* #define VMA_USR */
/* #define VMA_RW */
/* #define VMA_IOMAP */

/* struct s_vma *vma_global; */

/* int vma_map(pde_t *pd, struct s_vma *vma) */
/* { */
/* 	if(vma->vaddr & PAGE_MASK || */
/* 	   vma->paddr & PAGE_MASK || */
/* 	   vma->len & PAGE_MASK) */
/* 		panic("vma_map: addr or len not align\n"); */
	
	
/* } */

/* int vma_add(struct s_vma **plist, struct s_vma *vma) */
/* { */
/* 	struct s_vma *list = *plist; */
/* 	struct s_vma *prev = NULL; */
/* 	if(list == NULL) */
/* 	{ */
/* 		*plist = vma; */
/* 		return 0; */
/* 	} */
/* 	for(; list; prev = list, list = list->next) */
/* 	{ */
/* 		if(vma->vaddr + len <= list->vaddr) */
/* 		{ */
/* 			if(prev) */
/* 				perv->next = vma; */
/* 			else */
/* 				*plist = vma; */
/* 			vma->next = list; */
/* 			vma->count++; */
/* 			return 0; */
/* 		} */
/* 		if(list->vaddr + len > vma->addr) */
/* 			break; */
/* 	} */
/* 	return 1; */
/* } */

#define PA_P			(1<<0)
#define PA_RW			(1<<1)
#define PA_US			(1<<2)
#define PA_PWT			(1<<3)
#define PA_PCD			(1<<4)
#define PA_A			(1<<5)
		/*this bit reseved*/
#define PA_PS			(1<<7)
#define PA_G			(1<<8)

#define ADDR_ATTR(addr, attr) ((addr) | (attr))
#define ADDR(addr_attr) ((addr_attr) & PAGE_MASK)
#define ATTR(addr_attr) ((addr_attr) & (~PAGE_MASK))
#define NO2ADDR(no) ((no)<<PAGE_SHIFT)
#define ADDR2NO(addr) ((addr)>>PAGE_SHIFT)
#define for_each_user_pde(i) for(i = ADDR2NO(kernel_brk)/PDE_COUNT; i < max_usr_pde; i++)
#define for_each_kern_pde(i) for(i = 0; i < ADDR2NO(kernel_brk)/PDE_COUNT; i++)

#define pte_mem_stack_len	PDE_COUNT

/* asm */
#define change_page(pde_addr)	\
	asm volatile ("movl %0,%%cr3"::"a"(pde_addr))
#define refresh_page()		\
	asm volatile ("movl %%cr3,%%eax; movl %%eax,%%cr3":::"eax");
#define enable_page()	\
	asm volatile (					\
	"movl %%cr0,%%eax\n\t"			\
	"orl $0x80000000,%%eax\n\t"		\
	"movl %%eax,%%cr0\n\t"			\
	"jmp 1f\n"						\
	"1:\tnop"						\
	:::"eax"						\
	)
#define disable_page()	\
	asm volatile (					\
	"movl %%cr0,%%eax\n\t"			\
	"andl $0x7fffffff,%%eax\n\t"	\
	"movl %%eax,%%cr0\n\t"			\
	"jmp 1f\n"						\
	"1:\tnop"						\
	:::"eax"						\
	)

/* page_info */
struct s_page_info
{
	u16 count;
	u16 flags;
} __attribute__ ((packed));

/* page table */
static pte_t *pte = (void*)page_table_addr;	/* 共1024*1024项 */
static unsigned long pte_mem_stack[pte_mem_stack_len+1];
static int stack_p;

/* memory size */
static unsigned int mem_size;

/* page info */
static struct s_page_info *page_info = (void*)page_info_addr;
static unsigned long page_info_size;

static struct s_regs *gpregs;

static unsigned long pop_pte_mem()		/* 返回页号 */
{
	if(stack_p <= 0)
		panic("pte mem stack underflow");
	
	return pte_mem_stack[stack_p--];
}

static void push_pte_mem(unsigned long pg_no)
{
	/* check */
	stack_p++;
	if(stack_p >= pte_mem_stack_len + 1)
		panic("pte mem stack overflow");
	
	pte_mem_stack[stack_p] = pg_no;
}

static void mm_set_pte(pde_t *pd,
		unsigned long phy_pg_no,
		unsigned long logi_pg_no,
		unsigned int _flag)
{
	/* no check */
	unsigned long pte_no;
	pte_t *pte_addr;
	unsigned int flag = (_flag == MM_RW ? PA_RW : 0);

	if(pd->addr_attr[logi_pg_no/PDE_COUNT] == 0)
	{
		pte_no = pop_pte_mem();
		memset((unsigned long*)(pte_no<<PAGE_SHIFT),
		       0,
		       PTE_COUNT * sizeof(pte_t));
		pd->addr_attr[logi_pg_no/PDE_COUNT] =
			(pte_no<<PAGE_SHIFT) | PA_P | flag | PA_US;
	}
	else
	{
		pte_no = pd->addr_attr[logi_pg_no/PDE_COUNT]>>PAGE_SHIFT;
	}
	
	pte_addr = (void*)((pte_no<<12) +
			   sizeof(unsigned long)*(logi_pg_no&0x3ff));
	if(*pte_addr != 0)
		panic("mm_set_pte: logic page have already assigned.");
	*pte_addr = (phy_pg_no<<12) | PA_P | flag | PA_US;
}

static unsigned long mm_reset_pte(pde_t *pd, unsigned long logi_pg_no)
{
	unsigned long pte_no;
	unsigned long *pte_addr;
	unsigned long phy_pg_no;
	
	if(pd->addr_attr[logi_pg_no>>10] == 0)
	{
		panic("mm_reset_pte: no pde.");
	}
	
	pte_no = pd->addr_attr[logi_pg_no>>10]>>12;
	pte_addr = (void*)((pte_no<<12) +
			   sizeof(unsigned long)*(logi_pg_no&0x3ff));
	
	phy_pg_no = (*pte_addr) >> 12;
	*pte_addr  = 0;
	return phy_pg_no;
}

static void mm_panic(char *reason, unsigned long cr2)
{
	struct s_task *ptask = current;
	unsigned long err_code = gpregs->err_code;
	struct s_regs *pregs;

	pregs = get_user_regs(ptask);
	print = print_early;
	printk("mm panic:\n%s:\n"
		"CR2: 0x%x\n"
		"err_code: 0x%x\n"
		"EIP: 0x%x\n"
		"pid: %d\n"
		"kebp: 0x%x\n"
		"keip: 0x%x\n",
		reason,
		cr2,
		err_code,
		pregs->ip,
		ptask->pid,
	       (unsigned long)gpregs,
	       gpregs->ip);
	printk("memdump:\n");
	unsigned long i;
	for(i = pregs->ip-20; i < pregs->ip+20; i++)
	{
		printk("%x ", *(u8*)(i));
	}
	panic("mm");
}

/* linar address to phy page number */
static unsigned long la2pn(unsigned long la)
{
	pde_t *pd;
	unsigned long pde_no;
	unsigned long *ppte;

	pd = current->mm->pd;
	
	pde_no = ADDR2NO(la)/PDE_COUNT;
	if((pd->addr_attr[pde_no]&PA_P) == 0)
		panic("mm: la2pa: no pte");
	ppte = (void*)ADDR(pd->addr_attr[pde_no]);
	
	if(((*ppte)&PA_P) == 0)
		panic("mm: la2pa: la not present");
	
	return ADDR2NO(*ppte);
}

int do_page_fault(struct s_regs *pregs)
{
	unsigned long cr2;
	struct s_task *ptask = current;
	unsigned long err_code;
	unsigned long phy_pg_no;

	asm ("movl %%cr2, %%eax; movl %%eax, %0":"=m"(cr2)::"eax");
	
	gpregs = pregs;
	err_code = pregs->err_code;
	/* err_code
	 * b4   b3   b2   b1   b0
	 * I/D  RSVD U/S  W/R  P   
	 */
	 
	/* check error type */
	if(!(err_code&4) && cr2 < kernel_brk)
	{
		mm_panic("kernel memory error", cr2);
	}
	
	if(err_code&1)
	{
		if(err_code&2)
		{
			/* check page attr */
			if(page_info[la2pn(cr2)].flags & MM_PI_SHARE)
			{
				/* write a read-only shared page */
				mm_panic("write a read-only shared page", cr2);
			}
			else
			{
				/* Copy On Write */
				mm_panic("Copy On Write not implement!", cr2);
			}
		}
		else
		{
			mm_panic("error when read a page", cr2);
		}
	}
	/* check range */
	if(cr2 > ptask->brk && cr2 < (usr_stack_top-ptask->stack_size))
	{
		mm_panic("try to access illegal space", cr2);
	}

	/* FIXME */
	if(cr2 > usr_stack_top)
		phy_pg_no = ADDR2NO(cr2);
	else
		phy_pg_no = mm_get_free_page();
	if(phy_pg_no != -1)
		mm_set_pte(ptask->mm->pd, phy_pg_no, ADDR2NO(cr2), MM_RW);
	refresh_page();
	return 0;
}

//interfaces
void mm_recycle_page(unsigned long pg_no)
{
	if(page_info[pg_no].count == 0)
		panic("recycle a free page");
	
	page_info[pg_no].count--;
}

unsigned long mm_get_free_page()		/* 不考虑特殊情况，返回页号 */
{
	unsigned long i;
	
	for(i = 0; i < page_info_size; i++)
	{
		if(page_info[i].count == 0)
		{
			page_info[i].count = 1;
			page_info[i].flags = 0;
			return i;
		}
	}
	printk("current pid=%d, out of memory, kill\n", current->pid);
	do_exit(99);
	current->resched = 1;
	return -1;
	//panic("Mem not enough");
}

void mm_fork(struct s_task *task_new, struct s_task *task_old, unsigned int flags)
{
	pde_t *newpd, *oldpd;
	struct s_mm *oldmm, *newmm;
	int i, j;
	unsigned long new_pte_no;
	pte_t *pold_pte, *pnew_pte;
	unsigned long old_pg;
	unsigned long new_pg_no;
	
	/* 先暂时关闭分页机制，以便于进程间页面复制 */
	disable_page();
	
	if(task_new->mm)
		panic("mm_fork: newmm != NULL before fork");
	if(flags & FORK_SHARE_MM)
	{
		printk("mm_fork: share mm\n");
		task_new->mm = task_old->mm;
		task_new->mm->ref++;
		goto out;
	}
	
	/* 建立内核页表 */
	newmm = kmalloc(sizeof(struct s_mm));
	task_new->mm = newmm;
	newpd = kmalloc(PAGE_SIZE);
	newmm->pd = newpd;
	newmm->ref = 1;
	
	memset(newpd, 0, PAGE_SIZE);
	for_each_kern_pde(j)
	{
		newpd->addr_attr[j] = ADDR_ATTR(
			PAGE_SIZE*j + page_table_addr,
			PA_P | PA_RW);
	}

	if(task_old == NULL)
	{
		change_page(task_new->mm->pd);
		printk("mm_fork: new mm\n");
		goto out;
	}
	printk("mm_fork: copy mm\n");
	oldmm = task_old->mm;
	if(!oldmm)
		panic("mm_fork: oldmm == NULL");
	oldpd = oldmm->pd;
	
	/* 从用户区域开始复制 */
	for_each_user_pde(i)
	{
		if((oldpd->addr_attr[i]&PA_P) == 0)
		{
			/* not present */
			newpd->addr_attr[i] = 0;
			continue;
		}
		/* dup pde */
		new_pte_no = pop_pte_mem();
		newpd->addr_attr[i] = ADDR_ATTR(
			NO2ADDR(new_pte_no),
			ATTR(oldpd->addr_attr[i]));
		
		pold_pte = (pte_t *)ADDR(oldpd->addr_attr[i]);
		pnew_pte = (pte_t *)ADDR(newpd->addr_attr[i]);
		/* dup pte */
		for(j = 0;j < PTE_COUNT; j++, pold_pte++, pnew_pte++)
		{
			if(((*pold_pte)&PA_P) == 0)
			{
				/* not present */
				*pnew_pte = 0;
				continue;
			}
			/* detect if orginal page is shared */
			old_pg = ADDR2NO(*pold_pte);
			if(page_info[old_pg].flags & MM_PI_SHARE)
			{
				*pnew_pte = *pold_pte;
				page_info[old_pg].count++;
				printk("reach share memory\n");
			}
			else
			{
				new_pg_no = mm_get_free_page();
				if(new_pg_no == -1)
					goto out;
				*pnew_pte = ADDR_ATTR(
					NO2ADDR(new_pg_no),
					ATTR(*pold_pte));
				/* dup memory */
				memcpy(
					(void*)NO2ADDR(new_pg_no),
					(void*)ADDR(*pold_pte),
					PAGE_SIZE);
			}

		}
	}
	
	/* 重新打开分页 */
out:	enable_page();
}

void mm_exit(struct s_task *ptask)
{
	int i,j;
	struct s_mm *mm;
	pte_t *ppte;
	pde_t *ppde;
	
	mm = ptask->mm;
	mm->ref--;
	if(mm->ref)
	{
		printk("mm_exit: not delete mm\n");
		goto out;
	}
	printk("mm_exit: delete mm\n");
	ppde = mm->pd;
	
	for_each_user_pde(i)
	{
		/*present */
		if((ppde->addr_attr[i]&PA_P) == 0)
			continue;
		push_pte_mem(ADDR2NO(ppde->addr_attr[i]));
		ppte=(pte_t *)ADDR(ppde->addr_attr[i]);
		for(j = 0; j < 1024; j++, ppte++)
		{
			/* present */
			if(((*ppte)&PA_P) == 0)
				continue;
			mm_recycle_page(ADDR2NO(*ppte));
		}
		ppde->addr_attr[i] = 0;
	}
	kfree(ppde);
	kfree(mm);
out:
	ptask->mm = NULL;
}

void mm_share_page(unsigned long phy_pg, unsigned long logi_pg, int flag)
{
	int mflag = 0;
	
	if(flag & SHM_W)
		mflag = MM_RW;
	
	if(page_info[phy_pg].count == 0)
		panic("mm_share_page: page_count == 0");
	
	mm_set_pte(current->mm->pd, phy_pg, logi_pg, mflag);
	page_info[phy_pg].count++;
}

void mm_remove_share_page(unsigned long phy_pg, unsigned long logi_pg)
{
	unsigned long real_phy_pg;	
	
	real_phy_pg = mm_reset_pte(current->mm->pd, logi_pg);
	
	if(real_phy_pg != phy_pg)
		panic("mm_remove_share_page: phy_pg not equal");
	
	mm_recycle_page(phy_pg);
}

void mm_set_page_info_attr(unsigned long phy_pg, u16 flags)
{
	page_info[phy_pg].flags = flags;
}

void mm_refresh_page()
{
	refresh_page();
}

void mm_switch(struct s_task *prev, struct s_task *next)
{
	change_page(next->mm->pd);
}

void mm_init(unsigned int size)
{
	int i,j;
	mem_size = size;
	if(mem_size > usr_stack_top)
	{
		mem_size = usr_stack_top;
		printk("mm: only use %dK memory.\n", mem_size / 1024);
	}
	
	if(mem_size <= kernel_brk)
	{
		panic("Memory not enough");
	}
	
	stack_p = 0;
	
	memset(pte, 0, sizeof(unsigned long)*1024*1024);

	isr_register(14, do_page_fault);
	
	//0~16M(kernel_brk) 对等映射 for kernel
	/* for(i = 0; i < NR_TASK; i++) */
	/* { */
	/* 	for_each_kern_pde(j) */
	/* 	{ */
	/* 		pde[i].addr_attr[j] = ADDR_ATTR( */
	/* 			PAGE_SIZE*j + page_table_addr, */
	/* 			PA_P | PA_RW); */
	/* 	} */
	/* } */
	
	for_each_kern_pde(i)
	{
		for(j = 0; j < PTE_COUNT; j++)
		{
			pte[i*1024 + j] = ADDR_ATTR(
				PAGE_SIZE*(PTE_COUNT*i + j),
				PA_P | PA_RW);
		}
	}

	//init page info
	page_info_size = mem_size / PAGE_SIZE;
	memset(page_info, 0, sizeof(struct s_page_info) * page_info_size);
	for(i = 0; i < kernel_brk/PAGE_SIZE; i++)
	{
		page_info[i].count = 1;
		page_info[i].flags = 0;
	}
	
	//init pte_mem_stack
	for(i = ADDR2NO(kernel_brk)/PDE_COUNT; i < pte_mem_stack_len; i++)
	{
		push_pte_mem(ADDR2NO(page_table_addr) + i);
	}
}
