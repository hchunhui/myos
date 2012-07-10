#ifndef _DEVFS_H_
#define _DEVFS_H_
#include <lib/list.h>
#include <os/vfs.h>

struct d_devfs
{
	struct s_dentry common;
	int major;
	int minor;
	void *data;
};

struct dev_desc
{
	char name[32];
	int (*init)();
	int (*exit)();
	int (*open)(int minor, int mode, void **data);
	int (*close)(int minor, void *data);
	int (*ctl)(int minor, void *data, int cmd, void *arg);
	long (*read)(int minor, void *data, void *buf, long n, long off);
	long (*write)(int minor, void *data, void *buf, long n, long off);
	int (*poll)(int minor, void *data, int func, struct list_head *lsem);
};

int dev_register(int major, struct dev_desc *desc);
int dev_unregister(int major);
int dev_find_major(char *name);

extern struct s_fsys fsys_devfs;
#define DEV_MAJOR_NULL 0
#define DEV_MAJOR_PIT 1
#define DEV_MAJOR_RTC 2
#define DEV_MAJOR_VIDEO 3
#define DEV_MAJOR_KB 4
#define DEV_MAJOR_MOUSE 5
#define DEV_MAJOR_INPUT 6

#define DEV_MAJOR_PIPE 128
#define DEV_MAJOR_POLL 129
#define DEV_MAJOR_KLOG 254
#endif /* _DEVFS_H_ */
