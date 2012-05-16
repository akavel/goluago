/* File generated automatically by gen_wrappers.lua */

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "goctypes.h"

void
·luaL_newstate(uintptr ret) {
    ret = (uintptr) luaL_newstate();
    FLUSH(&ret);
}

void
·lua_close(uintptr L) {
    lua_close((lua_State*)L);
}

void
·lua_gettop(uintptr L, uintptr ret) {
    ret = (uintptr) lua_gettop((lua_State*)L);
    FLUSH(&ret);
}

void
·lua_pushinteger(uintptr L, uintptr n) {
    lua_pushinteger((lua_State*)L, (lua_Integer)n);
}

void
·lua_equal(uintptr L, uintptr i1, uintptr i2, uintptr ret) {
    ret = (uintptr) lua_equal((lua_State*)L, (int)i1, (int)i2);
    FLUSH(&ret);
}

void
·lua_lessthan(uintptr L, uintptr index1, uintptr index2, uintptr ret) {
    ret = (uintptr) lua_lessthan((lua_State*)L, (int)index1, (int)index2);
    FLUSH(&ret);
}

void
·lua_call(uintptr L, uintptr nargs, uintptr nresults) {
    lua_call((lua_State*)L, (int)nargs, (int)nresults);
}

void
·lua_pushcclosure(uintptr L, uintptr f, uintptr n) {
    lua_pushcclosure((lua_State*)L, (lua_CFunction)f, (int)n);
}

void
·luaL_loadbuffer(uintptr L, uintptr buff, uintptr sz, uintptr name, uintptr ret) {
    ret = (uintptr) luaL_loadbuffer((lua_State*)L, (const char*)buff, (size_t)sz, (const char*)name);
    FLUSH(&ret);
}

void
·lua_pushlstring(uintptr L, uintptr s, uintptr len) {
    lua_pushlstring((lua_State*)L, (const char*)s, (size_t)len);
}

void
·lua_tolstring(uintptr L, uintptr index, uintptr len, uintptr ret) {
    ret = (uintptr) lua_tolstring((lua_State*)L, (int)index, (size_t*)len);
    FLUSH(&ret);
}

