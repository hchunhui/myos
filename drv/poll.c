#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <drv/poll.h>

struct s_poll {
	struct d_devfs d_pipe;
	sem_t sem;
	struct list_head int_list;
};

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
	poll->d_pipe.common.fsys = &fsys_devfs;
	poll->d_pipe.major = DEV_MAJOR_PIPE;
	poll->d_pipe.minor = 0;
	INIT_LIST_HEAD(&poll->int_list);
	sem_init(&poll->sem, 0);
	fsys_devfs.open(&poll->d_pipe, 0);
	*data = poll;
	return 0;
}

static int poll_close(int minor, void *data)
{
	struct s_poll *poll = data;
	struct poll_sem *p, *tmp;
	struct s_fd *sfd;
	struct s_dentry *sden;

	list_for_each_entry_safe(p, tmp, &poll->int_list, int_list)
	{
		sfd = current->vfs->fdtab[p->fd];
		if(sfd == NULL)
			panic("poll_write_event\n");
		sden = sfd->entry;
		if(sden->fsys->poll)
			if(sden->fsys->poll(
				   sden,
				   POLL_FUNC_UNREGISTER,
				   &p->list))
				panic("poll_unset\n");
		list_del(&p->int_list);
	}

	fsys_devfs.close(&poll->d_pipe);
	kfree(poll);
	return 0;
}

static int poll_unset(struct s_poll *poll, int fd)
{
	struct poll_sem *p, *tmp;
	struct s_fd *sfd;
	struct s_dentry *sden;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	sden = sfd->entry;
	list_for_each_entry_safe(p, tmp, &poll->int_list, int_list)
	{
		if(p->fd == fd)
		{
			if(sden->fsys->poll)
				if(sden->fsys->poll(
					   sden,
					   POLL_FUNC_UNREGISTER,
					   &p->list))
					panic("poll_unset\n");
			list_del(&p->int_list);
		}
	}
	return 0;
}

static int poll_set(struct s_poll *poll, int fd, int type)
{
	struct poll_sem *pollsem;
	struct s_fd *sfd;
	struct s_dentry *sden;
	if(type & ~POLL_TYPE_READ)
	{
		printk("poll_set: only support read type.\n");
		return -1;
	}
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	sden = sfd->entry;
	pollsem = kmalloc(sizeof(struct poll_sem));
	INIT_LIST_HEAD(&pollsem->list);
	INIT_LIST_HEAD(&pollsem->int_list);
	pollsem->sem = &poll->sem;
	pollsem->fd = fd;
	list_add(&pollsem->int_list, &poll->int_list);
	if(sden->fsys->poll)
		return sden->fsys->poll(sden,
					POLL_FUNC_REGISTER,
					&pollsem->list);
	return 0;
}

static int poll_ctl(int minor, void *data, int cmd, void *arg)
{
	struct s_poll *poll = data;
	struct s_poll_event *event = arg;
	switch(cmd)
	{
	case POLL_CMD_SET:
		return poll_set(poll, event->fd, event->type);
	case POLL_CMD_UNSET:
		return poll_unset(poll, event->fd);
	}
	return -1;
}

static int poll_write_event(struct s_poll *poll)
{
	struct poll_sem *p;
	struct s_fd *sfd;
	struct s_dentry *sden;
	struct s_poll_event event;
	int ret;
	ret = 0;
	list_for_each_entry(p, &poll->int_list, int_list)
	{
		sfd = current->vfs->fdtab[p->fd];
		if(sfd == NULL)
			panic("poll_write_event\n");
		sden = sfd->entry;
		if(sden->fsys->poll)
			if(sden->fsys->poll(
				   sden,
				   POLL_FUNC_READABLE,
				   NULL))
			{
				event.fd = p->fd;
				event.type = POLL_TYPE_READ;
				fsys_devfs.write(
					&poll->d_pipe,
					0,
					&event,
					sizeof(struct s_poll_event));
				ret++;
			}
	}
	return ret;
}

static long poll_read(int minor, void *data, void *buf, long n, long off)
{
	struct s_poll *poll = data;
	if(n%sizeof(struct s_poll_event))
		return -1;
	if(!fsys_devfs.poll(&poll->d_pipe, POLL_FUNC_READABLE, 0))
		while(!poll_write_event(poll))
		{
			sem_force_down(&poll->sem);
		}
	return fsys_devfs.read(&poll->d_pipe, off, buf, n);
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
