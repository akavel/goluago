
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "goctypes.h"

#include "stdio.h"
#include "stdlib.h"
#include "../dumper/dumper.inc"
#include "../dumper/dumperh.inc"

void
·dumper_lua_newstate(uintptr ret) {
	ret = (uintptr)(void *)dumperh_lua_prep();
	FLUSH(&ret);
}
