#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/vfs.h>
#include <os/devfs.h>
#include <os/asm.h>
#include <os/multiboot.h>
#include <os/errno.h>
#include <os/fcntl.h>

extern struct s_fsys fsys_ramfs;
static struct list_head supers; /* list of struct s_super */
static struct s_super *sysroot;

static struct s_handle *new_handle(
	struct s_super *super,
	void *inode,
	char *path,
	char *name)
{
	struct s_handle *h;
	h = kmalloc(sizeof(struct s_handle));
	h->super = super;
	h->inode = inode;
	h->priv_ptr = NULL;
	strcpy(h->path, path);
	strcpy(h->name, name);
	return h;
}

static struct s_handle *new_handle0()
{
	struct s_handle *h;
	h = kmalloc(sizeof(struct s_handle));
	memset(h, 0, sizeof(struct s_handle));
	return h;
}

static struct s_handle *dup_handle(
	struct s_handle *s)
{
	struct s_handle *h;
	h = kmalloc(sizeof(struct s_handle));
	memcpy(h, s, sizeof(struct s_handle));
	return h;
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
			fdtab[i]->handle = NULL;
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
		return -EBADF;
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

static int get_name(char **pps, char *buf)
{
	int n;
	char *ps = *pps;
	while(*ps == '/')
		ps++;
	n = 0;
	while(*ps && *ps != '/')
	{
		*buf++ = *ps++;
		n++;
	}
	*buf = 0;
	*pps = ps;
	return n;
}

static struct s_handle *path_open(char *ps)
{
	int n;
	int i;
	char buf[32];
	struct s_handle *h;
        struct s_fsys *opr;
	struct dirent dbuf;
	h = new_handle(sysroot, sysroot->root_inode, "", "");
	opr = h->super->opr;
	while(1)
	{
		if((n = get_name(&ps, buf))== 0)
			goto final;
		if(opr->open(h, 0))
			return NULL;
		for(i = 0;;i++)
		{
			if(opr->readdir(h, i, &dbuf, 1) == 0)
				goto not_found;
			if(strcmp(dbuf.d_name, buf) == 0)
				goto found;
		}
	found:
		opr->close(h);
		h->inode = (void *)dbuf.d_ino;
		if(h->inode == NULL)
			return NULL;
		continue;
	not_found:
		/*printk("path_open: error!\n");*/
		return NULL;
	}
final:
	return h;
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
		if(i == 4) {
			h = new_handle(&dev_super, NULL, name, "0");
		} else {
			name[i] = 0;
			h = new_handle(&dev_super, NULL, name, name + i + 1);
			name[i] = '/';
		}
		return h;
	}
	return path_open(name);
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
		return -ENOENT;
	/* get fd */
	fd = get_new_fd(current->vfs->fdtab);
	if(fd == -1)
	{
		free_handle(h);
		return -EMFILE;
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
		sfd->handle = h;
		sfd->mode = flags;
		return fd;
	}
	printk("vfs_open: fail!\n");
	return -EFAULT;
}

int vfs_close(int fd)
{
	return release_fd(current->vfs->fdtab, fd, 1);
}

long vfs_read(int fd, void *buf, long count)
{
	struct s_fd *sfd;
	struct s_handle *h;
	long read;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -EBADF;
	h = sfd->handle;
	if(h->super->opr->read == NULL)
		return count;
	read = h->super->opr->read(h,
				   sfd->offset,
				   buf,
				   count);
	sfd->offset += read;
	return read;
}

long vfs_readdir(int fd, struct dirent *dirp, long count)
{
	struct s_fd *sfd;
	struct s_handle *h;
	long read;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -EBADF;
	h = sfd->handle;
	if(h->super->opr->readdir == NULL)
		return count;
	read = h->super->opr->readdir(h,
				      sfd->offset,
				      dirp,
				      count);
	sfd->offset += read;
	return read;
}

int vfs_mknod(char *name, int type)
{
	struct s_handle *h;
	int i, j, len;
	char *kname;
	int ret;
	ret = 0;

	/* 检查存在性 */
	h = path_resolve(name);
	if(h)
	{
		ret = -1;
		goto clean1;
	}
	/* 创建 */
	kname = kmalloc(PATH_MAX);
	len = strlen(name);
	for(i = len - 1; i >= 0; i--)
		if(name[i] == '/')
			break;
	j = i < 0 ? 0 : i;
	memcpy(kname, name, j);
	kname[j] = 0;
	h = path_open(kname);
	if(h == NULL)
	{
		ret = -1;
		goto clean;
	}
	strcpy(h->name, name+i+1);
	strcpy(h->path, kname);
	h->super->opr->mknod(h, type);
clean:	kfree(kname);
clean1:	free_handle(h);
	/*printk("vfs_mknod: %d\n", ret);*/
	return ret;
}

long vfs_write(int fd, void *buf, long count)
{
	struct s_fd *sfd;
	struct s_handle *h;
	long write;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -EBADF;
	h = sfd->handle;
	if(h->super->opr->write == NULL)
		return count;
	write = h->super->opr->write(h,
				     sfd->offset,
				     buf,
				     count);
	sfd->offset += write;
	return write;
}

int vfs_ioctl(int fd, int cmd, void *arg)
{
	struct s_fd *sfd;
	struct s_handle *h;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -EBADF;
	h = sfd->handle;
	if(h->super->opr->ioctl == NULL)
		return -ENOTTY;
	return h->super->opr->ioctl(h,
				    cmd,
				    arg);
}


int vfs_fstat(int fd, struct stat *stat)
{
	struct s_fd *sfd;
	struct s_handle *h;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -EBADF;
	h = sfd->handle;
	if(h->super->opr->stat == NULL)
		return -EACCES;
	return h->super->opr->stat(h,
				   stat,
				   0);
}

