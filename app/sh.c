#include <libc/libc.h>
char buf[100];

void float_test()
{
	double f, b;
	for(b = 0; ; b+=0.1)
		f = b * b + 0.9;
}

void ll(char *path)
{
	int fd, fd2;
	struct dirent dbuf;
	struct stat stat;
	int isdir;
	char buf[256];
	fd = open(path, 0);
	printf("%s\n", path);
	while(readdir(fd, &dbuf, 1) == 1)
	{
		strcpy(buf, path);
		strcat(buf, "/");
		strcat(buf, dbuf.d_name);
		fd2 = open(buf, 0);
		fstat(fd2, &stat);
		close(fd2);
		isdir = stat.st_mode;
		printf("%20s %5s %6d (%8x)\n",
		       dbuf.d_name,
		       isdir ? "<dir>" : "",
		       stat.st_size,
		       dbuf.inode);
	}
	close(fd);
}

void touch(char *name)
{
	mknod(name, 0);
}

void mkdir(char *name)
{
	mknod(name, 1);
}

void cat(char *name)
{
	int fd;
	int n, m, cnt;
	char buf[256];
	char *p;
	fd = open(name, 0);
	cnt = 0;
	while((n = read(fd, buf, 256)) > 0)
	{
		p = buf;
		cnt += n;
		while(n)
		{
			m = write(1, p, n);
			n -= m;
			p += m;
		}
	}
	close(fd);
	printf("\ncat: %d bytes!\n", cnt);
}

extern char **environ;
int main(int argc, char **argv)
{
	char *p;
	printf(
		"Alt+(1,2,3,4) : change console.\n"
		"Alt+5         : graphic mode.\n"
		"/w.bin        : a window manager.\n"
		"/task2.bin    : a window.\n"
		"/gauss.bin    : gauss elimination method.\n\n"
		);
	for(;;)
	{
		printf("#");
		//scanf("%s",buf);
		getline(buf);
		for(p=buf;*p!='\n';p++);
		*p='\0';
		if(strcmp(buf,"exit")==0)
		{
			exit(0);
		}
		else if(buf[0] == 'l' && buf[1] == 'l' && buf[2] == ' ')
		{
			ll(buf+3);
		}
		else if(buf[0] == 't' && buf[1] == 'o' && buf[2] == 'u' &&
			buf[3] == 'c' && buf[4] == 'h' && buf[5] == ' ')
		{
			touch(buf+6);
		}
		else if(buf[0] == 'm' && buf[1] == 'k' && buf[2] == 'd' &&
			buf[3] == 'i' && buf[4] == 'r' && buf[5] == ' ')
		{
			mkdir(buf+6);
		}
		else if(buf[0] == 'c' && buf[1] == 'a' && buf[2] == 't' &&
			buf[3] == ' ')
		{
			cat(buf+4);
		}
		else if(buf[0]=='\0')
		{
			//no operation
		}
		else if(buf[0]=='/')
		{
			int i, len, j;
			char *xargv[10]={0};
			len = strlen(buf);
			buf[len] = 0;
			j = 0;
			xargv[0] = buf;
			for(i = 0; i < len; i++)
				if(buf[i] == ' ')
				{
					buf[i] = 0;
					xargv[++j] = buf+i+1;
				}
			if(vfork()==0)
			{
				exit(execve(buf, xargv, environ));
			}
			int status,pid;
			pid=waitpid(-1,&status,0);
			printf("\npid=%d exit code=%d\n",pid,status);
		}
		else if(strlen(buf)>2 && buf[0]=='&' && buf[1]=='/')
		{
			if(vfork()==0)
			{
				exit(execle(buf+1, buf, 0, environ));
			}
		}
		else if(buf[0] == '!')
		{
			printf("testing float\n");
			float_test();
		}
		else
		{
			printf("Unknown commmand line.\n");
		}
	}
	return 0;
}

