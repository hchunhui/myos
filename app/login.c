#include <libc/libc.h>

char buf[256];
extern char **environ;
int main(int argc,char **argv)
{
	int ret, status, pid;
	while(1)
	{
		printf("spawning shell...\n");
		if((ret = vfork()) == 0)
			exit(execl("/sh.bin", "*sh*", 0));
		else if(ret < 0)
			break;
		pid = waitpid(-1,&status,0);
		printf("shell(pid %d) exit with code %d\n",
		       pid,
		       status);
	}
	printf("can not spawn shell.\n");
	return 1;
}
