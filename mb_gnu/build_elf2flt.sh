
CURDIR=`pwd`
. ./common.sh
echo "----------------------------------------------------------------"
echo "Building MicroBlaze elf2flt"
## Orig Sources
ELF2FLT_SRC=$SRCDIR/elf2flt

## Build Directories
ELF2FLT_BLDDIR=$BLDDIR/bld_elf2flt

rm -rf ${ELF2FLT_BLDDIR}
mkdir -p ${ELF2FLT_BLDDIR}
mkdir -p $ELF2FLT_BLDDIR/log

## Build elf2flt
cd ${ELF2FLT_BLDDIR}
BINUTILS_SRCS=$SRCDIR/binutils
if [ -e Makefile ]; then
    make clean > /dev/null 2>&1
fi
echo -n "Configuring..."
${ELF2FLT_SRC}/configure --target=microblaze --prefix=${RELDIR} \
        --with-libbfd=${RELDIR}/microblaze-xilinx-elf/lib/libbfd.a \
        --with-libiberty=${RELDIR}/lib/libiberty.a --program-prefix mb \
        --with-bfd-include-dir=${RELDIR}/include \
        --with-binutils-include-dir=${BINUTILS_SRCS}/include \
	--disable-ld-elf2flt-binary \
	--enable-emit-ctor-dtor	--disable-emit-relocs --enable-always-reloc-text \
	> $ELF2FLT_BLDDIR/log/elf2flt-config.log 2>&1
print_err " rc = " $?

echo -n "Making..."
make all > $ELF2FLT_BLDDIR/log/elf2flt-make.log 2>&1
print_err " rc = " $?

echo -n "Installing..."
rm -f $RELDIR/mb
ln -s microblaze-xilinx-elf $RELDIR/mb
make install > $ELF2FLT_BLDDIR/log/elf2flt-install.log 2>&1
print_err " rc = " $?

if [ $NOCLEAN = 0 ]; then
   echo "Now cleaning -- uClinux tools"
   rm -rf ${BLDDIR}
fi
echo "Microblaze elf2flt Done"
echo "----------------------------------------------------------------"




