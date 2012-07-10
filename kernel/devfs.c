#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>

static struct dev_desc *dev_desc[256];

int dev_register(int major, struct dev_desc *desc)
{
	if(major < 0 || major > 255)
		panic("dev_register: major");
	if(dev_desc[major])
		return -1;
	dev_desc[major] = desc;
	printk("dev_register: name %s  major %d\n", desc->name, major);
	if(desc->init)
		if(desc->init())
		{
			dev_desc[major] = NULL;
			printk("dev_register: init fail\n");
			return -1;
		}
	return 0;
}

int dev_unregister(int major)
{
	if(major < 0 || major > 255)
		panic("dev_unregister: major");
	if(dev_desc[major])
	{
		if(dev_desc[major]->exit)
			if(dev_desc[major]->exit())
			{
				printk("dev_unregister: exit fail\n");
				return -1;
			}
		dev_desc[major] = NULL;
		return 0;
	}
	return -1;
}

int dev_find_major(char *name)
{
	int i;
	for(i = 0; i < 256; i++)
		if(dev_desc[i] && strcmp(name, dev_desc[i]->name) == 0)
		{
			return i;
		}
	return -1;
}

static int dev_open(DEntry *entry, int mode)
{
	struct d_devfs *d = entry;
	if(d->major < 0 || d->major > 255)
		panic("dev_open: major");
	if(dev_desc[d->major])
	{
		if(dev_desc[d->major]->open)
			return dev_desc[d->major]
				->open(d->minor,
				       mode,
				       &(d->data));
		return 0;
	}
	d->data = NULL;
	return -1;
}

static int dev_close(DEntry *entry)
{
	struct d_devfs *d = entry;
	if(d->major < 0 || d->major > 255)
		panic("dev_close: major");
	if(dev_desc[d->major])
	{
		if(dev_desc[d->major]->close)
			return dev_desc[d->major]
				->close(d->minor,
					d->data);
		return 0;
	}
	return -1;
}

static int dev_ctl(DEntry *entry, int cmd, void *arg)
{
	struct d_devfs *d = entry;
	if(d->major < 0 || d->major > 255)
		panic("dev_ctl: major");
	if(dev_desc[d->major])
	{
		if(dev_desc[d->major]->ctl)
			return dev_desc[d->major]
				->ctl(d->minor,
				      d->data,
				      cmd,
				      arg);
		return 0;
	}
	return -1;
}

static long dev_read(DEntry *entry, long off, void *buf, long n)
{
	struct d_devfs *d = entry;
	if(d->major < 0 || d->major > 255)
		panic("dev_read: major");
	if(dev_desc[d->major])
	{
		if(dev_desc[d->major]->read)
			return dev_desc[d->major]
				->read(d->minor,
				       d->data,
				       buf,
				       n,
				       off);
		return 0;
	}
	return -1;
}

static long dev_write(DEntry *entry, long off, void *buf, long n)
{
	struct d_devfs *d = entry;
	if(d->major < 0 || d->major > 255)
		panic("dev_write: major");
	if(dev_desc[d->major])
	{
		if(dev_desc[d->major]->write)
			return dev_desc[d->major]
				->write(d->minor,
				       d->data,
				       buf,
				       n,
				       off);
		return 0;
	}
	return -1;
}

static int dev_poll(DEntry *entry, int func, struct list_head *lsem)
{
	struct d_devfs *d = entry;
	if(d->major < 0 || d->major > 255)
		panic("dev_write: major");
	if(dev_desc[d->major])
	{
		if(dev_desc[d->major]->poll)
			return dev_desc[d->major]
				->poll(d->minor,
				       d->data,
				       func,
				       lsem);
		/* default poll */
		switch(func)
		{
		case POLL_FUNC_READABLE:
			return 0;
		case POLL_FUNC_WRITEABLE:
			return 0;
		case POLL_FUNC_REGISTER:
			return 0;
		case POLL_FUNC_UNREGISTER:
			return 0;
		}
	}
	return -1;
}

extern struct dev_desc null_dev_desc;
extern struct dev_desc pipe_dev_desc;
extern struct dev_desc poll_dev_desc;
extern struct dev_desc klog_dev_desc;
void devfs_init()
{
	memset(dev_desc, 0, sizeof(dev_desc));
	dev_register(DEV_MAJOR_NULL, &null_dev_desc);
	dev_register(DEV_MAJOR_PIPE, &pipe_dev_desc);
	dev_register(DEV_MAJOR_POLL, &poll_dev_desc);
	dev_register(DEV_MAJOR_KLOG, &klog_dev_desc);
}

struct s_fsys fsys_devfs = {
	.name = "devfs",
	.open = dev_open,
	.close = dev_close,
	.read = dev_read,
	.write = dev_write,
	.ioctl = dev_ctl,
	.poll = dev_poll,
};
