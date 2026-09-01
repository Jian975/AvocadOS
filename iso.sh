#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/AvocadOS.kernel isodir/boot/AvocadOS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "AvocadOS" {
     multiboot /boot/AvocadOS.kernel
}
EOF
grub-mkrescue -o AvocadOS.iso isodir
