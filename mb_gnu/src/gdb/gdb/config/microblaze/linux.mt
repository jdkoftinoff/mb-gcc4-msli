# Target: Xilinx microblaze processor on Linux
TDEPFILES= microblaze-tdep.o microblaze-linux-tdep.o microblaze-rom.o \
 monitor.o dsrec.o solib.o solib-svr4.o solib-legacy.o corelow.o symfile-mem.o
DEPRECATED_TM_FILE= tm-linux.h
