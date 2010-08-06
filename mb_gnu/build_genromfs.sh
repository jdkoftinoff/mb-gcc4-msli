CURDIR=`pwd`
. ./common.sh
echo "----------------------------------------------------------------"
echo "Building MicroBlaze genromfs"

GENROMFS_SRC=$SRCDIR/genromfs

## Build Directories
GENROMFS_BLDDIR=$BLDDIR/bld_genromfs

rm -rf ${GENROMFS_BLDDIR}
mkdir -p ${GENROMFS_BLDDIR}
mkdir -p $GENROMFS_BLDDIR/log

## Build genromfs
cd ${GENROMFS_BLDDIR}
if [ -e Makefile ]; then
    make clean > /dev/null 2>&1
fi

echo -n "Making..."
( 
  cd ${GENROMFS_SRC}; make -f Makefile all > $GENROMFS_BLDDIR/log/genromfs-make.log 2>&1 
  rm -f $RELDIR/bin/gemromfs
  ln -s ${GENROMFS_SRC}/genromfs  $RELDIR/bin/genromfs 
)

echo "Microblaze genromfs Done"
echo "----------------------------------------------------------------"

