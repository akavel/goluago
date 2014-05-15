
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
·luaL_optnumber(uintptr L, uintptr narg, uintptr pd, uintptr pret) {
    *((lua_Number*)pret) = luaL_optnumber((lua_State*)L, (int)narg, *((lua_Number*)pd));
}

void
·lua_pushnumber(uintptr L, uintptr n) {
    lua_pushnumber((lua_State*)L, *(lua_Number*)n);
}

/*******/

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

/*******/

static const char*
stubreader(lua_State* L, void* data, size_t* size) {
    void ·go_stubreader(uintptr, uintptr, uintptr, uintptr);
    const char* ret;
    ·go_stubreader((uintptr)L, (uintptr)data, (uintptr)size, (uintptr)&ret);
    return ret;
}

void
·lua_load(uintptr L, uintptr pdata, uintptr pchunkname, uintptr ret) {
    ret = lua_load((lua_State*)L, stubreader, (void*)pdata, (const char*)pchunkname);
    FLUSH(&ret);
}

/*******/

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

/*******/

void *·open_base;
void *·open_debug;
void *·open_math;
void *·open_string;
void *·open_table;
void *·open_io;
void *·open_os;

void
·initlibs(void) {
    ·open_base = (void*)luaopen_base;
    ·open_debug = (void*)luaopen_debug;
    ·open_math = (void*)luaopen_math;
    ·open_string = (void*)luaopen_string;
    ·open_table = (void*)luaopen_table;
    ·open_io = (void*)luaopen_io;
    ·open_os = (void*)luaopen_os;
}
