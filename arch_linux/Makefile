everything:
	make -C init
	make -C kernel
dep:
	make -C init dep
	make -C kernel dep
clean:
	make -C init clean
	make -C kernel clean
all: clean everything
.PHONY:all everything clean dep

