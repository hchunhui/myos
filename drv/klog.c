#include <os/type.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/task.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <drv/klog.h>

static int flag;
void *klog_data;

void print_early(char *obj);
void (*print)(char *obj) = print_early;

static void print_normal(char *obj)
{
	int n = strlen(obj);
	dev_simp_write(DEV_MAJOR_PIPE, 0, klog_data, 0, obj, n);
}

static int klog_init()
{
	flag = 0;
	return 0;
}

static int klog_exit()
{
	return 0;
}

static int klog_open(int minor, int mode, void **data)
{
	void *klog;
	if(flag)
		return -1;
	flag = 1;
	dev_simp_open(DEV_MAJOR_PIPE, 0, 0, &klog);
	*data = klog;
	klog_data = klog;
	return 0;
}

static int klog_close(int minor, void *data)
{
	print = print_early;
	dev_simp_close(DEV_MAJOR_PIPE, 0, klog_data);
	flag = 0;
	return 0;
}

static int klog_ctl(int minor, void *data, int cmd, void *arg)
{
	switch(cmd)
	{
	case KLOG_CMD_BEGIN:
		print = print_normal;
		return 0;
	case KLOG_CMD_END:
		print = print_early;
		return 0;
	}
	return -1;
}

static long klog_read(int minor, void *data, void *buf, long n, long off)
{
	return dev_simp_read(DEV_MAJOR_PIPE, 0, klog_data, off, buf, n);
}

static long klog_write(int minor, void *data, void *buf, long n, long off)
{
	return n;
}

static int klog_poll(int minor, void *data, int func, struct list_head *lsem)
{
	return dev_simp_poll(DEV_MAJOR_PIPE, 0, klog_data, func, lsem);
}

struct dev_desc klog_dev_desc = {
	.name = "klog",
	.init = klog_init,
	.exit = klog_exit,
	.open = klog_open,
	.close = klog_close,
	.ctl = klog_ctl,
	.read = klog_read,
	.write = klog_write,
	.poll = klog_poll,
};
