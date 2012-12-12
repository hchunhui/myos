#include <libc/libc.h>
#include <drv/pipe.h>


char buf[256];
extern char **environ;
int main(int argc,char **argv)
{
	int ret, status, pid;
	int pub_fd, priv_fd;
	int in_fd = 8, out_fd = 9;
	if(argc == 1)
		exit(1);
	pub_fd = open("/dev/pipe/1", 0);
	priv_fd = open("/dev/pipe/0", 0);
	/* send priv_fd to server */
	while(ioctl(pub_fd, PIPE_CMD_SENDFD, priv_fd) < 0)
		;
	write(pub_fd, " ", 1);

	/* recv fd from server via priv_fd */
	write(priv_fd, &argv[1][0], 1);
	ioctl(priv_fd, PIPE_CMD_RECVFD, &in_fd);
	argv[1][0] += 3;
	write(priv_fd, &argv[1][0], 1);
	ioctl(priv_fd, PIPE_CMD_RECVFD, &out_fd);
	write(priv_fd, "X", 1);
	close(priv_fd);
	close(pub_fd);
	dup2(in_fd, 0);
	dup2(out_fd, 1);
	dup2(out_fd, 2);
	close(in_fd);
	close(out_fd);
	execl("/bin/sh.bin", "*sh*", 0);
	return 1;
}
