#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

void do_cat(int fd)
{
	char buf[4096];
	char *p;
	int n, m;
	while((n = read(fd, buf, 4096)) > 0)
	{
		p = buf;
		while(n)
		{
			m = write(1, p, n);
			if(m < 0)
				return;
			n -= m;
			p += m;
		}
	}
}

int cat_main(int argc, char **argv)
{
	int i;
	int fd;
	char *tmp;
	if(argc == 1)
		do_cat(0);
	else {
		for(i = 1; i < argc; i++)
		{
			fd = open(argv[i], O_RDONLY);
			if(fd < 0) {
				tmp = strerror(errno);
				write(2, argv[0], strlen(argv[0]));
				write(2, ": ", 2);
				write(2, argv[1], strlen(argv[1]));
				write(2, ": ", 2);
				write(2, tmp, strlen(tmp));
				write(2, "\n", 1);
			} else {
				do_cat(fd);
				close(fd);
			}
		}
	}
	return 0;
}


int main(int argc, char **argv)
{
	return cat_main(argc, argv);
}

