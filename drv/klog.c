#include <os/type.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/task.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <drv/klog.h>

static int flag;
struct s_klog {
	struct d_devfs d_pipe;
} g_klog;

void print_early(char *obj);
void (*print)(char *obj) = print_early;

static void print_normal(char *obj)
{
	int n = strlen(obj);
	fsys_devfs.write(&g_klog.d_pipe, 0, obj, n);
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
	struct s_klog *klog;
	if(flag)
		return -1;
	flag = 1;
	klog = &g_klog;
	klog->d_pipe.common.fsys = &fsys_devfs;
	klog->d_pipe.major = DEV_MAJOR_PIPE;
	klog->d_pipe.minor = 0;
	fsys_devfs.open(&klog->d_pipe, 0);
	*data = klog;
	return 0;
}

static int klog_close(int minor, void *data)
{
	struct s_klog *klog = data;
	print = print_early;
	fsys_devfs.close(&klog->d_pipe);
	flag = 0;
	return 0;
}

static int klog_ctl(int minor, void *data, int cmd, void *arg)
{
	struct s_klog *klog = data;
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
	struct s_klog *klog = data;
	return fsys_devfs.read(&klog->d_pipe, off, buf, n);
}

static long klog_write(int minor, void *data, void *buf, long n, long off)
{
	return n;
}

static int klog_poll(int minor, void *data, int func, struct list_head *lsem)
{
	struct s_klog *klog = data;
	return fsys_devfs.poll(&klog->d_pipe, func, lsem);
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
