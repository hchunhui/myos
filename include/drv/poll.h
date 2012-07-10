#ifndef _POLL_H_
#define _POLL_H_

#define POLL_CMD_SET 1
#define POLL_CMD_UNSET 2

#define POLL_TYPE_READ 1
#define POLL_TYPE_WRITE 2
#define POLL_TYPE_EXCEPT 4
struct s_poll_event {
	int fd;
	unsigned int type;
};

#endif /* _POLL_H_ */
