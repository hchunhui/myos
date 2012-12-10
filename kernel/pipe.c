#include <lib/klib.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <os/asm.h>

#define PIPE_SIZE 1024
struct s_pipe {
	char buf[PIPE_SIZE];
	int fp, ep;
#if 0
	sem_t read;
	sem_t write;
#else
	int count;
	sem_t empty;
	struct list_head poll_read;
#endif
};

static int pipe_init()
{
	printk("pipe up\n");
	return 0;
}

static int pipe_exit()
{
	printk("pipe down\n");
	return 0;
}

static int pipe_open(int minor, int mode, void **data)
{
	struct s_pipe *pipe;
	pipe = kmalloc(sizeof(struct s_pipe));
	pipe->fp = 0;
	pipe->ep = 0;
#if 0
	sem_init(&pipe->read, 0);
	sem_init(&pipe->write, PIPE_SIZE);
#else
	pipe->count = 0;
	sem_init(&pipe->empty, 0);
	INIT_LIST_HEAD(&pipe->poll_read);
#endif
	*data = pipe;
	return 0;
}

static int pipe_close(int minor, void *data)
{
	kfree(data);
	return 0;
}

static int pipe_ctl(int minor, void *data, int cmd, void *arg)
{
	switch(cmd)
	{
		
	}
	return 0;
}

static long pipe_read(int minor, void *data, void *buf, long n, long off)
{
	int read;
	struct s_pipe *pipe;
	char *cbuf;
	struct poll_sem *upsem;
	cbuf = buf;
	pipe = data;
#if 0
	sem_down(&pipe->read);
	*cbuf++ = pipe->buf[pipe->fp];
	pipe->fp = (pipe->fp + 1)%PIPE_SIZE;
	sem_up(&pipe->write);
	for(read = 1; read < n; read++)
	{
		if(!sem_trydown(&pipe->read))
			break;
		*cbuf++ = pipe->buf[pipe->fp];
		pipe->fp = (pipe->fp + 1)%PIPE_SIZE;
		sem_up(&pipe->write);
	}
#else
	while(pipe->count == 0)
		sem_down(&pipe->empty);
	for(read = 0; read < n && pipe->count; read++, pipe->count--)
	{
		*cbuf++ = pipe->buf[pipe->fp];
		pipe->fp = (pipe->fp + 1)%PIPE_SIZE;
	}
	if(pipe->count)
	{
		list_for_each_entry(upsem, &pipe->poll_read, list)
		{
			sem_up(upsem->sem);
		}
	}
#endif
	return read;
}

static long pipe_write(int minor, void *data, void *buf, long n, long off)
{
	int write;
	struct s_pipe *pipe;
	struct poll_sem *upsem;
	char *cbuf;
	int up;
	cbuf = buf;
	pipe = data;
#if 0
	for(write = 0; write < n; write++)
	{
		if(!sem_trydown(&pipe->write))
			break;
		pipe->buf[pipe->ep] = *cbuf++;
		pipe->ep = (pipe->ep + 1)%PIPE_SIZE;
		sem_up(&pipe->read);
	}
#else
	if(n && pipe->count == 0)
		up = 1;
	else
		up = 0;
	for(write = 0;
	    write < n && pipe->count < PIPE_SIZE;
	    write++, pipe->count++)
	{
		pipe->buf[pipe->ep] = *cbuf++;
		pipe->ep = (pipe->ep + 1)%PIPE_SIZE;
	}
	if(up)
	{
		sem_up(&pipe->empty);
		list_for_each_entry(upsem, &pipe->poll_read, list)
		{
			sem_up(upsem->sem);
		}
	}
#endif
	return write;
}

static int pipe_poll(int minor, void *data, int func, struct list_head *lsem)
{
	struct s_pipe *pipe;
	pipe = data;
	switch(func)
	{
	case POLL_FUNC_READABLE:
		return pipe->count;
	case POLL_FUNC_WRITEABLE:
		return PIPE_SIZE -pipe->count;
	case POLL_FUNC_REGISTER:
		disable_irq();
		list_add_tail(lsem, &pipe->poll_read);
		enable_irq();
		return 0;
	case POLL_FUNC_UNREGISTER:
		disable_irq();
		list_del(lsem);
		enable_irq();
		return 0;
	}
	return -1;
}

struct dev_desc pipe_dev_desc = {
	.name = "pipe",
	.init = pipe_init,
	.exit = pipe_exit,
	.open = pipe_open,
	.close = pipe_close,
	.ctl = pipe_ctl,
	.read = pipe_read,
	.write = pipe_write,
	.poll = pipe_poll,
};
