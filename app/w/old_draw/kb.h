#ifndef _KB_H_
#define _KB_H_
#include <type.h>
#include <libc/kstru.h>
#include "w.h"


void kb_do_km_keypress(WINFO *pwinfo, MSG *pmsg);
int kb_init(WINFO *pwinfo);
int kb_exit(WINFO *pwinfo);


#endif
