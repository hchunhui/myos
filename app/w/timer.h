#ifndef _TIMER_H_
#define _TIMER_H_
#include <libc/kstru.h>
#include "w.h"

void timer_do_km_timer(WInfo *pwinfo, MSG *pmsg);
int timer_init(WInfo *pwinfo);
int timer_exit(WInfo *pwinfo);


#endif
