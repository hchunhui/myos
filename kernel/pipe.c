#include <lib/klib.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <os/asm.h>
#include <os/vfs.h>
#include <drv/pipe.h>
#include <os/errno.h>

#define PIPE_SIZE 1024
struct s_pipe {
	char buf[PIPE_SIZE];
	int fp, ep;
	int count;
	sem_t empty;
	struct list_head poll_read;
	sem_t semfd;
	struct s_fd *sendfd;
	int ref_count;
};

#define PORT_MAX 1024
struct s_pipe *ports[PORT_MAX+1];

static int pipe_init()
{
	return 0;
}

static int pipe_exit()
{
	return 0;
}

static int pipe_open(int minor, int mode, void **data)
{
	struct s_pipe *pipe;
	if(minor > 0 && minor <= PORT_MAX && ports[minor])
	{
		ports[minor]->ref_count++;
		*data = ports[minor];
		return 0;
	}
	pipe = kmalloc(sizeof(struct s_pipe));
	pipe->fp = 0;
	pipe->ep = 0;
	if(minor < 0)
		return -EINVAL;
	pipe->count = 0;
	sem_init(&pipe->empty, 0);
	INIT_LIST_HEAD(&pipe->poll_read);
	sem_init(&pipe->semfd, 0);
	pipe->sendfd = NULL;
	pipe->ref_count = 1;
	*data = pipe;
	if(minor > 0 && minor <= PORT_MAX)
		ports[minor] = pipe;
	return 0;
}

static int pipe_close(int minor, void *data)
{
	struct s_pipe *pipe = data;
	pipe->ref_count--;
	if(pipe->ref_count == 0)
	{
		if(pipe->sendfd)
			panic("unclean sendfd\n");
		kfree(pipe);
		if(minor > 0 && minor <= PORT_MAX)
			ports[minor] = NULL;
	}
	return 0;
}

static int pipe_ctl(int minor, void *data, int cmd, void *arg)
{
	struct s_pipe *pipe;
	int fd, *pfd;
	pipe = data;
	switch(cmd)
	{
	case PIPE_CMD_SENDFD:
		fd = (long)arg;
		if(pipe->sendfd)
			return -1;
		pipe->sendfd = vfs_sendfd(fd);
		sem_up(&pipe->semfd);
		return 0;
		break;
	case PIPE_CMD_RECVFD:
		pfd = arg;
		sem_down(&pipe->semfd);
		fd = vfs_recvfd(pipe->sendfd, *pfd);
		if(fd >= 0)
			*pfd = fd;
		pipe->sendfd = NULL;
		return fd;
		break;
	case PIPE_CMD_TESTFD:
		return pipe->sendfd?1:0;
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
	if(n < 0)
		return 0;
	/* atomic write */
	if(n <= 128 && (PIPE_SIZE - pipe->count) < n)
		return 0;
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
