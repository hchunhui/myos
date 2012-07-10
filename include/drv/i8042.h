#ifndef _I8042_H_
#define _I8042_H_

extern struct dev_desc i8042_dev_desc;
#define I8042_CMD_SETCMD  1
#define I8042_CMD_SETCNTL 2
#define I8042_CMD_GETCNTL 3
#define I8042_CMD_GETSTAT 4
#define I8042_CMD_GETOBUF 5
#define I8042_CMD_SETIBUF 6

#endif /* _I8042_H_ */
