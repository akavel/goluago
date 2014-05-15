package internal

import (
	_ "github.com/akavel/gostdc"
	"unsafe"
)

func Open() State {
	//goc: luaL_newstate() ret
	return State(luaL_newstate())
}

//goc-simple: (L State) LWhere(lvl int) = luaL_where((lua_State*)L, (int)lvl)
//goc-simple: (L State) LRef(t int) int = luaL_ref((lua_State*)L, (int)t) int
//goc-simple: (L State) LUnref(t, ref int) = luaL_unref((lua_State*)L, (int)t, (int)ref)
//xgoc-simple: (L State) L = luaL_((lua_State*)L,

func (L State) LOptstring(narg int, d string) string {
	//goc: luaL_optlstring((lua_State*)L, (int)narg, (const char*)d, (size_t*)len) ret
	//goc-unused: luaL_optstring()
	var strlen uintptr
	rawaddr := luaL_optlstring(uintptr(L), uintptr(narg), toluastring(d), uintptr(unsafe.Pointer(&strlen)))
	return string(fromlualstring(rawaddr, strlen))
}

func luaL_optnumber(uintptr, uintptr, uintptr, uintptr)
func (L State) LOptnumber(narg int, d float64) float64 {
	var f float64
	luaL_optnumber(uintptr(L), uintptr(narg), uintptr(unsafe.Pointer(&d)), uintptr(unsafe.Pointer(&f)))
	return f
}

func (L State) LOpenlibs() {
	//goc-unused: luaL_openlibs()
	for _, f := range []Function{
		Open_base,
		//Open_package,
		Open_table,
		Open_io,
		Open_os,
		Open_string,
		Open_math,
		Open_debug,
	} {
		L.Pushgofunction(f)
		L.Call(0, 0)
	}
}
