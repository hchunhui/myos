#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <sys/types.h>

#define _LIBC 1
#define NOT_IN_libc 1
#include <sys/lock.h>
#undef _LIBC

#define HAVE_NO_D_NAMELEN
#define HAVE_DD_LOCK
#define MAXNAMLEN 255

#ifdef __cplusplus
extern "C" {
#endif
#include <os/dirent.h>


typedef struct {
	int dd_fd;
	int dd_loc;
	int dd_seek;
	char *dd_buf;
	int dd_len;
	int dd_size;
	_LOCK_RECURSIVE_T dd_lock;
} DIR;

#ifdef __cplusplus
}
#endif

/* --- redundant --- */

DIR *opendir(const char *);
struct dirent *readdir(DIR *);
void rewinddir(DIR *);
int closedir(DIR *);

/* internal prototype */
void _seekdir(DIR *dir, long offset);
DIR *_opendir(const char *);

#ifndef _POSIX_SOURCE
long telldir (DIR *);
void seekdir (DIR *, off_t loc);

int scandir (const char *__dir,
		             struct dirent ***__namelist,
			                  int (*select) (const struct dirent *),
					               int (*compar) (const struct dirent **, const struct dirent **));

int alphasort (const struct dirent **__a, const struct dirent **__b);
#endif /* _POSIX_SOURCE */

#endif
