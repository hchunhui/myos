everything:
	make -C init
	make -C kernel
	make -C lib
	make -C drv
clean:
	make -C init clean
	make -C kernel clean
	make -C lib clean
	make -C drv clean
all: clean everything
.PHONY:all everything clean dep

