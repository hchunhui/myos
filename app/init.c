#include <libc/libc.h>

char buf[256];
char *tty_argv[] = {
	"*tty*",
	0
};

extern char **environ;
int video_fd;

void t_print(char *str)
{
	write(video_fd, str, strlen(str));
}

int main(int argc, char **argv)
{
	int ret, status, pid;

	video_fd = open("/dev/video/0", 0);
	while(1)
	{
		t_print("spawning tty driver...\n");
		if((ret = vfork()) == 0)
		{
			close(video_fd);
			exit(execve("/tty.bin", tty_argv, environ));
		}
		else if(ret < 0)
			break;
		pid = waitpid(-1,&status,0);
		sprintf(buf, "driver(pid=%d) exit with code %d\n", pid, status);
		t_print(buf);
	}
	return 1;
}
