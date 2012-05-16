#ifndef __ASSERT_H
#define __ASSERT_H


#include "goctypes.h"

void runtime·panicstring(int8*);

#define assert(x) ((void)((x) || (runtime·panicstring("ASSERT FAIL in Lua code"), 1)))


#endif
