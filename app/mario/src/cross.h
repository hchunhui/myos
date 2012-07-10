#define MYOS
#ifndef MYOS
#include <windows.h>
#include <string.h>
#else
#include <os/type.h>
#include <os/unistd.h>
#include <libc/kstru.h>
#include <libc/libc.h>
#include <lib/string.h>
#include "../../w/draw.h"
#endif

