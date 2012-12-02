/*
 *  input
 */
#include <os/arch_config.h>
#include <os/type.h>
#include <lib/klib.h>
#include <os/isr.h>
#include <os/io.h>
#include <os/sem.h>
#include <os/fork.h>
#include <lib/list.h>
#include <lib/string.h>
#include <drv/input.h>
#include <os/asm.h>

#define FLIP_MAX 32
struct s_client
{
	struct list_head list;
	int mode;
	int flip;
	struct s_event flipbuf[2][FLIP_MAX];
	int intr_n;
	int user_i, user_left;
	sem_t sem;
	struct list_head poll_read;
};


struct list_head client_list[INPUT_MINOR_MAX];

static int
flip_buffer(struct s_client *client)
{
	if(client->intr_n)
	{
		disable_irq();
		client->flip = !client->flip;
		client->user_left = client->intr_n;
		sem_init(&client->sem, 0);
		client->intr_n = 0;
		enable_irq();
		client->user_i = 0;
		return 1;
	}
	//printk("can not flip\n");
	return 0;
}

static int
input_open(int minor, int mode, void **data)
{
	struct s_client *client;
	if(minor < 0 || minor >= INPUT_MINOR_MAX)
		return 1;
	client = kmalloc(sizeof(struct s_client));
	client->mode = mode;
	client->flip = 0;
	client->intr_n = 0;
	client->user_i = 0;
	client->user_left = 0;
	sem_init(&client->sem, 0);
	INIT_LIST_HEAD(&client->poll_read);
	disable_irq();
	list_add(&client->list, &client_list[minor]);
	enable_irq();
	*data = client;
	return 0;
}

static long
input_read(int minor, void *data, void *buf, long n, long off)
{
	struct s_client *client = data;
	struct s_client *p;
	struct poll_sem *upsem;
	int m = n;
	while(m >= sizeof(struct s_event))
	{
		if(!client->user_left)
		{
			while(!flip_buffer(client))
				sem_down(&client->sem);
		}
		memcpy(buf + n - m,
		       &client->flipbuf[client->flip][client->user_i],
		       sizeof(struct s_event));
		client->user_i++;
		client->user_i %= FLIP_MAX;
		client->user_left--;
		m -= sizeof(struct s_event);
	}
	if(client->user_left)
	{
		list_for_each_entry(p, &client_list[minor], list)
		{
			list_for_each_entry(upsem, &p->poll_read, list)
				sem_up(upsem->sem);
		}
	}
	return n - m;
}

static int
input_close(int minor, void *data)
{
	struct s_client *client = data;
	struct s_client *p;
	list_for_each_entry(p, &client_list[minor], list)
	{
		if(p == client)
			goto ok;
	}
	printk("input_close: can not find this client.\n");
	return -1;
ok:
	list_del(&p->list);
	kfree(p);
	return 0;
}

static int input_ctl(int minor, void *data, int cmd, void *arg)
{
	return 0;
}

static int input_init()
{
	int i;
	for(i = 0; i < INPUT_MINOR_MAX; i++)
		INIT_LIST_HEAD(&client_list[i]);
	printk("input up\n");
	return 0;
}

static int input_exit()
{
	printk("input down\n");
	return 0;
}

static int input_poll(int minor, void *data, int func, struct list_head *lsem)
{
	struct s_client *client = data;
	switch(func)
	{
	case POLL_FUNC_READABLE:
		if(!client->user_left && !flip_buffer(client))
			return 0;
		return 1;
	case POLL_FUNC_WRITEABLE:
		return 0;
	case POLL_FUNC_REGISTER:
		disable_irq();
		list_add_tail(lsem, &client->poll_read);
		enable_irq();
		return 0;
	case POLL_FUNC_UNREGISTER:
		disable_irq();
		list_del(lsem);
		enable_irq();
		return 0;
	}
	return -1;
}

struct dev_desc inputsys_dev_desc = {
	.name = "input",
	.init = input_init,
	.exit = input_exit,
	.open = input_open,
	.close = input_close,
	.ctl = input_ctl,
	.read = input_read,
	.poll = input_poll,
};

static struct input_dev_desc *idev_desc[INPUT_MINOR_MAX];
int input_dev_register(int minor, struct input_dev_desc *desc)
{
	assert(minor >= 0 && minor < INPUT_MINOR_MAX);
	if(idev_desc[minor])
		return -1;
	idev_desc[minor] = desc;
	idev_desc[minor]->minor = minor;
	printk("input_dev_register: name %s  minor %d\n",
	       desc->name,
	       minor);
	if(desc->init)
		if(desc->init())
		{
			idev_desc[minor] = NULL;
			printk("input_dev_register: init fail\n");
			return -1;
		}
	return 0;
}

int input_dev_unregister(int minor)
{
	assert(minor >= 0 && minor < INPUT_MINOR_MAX);
	if(idev_desc[minor]->exit)
		if(idev_desc[minor]->exit())
		{
			printk("input_dev_unregister: exit fail\n");
			return -1;
		}
	idev_desc[minor] = NULL;
	return 0;
}

void input_dev_event(struct input_dev_desc *desc, struct s_event *event)
{
	struct s_client *p;
	struct poll_sem *upsem;
	int minor = desc->minor;
	list_for_each_entry(p, &client_list[minor], list)
	{
		if(p->intr_n == 0)
		{
			sem_up(&p->sem);
			list_for_each_entry(upsem, &p->poll_read, list)
				sem_up(upsem->sem);
		}
		if(p->intr_n >= FLIP_MAX)
		{
			printk("input_dev_event: flipbuf full\n");
			continue;
		}
		memcpy(&p->flipbuf[!p->flip][p->intr_n],
		       event,
		       sizeof(struct s_event));
		p->intr_n++;
	}
}
