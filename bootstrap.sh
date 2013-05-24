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
rm -f Makefile.arch
ln -s Makefile.arch_x86 Makefile.arch
rm -f arch
ln -s arch_x86 arch
make clean || die "kernel"
make || die "kernel"

echo '----STEP 3: Build Userspace----'
make user

