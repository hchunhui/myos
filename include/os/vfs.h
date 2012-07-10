#ifndef _VFS_H_
#define _VFS_H_
#include <lib/list.h>
#include <os/sem.h>
#define PATH_MAX 64
typedef void DEntry;
struct s_task;

struct s_dentry
{
	struct s_fsys *fsys;
	DEntry *prev_d;
};

struct s_fd
{
	char path[PATH_MAX];
	DEntry *entry;
	int mode;
	long offset;
	int count;
};

struct stat
{
	unsigned int st_mode;
	long st_size;
};

#define S_IFDIR 1
struct s_fsys
{
	char name[16];
	int (*open)(DEntry *entry, int mode);
	int (*close)(DEntry *entry);
	long (*read)(DEntry *entry, long off, void *buf, long len);
	long (*write)(DEntry *entry, long off, void *buf, long len);
	int (*ioctl)(DEntry *entry, int cmd, void *arg);
	int (*get_stat)(DEntry *entry, struct stat **st);
	int (*set_stat)(DEntry *entry, struct stat *st);
	int (*next_dentry)(DEntry **prev_new, char **name);
	int (*go_dir)(DEntry **prev_new);
	int (*back_dir)(DEntry **prev_new);
	int (*new_dentry)(DEntry *entry, char *name, int isdir, DEntry **result);
	int (*link)(DEntry *from, DEntry *to);
	int (*unlink)(DEntry *entry);
	int (*post_mount)(DEntry *from, DEntry **to);
	int (*pre_mount)(int major, int minor, DEntry *to, DEntry **new);
	int (*post_umount)(DEntry *entry);
	int (*pre_umount)(DEntry *entry);
	int (*poll)(DEntry *entry, int func, struct list_head *lesm);
};

struct poll_sem {
	struct list_head list;
	struct list_head int_list;
	int fd;
	sem_t *sem;
};
#define POLL_FUNC_READABLE 1
#define POLL_FUNC_WRITEABLE 2
#define POLL_FUNC_REGISTER 3
#define POLL_FUNC_UNREGISTER 4

#define FD_MAX 16
struct s_vfs
{
	struct s_fd *fdtab[FD_MAX];
	DEntry *pwd;
	DEntry *root;
};

void vfs_init(struct s_task *ptask);
int vfs_open(char *name, int flags);
int vfs_close(int fd);
long vfs_read(int fd, void *buf, long count);
long vfs_write(int fd, void *buf, long count);
int vfs_ioctl(int fd, int cmd, void *arg);
void vfs_fork(struct s_task *child, struct s_task *father);
void vfs_exec(struct s_task *ptask);
void vfs_exit(struct s_task *ptask);
#endif /* _VFS_H_ */
