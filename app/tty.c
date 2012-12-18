#include <libc/libc.h>
#include <drv/input.h>
#include <drv/poll.h>
#include <drv/video.h>
#include <drv/klog.h>
#include <drv/pipe.h>
#include "kb_state.h"

#define NR_TTY 6
#define TTY_BUF_SIZE (80*25*2)
struct s_tty
{
	u8 buffer[TTY_BUF_SIZE];
	int i;
	u8 pend[TTY_BUF_SIZE];
	int pi;
	int pipe_in;
	int pipe_out;
	int allow_input;
};

static struct s_tty tty[NR_TTY];
static struct s_tty *tty_now;
int video_fd;
int sefd;
int poll_fd;

extern char **environ;

void t_print(char *str)
{
	write(video_fd, str, strlen(str));
}

void write_tty(struct s_tty *tty, char *buf, int len)
{
	if(tty == tty_now)
	{
		write(video_fd, buf, len);
	}
	for(;len--;)
	{
		tty->buffer[tty->i] = *buf++;
		tty->i = (tty->i + 1)%TTY_BUF_SIZE;
	}
}

void echo_tty(int ch)
{
	u8 tmp[1] = {ch};
	write(video_fd, tmp, 1);
	tty_now->buffer[tty_now->i] = ch;
	tty_now->i = (tty_now->i + 1)%TTY_BUF_SIZE;
}

void put_tty(int ch)
{
	int n;
	if(tty_now->pi >= 80*25)
		t_print("input buffer full\n");
	if(ch == '\b') {
		if(tty_now->pi) {
			tty_now->pi--;
			goto echo;
		}
		else goto no_echo;
	}
	tty_now->pend[tty_now->pi] = ch;
	tty_now->pi++;
	if(ch == '\n') {
		n = write(tty_now->pipe_in, tty_now->pend, tty_now->pi);
		if(n < tty_now->pi)
			t_print("truncation\n");
		tty_now->pi = 0;
	}
echo:	echo_tty(ch);
no_echo:;
}

void clear_video()
{
	char *retchar =
		"\n\n\n\n\n\n\n\n\n\n"
		"\n\n\n\n\n\n\n\n\n\n"
		"\n\n\n\n\n";
	write(video_fd, retchar, 25);
}

void switch_tty(struct s_tty *tty)
{
	int i;
	clear_video();
	i = tty->i;
	if(i < TTY_BUF_SIZE/2)
		write(video_fd,
		      tty->buffer + TTY_BUF_SIZE/2,
		      TTY_BUF_SIZE/2);
	write(video_fd,
	      tty->buffer,
	      i);
	tty_now = tty;
}

void poll_set_event(int pollfd, int fd, int type)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = type;
	if(ioctl(pollfd, POLL_CMD_SET, &event))
		t_print ("ioctl error\n");
}

void poll_unset_event(int pollfd, int fd)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = 0;
	if(ioctl(pollfd, POLL_CMD_UNSET, &event))
		t_print ("ioctl error\n");
}

typedef int (*act_func_t)(int fd);
act_func_t act_func[64];
int extra[64];

int act_noop(int fd)
{
	return 0;
}

int act_kbfd(int fd)
{
	int delta;
	struct s_event event;
	struct kb_state *kbs;
	read(fd, &event, sizeof(struct s_event));

	kbs = kb_trans(event.code, event.value);
	if(kbs->state & KBS_BRK)
		return 0;
	if(kbs->state & KBS_LAL ||
	   kbs->state & KBS_RAL)
	{
		if(kbs->func >= KB_F1 && kbs->func < KB_F1 + NR_TTY)
			switch_tty(tty + kbs->func - KB_F1);
		if(kbs->func == KB_ARU)
		{
			delta = -1;
			ioctl(video_fd, VIDEO_CMD_DOWN_SCREEN, &delta);
		}
		if(kbs->func == KB_ARD)
		{
			delta = 1;
			ioctl(video_fd, VIDEO_CMD_DOWN_SCREEN, &delta);
		}
	}
	if(kbs->ch != 0 && tty_now->allow_input)
		put_tty(kbs->ch);
	return 0;
}

int act_settyfd(int fd)
{
	int n;
	char buf[640];
	char *prev, *now;
	prev = buf;
	n = read(fd, buf, 640);
	for(now = buf; now < buf+n; now++) {
		if(*now == '\n') {
			write(sefd, prev, now-prev);
			write(sefd, "\r", 1);
			prev = now;
		}
	}
	write(sefd, prev, now-prev);
	return 0;
}

void se_print(char *str)
{
	write(sefd, str, strlen(str));
}

