Library goluago aims to become a port of Lua 5.1 interpreter to Go Language Toolchain
(first 8c/6c/5c, ultimately maybe pure Go).

The library is at early stage of development (not feature complete / **not ready
for production** use), but some important goals were already completed successfully:

STATUS
------

### Pushback (2014-12-10: Go 1.4):

**NOTE:** because the `go` command's support for the internal C compiler [was
removed with Go 1.4](https://golang.org/doc/go1.4#gocmd), the goluago project
won't build successfully with `go get` under Go 1.4+ anymore. On one hand,
that's a major setback. But on the other hand, that's a strong motivation to
explore the possible use of [Russ Cox's c2go](http://rsc.io/c2go) to convert
the Lua C sources to pure Go (with no more C).

That's what I'm aiming for with the current "c2go" branch of the goluago
project.

### Alpha2 (2014-05-15):

[C API: ~57% complete (81/142 + 1), ~15% have some test (21/143)](#C-API-STATUS)

  * [MILESTONE][API] most of the core C API implemented ([details below](#C-API-STATUS))

### What works - new in alpha1 (2013-12-30):

  * [MILESTONE] workaround in ldebug.c for a bug in Go toolchain's C compiler
  * [MILESTONE][Lua] nearly all standard libraries available (with notable exception of file access)
  * [Lua] most of the Lua Testsuite test code now passes successfully
  * [API] wrapper for lua_pcall() added
  * now uses new, more complete version of the http://github.com/akavel/gostdc library

### What works since pre-alpha preview 2:

  * [MILESTONE] parsing & compiling Lua scripts to bytecode (via luaL_loadbuffer())
  * [Lua] standard libraries: basic library (print(), ipairs(), assert(), loadstring(), etc.)
  * [Lua] passes parts of the Lua testsuite (tested on fragment of "calls.lua")
  * [API] basic strings API (lua_pushlstring(), lua_tolstring())
  * [API] exposing Go funcs into Lua (lua_pushgofunction(), lua_dump())
  * [tools] Lua script for embedding Lua testsuite parts in Go unit tests (wrap-test.lua)
  * [API, Lua] string <-> number conversions

### What works since pre-alpha preview 1:

  * [API] creating/destroying new Lua state (luaL_newstate(), lua_close())
  * [API] basic integer operations on stack (lua_pushinteger(), lua_gettop(), lua_equal())
  * [API] running simple precompiled Lua code chunk (luaL_loadbuffer(), lua_call(),
    tested on precompiled chunk "return 2+3")
  * compiled and tested on: x86 (8c+8g), x64 (6c+6g), Windows/Linux
  * [tools] Lua script to simplify generation of Go+C wrappers for 
    Lua API functions (internal/gen_wrappers.lua)

Build & Testsuite Status: [![Build & Testsuite Status][2]][1]

See also: [Build & Testsuite Status][1] on Travis-CI.
Please note, that the project is still officially at early stage of development, so if
the testsuite fails, it's nothing unexpected; rather, it's very good news that *it builds*
and *big part of the testsuite does already succeed*!

  [1]: http://travis-ci.org/akavel/goluago
  [2]: https://secure.travis-ci.org/akavel/goluago.png?branch=master

WANTED / PLANS
--------------

### Crucial:

  * fix/implement all the rest of needed C standard library functions
    (leveraging Go standard library where possible) in http://github.com/akavel/gostdc
    -- the embedded "panicstring" calls shall emit a runtime panic when a stub function is
    called, making them easier to spot.
    * preferably switch github.com/akavel/gostdc back from Plan9's APE C lib licensed
      with weird Lucent license, to my handmade lib, which is based where possible on thin wrappers
      over Go lib.
    * some most notably missing Lua functions now:
      * file & filesystem access
      * os.exit()
      * time-related functions
    * enable support for Lua's `package` library
  * MILESTONE: get goluago to fully pass the Lua 5.1 testsuite (lua5.1-tests/*.lua)
    * still missing: math.lua, big.lua, verybig.lua, attrib.lua
  * collect some other Lua testsuites from teh Internets and use them for testing too
  * MILESTONE: expose full Lua API in Go (except functions not compatible with Go)
    * [notably still missing](#C-API-STATUS):
      * coroutine ("thread") -related
      * lua_Debug -related
      * many luaL_* functions, although they're reportedly all doable with the non-luaL ones
  * fix allocator, to be per-State for custom synchronization & for GC-ability
  * ARM support, and other architectures later

### Would be nice-ies:

  * write prettier interface on top of official Lua API
    (maybe converge with http://github.com/stevedonovan/luar)
  * Lua 5.2
  * write unit tests for C standard library functions implemented for Lua;
  * improve C standard library in http://github.com/akavel/gostdc
    * maybe use some non-GPL Open Source code (FreeBSD? some stdlib for embedded systems?);
    * try to go back to non-APE version of the code, to avoid the nonstandard Lucent license
  * extract C standard library to separate package;
  * later, "ANSI C to Go translator", in extent needed by the Lua sources?

**NOTE:** you're welcome to contribute anything if you fancy, and not necessarily
from this list. The points above are mostly ideas as to what I believe would be 
most useful at this moment.


BACKGROUND INFO
---------------

### Lua?

http://lua.org

Lua is a nice scripting language. Small, written in ANSI C, highly portable,
reportedly fast. Especially popular among computer games producers, but not only.
Easily embeddable (one of its core goals), mature (Lua 1.0 ~ 1993, many applications
worldwide since then). MIT-style licensed.


### Go Language?

http://golang.org

Fairly new language developed at Google. Authors are however experienced in
building and experimenting with programming languages (specifically C, Limbo), with 
notable uses, including OS development (Unix, Plan9/Inferno). Highly portable
(x86/x64, ARM; Linux/*nix, Windows, Mac OS X, other ports in progress), written
(bootstrapped) in C. BSD-style licensed. Popularity hard to determine given short
time on market, but has several nice and interesting features and properties.


INSTALLATION
------------

With the [Go](http://golang.org) environment properly set up, type:

    go get github.com/akavel/goluago/internal
    go test github.com/akavel/goluago/internal

To retrieve and run a sample program:

    go get github.com/akavel/goluago/testlua
    cd $GOROOT   # or, see $GOPATH; on Windows %GOROOT%, %GOPATH%
    bin/testlua  # on Windows: bin\testlua.exe

<a name="C-API-STATUS"/>
C API STATUS
------------

~57% complete (81/142 + 1), ~15% have some test (21/143)

| Go  |  C  | tests? |
| --- | --- | ------ |
|   | *[luaL_addchar](http://lua.org/manual/5.1/manual.html#luaL_addchar)* |   |
|   | *[luaL_addlstring](http://lua.org/manual/5.1/manual.html#luaL_addlstring)* |   |
|   | *[luaL_addsize](http://lua.org/manual/5.1/manual.html#luaL_addsize)* |   |
|   | *[luaL_addstring](http://lua.org/manual/5.1/manual.html#luaL_addstring)* |   |
|   | *[luaL_addvalue](http://lua.org/manual/5.1/manual.html#luaL_addvalue)* |   |
|   | *[luaL_argcheck](http://lua.org/manual/5.1/manual.html#luaL_argcheck)* |   |
|   | *[luaL_argerror](http://lua.org/manual/5.1/manual.html#luaL_argerror)* |   |
|   | *[luaL_buffinit](http://lua.org/manual/5.1/manual.html#luaL_buffinit)* |   |
|   | *[luaL_callmeta](http://lua.org/manual/5.1/manual.html#luaL_callmeta)* |   |
|   | *[luaL_checkany](http://lua.org/manual/5.1/manual.html#luaL_checkany)* |   |
|   | *[luaL_checkint](http://lua.org/manual/5.1/manual.html#luaL_checkint)* |   |
|   | *[luaL_checkinteger](http://lua.org/manual/5.1/manual.html#luaL_checkinteger)* |   |
|   | *[luaL_checklong](http://lua.org/manual/5.1/manual.html#luaL_checklong)* |   |
|   | *[luaL_checklstring](http://lua.org/manual/5.1/manual.html#luaL_checklstring)* |   |
|   | *[luaL_checknumber](http://lua.org/manual/5.1/manual.html#luaL_checknumber)* |   |
|   | *[luaL_checkoption](http://lua.org/manual/5.1/manual.html#luaL_checkoption)* |   |
|   | *[luaL_checkstack](http://lua.org/manual/5.1/manual.html#luaL_checkstack)* |   |
|   | *[luaL_checkstring](http://lua.org/manual/5.1/manual.html#luaL_checkstring)* |   |
|   | *[luaL_checktype](http://lua.org/manual/5.1/manual.html#luaL_checktype)* |   |
|   | *[luaL_checkudata](http://lua.org/manual/5.1/manual.html#luaL_checkudata)* |   |
|   | *[luaL_dofile](http://lua.org/manual/5.1/manual.html#luaL_dofile)* |   |
|   | *[luaL_dostring](http://lua.org/manual/5.1/manual.html#luaL_dostring)* |   |
|   | *[luaL_error](http://lua.org/manual/5.1/manual.html#luaL_error)* |   |
|   | *[luaL_getmetafield](http://lua.org/manual/5.1/manual.html#luaL_getmetafield)* |   |
|   | *[luaL_getmetatable](http://lua.org/manual/5.1/manual.html#luaL_getmetatable)* |   |
|   | *[luaL_gsub](http://lua.org/manual/5.1/manual.html#luaL_gsub)* |   |
| **[State.Loadbuffer](http://godoc.org/github.com/akavel/goluago/internal#State.Loadbuffer)** | **[luaL_loadbuffer](http://lua.org/manual/5.1/manual.html#luaL_loadbuffer)** | **has test!** |
|   | *[luaL_loadfile](http://lua.org/manual/5.1/manual.html#luaL_loadfile)* |   |
|   | *[luaL_loadstring](http://lua.org/manual/5.1/manual.html#luaL_loadstring)* |   |
|   | *[luaL_newmetatable](http://lua.org/manual/5.1/manual.html#luaL_newmetatable)* |   |
| **[Open](http://godoc.org/github.com/akavel/goluago/internal#Open)** | **[luaL_newstate](http://lua.org/manual/5.1/manual.html#luaL_newstate)** | **has test!** |
| **[State.LOpenlibs](http://godoc.org/github.com/akavel/goluago/internal#State.LOpenlibs)** | **[luaL_openlibs](http://lua.org/manual/5.1/manual.html#luaL_openlibs)** |   |
|   | *[luaL_optint](http://lua.org/manual/5.1/manual.html#luaL_optint)* |   |
|   | *[luaL_optinteger](http://lua.org/manual/5.1/manual.html#luaL_optinteger)* |   |
|   | *[luaL_optlong](http://lua.org/manual/5.1/manual.html#luaL_optlong)* |   |
| **[State.LOptstring](http://godoc.org/github.com/akavel/goluago/internal#State.LOptstring)** | **[luaL_optlstring](http://lua.org/manual/5.1/manual.html#luaL_optlstring)** |   |
| **[State.LOptnumber](http://godoc.org/github.com/akavel/goluago/internal#State.LOptnumber)** | **[luaL_optnumber](http://lua.org/manual/5.1/manual.html#luaL_optnumber)** |   |
| **[State.LOptstring](http://godoc.org/github.com/akavel/goluago/internal#State.LOptstring)** | **[luaL_optstring](http://lua.org/manual/5.1/manual.html#luaL_optstring)** |   |
|   | *[luaL_prepbuffer](http://lua.org/manual/5.1/manual.html#luaL_prepbuffer)* |   |
|   | *[luaL_pushresult](http://lua.org/manual/5.1/manual.html#luaL_pushresult)* |   |
| **[State.LRef](http://godoc.org/github.com/akavel/goluago/internal#State.LRef)** | **[luaL_ref](http://lua.org/manual/5.1/manual.html#luaL_ref)** |   |
|   | *[luaL_register](http://lua.org/manual/5.1/manual.html#luaL_register)* |   |
|   | *[luaL_typename](http://lua.org/manual/5.1/manual.html#luaL_typename)* |   |
|   | *[luaL_typerror](http://lua.org/manual/5.1/manual.html#luaL_typerror)* |   |
| **[State.LUnref](http://godoc.org/github.com/akavel/goluago/internal#State.LUnref)** | **[luaL_unref](http://lua.org/manual/5.1/manual.html#luaL_unref)** |   |
| **[State.LWhere](http://godoc.org/github.com/akavel/goluago/internal#State.LWhere)** | **[luaL_where](http://lua.org/manual/5.1/manual.html#luaL_where)** |   |
|   | *[lua_atpanic](http://lua.org/manual/5.1/manual.html#lua_atpanic)* |   |
| **[State.Call](http://godoc.org/github.com/akavel/goluago/internal#State.Call)** | **[lua_call](http://lua.org/manual/5.1/manual.html#lua_call)** | **has test!** |
| **[State.Checkstack](http://godoc.org/github.com/akavel/goluago/internal#State.Checkstack)** | **[lua_checkstack](http://lua.org/manual/5.1/manual.html#lua_checkstack)** |   |
| **[State.Close](http://godoc.org/github.com/akavel/goluago/internal#State.Close)** | **[lua_close](http://lua.org/manual/5.1/manual.html#lua_close)** | **has test!** |
| **[State.Concat](http://godoc.org/github.com/akavel/goluago/internal#State.Concat)** | **[lua_concat](http://lua.org/manual/5.1/manual.html#lua_concat)** |   |
| **[State.Gopcall](http://godoc.org/github.com/akavel/goluago/internal#State.Gopcall)** | **[lua_cpcall](http://lua.org/manual/5.1/manual.html#lua_cpcall)** |   |
| **[State.Createtable](http://godoc.org/github.com/akavel/goluago/internal#State.Createtable)** | **[lua_createtable](http://lua.org/manual/5.1/manual.html#lua_createtable)** |   |
| **[State.Dump](http://godoc.org/github.com/akavel/goluago/internal#State.Dump)** | **[lua_dump](http://lua.org/manual/5.1/manual.html#lua_dump)** |   |
| **[State.Equal](http://godoc.org/github.com/akavel/goluago/internal#State.Equal)** | **[lua_equal](http://lua.org/manual/5.1/manual.html#lua_equal)** | **has test!** |
| **[State.Error](http://godoc.org/github.com/akavel/goluago/internal#State.Error)** | **[lua_error](http://lua.org/manual/5.1/manual.html#lua_error)** |   |
| **[State.Gc](http://godoc.org/github.com/akavel/goluago/internal#State.Gc)** | **[lua_gc](http://lua.org/manual/5.1/manual.html#lua_gc)** |   |
|   | *[lua_getallocf](http://lua.org/manual/5.1/manual.html#lua_getallocf)* |   |
| **[State.Getfenv](http://godoc.org/github.com/akavel/goluago/internal#State.Getfenv)** | **[lua_getfenv](http://lua.org/manual/5.1/manual.html#lua_getfenv)** |   |
| **[State.Getfield](http://godoc.org/github.com/akavel/goluago/internal#State.Getfield)** | **[lua_getfield](http://lua.org/manual/5.1/manual.html#lua_getfield)** | **has test!** |
| **[State.Getglobal](http://godoc.org/github.com/akavel/goluago/internal#State.Getglobal)** | **[lua_getglobal](http://lua.org/manual/5.1/manual.html#lua_getglobal)** | **has test!** |
|   | *[lua_gethook](http://lua.org/manual/5.1/manual.html#lua_gethook)* |   |
|   | *[lua_gethookcount](http://lua.org/manual/5.1/manual.html#lua_gethookcount)* |   |
|   | *[lua_gethookmask](http://lua.org/manual/5.1/manual.html#lua_gethookmask)* |   |
|   | *[lua_getinfo](http://lua.org/manual/5.1/manual.html#lua_getinfo)* |   |
|   | *[lua_getlocal](http://lua.org/manual/5.1/manual.html#lua_getlocal)* |   |
| **[State.Getmetatable](http://godoc.org/github.com/akavel/goluago/internal#State.Getmetatable)** | **[lua_getmetatable](http://lua.org/manual/5.1/manual.html#lua_getmetatable)** |   |
|   | *[lua_getstack](http://lua.org/manual/5.1/manual.html#lua_getstack)* |   |
| **[State.Gettable](http://godoc.org/github.com/akavel/goluago/internal#State.Gettable)** | **[lua_gettable](http://lua.org/manual/5.1/manual.html#lua_gettable)** |   |
| **[State.Gettop](http://godoc.org/github.com/akavel/goluago/internal#State.Gettop)** | **[lua_gettop](http://lua.org/manual/5.1/manual.html#lua_gettop)** | **has test!** |
| **[State.Getupvalue](http://godoc.org/github.com/akavel/goluago/internal#State.Getupvalue)** | **[lua_getupvalue](http://lua.org/manual/5.1/manual.html#lua_getupvalue)** | **has test!** |
| **[State.Insert](http://godoc.org/github.com/akavel/goluago/internal#State.Insert)** | **[lua_insert](http://lua.org/manual/5.1/manual.html#lua_insert)** |   |
| **[State.Isboolean](http://godoc.org/github.com/akavel/goluago/internal#State.Isboolean)** | **[lua_isboolean](http://lua.org/manual/5.1/manual.html#lua_isboolean)** |   |
| **[State.Iscfunction](http://godoc.org/github.com/akavel/goluago/internal#State.Iscfunction)** | **[lua_iscfunction](http://lua.org/manual/5.1/manual.html#lua_iscfunction)** |   |
| **[State.Isfunction](http://godoc.org/github.com/akavel/goluago/internal#State.Isfunction)** | **[lua_isfunction](http://lua.org/manual/5.1/manual.html#lua_isfunction)** |   |
| **[State.Islightuserdata](http://godoc.org/github.com/akavel/goluago/internal#State.Islightuserdata)** | **[lua_islightuserdata](http://lua.org/manual/5.1/manual.html#lua_islightuserdata)** |   |
| **[State.Isnil](http://godoc.org/github.com/akavel/goluago/internal#State.Isnil)** | **[lua_isnil](http://lua.org/manual/5.1/manual.html#lua_isnil)** |   |
| **[State.Isnone](http://godoc.org/github.com/akavel/goluago/internal#State.Isnone)** | **[lua_isnone](http://lua.org/manual/5.1/manual.html#lua_isnone)** |   |
| **[State.Isnoneornil](http://godoc.org/github.com/akavel/goluago/internal#State.Isnoneornil)** | **[lua_isnoneornil](http://lua.org/manual/5.1/manual.html#lua_isnoneornil)** |   |
| **[State.Isnumber](http://godoc.org/github.com/akavel/goluago/internal#State.Isnumber)** | **[lua_isnumber](http://lua.org/manual/5.1/manual.html#lua_isnumber)** |   |
| **[State.Isstring](http://godoc.org/github.com/akavel/goluago/internal#State.Isstring)** | **[lua_isstring](http://lua.org/manual/5.1/manual.html#lua_isstring)** |   |
| **[State.Istable](http://godoc.org/github.com/akavel/goluago/internal#State.Istable)** | **[lua_istable](http://lua.org/manual/5.1/manual.html#lua_istable)** |   |
| **[State.Isthread](http://godoc.org/github.com/akavel/goluago/internal#State.Isthread)** | **[lua_isthread](http://lua.org/manual/5.1/manual.html#lua_isthread)** |   |
| **[State.Isuserdata](http://godoc.org/github.com/akavel/goluago/internal#State.Isuserdata)** | **[lua_isuserdata](http://lua.org/manual/5.1/manual.html#lua_isuserdata)** |   |
| **[State.Lessthan](http://godoc.org/github.com/akavel/goluago/internal#State.Lessthan)** | **[lua_lessthan](http://lua.org/manual/5.1/manual.html#lua_lessthan)** |   |
| **[State.Load](http://godoc.org/github.com/akavel/goluago/internal#State.Load)** | **[lua_load](http://lua.org/manual/5.1/manual.html#lua_load)** | **has test!** |
|   | *[lua_newstate](http://lua.org/manual/5.1/manual.html#lua_newstate)* |   |
| **[State.Newtable](http://godoc.org/github.com/akavel/goluago/internal#State.Newtable)** | **[lua_newtable](http://lua.org/manual/5.1/manual.html#lua_newtable)** |   |
|   | *[lua_newthread](http://lua.org/manual/5.1/manual.html#lua_newthread)* |   |
|   | *[lua_newuserdata](http://lua.org/manual/5.1/manual.html#lua_newuserdata)* |   |
| **[State.Next](http://godoc.org/github.com/akavel/goluago/internal#State.Next)** | **[lua_next](http://lua.org/manual/5.1/manual.html#lua_next)** |   |
| **[State.Objlen](http://godoc.org/github.com/akavel/goluago/internal#State.Objlen)** | **[lua_objlen](http://lua.org/manual/5.1/manual.html#lua_objlen)** |   |
| **[State.Pcall](http://godoc.org/github.com/akavel/goluago/internal#State.Pcall)** | **[lua_pcall](http://lua.org/manual/5.1/manual.html#lua_pcall)** |   |
| **[State.Pop](http://godoc.org/github.com/akavel/goluago/internal#State.Pop)** | **[lua_pop](http://lua.org/manual/5.1/manual.html#lua_pop)** |   |
| **[State.Pushboolean](http://godoc.org/github.com/akavel/goluago/internal#State.Pushboolean)** | **[lua_pushboolean](http://lua.org/manual/5.1/manual.html#lua_pushboolean)** |   |
| **[State.Pushgofunction](http://godoc.org/github.com/akavel/goluago/internal#State.Pushgofunction)** | **[lua_pushcclosure](http://lua.org/manual/5.1/manual.html#lua_pushcclosure)** | **has test!** |
| **[State.Pushgofunction](http://godoc.org/github.com/akavel/goluago/internal#State.Pushgofunction)** | **[lua_pushcfunction](http://lua.org/manual/5.1/manual.html#lua_pushcfunction)** | **has test!** |
|   | *[lua_pushfstring](http://lua.org/manual/5.1/manual.html#lua_pushfstring)* |   |
| **[State.Pushgofunction](http://godoc.org/github.com/akavel/goluago/internal#State.Pushgofunction)** | lua_pushgofunction | **has test!** |
| **[State.Pushinteger](http://godoc.org/github.com/akavel/goluago/internal#State.Pushinteger)** | **[lua_pushinteger](http://lua.org/manual/5.1/manual.html#lua_pushinteger)** | **has test!** |
| **[State.Pushlightuserdata](http://godoc.org/github.com/akavel/goluago/internal#State.Pushlightuserdata)** | **[lua_pushlightuserdata](http://lua.org/manual/5.1/manual.html#lua_pushlightuserdata)** |   |
| **[State.Pushstring](http://godoc.org/github.com/akavel/goluago/internal#State.Pushstring)** | **[lua_pushliteral](http://lua.org/manual/5.1/manual.html#lua_pushliteral)** | **has test!** |
| **[State.Pushstring](http://godoc.org/github.com/akavel/goluago/internal#State.Pushstring)** | **[lua_pushlstring](http://lua.org/manual/5.1/manual.html#lua_pushlstring)** | **has test!** |
| **[State.Pushnil](http://godoc.org/github.com/akavel/goluago/internal#State.Pushnil)** | **[lua_pushnil](http://lua.org/manual/5.1/manual.html#lua_pushnil)** |   |
| **[State.Pushnumber](http://godoc.org/github.com/akavel/goluago/internal#State.Pushnumber)** | **[lua_pushnumber](http://lua.org/manual/5.1/manual.html#lua_pushnumber)** |   |
| **[State.Pushstring](http://godoc.org/github.com/akavel/goluago/internal#State.Pushstring)** | **[lua_pushstring](http://lua.org/manual/5.1/manual.html#lua_pushstring)** | **has test!** |
|   | *[lua_pushthread](http://lua.org/manual/5.1/manual.html#lua_pushthread)* |   |
| **[State.Pushvalue](http://godoc.org/github.com/akavel/goluago/internal#State.Pushvalue)** | **[lua_pushvalue](http://lua.org/manual/5.1/manual.html#lua_pushvalue)** |   |
|   | *[lua_pushvfstring](http://lua.org/manual/5.1/manual.html#lua_pushvfstring)* |   |
| **[State.Rawequal](http://godoc.org/github.com/akavel/goluago/internal#State.Rawequal)** | **[lua_rawequal](http://lua.org/manual/5.1/manual.html#lua_rawequal)** |   |
| **[State.Rawget](http://godoc.org/github.com/akavel/goluago/internal#State.Rawget)** | **[lua_rawget](http://lua.org/manual/5.1/manual.html#lua_rawget)** |   |
| **[State.Rawgeti](http://godoc.org/github.com/akavel/goluago/internal#State.Rawgeti)** | **[lua_rawgeti](http://lua.org/manual/5.1/manual.html#lua_rawgeti)** |   |
| **[State.Rawset](http://godoc.org/github.com/akavel/goluago/internal#State.Rawset)** | **[lua_rawset](http://lua.org/manual/5.1/manual.html#lua_rawset)** |   |
| **[State.Rawseti](http://godoc.org/github.com/akavel/goluago/internal#State.Rawseti)** | **[lua_rawseti](http://lua.org/manual/5.1/manual.html#lua_rawseti)** |   |
| **[State.Register](http://godoc.org/github.com/akavel/goluago/internal#State.Register)** | **[lua_register](http://lua.org/manual/5.1/manual.html#lua_register)** |   |
| **[State.Remove](http://godoc.org/github.com/akavel/goluago/internal#State.Remove)** | **[lua_remove](http://lua.org/manual/5.1/manual.html#lua_remove)** |   |
| **[State.Replace](http://godoc.org/github.com/akavel/goluago/internal#State.Replace)** | **[lua_replace](http://lua.org/manual/5.1/manual.html#lua_replace)** |   |
|   | *[lua_resume](http://lua.org/manual/5.1/manual.html#lua_resume)* |   |
|   | *[lua_setallocf](http://lua.org/manual/5.1/manual.html#lua_setallocf)* |   |
| **[State.Setfenv](http://godoc.org/github.com/akavel/goluago/internal#State.Setfenv)** | **[lua_setfenv](http://lua.org/manual/5.1/manual.html#lua_setfenv)** |   |
| **[State.Setfield](http://godoc.org/github.com/akavel/goluago/internal#State.Setfield)** | **[lua_setfield](http://lua.org/manual/5.1/manual.html#lua_setfield)** |   |
| **[State.Setglobal](http://godoc.org/github.com/akavel/goluago/internal#State.Setglobal)** | **[lua_setglobal](http://lua.org/manual/5.1/manual.html#lua_setglobal)** |   |
|   | *[lua_sethook](http://lua.org/manual/5.1/manual.html#lua_sethook)* |   |
|   | *[lua_setlocal](http://lua.org/manual/5.1/manual.html#lua_setlocal)* |   |
| **[State.Setmetatable](http://godoc.org/github.com/akavel/goluago/internal#State.Setmetatable)** | **[lua_setmetatable](http://lua.org/manual/5.1/manual.html#lua_setmetatable)** | **has test!** |
| **[State.Settable](http://godoc.org/github.com/akavel/goluago/internal#State.Settable)** | **[lua_settable](http://lua.org/manual/5.1/manual.html#lua_settable)** |   |
| **[State.Settop](http://godoc.org/github.com/akavel/goluago/internal#State.Settop)** | **[lua_settop](http://lua.org/manual/5.1/manual.html#lua_settop)** |   |
|   | *[lua_setupvalue](http://lua.org/manual/5.1/manual.html#lua_setupvalue)* |   |
| **[State.Status](http://godoc.org/github.com/akavel/goluago/internal#State.Status)** | **[lua_status](http://lua.org/manual/5.1/manual.html#lua_status)** |   |
| **[State.Toboolean](http://godoc.org/github.com/akavel/goluago/internal#State.Toboolean)** | **[lua_toboolean](http://lua.org/manual/5.1/manual.html#lua_toboolean)** |   |
|   | *[lua_tocfunction](http://lua.org/manual/5.1/manual.html#lua_tocfunction)* |   |
| **[State.Tointeger](http://godoc.org/github.com/akavel/goluago/internal#State.Tointeger)** | **[lua_tointeger](http://lua.org/manual/5.1/manual.html#lua_tointeger)** | **has test!** |
| **[State.Tostring](http://godoc.org/github.com/akavel/goluago/internal#State.Tostring)** | **[lua_tolstring](http://lua.org/manual/5.1/manual.html#lua_tolstring)** | **has test!** |
| **[State.Tonumber](http://godoc.org/github.com/akavel/goluago/internal#State.Tonumber)** | **[lua_tonumber](http://lua.org/manual/5.1/manual.html#lua_tonumber)** |   |
|   | *[lua_topointer](http://lua.org/manual/5.1/manual.html#lua_topointer)* |   |
| **[State.Tostring](http://godoc.org/github.com/akavel/goluago/internal#State.Tostring)** | **[lua_tostring](http://lua.org/manual/5.1/manual.html#lua_tostring)** | **has test!** |
|   | *[lua_tothread](http://lua.org/manual/5.1/manual.html#lua_tothread)* |   |
| **[State.Touserdata](http://godoc.org/github.com/akavel/goluago/internal#State.Touserdata)** | **[lua_touserdata](http://lua.org/manual/5.1/manual.html#lua_touserdata)** |   |
| **[State.Type](http://godoc.org/github.com/akavel/goluago/internal#State.Type)** | **[lua_type](http://lua.org/manual/5.1/manual.html#lua_type)** |   |
| **[State.Typename](http://godoc.org/github.com/akavel/goluago/internal#State.Typename)** | **[lua_typename](http://lua.org/manual/5.1/manual.html#lua_typename)** |   |
| **[Upvalueindex](http://godoc.org/github.com/akavel/goluago/internal#Upvalueindex)** | **[lua_upvalueindex](http://lua.org/manual/5.1/manual.html#lua_upvalueindex)** |   |
|   | *[lua_xmove](http://lua.org/manual/5.1/manual.html#lua_xmove)* |   |
|   | *[lua_yield](http://lua.org/manual/5.1/manual.html#lua_yield)* |   |


LICENSE
-------


### Where not otherwise specified, MIT-licensed as:


Copyright (c) 2011-2014 Mateusz Czapliński

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


### Lua code MIT-licensed as:


Copyright (C) 1994-2008 Lua.org, PUC-Rio.  All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
