#include <lib/klib.h>
#include <os/devfs.h>

static int null_init()
{
	printk("null up\n");
	return 0;
}

static int null_exit()
{
	printk("null down\n");
	return 0;
}

static int null_open(int minor, int mode)
{
	return 0;
}

static int null_close(int minor)
{
	return 0;
}

static int null_ctl(int minor, int cmd, void *arg)
{
	switch(cmd)
	{
		
	}
	return 0;
}

struct dev_desc null_dev_desc = {
	.name = "null",
	.init = null_init,
	.exit = null_exit,
	.open = null_open,
	.close = null_close,
	.ctl = null_ctl,
};