int act_sefd(int fd)
{
	int i, n, m;
	char sebuf[256], ch;
	struct s_tty *setty = tty + 5;
	n = read(fd, sebuf, 256);
	for(i = 0; i < n; i++)
	{
		ch = sebuf[i];
		if(ch == '\r') ch = '\n';
		if(setty->pi >= 80*25)
			se_print("input buffer full\n");
		if(ch == '\b') {
			if(setty->pi) {
				setty->pi--;
				goto echo;
			}
			else continue;
		}
		setty->pend[setty->pi] = ch;
		setty->pi++;
		if(ch == '\n') {
			m = write(setty->pipe_in, setty->pend, setty->pi);
			if(m < setty->pi)
				se_print("truncation\n");
			setty->pi = 0;
		}
	echo:
		if(ch == '\n')
			write(sefd, "\r\n", 2);
		else
			write(sefd, &ch, 1);
	}
	return 0;
}

int act_msfd(int fd)
{
	struct s_event event;
	read(fd, &event, sizeof(struct s_event));
	return 0;
}

int act_klogfd(int fd)
{
	int n;
	char buf[640];
	n = read(fd, buf, 640);
	if(n > 0)
		write_tty(tty + 3, buf, n);
	return 0;
}

int act_ttyfd(int fd)
{
	int n;
	char buf[640];
	n = read(fd, buf, 640);
	write_tty(tty+extra[fd], buf, n);
	return 0;
}

int act_sendfd(int fd)
{
	char buf[2];
	buf[1] = 0;
	read(fd, buf, 1);
	if(buf[0] >= 'a' && buf[0] < 'a'+NR_TTY) {
		//request stdin
		ioctl(fd, PIPE_CMD_SENDFD, (void *)(tty[buf[0]-'a'].pipe_in));
	} else if(buf[0] >= 'A' && buf[0] < 'A'+NR_TTY) {
		//request stdout
		ioctl(fd, PIPE_CMD_SENDFD, (void *)(tty[buf[0]-'A'].pipe_out));
	} else {
		poll_unset_event(poll_fd, fd);
		act_func[fd] = act_noop;
		close(fd);
	}
	return 0;
}

int act_lisfd(int fd)
{
	char buf[1];
	int xfd;
	read(fd, buf, 1);
	xfd = -1;
	if(ioctl(fd, PIPE_CMD_TESTFD, 0))
	{
		ioctl(fd, PIPE_CMD_RECVFD, &xfd);
		if(xfd < 0)
			t_print("listen fd recv error!\n");
		poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
		act_func[xfd] = act_sendfd;
	}
	else
		t_print("bad protocol\n");
	return 0;
}

int main(int argc, char **argv)
{	
	int i;
	int xfd;
	struct s_poll_event poll_event;
	if(argc >= 1 && strcmp(argv[0], "*tty*"))
		exit(1);
	/* global var init */
	tty_now = tty;
	for(i = 0; i < 64; i++)
		act_func[i] = act_noop;
	/* setup fd */
	video_fd = open("/dev/video/0", 0);
	poll_fd = open("/dev/poll/0", 0);

	xfd = open("/dev/klog/0", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_klogfd;
	ioctl(xfd, KLOG_CMD_BEGIN, 0);

	xfd = open("/dev/input/1", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_kbfd;

	xfd = open("/dev/input/2", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_msfd;

	sefd = open("/dev/serial/0", 0);
	poll_set_event(poll_fd, sefd, POLL_TYPE_READ);
	act_func[sefd] = act_sefd;

	/* setup pipe */
	for(i = 0; i < NR_TTY; i++)
	{
		tty[i].allow_input = 1;
		tty[i].pipe_in = open("/dev/pipe/0", 0);
		tty[i].pipe_out = open("/dev/pipe/0", 0);
		poll_set_event(poll_fd, tty[i].pipe_out, POLL_TYPE_READ);
		act_func[tty[i].pipe_out] = act_ttyfd;
		extra[tty[i].pipe_out] = i;
	}
	tty[3].allow_input = 0;
	tty[4].allow_input = 0;
	tty[5].allow_input = 0;
	act_func[tty[5].pipe_out] = act_settyfd;

	xfd = open("/dev/pipe/1", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_lisfd;

	/* test arg */
	for(i = 0; i < argc; i++)
	{
		t_print(argv[i]);
		t_print("\n");
	}
	for(i = 0; environ[i]; i++)
	{
		t_print(environ[i]);
		t_print("\n");
	}

	/* main loop */
	for(;;)
	{
		if(read(poll_fd, &poll_event, sizeof(struct s_poll_event)) == -1)
			break;
		xfd = poll_event.fd;
		act_func[xfd](xfd);
	}
	return 0;
}
