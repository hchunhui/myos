#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;
const char *prompt;

void spawn(char **argv)
{
	int fd;
	int pid, status;
	char buf[256];

	strcpy(buf, argv[0]);
	fd = open(buf, O_RDONLY);
	if(fd > 0)
		goto do_spawn;
	strcpy(buf, "/bin/");
	strcat(buf, argv[0]);
	fd = open(buf, O_RDONLY);
	if(fd > 0)
		goto do_spawn;
	printf("bad command.\n");
	return;
do_spawn:
	close(fd);
	if(fork() == 0)
		_exit(execve(buf, argv, environ));
	pid = wait(&status);
	printf("pid = %d, status = %d\n", pid, status);
}

int xsh_main(int argc, char **argv)
{
	char line[256];
	prompt = getenv("PS1");
	if(prompt == NULL)
		prompt = "xsh # ";
	for(;;)
	{
		int i;
		char *xargv[64] = {0};
		char *saveptr;
		printf("%s", prompt);
		fflush(stdout);
		fgets(line, 256, stdin);
		line[strlen(line) - 1] = 0;

		/* parse arg */
		i = 0;
		xargv[i++] = strtok_r(line, " ", &saveptr);
		if(xargv[0] == NULL)
			continue;
		for(;xargv[i++] = strtok_r(NULL, " ", &saveptr);)
			;

		if(strcmp(xargv[0], "exit") == 0)
			exit(0);
		spawn(xargv);
	}
	return 0;
}


int main(int argc, char **argv)
{
	return xsh_main(argc, argv);
}

