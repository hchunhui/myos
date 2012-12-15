#define MYOS
#ifndef MYOS
#include <windows.h>
#include <string.h>
#else
#include <libc/libc.h>
#include <lib/string.h>
#include <drv/pipe.h>
#include <drv/poll.h>
#include "../../w/draw.h"
#include "../../w/msg.h"
#include "../../kb_state.h"
#endif

