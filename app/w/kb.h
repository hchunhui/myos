#ifndef _KB_H_
#define _KB_H_
#include <libc/kstru.h>
#include "w.h"


void kb_do_km_keypress(WInfo *pwinfo, MSG *pmsg);
int kb_init(WInfo *pwinfo);
int kb_exit(WInfo *pwinfo);


#endif
