
#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#include "time.h"
#include "locale.h"

#include "goctypes.h"

void
·lua_tonumber(uintptr L, uintptr index, uintptr pret) {
    *((lua_Number*)pret) = lua_tonumber((lua_State*)L, (int)index);
}

void
·lua_pushnumber(uintptr L, uintptr n) {
    lua_pushnumber((lua_State*)L, *(lua_Number*)n);
}

static int
stubwriter(lua_State* L, const void* p, size_t sz, void* ud) {
    void ·go_stubwriter(uintptr, uintptr, uintptr, uintptr, uintptr);
    int32 ret;
    ·go_stubwriter((uintptr)L, (uintptr)p, (uintptr)sz, (uintptr)ud, (uintptr)&ret);
    return ret;
}

void
·lua_dump(uintptr L, uintptr dumpinfo, uintptr ret) {
    ret = lua_dump((lua_State*)L, stubwriter, (void*)dumpinfo);
    FLUSH(&ret);
}

static int
stubcfunction(lua_State* L) {
    void ·go_stubcfunction(uintptr, uintptr, uintptr);
    int32 ret = 0;
    void* f = lua_touserdata(L, lua_upvalueindex(1));
    ·go_stubcfunction((uintptr)L, (uintptr)f, (uintptr)&ret);
    return ret;
}

void
·lua_pushgofunction(uintptr L, uintptr f) {
    lua_pushlightuserdata((lua_State*)L, (void*)f);
    lua_pushcclosure((lua_State*)L, stubcfunction, 1);
}

void *·Open_base;
void *·Open_debug;
void *·Open_math;
void *·Open_string;
void *·Open_table;
void *·Open_io;
void *·Open_os;

void
·initlibs(void) {
    ·Open_base = (void*)luaopen_base;
    ·Open_debug = (void*)luaopen_debug;
    ·Open_math = (void*)luaopen_math;
    ·Open_string = (void*)luaopen_string;
    ·Open_table = (void*)luaopen_table;
    ·Open_io = (void*)luaopen_io;
    ·Open_os = (void*)luaopen_os;
}
