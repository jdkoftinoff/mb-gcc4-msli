#
#  Build GDB
#

#  Source and patches
GDBVER=6.5

CFLAGS="-O2"

. common.sh

TARGET=microblaze-xilinx-elf
PROG_PREFIX=mb-

GDB_SRCDIR=$SRCDIR/gdb
BLDDIR=$BLDDIR/bld_gdb
BINDIR=$RELDIR/bin
GDB_SRC_DIR=$BLDDIR/gdb

DESC="Build\t\t: gdb-$GDBVER"
echo $SEPARATOR
echo -e $DESC
echo -e "Target\t\t: $TARGET"
echo -e "CWD\t\t: $CURDIR"
echo -e "CFLAGS\t\t: $CFLAGS"
echo -e "Version String\t: $TOOL_VERSION"
echo -e "Platform\t: $PLATFORM"

rm -rf $BLDDIR/gdb
rm -rf $BLDDIR/build
rm -rf $BLDDIR/log
mkdir -p $BLDDIR/build
mkdir -p $BLDDIR/log

if [ ! -d $RELDIR ]; then mkdir -p $RELDIR; fi

#  Unpack and patch sources
echo "Staging sources..."
cd $BLDDIR
cp -r $GDB_SRCDIR $GDB_SRC_DIR
if [ $? != 0 ]; then
    echo ""
    echo "Exiting because of previous errors"
    echo ""
    exit
fi

# Set tool version
cd $BLDDIR/gdb/gdb
sed -e "s/\([0-9]*\.[0-9]*\.[0-9]*\).*$/\1 $TOOL_VERSION/" version.in > version.new
mv version.in version.in.old
mv version.new version.in

#  Create build directory
cd $BLDDIR/build

# Use back-rev gcc if available
if [ -d /usr/local/bin/gcc-3.4.6 ]; then
  PATH=/usr/local/bin/gcc-3.4.6/bin:$PATH
fi

PATH=$BINDIR:$PATH

echo -n "Configuring..."
$GDB_SRC_DIR/configure 				\
	--target=$TARGET			\
	--prefix=$RELDIR 			\
	--program-prefix=$PROG_PREFIX		\
		> $BLDDIR/log/gdb-config.log 2>&1 
rc=$?
print_err " rc = " $rc

if [ $NOBUILD = 0 ]; then
  echo -n "Compiling..."
  $MAKE all CFLAGS="$CFLAGS"			\
		> $BLDDIR/log/gdb-make.log 2>&1
  rc=$?
  print_err " rc = " $rc
  
  echo -n "Installing..."
  $MAKE install CFLAGS="$CFLAGS"		\
		> $BLDDIR/log/gdb-install.log 2>&1
  rc=$?
  print_err " rc = " $rc
fi

cd $CURDIR
if [ $NOCLEAN == 0 ]; then
  rm -rf $BLDDIR
fi

echo "Build complete."
