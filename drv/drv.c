#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <drv/i8042.h>
#include <drv/input.h>
#include <drv/video.h>

//some device for kernel use
struct d_devfs den_video = {
	.major = DEV_MAJOR_VIDEO,
	.minor = 0,
	.data = NULL,
};

struct d_devfs den_input = {
	.major = DEV_MAJOR_INPUT,
	.minor = 0,
	.data = NULL,
};

struct d_devfs den_kb = {
	.major = DEV_MAJOR_KB,
	.minor = 0,
	.data = NULL,
};

void drv_pre_init()
{
	dev_register(DEV_MAJOR_VIDEO, &video_dev_desc);
	fsys_devfs.open(&den_video, 0);
}

void drv_post_init()
{
	dev_register(DEV_MAJOR_INPUT, &inputsys_dev_desc);
	dev_register(DEV_MAJOR_KB, &i8042_dev_desc);
	fsys_devfs.open(&den_kb, 0);
}
