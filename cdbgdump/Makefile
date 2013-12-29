
LUA_INCLUDE=c:\dnload\lua\lua-5.1.5-64\src
LUA_LIB=c:\dnload\lua\lua-5.1.5-64\src

EXE=.exe
CCFLAGS=-I$(LUA_INCLUDE) -I. -L$(LUA_LIB)
CC=gcc

cdbgdump$(EXE): cdbgdump.c ../dumper/dumper.inc ../dumper/dumperh.inc
	$(CC) $(CCFLAGS) -o $@ $(filter %.c,$^) -llua

