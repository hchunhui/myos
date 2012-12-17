#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <drv/i8042.h>
#include <drv/input.h>
#include <drv/video.h>

void drv_init()
{
	dev_register(DEV_MAJOR_VIDEO, &video_dev_desc);
	dev_register(DEV_MAJOR_INPUT, &inputsys_dev_desc);
	dev_register(DEV_MAJOR_KB, &i8042_dev_desc);
}
