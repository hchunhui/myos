#ifndef _MOUSE_H_
#define _MOUSE_H_
#include <libc/kstru.h>
#include "w.h"

void mouse_do_km_mouseact(WInfo *pwinfo, MSG *pmsg);
int mouse_init(WInfo *pwinfo);
int mouse_exit(WInfo *pwinfo);


#endif
