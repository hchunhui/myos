AUTOOBJS=
QEMU=qemu-system-i386
QEMU_LINE=-s -kernel mykern.bin -initrd initrd.tar -m 128 -localtime
everything: mk1 mykern.bin
include Makefile.arch
.PHONY: all cemu emu kvm everything clean bx dep user x86 linux
all:clean everything
clean: clean1
x86:
	rm -f Makefile.arch
	ln -s Makefile.arch_x86 Makefile.arch
	rm -f arch
	ln -s arch_x86 arch
linux:
	rm -f Makefile.arch
	ln -s Makefile.arch_linux Makefile.arch
	rm -f arch
	ln -s arch_linux arch
kvm: everything
	$(QEMU) -enable-kvm $(QEMU_LINE)
emu: everything
	$(QEMU) -no-kvm $(QEMU_LINE)
cemu: everything
	$(QEMU) -no-kvm $(QEMU_LINE) -display curses
demu: everything
	$(QEMU) -no-kvm -S $(QEMU_LINE) -localtime &
	xterm gdb
bx: everything
	bochs -f new.bxrc
user:
	make -C userspace
mktar:
	mkdir -p root
	mkdir -p root/bin
	mkdir -p root/share
	mkdir -p root/home
	rm -f initrd.tar
	-cp userspace/bin/* root/bin
	-strip root/bin/*
	cd root;tar cvf ../initrd.tar *;cd ..
mkimg: mktar mount_img domkimg umount_img
domkimg:
	sudo rm -f mnt/*.bin
	sudo rm -f mnt/boot/grub/menu.lst
	sudo cp mykern.bin mnt/
	sudo cp menu.lst mnt/boot/grub/menu.lst
	sudo cp initrd.tar.gz mnt/
mount_img:
	sudo mount `sudo losetup -o 32256 --find --show new.img` mnt
umount_img:
	sudo umount mnt
	sudo losetup -d /dev/loop0
dep: dep1

##dep
