#!/bin/bash
function die() {
	echo 'Bootstrap Error: '$1
	exit 1
}

echo '----STEP 1: Build toolchain----'
if [ ! -f toolchain/crossenv ]; then
	cd toolchain
	./play || die "toolchain"
	cd ..
fi
. toolchain/crossenv

echo '----STEP 2: Build OS kernel----'
make x86 || die "kernel"
make || die "kernel"

echo '----STEP 3: Build Userspace----'
make user || die "userspace"

echo '----STEP 4: Build ports----'
git clone --recursive https://github.com/hchunhui/myos-ports.git userspace/ports
cd userspace/ports && make && make mktar && cd ../..

make mktar

echo 'type "make emu" to start!'
