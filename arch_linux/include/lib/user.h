#ifndef _USER_H_
#define _USER_H_

struct s_context;

int context_len();
void context_switch(struct s_context *p,
		    struct s_context *q);
void context_make(struct s_context *p,
		  unsigned long pc,
		  unsigned long sp);

void user_pause();
long user_read_rtc();
void user_ualarm(long t);

#endif /* _USER_H_ */
