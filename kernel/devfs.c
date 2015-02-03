#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>

static struct dev_desc *dev_desc[256];

int dev_register(int major, struct dev_desc *desc)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
		return -1;
	dev_desc[major] = desc;
	if(desc->init)
		if(desc->init())
		{
			dev_desc[major] = NULL;
			printk("dev_register: init fail, name: %s, major: %d\n",
			       desc->name, major);
			return -1;
		}
	return 0;
}

int dev_unregister(int major)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->exit)
			if(dev_desc[major]->exit())
			{
				printk("dev_unregister: exit fail, name %s\n",
				       dev_desc[major]->name);
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

/* raw interface */
int dev_simp_open(int major, int minor, int mode, void **data)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->open)
			return dev_desc[major]
				->open(minor,
				       mode,
				       data);
		return 0;
	}
	return -1;
}

int dev_simp_close(int major, int minor, void *data)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->close)
			return dev_desc[major]
				->close(minor,
					data);
		return 0;
	}
	return -1;
}

int dev_simp_ioctl(int major, int minor, void *data, int cmd, void *arg)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->ctl)
			return dev_desc[major]
				->ctl(minor,
				      data,
				      cmd,
				      arg);
		return 0;
	}
	return -1;
}

long dev_simp_read(int major, int minor, void *data, long off, void *buf, long n)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->read)
			return dev_desc[major]
				->read(minor,
				       data,
				       buf,
				       n,
				       off);
		return 0;
	}
	return -1;
}

long dev_simp_write(int major, int minor, void *data, long off, void *buf, long n)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->write)
			return dev_desc[major]
				->write(minor,
				       data,
				       buf,
				       n,
				       off);
		return 0;
	}
	return -1;
}

int dev_simp_poll(int major, int minor, void *data, int func, struct list_head *lsem)
{
	assert(major >= 0 && major <= 255);
	if(dev_desc[major])
	{
		if(dev_desc[major]->poll)
			return dev_desc[major]
				->poll(minor,
				       data,
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


/* file system interface */
int dev_open(struct s_handle *h, int mode)
{
	int len, i;
	int major, minor;
	int lev;
	char tmp[32];
	/* get minor */
	lev = 1;
	len = strlen(h->name);
	minor = 0;
	for(i = len - 1; i >= 0; i--)
	{
		if(h->name[i] >= '0' && h->name[i] <= '9')
			minor += lev * (h->name[i] - '0');
		else
			return -1;
		lev *= 10;	
	}
	/* get device name */
	len = strlen(h->path);
	for(i = len -1; i >= 0; i--)
		if(h->path[i] == '/')
			break;
	if(i < 0)
		return -1;
	memcpy(tmp, h->path + i + 1, len - i - 1);
	tmp[len - i - 1] = 0;
	/* find dev */
	if((major = dev_find_major(tmp)) == -1)
		return -1;
	/* record */
	h->priv_long1 = major;
	h->priv_long2 = minor;
	h->priv_ptr = NULL;
	/* exec open */
	return dev_simp_open(major, minor, mode, &(h->priv_ptr));
}

static int dev_close(struct s_handle *h)
{
	int major = h->priv_long1;
	int minor = h->priv_long2;
	void *data = h->priv_ptr;
	return dev_simp_close(major, minor, data);
}

static int dev_ctl(struct s_handle *h, int cmd, void *arg)
{
	int major = h->priv_long1;
	int minor = h->priv_long2;
	void *data = h->priv_ptr;
	return dev_simp_ioctl(major, minor, data, cmd, arg);
}

static long dev_read(struct s_handle *h, long off, void *buf, long n)
{
	int major = h->priv_long1;
	int minor = h->priv_long2;
	void *data = h->priv_ptr;
	return dev_simp_read(major, minor, data, off, buf, n);
}

static long dev_write(struct s_handle *h, long off, void *buf, long n)
{
	int major = h->priv_long1;
	int minor = h->priv_long2;
	void *data = h->priv_ptr;
	return dev_simp_write(major, minor, data, off, buf, n);
}

static int dev_poll(struct s_handle *h, int func, struct list_head *lsem)
{
	int major = h->priv_long1;
	int minor = h->priv_long2;
	void *data = h->priv_ptr;
	return dev_simp_poll(major, minor, data, func, lsem);
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
