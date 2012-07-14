#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/vfs.h>
#include <os/devfs.h>
#include <os/asm.h>

static struct list_head supers; /* list of struct s_super */
static struct s_super *sysroot;

static struct s_handle *new_handle(
	struct s_super *super,
	char *path,
	char *name)
{
	struct s_handle *h;
	h = kmalloc(sizeof(struct s_handle));
	h->super = super;
	strcpy(h->path, path);
	strcpy(h->name, name);
	return h;
}

static void dup_handle(
	struct s_handle *src,
	struct s_handle *dest)
{
	memcpy(dest, src, sizeof(struct s_handle));
}

static void free_handle(
	struct s_handle *h)
{
	kfree(h);
}


/*  vfs(s_vfs).fdtab[i](s_fd)-->handle */
static int get_new_fd(
	struct s_fd *fdtab[])
{
	int i;
	for (i = 0; i < FD_MAX; ++i)
	{
		if(fdtab[i] == NULL)
		{
			fdtab[i] = kmalloc(sizeof(struct s_fd));
			fdtab[i]->mode = 0;
			fdtab[i]->offset = 0;
			fdtab[i]->ref_count = 1;
			return i;
		}
	}
	return -1;
}

static int release_fd(
	struct s_fd *fdtab[], int i, int close)
{
	int ret = 0;
	struct s_handle *h;
	if(fdtab[i] == NULL)
		return -1;
	if(fdtab[i]->ref_count == 1)
	{
		h = fdtab[i]->handle;
		if(close && h->super->opr &&
		   h->super->opr->close)
		{
			ret = h->super->opr->close(h);
			if(ret)
				return ret;
		}
		free_handle(h);
		kfree(fdtab[i]);
		fdtab[i] = NULL;
		return 0;
	}
	fdtab[i]->ref_count--;
	fdtab[i] = NULL;
	return 0;
}

static struct s_super dev_super;
static struct s_handle
*path_resolve(char *name)
{
	int i;
	int len;
	struct s_handle *h;
	if(name[0] == '/' &&
	   name[1] == 'd' &&
	   name[2] == 'e' &&
	   name[3] == 'v' &&
	   name[4] == '/')
	{
		dev_super.opr = &fsys_devfs;
		len = strlen(name);
		for(i = len - 1; i >= 0; i--)
			if(name[i] == '/')
				break;
		name[i] = 0;
		h = new_handle(&dev_super, name, name + i + 1);
		name[i] = '/';
		return h;
	}
	return NULL;
}

int vfs_open(char *name, int flags)
{
	struct s_handle *h;
	int ret;
	int fd;
	struct s_fd *sfd;
	/* resolve path */
	h = path_resolve(name);
	if(h == NULL)
		return -1;
	/* get fd */
	fd = get_new_fd(current->vfs->fdtab);
	if(fd == -1)
	{
		free_handle(h);
		return -1;
	}
	sfd = current->vfs->fdtab[fd];
	
	/* exec open */
	if(h->super->opr &&
	   h->super->opr->open)
	{
		ret = h->super->opr->open(h, flags);
		if(ret)
		{
			release_fd(current->vfs->fdtab, fd, 0);
			free_handle(h);
			return ret;
		}
		h->open = 1;
		sfd->handle = h;
		sfd->mode = flags;
		return fd;
	}
	printk("vfs_open: fail!\n");
	return -1;
}

int vfs_close(int fd)
{
	return release_fd(current->vfs->fdtab, fd, 1);
}

long vfs_read(int fd, void *buf, long count)
{
	struct s_fd *sfd;
	struct s_handle *h;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	h = sfd->handle;
	if(h->super->opr->read == NULL)
		return count;
	return h->super->opr->read(h,
				   sfd->offset,
				   buf,
				   count);
}

long vfs_write(int fd, void *buf, long count)
{
	struct s_fd *sfd;
	struct s_handle *h;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	h = sfd->handle;
	if(h->super->opr->write == NULL)
		return count;
	return h->super->opr->write(h,
				    sfd->offset,
				    buf,
				    count);
}

int vfs_ioctl(int fd, int cmd, void *arg)
{
	struct s_fd *sfd;
	struct s_handle *h;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	h = sfd->handle;
	if(h->super->opr->ioctl == NULL)
		return -1;
	return h->super->opr->ioctl(h,
				    cmd,
				    arg);
}

void vfs_init(struct s_task *ptask)
{
	ptask->vfs = kmalloc(sizeof(struct s_vfs));
	memset(ptask->vfs, 0, sizeof(struct s_vfs));
}

void vfs_fork(struct s_task *child, struct s_task *father)
{
	int i;
	child->vfs = kmalloc(sizeof(struct s_vfs));
	memcpy(child->vfs, father->vfs, sizeof(struct s_vfs));
	for(i = 0; i < FD_MAX; i++)
		if(child->vfs->fdtab[i])
			child->vfs->fdtab[i]->ref_count++;
}

void vfs_exec(struct s_task *ptask)
{
	int i;
	for(i = 3; i < FD_MAX; i++)
		vfs_close(i);
}

void vfs_exit(struct s_task *ptask)
{
	int i;
	for(i = 0; i < FD_MAX; i++)
		vfs_close(i);
	kfree(ptask->vfs);
}

asmlinkage long sys_open(char *name, int flags)
{
	return vfs_open(name, flags);
}

asmlinkage long sys_close(int fd)
{
	return vfs_close(fd);
}

asmlinkage long sys_read(int fd, void *buf, long count)
{
	return vfs_read(fd, buf, count);
}

asmlinkage long sys_write(int fd, void *buf, long count)
{
	return vfs_write(fd, buf, count);
}

asmlinkage long sys_ioctl(int fd, int cmd, void *arg)
{
	return vfs_ioctl(fd, cmd, arg);
}

asmlinkage long sys_dup2(int oldfd, int newfd)
{
	if(oldfd < 0 || oldfd >= FD_MAX)
		return -1;
	if(newfd < 0 || newfd >= FD_MAX)
		return -1;
	if(current->vfs->fdtab[newfd])
		if(release_fd(current->vfs->fdtab, newfd, 1))
			return -1;
	current->vfs->fdtab[oldfd]->ref_count++;
	current->vfs->fdtab[newfd] = current->vfs->fdtab[oldfd];
	return 0;
}
