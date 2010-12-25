#! /bin/bash -e

export TOP="$PWD"

if [ ! -f "$TOP"/prepare-mb-gcc4.sh ]; then
    cd "$TOP"/mb_gnu
    ./build_binutils.sh
    ./build_elf2flt.sh
    ./build_gcc.sh
    ./build_gdb.sh
    ./build_genromfs.sh
    echo "PATH=\"$TOP/mb_gnu/release/lin64/bin:$TOP/mb_gnu/release/lin/bin:\$PATH\"" >"$TOP"/prepare-mb-gcc4.sh
fi
