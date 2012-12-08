#ifndef _VFS_H_
#define _VFS_H_
#include <lib/list.h>
#include <os/sem.h>
#include <os/dirent.h>
#include <os/stat.h>
#define PATH_MAX 256

struct s_task;

struct s_super
{
	struct s_fsys *opr;
	struct list_head list;
	void *root_inode;
	/* private data */
	void *priv_ptr;
};

struct s_handle
{
	struct s_super *super;
	char path[PATH_MAX];
	char name[PATH_MAX];
	void *inode;
	/* private data */
	void *priv_ptr;
	unsigned long priv_long1;
	unsigned long priv_long2;
	unsigned long priv_long3;
};

struct s_fd
{
	struct s_handle *handle;
	int mode;
	long offset;
	int ref_count;
};

struct s_fsys
{
	char name[16];
	int (*open)(struct s_handle *h, int mode);
	int (*close)(struct s_handle *h);
	/* 这些操作需要打开文件 */
	long (*read)(struct s_handle *h, long off, void *buf, long len);
	long (*write)(struct s_handle *h, long off, void *buf, long len);
	long (*readdir)(struct s_handle *h, long off, struct dirent *buf, long len);
	int (*ioctl)(struct s_handle *h, int cmd, void *arg);
	int (*poll)(struct s_handle *entry, int func, struct list_head *lesm);
	/* 这些操作不需要打开文件 */
	int (*mount)(struct s_super *super, int major, int minor, int option);
	int (*umount)(struct s_super *super);
	int (*stat)(struct s_handle *h, struct stat *st, int set);
	int (*mknod)(struct s_handle *h, int type);
	int (*link)(struct s_handle *from, struct s_handle *to);
	int (*unlink)(struct s_handle *h);
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
	struct s_handle *pwd;
	struct s_handle *root;
};

void vfs_init(struct s_task *ptask);
int vfs_open(char *name, int flags);
int vfs_close(int fd);
long vfs_read(int fd, void *buf, long count);
long vfs_write(int fd, void *buf, long count);
int vfs_ioctl(int fd, int cmd, void *arg);
long vfs_lseek(int fd, long offset, int whence);
void vfs_fork(struct s_task *child, struct s_task *father);
void vfs_exec(struct s_task *ptask);
void vfs_exit(struct s_task *ptask);
#endif /* _VFS_H_ */
