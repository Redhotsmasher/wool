# Makefile for building the Wool library.
#
# User configuration and variables defined in $(TOP)/Makefile.inc which
# is shared for building the wool library, examples and tests.

TOP = ..
include $(TOP)/Makefile.inc

OBJS = wool.o
TARGET=libwool.a
EXTRA_OBJS=wool-main.o
CFLAGS += -W -Wno-unused-parameter

all: $(TARGET) $(EXTRA_OBJS)

wool.h: wool-gen.sh
	./wool-gen.sh $(MAX_ARITY) > wool.h

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^

clean :
	$(RM) wool.h $(OBJS) $(EXTRA_OBJS) $(TARGET)
	$(RM) *.ll
	$(RM) wool_complete.c



wool.o: wool.h wool-common.h
	$(CC) $(CFLAGS) wool.c -c -o $@
	$(CC) $(CFLAGS) wool.c -c -S -emit-llvm -o wool.ll
	cpp $(CFLAGS) wool.c -E -C -fdirectives-only -o wool_complete.c
wool-main.o: wool.h wool-common.h
	$(CC) $(CFLAGS) wool-main.c -c -o $@
	$(CC) $(CFLAGS) wool-main.c -c -S -emit-llvm -o wool-main.ll

