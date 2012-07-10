#ifndef _TIMER_H_
#define _TIMER_H_
#include <type.h>
#include <libc/kstru.h>
#include "w.h"

void timer_do_km_timer(WINFO *pwinfo, MSG *pmsg);
int timer_init(WINFO *pwinfo);
int timer_exit(WINFO *pwinfo);


#endif
