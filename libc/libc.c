#include <os/type.h>
#include <os/unistd.h>
#include <libc/libc.h>
#include <lib/string.h>

extern char **environ;
clock_t clock()
{
	return usr_sys_call0(__NR_get_utime);
}
#define RAND_MAX 0x7fff
static unsigned long long next;
int
rand(void)
{
  /* This multiplier was obtained from Knuth, D.E., "The Art of
     Computer Programming," Vol 2, Seminumerical Algorithms, Third
     Edition, Addison-Wesley, 1998, p. 106 (line 26) & p. 108 */
  next = next * 6364136223846793005LL + 1;
  /* was: next = next * 0x5deece66dLL + 11; */
  return (int)((next >> 32) & RAND_MAX);
}

void
srand(unsigned seed)
{
  next = seed;
}


long gettime()
{
	return usr_sys_call0(__NR_gettime);
}

int fork()
{
	return usr_sys_call0(__NR_fork);
}

void exit(int err_code)
{
	usr_sys_call1(__NR_exit,err_code);
}


int waitpid(int pid,int* status,int options)
{
	return usr_sys_call3(__NR_waitpid,pid,status,options);
}


int execve(char *path, char *argv[], char *envp[])
{
	return usr_sys_call3(__NR_execve, path, argv, envp);
}

int execv(char *path, char *argv[])
{
	return execve(path, argv, environ);
}

int execl(char *path, char *arg, ...)
{
	return execve(path, &arg, environ);
}

int execle(char *path, char *arg, ...)
{
	char **ptr;
	for(ptr = &arg; *ptr; ptr++);
	ptr = (char **)*(ptr+1);
	return execve(path, &arg, ptr);
}

void getline(char* buf)
{
	int n;
	n = read(0, buf, 256);
	buf[n] = 0;
}

void uprint(char* obj)
{
	int len, n;
	len = strlen(obj);
	while(len)
	{
		n = write(1, obj, len);
		obj += n;
		len -= n;
	}
}

int get_graph_info(struct myos_graph_info *info)
{
	int ret;
	int fd;
	fd = open("/dev/video/0", 0);
	ret = ioctl(fd, VIDEO_CMD_GET_INFO, info);
	close(fd);
	return ret;
}

int send(int pid_to, MSG *m)
{
	return usr_sys_call2(__NR_send, pid_to, m);
}

int recv(int pid_from, MSG *m, int block)
{
	return usr_sys_call3(__NR_recv, pid_from, m, block);
}

int getpid()
{
	return usr_sys_call0(__NR_getpid);
}

int getppid()
{
	return usr_sys_call0(__NR_getppid);
}

int shm_at(int key, void *base_addr, unsigned int flag)
{
	return usr_sys_call3(__NR_shm_at, key, base_addr, flag);
}

int shm_dt(int key, void *base_addr)
{
	return usr_sys_call2(__NR_shm_dt, key, base_addr);
}

int shm_get(int key, unsigned long size)
{
	return usr_sys_call2(__NR_shm_get, key, size);
}

int shm_free(int key)
{
	return usr_sys_call1(__NR_shm_free, key);
}

int read(int fd, void *buf, ssize_t count)
{
	return usr_sys_call3(__NR_read, fd, buf, count);
}

int write(int fd, void *buf, ssize_t count)
{
	return usr_sys_call3(__NR_write, fd, buf, count);
}

int open(char *name, int flags)
{
	return usr_sys_call2(__NR_open, name, flags);
}

int close(int fd)
{
	return usr_sys_call1(__NR_close, fd);
}

int ioctl(int fd, int cmd, void *arg)
{
	return usr_sys_call3(__NR_ioctl, fd, cmd, arg);
}

int nice(int nice)
{
	return usr_sys_call1(__NR_nice, nice);
}

int dup2(int oldfd, int newfd)
{
	return usr_sys_call2(__NR_dup2, oldfd, newfd);
}

int tty_switch(int dummy)
{
}

int mknod(char *name, int type)
{
	return usr_sys_call2(__NR_mknod, name, type);
}

int readdir(int fd, struct dirent *dirp, int count)
{
	return usr_sys_call3(__NR_readdir, fd, dirp, count);
}

int fstat(int fd, struct stat *stat)
{
	return usr_sys_call2(__NR_fstat, fd, stat);
}
