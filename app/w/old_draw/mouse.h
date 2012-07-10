#ifndef _MOUSE_H_
#define _MOUSE_H_
#include <type.h>
#include <libc/kstru.h>
#include "w.h"

void mouse_do_km_mouseact(WINFO *pwinfo, MSG *pmsg);
int mouse_init(WINFO *pwinfo);
int mouse_exit(WINFO *pwinfo);


#endif
