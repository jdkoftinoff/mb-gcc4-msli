#
#  Build Binutils
#

#  Source and patches
BINVER=2.16

CFLAGS="-O2"

. common.sh

# Override source directory
SRCDIR=$SRCDIR/binutils
TARGET=microblaze-xilinx-elf
SYSROOT=$RELDIR/$TARGET
BLDDIR=$BLDDIR/bld_bin
BINDIR=$RELDIR/bin

DESC="Build\t\t: binutils-$BINVER"
echo $SEPARATOR
echo -e $DESC
echo -e "Target\t\t: $TARGET"
echo -e "CWD\t\t: $CURDIR"
echo -e "CFLAGS\t\t: $CFLAGS"
echo -e "Version String\t: $TOOL_VERSION"
echo -e "Platform\t: $PLATFORM"
echo -e "Build started\t: `date`"

rm -rf $BLDDIR/binutils
rm -rf $BLDDIR/build
rm -rf $BLDDIR/log
mkdir -p $BLDDIR/build
mkdir -p $BLDDIR/log

if [ ! -d $RELDIR ]; then mkdir -p $RELDIR; fi

errors=0

#  Create build directory
cd $BLDDIR/build

# Use back-rev gcc if available
if [ -d /usr/local/bin/gcc-3.4.6 ]; then
  PATH=/usr/local/bin/gcc-3.4.6/bin:$PATH
fi

echo -n "Configuring..."
$SRCDIR/configure 			\
    --target=$TARGET			\
    --prefix=$RELDIR 			\
    --program-prefix="mb-" 		\
    --with-sysroot=$SYSROOT             \
    > $BLDDIR/log/binutils-config.log 2>&1 
print_err " rc = " $?

if [ $NOBUILD = 0 ]; then 
  echo -n "Compiling..."
  $MAKE all CFLAGS="$CFLAGS"			\
		> $BLDDIR/log/binutils-make.log 2>&1
  rc=$?
  print_err " rc = " $rc
  echo -n "Installing..."
  $MAKE install CFLAGS="$CFLAGS" \
      > $BLDDIR/log/binutils-install.log 2>&1
  rc=$?
  print_err " rc = " $rc

  # Copy libbfd.a to release area
  mkdir -p $RELDIR/$TARGET/lib
  cp $BLDDIR/build/bfd/libbfd.a $RELDIR/$TARGET/lib
  rc=$?
  print_err "Installing libbfd.a... rc = " $rc

  # Copy libbfd headers
  mkdir -p $RELDIR/include
  cp $BLDDIR/build/bfd/bfd.h $RELDIR/include
  cp $SRCDIR/include/ansidecl.h $RELDIR/include
  cp $SRCDIR/include/bfdlink.h $RELDIR/include
  cp $SRCDIR/include/symcat.h $RELDIR/include
  rc=$?
  print_err "Installing libbfd headers... rc = " $rc

  echo -n "Configuring Gprof..."
  mkdir gprof
  cd gprof
  $SRCDIR/gprof/configure		\
      --target=$TARGET			\
      --prefix=$RELDIR 			\
      --program-prefix="mb-"       	\
      > $BLDDIR/log/gprof-config.log 2>&1
  rc=$?
  print_err " rc = " $rc
  
  echo -n "Compiling Gprof..."
  $MAKE all CFLAGS="$CFLAGS"			\
      > $BLDDIR/log/gprof-make.log 2>&1
  rc=$?
  print_err " rc = " $rc
  echo -n "Installing Gprof..."
  $MAKE install	CFLAGS="$CFLAGS"		\
      > $BLDDIR/log/gprof-install.log 2>&1
  rc=$?
  print_err " rc = " $rc
fi

cd $CURDIR
if [ $NOCLEAN = 0 ]; then
  rm -rf $BLDDIR
fi

echo "Build completed: `date`."
