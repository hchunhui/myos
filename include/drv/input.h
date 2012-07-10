#ifndef _INPUT_H_
#define _INPUT_H_

struct s_event
{
	long ticks;
	unsigned short type;
	unsigned short code;
	unsigned int value;
};

struct input_dev_desc
{
	char name[32];
	int minor;
	int (*init)();
	int (*exit)();
};

int input_dev_register(int minor, struct input_dev_desc *desc);
int input_dev_unregister(int minor);
void input_dev_event(struct input_dev_desc *desc, struct s_event *event);

extern struct dev_desc inputsys_dev_desc;

#define INPUT_MINOR_KBD 1
#define INPUT_MINOR_MOUSE 2
#define INPUT_MINOR_MAX 8
#endif /* _INPUT_H_ */
