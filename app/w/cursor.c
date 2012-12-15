#include <libc/libc.h>
#include "cursor.h"
#include "draw.h"
#include "w.h"

static u16 curmem[12*20 + 40];
static DrawCanvas _cursor;
static DrawCanvas * const cursor = &_cursor;

static char mbmp[10*1024];
void cursor_init(WInfo *pwinfo)
{
	int fd;
	cursor->video = curmem;
	cursor->x = 12;
	cursor->y = 20;
	cursor->depth = 16;
	
	fd = open("/share/cursor.bmp", 0);
	if(fd < 0)
	{
		printf("can't find cursor.bmp!\n");
		exit(1);
	}
	read(fd, mbmp, 10*1024);
	close(fd);
	
	draw_bmp(cursor, 0, 0, mbmp, 0, 0);
	pwinfo->cursor = cursor;
}



