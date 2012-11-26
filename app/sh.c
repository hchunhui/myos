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

extern char **environ;
int main(int argc, char **argv)
{
	char *p;

	mknod("/a", 0);
	mknod("/dir", 1);
	mknod("/dir/a", 0);
	mknod("/dir/b", 0);
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
		else if(buf[0]=='\0')
		{
			//no operation
		}
		else if(buf[0]=='/')
		{
			if(vfork()==0)
			{
				exit(execle(buf, buf, 0, environ));
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

