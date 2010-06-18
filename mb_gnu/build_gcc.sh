#
#  Build GCC
#

#  Source and patches
GCCVER=4.1.2
NEWLIBVER=1.14.0
LIB_VARIANTS=newlib-variants

LANGS="c,c++"
CFLAGS="-O2"
CXXFLAGS="-O2"

. common.sh

# Override source directory
GCC_SRCDIR=$SRCDIR/gcc
NEWLIB_SRCDIR=$SRCDIR/newlib
TARGET=microblaze-xilinx-elf
SYSROOT=$RELDIR/$TARGET

BLDDIR=$BLDDIR/bld_gcc
BINDIR=$RELDIR/bin

DESC="Build\t\t: gcc-$GCCVER newlib-$NEWLIBVER"
echo $SEPARATOR
echo -e $DESC
echo -e "Target\t\t: $TARGET"
echo -e "CWD\t\t: $CURDIR"
echo -e "CFLAGS\t\t: $CFLAGS"
echo -e "Version String\t: $TOOL_VERSION"
echo -e "Platform\t: $PLATFORM"
echo -e "Build started: `date`"

rm -rf $BLDDIR/build
rm -rf $BLDDIR/log
mkdir -p $BLDDIR/build
mkdir -p $BLDDIR/log

if [ ! -d $RELDIR ]; then mkdir -p $RELDIR; fi

errors=0

# Set tool version 
echo $TOOL_VERSION > $GCC_SRCDIR/gcc/DEV-PHASE

#  Create build directory
cd $BLDDIR/build

# Use back-rev gcc if available
if [ -d /usr/local/bin/gcc-3.4.6 ]; then
  PATH=/usr/local/bin/gcc-3.4.6/bin:$PATH
fi

PATH=$BINDIR:$PATH

export AR_FOR_TARGET=mb-ar
export AS_FOR_TARGET=mb-as
echo -n "Configuring..."
$GCC_SRCDIR/configure 			\
    --target=$TARGET                    \
    --prefix=$RELDIR 			\
    --program-prefix="mb-" 		\
    --with-newlib			\
    --enable-languages=$LANGS		\
    --enable-multilib			\
    --with-sysroot=$SYSROOT             \
    --disable-libssp			\
    --disable-newlib-atexit-dynamic-alloc	\
    --enable-optimize-memory		\
    > $BLDDIR/log/gcc-config.log 2>&1 
    rc=$?
print_err " rc = " $rc

if [ $NOBUILD = 0 ]; then
  echo -n "Compiling..."
  $MAKE all CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS" 	\
		> $BLDDIR/log/gcc-make.log 2>&1 
  rc=$?
  print_err " rc = " $rc

  echo -n "Installing..."
  $MAKE install CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS"	\
      > $BLDDIR/log/gcc-install.log 2>&1
  rc=$?
  print_err " rc = " $rc
fi

cd $CURDIR

./build_newlib_variants.sh 

if [ $NOCLEAN = 0 ]; then
  rm -rf $BLDDIR
fi

echo "Build completed: `date`."