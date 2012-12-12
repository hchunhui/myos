#include <libc/libc.h>

char buf[256];
char *tty_argv[] = {
	"*tty*",
	0
};

char *sh_argv[] = {
	"*login*",
	0,
	0,
};

extern char **environ;
int video_fd;

void t_print(char *str)
{
	write(video_fd, str, strlen(str));
}

int spawn(char *path, char **xargv)
{
	int ret;
	if((ret = vfork()) == 0)
	{
		close(video_fd);
		exit(execve(path, xargv, environ));
	}
	return ret;
}

int main(int argc, char **argv)
{
	int ret, status;
	int pid;
	int tty_pid, sh_pid[3];

	video_fd = open("/dev/video/0", 0);
	t_print("my os init...\n");
	t_print("spawning tty driver...\n");
	tty_pid = spawn("/bin/tty.bin", tty_argv);
	t_print("spawning shell...\n");
	sh_argv[1] = "1";
	sh_pid[0] = spawn("/bin/login.bin", sh_argv);
	sh_argv[1] = "2";
	sh_pid[1] = spawn("/bin/login.bin", sh_argv);
	sh_argv[1] = "3";
	sh_pid[2] = spawn("/bin/login.bin", sh_argv);
	while(1)
	{
		pid = waitpid(-1,&status,0);
		sprintf(buf, "(pid=%d) exit with code %d\n",
			pid, status);
		t_print(buf);
	}
	return 1;
}
