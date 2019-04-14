TOPDIR = .
EXTRA_CLEAN = mykern.x mykern.bin
SUBDIRS = ${TOP_SUBDIRS}
PROG = mykern.x
OBJS = ${TOP_OBJS}

.PHONY: everything
everything: all
	${MAKE} mykern.bin

-include Makefile.arch

.PHONY: cemu emu kvm bx dep user x86 linux
QEMU=qemu-system-i386
QEMU_LINE=-s -kernel mykern.bin -initrd initrd.tar,ports.tar -m 128 #-drive file=a.img,if=virtio -net nic,model=virtio -net tap

x86:
	rm -f Makefile.arch
	ln -s Makefile.arch_x86 Makefile.arch
	${MAKE} clean
linux:
	rm -f Makefile.arch
	ln -s Makefile.arch_linux Makefile.arch
	${MAKE} clean
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
	${MAKE} -C userspace
	${MAKE} -C userspace install
mktar:
	mkdir -p root
	mkdir -p root/bin
	mkdir -p root/share
	mkdir -p root/home
	rm -f initrd.tar
	-cp userspace/bin/* root/bin
	-strip root/bin/*
	cd root;tar cvf ../initrd.tar *;cd ..
	rm -f ports.tar
	touch ports.tar
	-cp userspace/ports/ports.tar .

mkimg: mktar mount_img domkimg umount_img
domkimg:
	sudo rm -f mnt/*.bin
	sudo rm -f mnt/boot/grub/menu.lst
	sudo cp mykern.bin mnt/
	sudo cp menu.lst mnt/boot/grub/menu.lst
	sudo cp initrd.tar mnt/
mount_img:
	sudo mount `sudo losetup -o 32256 --find --show new.img` mnt
umount_img:
	sudo umount mnt
	sudo losetup -d /dev/loop0
