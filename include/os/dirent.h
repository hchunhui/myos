#ifndef	_OS_DIRENT_H
#define	_OS_DIRENT_H

#include <os/type.h>

struct os_dirent {
	__ino_t d_ino;
	__off_t d_off;
	size_t d_reclen;
	char d_name[256];
};

#ifdef __KERNEL__
#define dirent os_dirent
#endif

#endif /* _OS_DIRENT_H */
