package main

/*
** $Id: lauxlib.c,v 1.159.1.3 2008/01/21 13:20:51 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/* This file uses only the official API of Lua.
** Any function declared here could be written as an application function.
 */
/* convert a stack index to positive */
/*
** {======================================================
** Error-report functions
** =======================================================
 */
func luaL_argerror(_L *lua_State, narg int, extramsg string) int {
	var ar lua_Debug
	if lua_getstack(_L, 0, &ar) == 0 {
		return luaL_error(_L, "bad argument #%d (%s)", narg, extramsg)
	}
	lua_getinfo(_L, "n", &ar)
	if ar.namewhat == "method" {
		narg--         /* do not count `self' */
		if narg == 0 { /* error is in the self argument itself? */
			return luaL_error(_L, "calling "+"'"+"%s"+"'"+" on bad self (%s)", ar.name, extramsg)
		}
	}

	if ar.name == "" {
		ar.name = "?"
	}
	return luaL_error(_L, "bad argument #%d to "+"'"+"%s"+"'"+" (%s)", narg, ar.name, extramsg)
}