long vfs_lseek(int fd, long offset, int whence)
{
	struct s_fd *sfd;
	long xoff;
	struct stat st;
	int ret;
	sfd = current->vfs->fdtab[fd];
	if(sfd == NULL)
		return -EBADF;
	if((ret = vfs_fstat(fd, &st)) < 0)
		return ret;
	switch(whence)
	{
	case 0:
		xoff = offset;
		break;
	case 1:
		xoff = sfd->offset + offset;
		break;
	case 2:
		xoff = st.st_size + offset;
		break;
	default:
		return -EINVAL;
	};
	if(xoff < 0)
		return -EINVAL;
	sfd->offset = xoff;
	return xoff;
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

struct posix_tar_header
{				/* byte offset */
	char name[100];		/*   0 */
	char mode[8];		/* 100 */
	char uid[8];		/* 108 */
	char gid[8];		/* 116 */
	char size[12];		/* 124 */
	char mtime[12];		/* 136 */
	char chksum[8];		/* 148 */
	char typeflag;		/* 156 */
	char linkname[100];	/* 157 */
	char magic[6];		/* 257 */
	char version[2];	/* 263 */
	char uname[32];		/* 265 */
	char gname[32];		/* 297 */
	char devmajor[8];	/* 329 */
	char devminor[8];	/* 337 */
	char prefix[155];	/* 345 */
	/* 500 */
};

static void vfs_import_tar(char *tardata)
{
	void ramfs_set_file(void *i, char *data, long len);
	int tarp;
	struct posix_tar_header * phdr;
	struct s_handle *h;
	char *p;
	int f_len;

	tarp = 0;
	while(1)
	{
		phdr = (struct posix_tar_header *)(tardata + tarp);
		if (tardata[tarp] == 0)
			break;
		tarp += 512;
		/* calculate the file size */
		p = phdr->size;
		f_len = 0;
		while (*p)
			f_len = (f_len * 8) + (*p++ - '0'); /* octal */

		/* parse name */
		for(p = phdr->name; *p; p++)
		{
			if(*p == '/')
			{
				*p = 0;
				vfs_mknod(phdr->name, 1);
				*p = '/';
			}
		}
		if(*(p-1) != '/')
		{
			vfs_mknod(phdr->name, 0);
			h = path_open(phdr->name);
			ramfs_set_file(h->inode, tardata + tarp, f_len);
			tarp += ((f_len-1)/512 + 1)*512;
		}
	}
}

void vfs_start()
{
	struct s_super *ram_super;
	module_t *mod;
	multiboot_info_t *pmbi = pmultiboot_info;
	int i, l;
	char *s;

	/* mount root file system */
	INIT_LIST_HEAD(&supers);

	printk("vfs: mount root\n");
	ram_super = kmalloc(sizeof(struct s_super));
	if(fsys_ramfs.mount(ram_super, 0, 0, 0))
		panic("unable to mount root!");
	list_add(&ram_super->list, &supers);
	sysroot = ram_super;

	/* import tar */
	printk("vfs: import modules to file system\n");

	for (i = 0, mod = (module_t *) pmbi->mods_addr;
	     i < pmbi->mods_count; i++, mod ++)
	{
		s = (char *)(mod->string);
		l = strlen(s);
		for(; s[l-1] == ' '; s[--l] = 0);
		printk("vfs: import module %s\n", s);
		if((l > 3 && strcmp(s+l-4, ".tar") == 0) ||
		   (l > 6 && strcmp(s+l-7, ".tar.gz") == 0))
			vfs_import_tar((char *)mod->mod_start);
	}
}

struct s_fd *vfs_sendfd(int fd)
{
	if(fd < 0 || fd >= FD_MAX)
		return NULL;
	if(current->vfs->fdtab[fd] == NULL)
		return NULL;
	current->vfs->fdtab[fd]->ref_count++;
	return current->vfs->fdtab[fd];
}

int vfs_recvfd(struct s_fd *pfd, int newfd)
{
	int i;
	int ret;
	if(pfd == NULL)
		return -EBADF;
	if(newfd == -1)
		for (i = 0; i < FD_MAX; ++i)
			if(current->vfs->fdtab[i] == NULL)
			{
				newfd = i;
				break;
			}
	if(newfd < 0 || newfd >= FD_MAX)
		return -EBADF;
	if(current->vfs->fdtab[newfd])
		if((ret = release_fd(current->vfs->fdtab, newfd, 1)))
			return ret;
	current->vfs->fdtab[newfd] = pfd;
	return newfd;
}

asmlinkage long sys_open(char *name, int flags)
{
	int fd;
	if(flags & _FCREAT)
		vfs_mknod(name, 0);
	fd = vfs_open(name, flags);
	if(fd < 0)
		return fd;
	if(flags & _FAPPEND)
		vfs_lseek(fd, 0, 2);
	return fd;
}

asmlinkage long sys_close(int fd)
{
	return vfs_close(fd);
}

asmlinkage long sys_read(int fd, void *buf, long count)
{
	return vfs_read(fd, buf, count);
}

asmlinkage long sys_readdir(int fd, struct dirent *dirp, long count)
{
	return vfs_readdir(fd, dirp, count);
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
	struct s_fd *sfd;
	sfd = vfs_sendfd(oldfd);
	return vfs_recvfd(sfd, newfd);
}

asmlinkage long sys_mknod(char *name, int type)
{
	return vfs_mknod(name, type);
}

asmlinkage long sys_fstat(int fd, struct stat *stat)
{
	return vfs_fstat(fd, stat);
}

asmlinkage long sys_lseek(int fd, long offset, int whence)
{
	return vfs_lseek(fd, offset, whence);
}
