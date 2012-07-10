#include <libc/libc.h>

char buf[256];
char *tty_argv[] = {
	"*tty*",
	0
};

extern char **environ;
int main(int argc, char **argv)
{
	int ret, status, pid;
	while(1)
	{
		printf("spawning tty driver...\n");
		if((ret = vfork()) == 0)
			exit(execve("/tty.bin", tty_argv, environ));
		else if(ret < 0)
			break;
		pid = waitpid(-1,&status,0);
		printf("shell(pid %d) exit with code %d\n",
		       pid,
		       status);
	}
	printf("can not spawn tty driver.\n");
	return 1;
}
