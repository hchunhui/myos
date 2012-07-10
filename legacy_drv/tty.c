#include <drv/tty.h>
#include <os/task.h>
#include <os/type.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/protect.h>
#include <os/asm.h>


#define ESCAPE_LEN 16
#define ESC 0x1b

#define USE_BACKUP


struct s_tty
{
	u32 start_addr;
	int cpos;
	char escape[ESCAPE_LEN];
	char *esc_ptr;
	int in_escape;
};

static struct s_tty tty[NR_TTY];
static int tty_now=0;
static int is_setup;

#ifdef USE_BACKUP
u8 buffer[video_text_len];
#endif

static struct s_queue r_queue[NR_TTY];


void drv_tty_put_rqueue(struct s_task *ptask)
{
	struct s_queue *pq = &(r_queue[ptask->tty_nr]);
	*(pq->q++)=ptask;
	if(pq->q > &(pq->ptask[NR_TASK-1]))
		pq->q = &(pq->ptask[0]);
}

void drv_tty_wakeup()
{
	if(tty_now>=NR_TTY)return;
	struct s_queue *pq = &(r_queue[tty_now]);
	if(pq->p == pq->q)
	{
		//printk("tty_wakeup\n");
		return;
	}
	struct s_task *ptask=*(pq->p);
	if(ptask->state == TASK_STAT_BLOCK)
	{
		//printk("drv_tty: wake up pid:%d\n",ptask->pid);
		ptask->state=TASK_STAT_READY;
		pq->p++;
		if(pq->p > &(pq->ptask[NR_TASK-1]))
			pq->p = &(pq->ptask[0]);
	}
}

int drv_tty_now()
{
	return tty_now;
}

int drv_tty_is_setup()
{
	return is_setup;
}

void drv_tty_init()
{
	int i;
	printk("drv_tty_init: begin.\n");
	for(i=0;i<NR_TTY;i++)
	{
		tty[i].start_addr=i*4096;
		tty[i].cpos=i*4096;
		tty[i].escape[0]=0;
		tty[i].esc_ptr=tty[i].escape;
		tty[i].in_escape=0;
	}
	tty_now=0;
	tty[0].cpos=drv_video_get_cpos();
	#ifdef USE_BACKUP
	memcpy(buffer,(u8 *)video_text_base_addr,video_text_len);
	#endif
	is_setup=1;
	
	for(i=0;i<NR_TTY;i++)
	{
		r_queue[i].p=&(r_queue[i].ptask[0]);
		r_queue[i].q=r_queue[i].p;
	}
	printk("drv_tty_init: end.\n");
}

void drv_tty_switch(int nr)
{
	int vmode=video_text_mode;
	if(nr>=NR_TTY)vmode=video_graph_mode;
	if(nr<0)return;
	drv_kb_lock();
	drv_video_set_mode(vmode);
	if(tty_now < NR_TTY && tty_now >=0)
	{
		tty[tty_now].start_addr=drv_video_get_start_addr();
		tty[tty_now].cpos=drv_video_get_cpos();
	}
	while( !drv_kb_emptybuf() )drv_kb_getbuf();	//清空输入缓冲区
	tty_now=nr;
	if(nr>=NR_TTY)
	{
		goto end;
	}
	#ifdef USE_BACKUP
	//memcpy((u8 *)video_text_base_addr,buffer,video_text_len);
	memcpy((u8 *)(video_text_base_addr+nr*4096*2),(u8 *)(buffer+nr*4096*2),4096*2);
	#endif
	drv_video_set_base_addr(nr*4096);
	drv_video_set_start_addr(tty[nr].start_addr);
	drv_video_set_cpos(tty[nr].cpos);
end:	drv_kb_unlock();
}

static void drv_tty_putchar(int nr,unsigned char x,int attr)
{
	#ifdef USE_BACKUP
	u16 *video_base=(u16 *)buffer;
	#else
	u16 *video_base=(u16 *)video_text_base_addr;
	#endif
	int base_addr=nr*4096;
	drv_kb_lock();
	if(nr>=NR_TTY || nr<0)goto end;
	if(nr==tty_now)
	{
		drv_video_putchar(x,attr);
		#ifdef USE_BACKUP
		#else
		goto end;
		#endif
	}
	if(x=='\n')
	{
		tty[nr].cpos+=80-( (tty[nr].cpos-base_addr)%80 );
		goto quit;
	}
	if(x=='\b')
	{
		tty[nr].cpos--;
		*(video_base+tty[nr].cpos)=(attr<<8)|' ';
		goto quit;
	}
	*(video_base+tty[nr].cpos)=(attr<<8)|x;
	tty[nr].cpos++;
quit:	
	if(tty[nr].cpos>=( base_addr +80*25*2))
	{
		int i;
		u32 sa=(u32)video_base+tty[nr].start_addr*2;
		u32 da=(u32)video_base+base_addr*2;

		memcpy(da, sa, 80*25*2);
		for(i = 0; i < 80*25; i++)
		{
			((u16 *)sa)[i] = (CHAR_ATTR<<8);
		}
		/* asm volatile ( */
		/* "cld;rep movsl" */
		/* ::"S"(sa),"D"(da),"c"(80*25*2/4):"memory"); */
		/* asm volatile ( */
		/* "cld;rep stosl" */
		/* ::"a"((CHAR_ATTR<<8)|(CHAR_ATTR<<24)),"D"(sa),"c"(80*25*2/4):"memory"); */
		tty[nr].cpos=base_addr+80*25;
		tty[nr].start_addr=base_addr;
	}
	if(tty[nr].cpos>=(tty[nr].start_addr+80*25))tty[nr].start_addr+=80;
end:	drv_kb_unlock();
}

int drv_tty_read(int tty_nr,void* buf,s32 count)
{
	if(tty_nr>=NR_TTY || tty_nr<0)return count;
	if(tty_nr!=tty_now)return count;

	while((!drv_kb_emptybuf()) && count)
	{
		*(char*)(buf++)=drv_kb_getbuf();
		count--;
	}
	return count;
}

#define isalpha(c) ( ( (c) >='a' && (c) <='z') || ( (c) >='A' && (c) <='Z') )

static void drv_tty_esc_handler(int tty_nr,char *seq)
{
	
}

int drv_tty_write(int tty_nr,void* buf,s32 count,int mode)
{
	if(tty_nr>=NR_TTY || tty_nr<0)return count;
	char c;
	while(count)
	{
		if(*(char*)buf==ESC)
		{
			printk("drv_tty_write: esc down\n");
			tty[tty_nr].in_escape=1;
			tty[tty_nr].esc_ptr=tty[tty_nr].escape;
			goto next_loop;
		}
		if(tty[tty_nr].in_escape)
		{
			*tty[tty_nr].esc_ptr++=*(char*)buf;
			c=*(char*)buf;
			if(isalpha(c))
			{
				tty[tty_nr].in_escape=0;
				printk("drv_tty_write: esc end\n");
				*tty[tty_nr].esc_ptr='\0';
				drv_tty_esc_handler(tty_nr,tty[tty_nr].escape);
			}
			buf++;
			goto next_loop;
		}
		
		drv_tty_putchar(tty_nr,*(char*)(buf++),mode);
		
	next_loop:
		count--;
	}
	return count;
}

void drv_tty_goxy(int tty_nr,int x,int y)
{
	if(tty_nr>=NR_TTY || tty_nr<0)return;
	if(tty_nr==tty_now)drv_video_goxy(x,y);
	if(x<=0 || x>25 || y<=0 || y>80)return;
	tty[tty_nr].cpos=tty[tty_nr].start_addr+(80*(x-1)+y-1);
}


