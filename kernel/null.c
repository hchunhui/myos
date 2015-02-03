#include <lib/klib.h>
#include <os/devfs.h>

static int null_init()
{
	return 0;
}

static int null_exit()
{
	return 0;
}

static int null_open(int minor, int mode, void **data)
{
	return 0;
}

static int null_close(int minor, void *data)
{
	return 0;
}

static int null_ctl(int minor, void *data, int cmd, void *arg)
{
	switch(cmd)
	{
		
	}
	return 0;
}

static long null_read(int minor, void *data, void *buf, long n, long off)
{
	return n;
}

static long null_write(int minor, void *data, void *buf, long n, long off)
{
	return n;
}

struct dev_desc null_dev_desc = {
	.name = "null",
	.init = null_init,
	.exit = null_exit,
	.open = null_open,
	.close = null_close,
	.ctl = null_ctl,
	.read = null_read,
	.write = null_write,
};
