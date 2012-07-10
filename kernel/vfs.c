#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/vfs.h>
#include <os/devfs.h>
#include <os/asm.h>

static DEntry *find_dentry(DEntry *entry, char *name)
{
	struct s_dentry *d = entry;
	char *dname;
	if(name[0] == '.' && name[1] == 0)
		return entry;
	if(name[0] == '.' && name[1] == '.' && name[2] == 0)
	{
		if(d->fsys->back_dir(&entry))
			return NULL;
		return entry;
	}
	while(!d->fsys->next_dentry(&entry, &dname))
	{
		if(strcmp(name, dname) == 0)
			return entry;
	}
	return NULL;
}

static DEntry *path_resolve(DEntry *entry, char *path)
{
	int i;
	char name[32];
	if(path[0]=='/')
		panic("path_resolve\n");
	i = 0;
	for(; *path; path++)
	{
		if(*path == '/')
		{
			name[i] = 0;
			if((entry = find_dentry(entry, name)) == NULL)
				return NULL;
			i = 0;
		}
		else
			name[i++] = *path;
			
	}
	name[i] = 0;
	if(i)
		if((entry = find_dentry(entry, name)) == NULL)
			return NULL;
	return entry;
}

/*
 *  vfs(s_vfs)-->fdtab[i](s_fd)-->path(char[])
 *                              |->entry(Dentry)
 *                              |->mode(int)
 *                              |->offset(long)
 *                              |->count(int)
 */
static int get_new_fd(struct s_fd *fdtab[])
{
	int i;
	for (i = 0; i < FD_MAX; ++i)
	{
		if(fdtab[i] == NULL)
		{
			fdtab[i] = kmalloc(sizeof(struct s_fd));
			fdtab[i]->path[0] = 0;
			fdtab[i]->entry = NULL;
			fdtab[i]->mode = 0;
			fdtab[i]->offset = 0;
			fdtab[i]->count = 1;
			return i;
		}
	}
	return -1;
}

static int release_fd(struct s_fd *fdtab[], int i)
{
	struct s_dentry *den;
	int ret = 0;
	if(fdtab[i] == NULL)
		return -1;
	if(fdtab[i]->count == 1)
	{
		den = fdtab[i]->entry;
		if(den->fsys->close)
			ret = den->fsys
				->close(fdtab[i]->entry);
		kfree(fdtab[i]);
		/*fdtab[i] = NULL;*/
		return ret;
	}
	fdtab[i]->count--;
	fdtab[i] = NULL;
	return 0;
}

int vfs_open(char *name, int flags)
{
	int len = strlen(name);
	int i;
	int minor = 0;
	int major;
	int lev = 1;
	char tmp[32];
	struct d_devfs *d;
	int fd;
	struct s_fd *sfd;
	
	for(i = len - 1; i >= 0; i--)
	{
		if(name[i] == '/')
			break;
		if(name[i] >= '0' && name[i] <= '9')
			minor += lev * (name[i] - '0');
		else
			return -1;
		lev *= 10;
		
	}
	if(name[0] == '/' &&
	   name[1] == 'd' &&
	   name[2] == 'e' &&
	   name[3] == 'v' &&
	   name[4] == '/')
	{
		for(i = 5; i < len && name[i] != '/'; i++)
			tmp[i-5] = name[i];
		tmp[i-5] = 0;
		if((major = dev_find_major(tmp)) == -1)
			return -1;
		fd = get_new_fd(current->vfs->fdtab);
		if(fd == -1)
			return -1;
		sfd = current->vfs->fdtab[fd];
		d = kmalloc(sizeof(struct d_devfs));
		d->common.fsys = &fsys_devfs;
		d->major = major;
		d->minor = minor;
		d->data = NULL;
		i = fsys_devfs.open(d, flags);
		if(i == 0)
		{
			strcpy(sfd->path, name);
			sfd->entry = d;
			sfd->mode = flags;
			return fd;
		}
		else
		{
			release_fd(current->vfs->fdtab, fd);
			kfree(d);
			return i;
		}
	}
	return -1;
}

int vfs_close(int fd)
{
	return release_fd(current->vfs->fdtab, fd);
}

long vfs_read(int fd, void *buf, long count)
{
	struct s_fd *sfd;
	struct s_dentry *sden;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	sden = sfd->entry;
	if(sden->fsys->read == NULL)
		return count;
	return sden->fsys->read(sfd->entry,
				sfd->offset,
				buf,
				count);
}

long vfs_write(int fd, void *buf, long count)
{
	struct s_fd *sfd;
	struct s_dentry *sden;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	sden = sfd->entry;
	if(sden->fsys->write == NULL)
		return count;
	return sden->fsys->write(sfd->entry,
				 sfd->offset,
				 buf,
				 count);
}

int vfs_ioctl(int fd, int cmd, void *arg)
{
	struct s_fd *sfd;
	struct s_dentry *sden;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -1;
	sden = sfd->entry;
	if(sden->fsys->ioctl == NULL)
		return -1;
	return sden->fsys->ioctl(sfd->entry,
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
			child->vfs->fdtab[i]->count++;
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
		if(release_fd(current->vfs->fdtab, newfd))
			return -1;
	current->vfs->fdtab[oldfd]->count++;
	current->vfs->fdtab[newfd] = current->vfs->fdtab[oldfd];
	return 0;
}
