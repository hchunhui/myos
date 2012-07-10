#include <lib/klib.h>
#include <os/devfs.h>
#include <drv/i8042.h>
#include <drv/input.h>
void drv_kb_init();
void drv_video_init();
void drv_tty_init();
void drv_hd_init();
void drv_mouse_init();
void drv_speaker_init();

#define outportl(port, data)	asm ("outl %%eax, %%dx"::"a"(data),"d"(port))
#define inportl(port)		({unsigned int data;asm ("inl %%dx,%%eax":"=a"(data):"d"(port));data;})

void test_pci()
{
	unsigned int busNo, deviceNo, funcNo, regVal, retVal;
	unsigned int vendorID, devID, class3, class2, class1;
	int i;
	printk("pci test begin\n");
	printk("\nNo.  Vendor/Device  Bus No.  Dev No.  Func No.  Class");
	i = 0;
	for (busNo = 0; busNo < 5; busNo++) {                 // bus No
		for(deviceNo = 0; deviceNo < 32; deviceNo++) {      // device no
			for (funcNo = 0; funcNo < 8; funcNo++) {          // Function No
				regVal = 0x80000000                             // bit31 使能
				+ (busNo << 16)                        // Bus No
				+ (deviceNo << 11)                     // Device No
				+ (funcNo << 8);                       // Function No
				outportl(0xCF8, regVal);
				retVal = inportl(0xCFC);                        // 得到配置空间偏移为0的双字
				if (retVal != 0xffffffff) {                     // 设备存在
					i++;
					vendorID = retVal & 0xffff;                   // 得到供应商代码
					devID    = (retVal >> 16) & 0xffff;           // 得到设备代码
					regVal += 0x08;                               // 得到配置空间偏移为08H的双字
					outportl(0xCF8, regVal);
					retVal = inportl(0xCFC);
					retVal = retVal >> 8;                         // 滤掉版本号
					class3 = retVal & 0x0FF;                      // 得到三个分类代码
					class2 = (retVal >> 8) &0x0FF;
					class1 = (retVal >> 16) &0x0FF;
					printk("\n%02d   %04x/%04x       %02x       %02x       %02x      %02x-%02x-%02x",
						i, vendorID, devID, busNo, deviceNo, funcNo, class1, class2, class3);
					if (funcNo == 0) {                          // 如果是单功能设备，则不再查funcNo>0的设备
						regVal = (regVal & 0xFFFFFFF0) + 0x0C;
						outportl(0xCF8, regVal);
						retVal = inportl(0xCFC);
						retVal = retVal >> 16;
						if ((retVal & 0x80) == 0) funcNo = 8;
					}
				}
			}
		}
	}
	printk("\npci test end\n");
}

void drv_init()
{
	test_pci();
	//for(;;);
	/*drv_kb_init();
	  drv_mouse_init();*/
	dev_register(DEV_MAJOR_INPUT, &inputsys_dev_desc);
	dev_register(DEV_MAJOR_KB, &i8042_dev_desc);
	drv_video_init();
	drv_tty_init();
	drv_speaker_init();
	//drv_hd_init();
}
