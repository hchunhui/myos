#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <drv/poll.h>

struct s_poll {
	void *pipe_data;
	sem_t sem;
	struct list_head int_list;
};

static int poll_write_event(struct s_poll *poll)
{
	struct poll_sem *p;
	struct s_fd *sfd;
	struct s_handle *h;
	struct s_poll_event event;
	int ret;
	ret = 0;
	list_for_each_entry(p, &poll->int_list, int_list)
	{
		sfd = current->vfs->fdtab[p->fd];
		assert(sfd != NULL);
		h = sfd->handle;
		if(h->super->opr->poll)
			if(h->super->opr->poll(
				   h,
				   POLL_FUNC_READABLE,
				   NULL))
			{
				event.fd = p->fd;
				event.type = POLL_TYPE_READ;
				dev_simp_write(DEV_MAJOR_PIPE,
					       0,
					       poll->pipe_data,
					       0,
					       &event,
					       sizeof(struct s_poll_event));
				ret++;
			}
	}
	return ret;
}

static int poll_init()
{
	printk("poll up\n");
	return 0;
}

static int poll_exit()
{
	printk("poll down\n");
	return 0;
}

static int poll_open(int minor, int mode, void **data)
{
	struct s_poll *poll;
	poll = kmalloc(sizeof(struct s_poll));
	INIT_LIST_HEAD(&poll->int_list);
	sem_init(&poll->sem, 0);
	dev_simp_open(DEV_MAJOR_PIPE, 0, mode, &poll->pipe_data);
	*data = poll;
	return 0;
}

static int poll_close(int minor, void *data)
{
	struct s_poll *poll = data;
	struct poll_sem *p, *tmp;
	struct s_fd *sfd;
	struct s_handle *h;

	list_for_each_entry_safe(p, tmp, &poll->int_list, int_list)
	{
		sfd = current->vfs->fdtab[p->fd];
		if(sfd)
		{
			h = sfd->handle;
			if(h->super->opr->poll)
				if(h->super->opr->poll(
					   h,
					   POLL_FUNC_UNREGISTER,
					   &p->list))
					panic("poll_unset\n");
		}
		list_del(&p->int_list);
	}
	dev_simp_close(DEV_MAJOR_PIPE, 0, poll->pipe_data);
	kfree(poll);
	return 0;
}

static int poll_unset(struct s_poll *poll, int fd)
{
	struct poll_sem *p, *tmp;
	struct s_fd *sfd;
	struct s_handle *h;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	h = sfd->handle;
	list_for_each_entry_safe(p, tmp, &poll->int_list, int_list)
	{
		if(p->fd == fd)
		{
			if(h->super->opr->poll)
				if(h->super->opr->poll(
					   h,
					   POLL_FUNC_UNREGISTER,
					   &p->list))
					panic("poll_unset\n");
			list_del(&p->int_list);
			kfree(p);
		}
	}
	return 0;
}

static int poll_set(struct s_poll *poll, int fd, int type)
{
	struct poll_sem *pollsem;
	struct s_fd *sfd;
	struct s_handle *h;
	if(type & ~POLL_TYPE_READ)
	{
		printk("poll_set: only support read type.\n");
		return -1;
	}
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	h = sfd->handle;
	pollsem = kmalloc(sizeof(struct poll_sem));
	INIT_LIST_HEAD(&pollsem->list);
	INIT_LIST_HEAD(&pollsem->int_list);
	pollsem->sem = &poll->sem;
	pollsem->fd = fd;
	list_add(&pollsem->int_list, &poll->int_list);
	if(h->super->opr->poll)
		return h->super->opr->poll(h,
					POLL_FUNC_REGISTER,
					&pollsem->list);
	return 0;
}

static int poll_ctl(int minor, void *data, int cmd, void *arg)
{
	struct s_poll *poll = data;
	struct s_poll_event *event = arg;
	int nr;
	switch(cmd)
	{
	case POLL_CMD_SET:
		return poll_set(poll, event->fd, event->type);
	case POLL_CMD_UNSET:
		return poll_unset(poll, event->fd);
	case POLL_CMD_PEEK:
		if((nr = dev_simp_poll(DEV_MAJOR_PIPE, 0, poll->pipe_data,
				       POLL_FUNC_READABLE, 0)))
			return nr / sizeof(struct s_poll_event);
		return poll_write_event(poll);
	}
	return -1;
}

static long poll_read(int minor, void *data, void *buf, long n, long off)
{
	struct s_poll *poll = data;
	if(n%sizeof(struct s_poll_event))
		return -1;
	if(!dev_simp_poll(DEV_MAJOR_PIPE, 0, poll->pipe_data,
			  POLL_FUNC_READABLE, 0))
		while(!poll_write_event(poll))
		{
			sem_force_down(&poll->sem);
		}
	return dev_simp_read(DEV_MAJOR_PIPE, 0, poll->pipe_data,
			     off, buf, n);
}

static long poll_write(int minor, void *data, void *buf, long n, long off)
{
	return n;
}

struct dev_desc poll_dev_desc = {
	.name = "poll",
	.init = poll_init,
	.exit = poll_exit,
	.open = poll_open,
	.close = poll_close,
	.ctl = poll_ctl,
	.read = poll_read,
	.write = poll_write,
};
