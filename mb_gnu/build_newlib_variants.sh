#
#  Build newlib variants
#

#  Source and patches
NEWLIBVER=1.14.0
LIB_VARIANTS_LE=newlib-variants-le
LIB_VARIANTS_BE=newlib-variants-be
LIB_VARIANT_LINKS=newlib-variant-links

. common.sh

# Override source directory
NEWLIB_SRCDIR=$SRCDIR/newlib
TARGET=microblaze-xilinx-elf
SYSROOT=$RELDIR/$TARGET
BLDDIR=$BLDDIR/bld_gcc
BINDIR=$RELDIR/bin

DESC="Build\t\t: newlib-$NEWLIBVER multilib variants"
echo -e "Build libraries started\t: `date`"
echo $SEPARATOR
echo -e $DESC

errors=0

cd $BLDDIR/build

PATH=$BINDIR:$PATH

export AR_FOR_TARGET=mb-ar
export AS_FOR_TARGET=mb-as

echo "" > $BLDDIR/log/libs-make.log

echo "Building newlib little endian variants..."
while read LIB NAME ; do
    read FLAGS
    make -C $BLDDIR/build/$TARGET/newlib/$LIB clean 	\
        >> $BLDDIR/log/libs-make.log 2>&1
    make -C $BLDDIR/build/$TARGET/newlib/$LIB CFLAGS="$FLAGS" AR_FLAGS=rc   \
        >> $BLDDIR/log/libs-make.log 2>&1
    print_err "   install $NAME -- rc = " $?
    mv $BLDDIR/build/$TARGET/newlib/$LIB/$LIB.a $RELDIR/$TARGET/lib/$NAME   \
        >> $BLDDIR/log/libs-make.log 2>&1
done < $SRCDIR/$LIB_VARIANTS_LE

echo "Building newlib big endian variants..."
while read LIB NAME ; do
    read FLAGS
    make -C $BLDDIR/build/$TARGET/newlib/$LIB clean 	\
        >> $BLDDIR/log/libs-make.log 2>&1
    make -C $BLDDIR/build/$TARGET/newlib/$LIB CFLAGS="$FLAGS" AR_FLAGS=rc   \
        >> $BLDDIR/log/libs-make.log 2>&1
    print_err "   install $NAME -- rc = " $?
    mv $BLDDIR/build/$TARGET/newlib/$LIB/$LIB.a $RELDIR/$TARGET/lib/$NAME   \
        >> $BLDDIR/log/libs-make.log 2>&1
done < $SRCDIR/$LIB_VARIANTS_BE

echo "Setting up multilib links..."
while read LDIR LPATH LNAME; do
    if [[ $LDIR = "#" || $LDIR = "" ]] ; then
        continue
    fi
    cd $RELDIR/$TARGET/lib/$LDIR
    rm -rf $LNAME
    ln -s $LPATH $LNAME >> $BLDDIR/log/libs-make.log
done < $SRCDIR/$LIB_VARIANT_LINKS

echo "Build libraries completed: `date`."