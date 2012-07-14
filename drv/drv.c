#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <drv/i8042.h>
#include <drv/input.h>
#include <drv/video.h>

//some device for kernel use
void *kb_data;
void *video_data;

void drv_pre_init()
{
	dev_register(DEV_MAJOR_VIDEO, &video_dev_desc);
	dev_simp_open(DEV_MAJOR_VIDEO, 0, 0, &video_data);
}

void drv_post_init()
{
	dev_register(DEV_MAJOR_INPUT, &inputsys_dev_desc);
	dev_register(DEV_MAJOR_KB, &i8042_dev_desc);
	dev_simp_open(DEV_MAJOR_KB, 0, 0, &kb_data);
}
