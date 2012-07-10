#include <os/type.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/vfs.h>
#include <lib/list.h>

struct s_irootfs
{
	int ref_count;
	int isdir;
	struct s_drootfs *fchld;
	void *data;
	long len;
};

struct s_drootfs
{
	struct s_dentry common;
	struct s_drootfs *parent;
	struct s_drootfs *next;
	char name[32];
	struct s_irootfs *inode;
};

struct s_irootfs rootfs_iroot = {
	.ref_count = 1,
	.isdir = 1,
	.fchld = NULL,
};
	
struct s_drootfs rootfs_droot = {
	.name = "",
	.inode = &rootfs_iroot,
};


long rootfs_read(DEntry *entry, long off, void *buf, long len)
{
	return 0;
}

long rootfs_write(DEntry *entry, long off, void *buf, long len)
{
	return 0;
}

int rootfs_get_stat(DEntry *entry, struct stat **st)
{
	struct s_drootfs *dentry = entry;
	(*st)->st_size = dentry->inode->len;
	(*st)->st_mode = dentry->inode->isdir ? 1 : 0;
	return 0;
}

int rootfs_set_stat(DEntry *entry, struct stat *st)
{
	return -1;
}

int rootfs_next_dentry(DEntry **prev_new, char **name)
{
	struct s_drootfs *dentry, **pdnew;
	if(prev_new == NULL || name == NULL)
		return -1;
	dentry = *(struct s_drootfs **)prev_new;
	pdnew = (struct s_drootfs **)prev_new;
	*pdnew = dentry->next;
	if(*pdnew)
	{
		*name = (*pdnew)->name;
		return 0;
	}
	return 1;
}

int rootfs_go_dir(DEntry **prev_new)
{
	struct s_drootfs *dentry, **pdnew;
	if(prev_new == NULL)
		return -1;
	dentry = *(struct s_drootfs **)prev_new;
	pdnew = (struct s_drootfs **)prev_new;
	if(!dentry->inode->isdir)
		return 1;
	*pdnew = dentry->inode->fchld;
	return 0;
}

int rootfs_back_dir(DEntry **prev_new)
{
	struct s_drootfs *dentry, **pdnew;
	if(prev_new == NULL)
		return -1;
	dentry = *(struct s_drootfs **)prev_new;
	pdnew = (struct s_drootfs **)prev_new;
	if(!dentry->inode->isdir)
		return 1;
	if(dentry->parent == NULL)
		return 2;
	*pdnew = dentry->parent;
	return 0;
}

static int inode_create(struct s_irootfs **pinode)
{
	struct s_irootfs *inode;
	inode = kmalloc(sizeof(struct s_irootfs));
	*pinode = inode;
	inode->ref_count = 0;
	inode->isdir = 0;
	inode->fchld = NULL;
	inode->data = NULL;
	inode->len = 0;
	return 0;
}

static int inode_delete(struct s_irootfs *inode)
{
	kfree(inode);
	return 0;
}


int rootfs_new_dentry(DEntry *entry, char *name, int isdir, DEntry **result)
{
	struct s_drootfs *dentry, *dnew;
	struct s_irootfs *inode;
	if(!entry)
		return -1;
	dentry = entry;
	if(!dentry->inode->isdir)
		return 1;
	if(inode_create(&inode))
		return 1;
	dnew = kmalloc(sizeof(struct s_drootfs));
	dnew->parent = dentry;
	dnew->next = dentry->inode->fchld;
	dentry->inode->fchld = dnew;
	dnew->inode = inode;
	strcpy(dnew->name, name);

	dnew->inode->ref_count++;
	dnew->inode->isdir = isdir;
	return 0;
}

int rootfs_link(DEntry *from, DEntry *to)
{
	struct s_drootfs *dfrom, *dto;
	dfrom = from;
	dto = to;
	if(!from || !to)
		return -1;
	if(dto->inode)
	{
		dto->inode->ref_count--;
		if(dto->inode->ref_count == 0)
			inode_delete(dto->inode);
	}
	dto->inode = dfrom->inode;
	dfrom->inode->ref_count++;
	return 0;
}

int rootfs_unlink(DEntry *entry)
{
	struct s_drootfs *dentry, *parent, *d;
	dentry = entry;
	if(!entry)
		return -1;
	if(dentry->inode->fchld)
		return 1;
	parent = dentry->parent;
	if(!parent)
		return 1;
	if(parent->inode->fchld == dentry)
	{
		parent->inode->fchld = dentry->next;
	}
	else
	{
		for(d = parent->inode->fchld; d; d = d->next)
			if(d->next == dentry)
			{
				d->next = dentry->next;
				break;
			}
	}
	
	dentry->inode->ref_count--;
	if(dentry->inode->ref_count == 0)
	{
		inode_delete(dentry->inode);
	}
	
	kfree(dentry);
	return 0;
}

int rootfs_post_mount(DEntry *from, DEntry **to)
{
	struct s_dentry *dfrom = from;
	DEntry *iter;
	if(dfrom->prev_d)
	{
		printk("mount: dfrom->prev_d != NULL\n");
		return 1;
	}
	iter = from;
	dfrom->fsys->back_dir(&iter);
	if(iter != *to)
	{
		printk("mount: dfrom\n");
		return 1;
	}
	dfrom->prev_d = *to;
	*to = from;
	return 0;
}

int rootfs_pre_mount(int major, int minor, DEntry *to, DEntry **new)
{
	rootfs_droot.parent = to;
	*new = &rootfs_droot;
	return 0;
}

int rootfs_pre_umount(DEntry *entry)
{
	return 0;
}

int rootfs_post_umount(DEntry *entry)
{
	return 0;
}

struct s_fsys rootfs =
{
	.name = "rootfs",
	.read = rootfs_read,
	.write = rootfs_write,
	.get_stat = rootfs_get_stat,
	.set_stat = rootfs_set_stat,
	.next_dentry = rootfs_next_dentry,
	.go_dir = rootfs_go_dir,
	.back_dir = rootfs_back_dir,
	.new_dentry = rootfs_new_dentry,
	.link = rootfs_link,
	.unlink = rootfs_unlink,
	.post_mount = rootfs_post_mount,
	.pre_mount = rootfs_pre_mount,
	.post_umount = rootfs_post_umount,
	.pre_umount = rootfs_pre_umount
};
