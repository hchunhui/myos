#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <drv/i8042.h>
#include <drv/input.h>
#include <drv/video.h>
#include <drv/serial.h>
#include <drv/virtio.h>

#include <os/io.h>

void drv_init()
{
	dev_register(DEV_MAJOR_VIDEO, &video_dev_desc);
	dev_register(DEV_MAJOR_INPUT, &inputsys_dev_desc);
	dev_register(DEV_MAJOR_KB, &i8042_dev_desc);
	dev_register(DEV_MAJOR_SERIAL, &serial_dev_desc);
	dev_register(DEV_MAJOR_VIRTIO, &virtio_dev_desc);
}
