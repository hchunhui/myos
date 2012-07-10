#ifndef _MESSAGE_H
#define _MESSAGE_H
#include <libc/kstru.h>
struct s_task;
int do_send(int pid_to, MSG *m, int is_kernel);
int do_recv(int pid_from, MSG *m, int block);
int do_send_to_user(MSG *m);
void message_init(struct s_task *ptask);
void message_exit(struct s_task *ptask);
//有些在libc/kstru.h
#endif
