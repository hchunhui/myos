#include <libc/libc.h>
#include <drv/input.h>
#include <drv/poll.h>
#include <drv/video.h>
#include <drv/klog.h>
#include <drv/pipe.h>

#define NR_TTY 4
#define TTY_BUF_SIZE (80*25*2)
struct s_tty
{
	u8 buffer[TTY_BUF_SIZE];
	int i;
	u8 pend[TTY_BUF_SIZE];
	int pi;
	int pipe_in;
	int pipe_out;
};

static struct s_tty tty[NR_TTY];
static struct s_tty *tty_now;
int video_fd;
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
//scan code 2 define
#define CODE_BRK	0xf0
#define CODE_EX0	0xe0
#define CODE_EX1	0xe1

#define CODE_LSHIFT		0x12
#define CODE_RSHIFT		0x59
#define CODE_LCTRL		0x14
#define CODE_RCTRL		0xe014
#define CODE_LALT		0x11
#define CODE_RALT		0xe011
#define CODE_BACK		0x66
#define CODE_ENTER		0x5a
#define CODE_NUMLOCK		0x77
#define CODE_CAPSLOCK		0x58
#define CODE_SCROLOCK		0x7e
#define CODE_UP			0xe075
#define CODE_DOWN		0xe072
#define CODE_LEFT		0xe06b
#define CODE_RIGHT		0xe074
#define CODE_DELETE		0xe071
#define CODE_PAD_DEL		0x71
#define CODE_ESC		0x76
#define LED_NUM			1
#define LED_CAPS		2
#define LED_SCRO		4

static int is_lshift,is_rshift,is_lctrl,is_rctrl,is_lalt,is_ralt;
static u32 led;

const char kb_table[2][256]=
{
	{
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,'\t','`',0,0,
	0,0,0,0,'q','1',0,0,0,'z','s','a','w','2',0,0,
	'c','x','d','e','4','3',0,0,' ','v','f','t','r','5',0,0,
	'n','b','h','g','y','6',0,0,0,'m','j','u','7','8',0,0,
	',','k','i','o','0','9',0,0,'.','/','l',';','p','-',0,0,
	0,'\'',0,'[','=',0,0,0,0,'\n',']',0,'\\',0,0,0,
	0,0,0,0,0,'\b',0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0x1b,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	{
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,'\t','~',0,0,
	0,0,0,0,'Q','!',0,0,0,'Z','S','A','W','@',0,0,
	'C','X','D','E','$','#',0,0,' ','V','F','T','R','%',0,0,
	'N','B','H','G','Y','^',0,0,0,'M','J','U','&','*',0,0,
	'<','K','I','O',')','(',0,0,'>','?','L',':','P','_',0,0,
	0,'"',0,'{','+',0,0,0,0,'\n','}',0,'|',0,0,0,
	0,0,0,0,0,'\b',0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0x1b,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
};

void kb_reboot()
{
	t_print("reboot\n");
}

void kb_halt()
{
	t_print("halt\n");
}

static void translate(unsigned short gcode, unsigned short is_brk)
{
	int delta;
	char ch;
	switch(gcode)
	{
	case CODE_LSHIFT:	is_lshift=!is_brk;break;
	case CODE_RSHIFT:	is_rshift=!is_brk;break;
	case CODE_LCTRL:	is_lctrl=!is_brk;break;
	case CODE_RCTRL:	is_rctrl=!is_brk;break;
	case CODE_LALT:		is_lalt=!is_brk;break;
	case CODE_RALT:		is_ralt=!is_brk;break;
	case CODE_NUMLOCK:	if(!is_brk)led=(led|LED_NUM)&(~(led&LED_NUM));break;
	case CODE_CAPSLOCK:	if(!is_brk)led=(led|LED_CAPS)&(~(led&LED_CAPS));break;
	case CODE_SCROLOCK:	if(!is_brk)led=(led|LED_SCRO)&(~(led&LED_SCRO));break;
	case CODE_ENTER:
	case CODE_BACK:
	default:
		if(is_lshift || is_rshift)
			ch=kb_table[!(led&LED_CAPS)][gcode&0xff];
		else
			ch=kb_table[!!(led&LED_CAPS)][gcode&0xff];
		if(is_brk)
			break;
		/* 处理控制键 */
		if( (is_lalt || is_ralt) && (is_lctrl || is_rctrl) && (ch=='h'))
		{
			kb_halt();
		}
		if( (is_lalt || is_ralt)  && (is_lctrl || is_rctrl) && (ch=='\b'))	//reboot
		{
			kb_reboot();
		}
		if( (is_lalt || is_ralt)  && (is_lctrl || is_rctrl) && (gcode==CODE_DELETE || gcode==CODE_PAD_DEL))	//reboot
		{
			kb_reboot();
		}
		if( (is_lalt || is_ralt) )
		{
			switch(ch)
			{
			case '1':
			case '2':
			case '3':
			case '4':
				switch_tty(tty + ch - '1');
				return;
			}
			switch(gcode)
			{
			case CODE_UP:
				delta = -1;
				ioctl(video_fd, VIDEO_CMD_DOWN_SCREEN, &delta);
				break;
			case CODE_DOWN:
				delta = 1;
				ioctl(video_fd, VIDEO_CMD_DOWN_SCREEN, &delta);
				break;
			}
			return;
		}
		if(ch==0)return;	//其他未处理字符不放入缓冲区
		put_tty(ch);
	}

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
	struct s_event event;
	read(fd, &event, sizeof(struct s_event));
	translate(event.code, event.value);
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
	if(buf[0] >= '1' && buf[0] <= '3') {
		//request stdin
		ioctl(fd, PIPE_CMD_SENDFD, tty[buf[0]-'1'].pipe_in);
	} else if(buf[0] >= '4' && buf[0] <= '6') {
		//request stdout
		ioctl(fd, PIPE_CMD_SENDFD, tty[buf[0]-'4'].pipe_out);
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
	is_lshift=0;
	is_rshift=0;
	is_lctrl=0;
	is_rctrl=0;
	is_lalt=0;
	is_ralt=0;
	led=0;
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

	/* setup pipe */
	for(i = 0; i < NR_TTY; i++)
	{
		tty[i].pipe_in = open("/dev/pipe/0", 0);
		tty[i].pipe_out = open("/dev/pipe/0", 0);
		poll_set_event(poll_fd, tty[i].pipe_out, POLL_TYPE_READ);
		act_func[tty[i].pipe_out] = act_ttyfd;
		extra[tty[i].pipe_out] = i;
	}

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
