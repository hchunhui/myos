#define MYOS
#ifndef MYOS
#include <windows.h>
#include <string.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <drv/pipe.h>
#include <drv/poll.h>
extern "C" {
#include <os/shm.h>
}
#include "../../w/draw.h"
#include "../../w/msg.h"
#include "../../../libkb/kb_state.h"
#endif

