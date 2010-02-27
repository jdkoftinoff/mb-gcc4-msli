#  Common setup

CURDIR=`pwd`
BASE=$CURDIR
SRCDIR=$CURDIR/src
NOBUILD=0
NOCLEAN=0
DEV=0
#SYSROOT=/proj/fv1/gnu_builds/head/mb/sysroot
LINUX=0

function usage
{
  CMD=`basename $0`
  echo $DESC
  echo "usage: $CMD <options>"
  echo "  options:"
  echo "     -base <dir>  Set dir for build (defaults to current dir)"
  echo "     -dev         Dev only (merge EDK functions into libxil.a)"
  echo "     -help	  Print this help info"
  echo "     -nobuild	  Do not build package"
  echo "     -noclean	  Do not delete build files"
  echo "     -source	  Dir containing source (defaults to ./srcs)"
  echo "     -debug       Generate debug versions of the binaries"
  echo 
}

function print_err
{
  #echo "in print_err: $0 $1 $2"
  if [ "$1" == "-n" ]; then
    opt="-n"; shift
  else
    opt=""
  fi
  text=$1
  errcode=$2
  echo $opt "$text$errcode."
  if [ "$errcode" != 0 ]; then
    echo ""
    echo "Exiting because of previous errors"
    echo ""
    exit
  fi
}



  
while [ $# -gt 0 ] ; do
  case $1 in 
    "-base" | "--base"       )
        BASE=$2; shift; shift ;;
    "-dev" | "--dev"	)
	DEV=1; shift ;;
    "-nobuild" | "--nobuild" ) 
    	NOBUILD=1; shift ;;
    "-noclean" | "--noclean" )
        NOCLEAN=1; shift ;;
    "-help" | "--help"	     ) 
        usage; exit ;;
    "-source" | "--source"   ) 
        SRCDIR=$2; shift; shift ;;
    "-debug" | "--debug"     )
        CFLAGS=" -g"; CXXFLAGS=" -g"; shift;;
    -*                       )
      echo "Unrecognized option: $1"; exit ;;
    * )          
      OPTS="$OPTS $1" ; shift ;;
  esac
done

sys=`uname`

uname -a | grep x86_64 > /dev/null
if [ $? == 0 ]; then
    BITS64=64
else
    BITS64=
fi

case $sys in
  Sun*)		PLATFORM=sol
  		EXT=
		MAKE=gmake
  		;;
  CYGWIN*)	PLATFORM=nt
  		EXT=.exe
		MAKE=make
  		;;
  Linux*)	PLATFORM=lin$BITS64
  		EXT=
		MAKE=make
  		;;
esac


BLDDIR=$BASE/build/${PLATFORM}
RELDIR=$BASE/release/${PLATFORM}

# Create an sdk_version.h if one does not exist
if [ ! -f $SRCDIR/sdk_version.h ]; then
    echo "#ifndef __SDK_VERSION_H__" > $SRCDIR/sdk_version.h
    echo "#define __SDK_VERSION_H__" >> $SRCDIR/sdk_version.h
    echo "#define SDK_SoftwareRelease_macro \"Xilinx 11.1\"" >> $SRCDIR/sdk_version.h
    echo "#define SDK_SoftwareBuild_macro \"EDK_L.14\"" >> $SRCDIR/sdk_version.h
    echo "#endif" >> $SRCDIR/sdk_version.h
    echo "" >> $SRCDIR/sdk_version.h    
fi

#  Extract Xilinx version info from sdk_version.h
VERSION=`grep "#define SDK_SoftwareRelease_macro " \
	 $SRCDIR/sdk_version.h | sed -e 's/^.*"\([^"]*\)"$/\1/'`
BUILD=`grep "#define SDK_SoftwareBuild_macro " \
       $SRCDIR/sdk_version.h | sed -e 's/^.*"\([^"]*\)"$/\1/'`
TODAY=`date +"%e %b %Y"`
TOOL_VERSION="$VERSION Build $BUILD $TODAY"

SEPARATOR=\
"-------------------------------------------------------------------------------" 
