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
·lua_call(uintptr L, uintptr nargs, uintptr nresults) {
    lua_call((lua_State*)L, (int)nargs, (int)nresults);
}

void
·lua_checkstack(uintptr L, uintptr extra, uintptr ret) {
    ret = (uintptr) lua_checkstack((lua_State*)L, (int)extra);
    FLUSH(&ret);
}

void
·lua_concat(uintptr L, uintptr n) {
    lua_concat((lua_State*)L, (int)n);
}

void
·lua_createtable(uintptr L, uintptr narr, uintptr nrec) {
    lua_createtable((lua_State*)L, (int)narr, (int)nrec);
}

void
·lua_equal(uintptr L, uintptr i1, uintptr i2, uintptr ret) {
    ret = (uintptr) lua_equal((lua_State*)L, (int)i1, (int)i2);
    FLUSH(&ret);
}

void
·lua_error(uintptr L, uintptr ret) {
    ret = (uintptr) lua_error((lua_State*)L);
    FLUSH(&ret);
}

void
·lua_gc(uintptr L, uintptr what, uintptr data, uintptr ret) {
    ret = (uintptr) lua_gc((lua_State*)L, (int)what, (int)data);
    FLUSH(&ret);
}

void
·lua_getfenv(uintptr L, uintptr index) {
    lua_getfenv((lua_State*)L, (int)index);
}

void
·lua_getmetatable(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_getmetatable((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_gettable(uintptr L, uintptr index) {
    lua_gettable((lua_State*)L, (int)index);
}

void
·lua_gettop(uintptr L, uintptr ret) {
    ret = (uintptr) lua_gettop((lua_State*)L);
    FLUSH(&ret);
}

void
·lua_insert(uintptr L, uintptr index) {
    lua_insert((lua_State*)L, (int)index);
}

void
·lua_isboolean(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isboolean((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isfunction(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isfunction((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_islightuserdata(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_islightuserdata((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isnil(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isnil((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isnone(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isnone((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isnoneornil(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isnoneornil((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isnumber(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isnumber((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isstring(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isstring((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_istable(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_istable((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isthread(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isthread((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_isuserdata(uintptr L, uintptr index, uintptr ret) {
    ret = (uintptr) lua_isuserdata((lua_State*)L, (int)index);
    FLUSH(&ret);
}

void
·lua_lessthan(uintptr L, uintptr index1, uintptr index2, uintptr ret) {
    ret = (uintptr) lua_lessthan((lua_State*)L, (int)index1, (int)index2);
    FLUSH(&ret);
}

void
·lua_newtable(uintptr L) {
    lua_newtable((lua_State*)L);
}

void
·lua_next(uintptr L, uintptr index) {
    lua_next((lua_State*)L, (int)index);
}

void
·lua_pcall(uintptr L, uintptr nargs, uintptr nresults, uintptr errfunc, uintptr ret) {
    ret = (uintptr) lua_pcall((lua_State*)L, (int)nargs, (int)nresults, (int)errfunc);
    FLUSH(&ret);
}

void
·lua_pop(uintptr L, uintptr n) {
    lua_pop((lua_State*)L, (int)n);
}

void
·lua_pushboolean(uintptr L, uintptr b) {
    lua_pushboolean((lua_State*)L, (int)b);
}

void
·lua_pushcclosure(uintptr L, uintptr f, uintptr n) {
    lua_pushcclosure((lua_State*)L, (lua_CFunction)f, (int)n);
}

void
·lua_pushinteger(uintptr L, uintptr n) {
    lua_pushinteger((lua_State*)L, (lua_Integer)n);
}

void
·lua_pushnil(uintptr L) {
    lua_pushnil((lua_State*)L);
}

void
·lua_pushvalue(uintptr L, uintptr index) {
    lua_pushvalue((lua_State*)L, (int)index);
}

void
·lua_rawequal(uintptr L, uintptr index1, uintptr index2, uintptr ret) {
    ret = (uintptr) lua_rawequal((lua_State*)L, (int)index1, (int)index2);
    FLUSH(&ret);
}

void
·lua_rawget(uintptr L, uintptr index) {
    lua_rawget((lua_State*)L, (int)index);
}

void
·lua_rawgeti(uintptr L, uintptr index, uintptr n) {
    lua_rawgeti((lua_State*)L, (int)index, (int)n);
}

void
·lua_rawset(uintptr L, uintptr index) {
    lua_rawset((lua_State*)L, (int)index);
}

void
·lua_rawseti(uintptr L, uintptr index, uintptr n) {
    lua_rawseti((lua_State*)L, (int)index, (int)n);
}

void
·lua_setmetatable(uintptr L, uintptr index) {
    lua_setmetatable((lua_State*)L, (int)index);
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

void
·lua_getfield(uintptr L, uintptr index, uintptr k) {
    lua_getfield((lua_State*)L, (int)index, (const char*)k);
}

void
·lua_getglobal(uintptr L, uintptr name) {
    lua_getglobal((lua_State*)L, (const char*)name);
}

void
·lua_getupvalue(uintptr L, uintptr funcindex, uintptr n, uintptr ret) {
    ret = (uintptr) lua_getupvalue((lua_State*)L, (int)funcindex, (int)n);
    FLUSH(&ret);
}

