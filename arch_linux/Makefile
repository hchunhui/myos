everything:
	make -C init
	make -C kernel
	make -C lib
dep:
	make -C init dep
	make -C kernel dep
	make -C lib dep
clean:
	make -C init clean
	make -C kernel clean
	make -C lib clean
all: clean everything
.PHONY:all everything clean dep

