#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/vfs.h>
#include <lib/list.h>

extern struct s_fsys fsys_ramfs;

struct s_iramfs
{
	int ref_count;
	int isdir;
	int fixed;
	union {
		char *data;
		struct s_dramfs *ds;
	};
	long len;
	long alloc_len;
};

struct s_dramfs
{
	char name[32];
	struct s_iramfs *inode;
};

static void inode_get(struct s_iramfs *inode)
{
	inode->ref_count++;
}

static void inode_put(struct s_iramfs *inode)
{
	inode->ref_count--;
	if(inode->ref_count == 0)
	{
		/* TODO: delete */
	}
}

static void __my_mkd(struct s_dramfs *d, struct s_iramfs *inode, char *name)
{
	strcpy(d->name, name);
	d->inode = inode;
	if(inode)
		inode_get(inode);
}

static struct s_iramfs *my_mkdir(struct s_iramfs *p_inode)
{
	struct s_iramfs *inode;
	inode = kmalloc(sizeof(struct s_iramfs));
	inode->ref_count = 0;
	inode->isdir = 1;
	inode->fixed = 0;
	inode->ds = kmalloc(sizeof(struct s_dramfs)*2);
	inode->len = 2;
	inode->alloc_len = 2;

	__my_mkd(inode->ds, inode, ".");
	__my_mkd(inode->ds + 1, p_inode, "..");
	return inode;
}

static struct s_iramfs *my_mkfile()
{
	struct s_iramfs *inode;
	inode = kmalloc(sizeof(struct s_iramfs));
	inode->ref_count = 0;
	inode->isdir = 0;
	inode->fixed = 0;
	inode->data = NULL;
	inode->len = 0;
	inode->alloc_len = 0;
	return inode;
}

static void my_mkd(struct s_iramfs *inode, struct s_iramfs *d_inode, char *name)
{
	struct s_dramfs *tmp;
	if(!d_inode->isdir)
		panic("my_mkfile_d");
	if(d_inode->len == d_inode->alloc_len)
	{
		tmp = kmalloc(sizeof(struct s_dramfs)*2*d_inode->alloc_len);
		memcpy(tmp, d_inode->ds, sizeof(struct s_dramfs)*d_inode->alloc_len);
		d_inode->alloc_len *= 2;
		kfree(d_inode->ds);
		d_inode->ds = tmp;
	}
	__my_mkd(d_inode->ds + d_inode->len, inode, name);
	d_inode->len++;
}

static struct s_dramfs *my_lookup(char *name, struct s_iramfs *inode)
{
	int i;
	if(!inode)
		return NULL;
	if(!inode->isdir)
		panic("my_lookup");
	for(i = 0; i < inode->len; i++)
	{
		if(strcmp(inode->ds[i].name, name) == 0)
			return inode->ds + i;
	}
	return NULL;
}


static int ramfs_mount(struct s_super *super, int major, int minor, int option)
{
	struct s_iramfs *iroot;
	iroot = my_mkdir(NULL);
	super->opr = &fsys_ramfs;
	inode_get(iroot);
	super->root_inode = iroot;
	super->priv_ptr = NULL;
	return 0;	
}

static int ramfs_umount(struct s_super *super)
{
	inode_put(super->root_inode);
	printk("ramfs_umount: not impl! memory leak!\n");
	return 0;
}

static int ramfs_mknod(struct s_handle *h, int type)
{
	struct s_iramfs *inode;
	if(my_lookup(h->name, h->inode))
		return -2;
	if(type == 1)
		inode = my_mkdir(h->inode);
	else
		inode = my_mkfile();
	my_mkd(inode, h->inode, h->name);
	return 0;
}

static int ramfs_stat(struct s_handle *h, struct stat *st, int set)
{
	struct s_iramfs *inode;
	inode = h->inode;
	if(inode == NULL)
		return -2;
	if(!set)
	{
		st->st_mode = inode->isdir;
		st->st_size = inode->len;
	}
	else
	{
		return -1;
	}
	return 0;
}

static int ramfs_link(struct s_handle *from, struct s_handle *to)
{
	return -1;
}

static int ramfs_unlink(struct s_handle *h)
{
	return -1;
}

static int ramfs_open(struct s_handle *h, int mode)
{
	inode_get(h->inode);
	return 0;
}

static int ramfs_close(struct s_handle *h)
{
	inode_put(h->inode);
	return 0;
}

static long ramfs_readdir(struct s_handle *h, long off, struct dirent *buf, long len)
{
	struct s_iramfs *inode;
	long i;
	inode = h->inode;
	if(!inode->isdir)
		return -1;
	for(i = 0; i < len; i++)
	{
		if(i + off >= inode->len)
			break;
		strcpy(buf[i].d_name, inode->ds[i+off].name);
		buf[i].inode = inode->ds[i+off].inode;
	}
	return i;
}

static long ramfs_read(struct s_handle *h, long off, void *buf, long len)
{
	struct s_iramfs *inode;
	long i;
	inode = h->inode;
	if(inode->isdir)
		return -1;
	for(i = 0; i < len; i++)
	{
		if(i + off >= inode->len)
			break;
		((char *)buf)[i] = inode->data[i+off];
	}
	return i;
}

static long ramfs_write(struct s_handle *h, long off, void *buf, long len)
{
	struct s_iramfs *inode;
	char *o_buf;
	long i;
	inode = h->inode;
	if(inode->isdir)
		return -1;
	if(off+len > inode->alloc_len)
	{
		o_buf = inode->data;
		inode->data = kmalloc(off + len);
		if(o_buf)
		{
			memcpy(inode->data, o_buf, off);
			kfree(o_buf);
		}
	}
	memcpy(inode->data + off, buf, len);
	inode->len = off+len;
	return len;
}

struct s_fsys fsys_ramfs = {
	.open = ramfs_open,
	.close = ramfs_close,
	.read = ramfs_read,
	.write = ramfs_write,
	.readdir = ramfs_readdir,
	.ioctl = NULL,
	.poll = NULL,
	.mount = ramfs_mount,
	.umount = ramfs_umount,
	.stat = ramfs_stat,
	.mknod = ramfs_mknod,
	.link = ramfs_link,
	.unlink = ramfs_unlink,
};

void ramfs_set_file(void *i, char *data, long len)
{
	struct s_iramfs *inode = i;
	if(!inode->fixed && inode->data)
		kfree(inode->data);
	inode->fixed = 1;
	inode->len = len;
	inode->alloc_len = len;
	inode->data = data;
}

