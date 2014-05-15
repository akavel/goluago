package internal

import (
	_ "github.com/akavel/gostdc"
	"unsafe"
)

type State uintptr

func Open() State {
	//goc: luaL_newstate() ret
	return State(luaL_newstate())
}

//goc-simple: (L State) Close() = lua_close((lua_State*)L)
//goc-simple: (L State) Call(nargs, nresults int) = lua_call((lua_State*)L, (int)nargs, (int)nresults)
//goc-simple: (L State) Checkstack(extra int) int = lua_checkstack((lua_State*)L, (int)extra) int
//goc-simple: (L State) Concat(n int) = lua_concat((lua_State*)L, (int)n)
//goc-simple: (L State) Createtable(narr, nrec int) = lua_createtable((lua_State*)L, (int)narr, (int)nrec)
//goc-simple: (L State) Equal(i1, i2 int) int = lua_equal((lua_State*)L, (int)i1, (int)i2) int
//goc-simple: (L State) Error() int = lua_error((lua_State*)L) int
//goc-simple: (L State) Gc(what, data int) int = lua_gc((lua_State*)L, (int)what, (int)data) int
//goc-simple: (L State) Getfenv(index int) = lua_getfenv((lua_State*)L, (int)index)
//goc-simple: (L State) Getmetatable(index int) int = lua_getmetatable((lua_State*)L, (int)index) int
//goc-simple: (L State) Gettable(index int) = lua_gettable((lua_State*)L, (int)index)
//goc-simple: (L State) Gettop() int = lua_gettop((lua_State*)L) int
//goc-simple: (L State) Insert(index int) = lua_insert((lua_State*)L, (int)index)
//goc-simple: (L State) Isboolean(index int) int = lua_isboolean((lua_State*)L, (int)index) int
//goc-simple: (L State) Isfunction(index int) int = lua_isfunction((lua_State*)L, (int)index) int
//goc-simple: (L State) Islightuserdata(index int) int = lua_islightuserdata((lua_State*)L, (int)index) int
//goc-simple: (L State) Isnil(index int) int = lua_isnil((lua_State*)L, (int)index) int
//goc-simple: (L State) Isnone(index int) int = lua_isnone((lua_State*)L, (int)index) int
//goc-simple: (L State) Isnoneornil(index int) int = lua_isnoneornil((lua_State*)L, (int)index) int
//goc-simple: (L State) Isnumber(index int) int = lua_isnumber((lua_State*)L, (int)index) int
//goc-simple: (L State) Isstring(index int) int = lua_isstring((lua_State*)L, (int)index) int
//goc-simple: (L State) Istable(index int) int = lua_istable((lua_State*)L, (int)index) int
//goc-simple: (L State) Isthread(index int) int = lua_isthread((lua_State*)L, (int)index) int
//goc-simple: (L State) Isuserdata(index int) int = lua_isuserdata((lua_State*)L, (int)index) int
//goc-simple: (L State) Lessthan(index1, index2 int) int = lua_lessthan((lua_State*)L, (int)index1, (int)index2) int
//goc-simple: (L State) Newtable() = lua_newtable((lua_State*)L)
//goc-simple: (L State) Next(index int) = lua_next((lua_State*)L, (int)index)
//goc-simple: (L State) Pcall(nargs, nresults, errfunc int) int = lua_pcall((lua_State*)L, (int)nargs, (int)nresults, (int)errfunc) int
//goc-simple: (L State) Pop(n int) = lua_pop((lua_State*)L, (int)n)
//goc-simple: (L State) Pushboolean(b int) = lua_pushboolean((lua_State*)L, (int)b)
//goc-simple: (L State) pushcclosure(f uintptr, n int) = lua_pushcclosure((lua_State*)L, (lua_CFunction)f, (int)n)
//goc-simple: (L State) Pushinteger(n int) = lua_pushinteger((lua_State*)L, (lua_Integer)n)
//goc-simple: (L State) Pushnil() = lua_pushnil((lua_State*)L)
//goc-simple: (L State) Pushvalue(index int) = lua_pushvalue((lua_State*)L, (int)index)
//goc-simple: (L State) Rawequal(index1, index2 int) int = lua_rawequal((lua_State*)L, (int)index1, (int)index2) int
//goc-simple: (L State) Rawget(index int) = lua_rawget((lua_State*)L, (int)index)
//goc-simple: (L State) Rawgeti(index, n int) = lua_rawgeti((lua_State*)L, (int)index, (int)n)
//goc-simple: (L State) Rawset(index int) = lua_rawset((lua_State*)L, (int)index)
//goc-simple: (L State) Rawseti(index, n int) = lua_rawseti((lua_State*)L, (int)index, (int)n)
//goc-simple: (L State) Setmetatable(index int) = lua_setmetatable((lua_State*)L, (int)index)
//xgoc-simple: (L State) = lua_((lua_State*)L,

// FIXME: in 'name', notify about trimming on embedded zero-bytes, maybe
// TODO: return error
func (s State) Loadbuffer(buff []byte, name string) int {
	//goc: luaL_loadbuffer((lua_State*)L, (const char*)buff, (size_t)sz, (const char*)name) ret
	return int(luaL_loadbuffer(uintptr(s), uintptr(unsafe.Pointer(&buff[0])), uintptr(len(buff)), toluastring(name)))
}

func (L State) Pushlstring(s []byte) {
	//goc: lua_pushlstring((lua_State*)L, (const char*)s, (size_t)len)
	tmp := s
	if len(s) == 0 {
		tmp = make([]byte, 1)
	}
	lua_pushlstring(uintptr(L), uintptr(unsafe.Pointer(&tmp[0])), uintptr(len(s)))
}

func (L State) Tolstring(index int) []byte {
	//goc: lua_tolstring((lua_State*)L, (int)index, (size_t*)len) ret
	var strlen uintptr
	rawaddr := lua_tolstring(uintptr(L), uintptr(index), uintptr(unsafe.Pointer(&strlen)))
	buf := make([]byte, strlen)
	for i := uintptr(0); i < strlen; i++ {
		addr := (*byte)(unsafe.Pointer(rawaddr + i))
		buf[i] = *addr
	}
	return buf
}

func lua_tonumber(uintptr, uintptr, uintptr)
func (L State) Tonumber(index int) float64 {
	var f float64
	lua_tonumber(uintptr(L), uintptr(index), uintptr(unsafe.Pointer(&f)))
	return f
}

func lua_pushnumber(uintptr, uintptr)
func (L State) Pushnumber(n float64) {
	lua_pushnumber(uintptr(L), uintptr(unsafe.Pointer(&n)))
}

type Writer func(L State, pbuf, size uintptr, userdata interface{}) int
type dumpinfo struct {
	writer Writer
	data   interface{}
}

func lua_dump(uintptr, uintptr) uintptr
func (L State) Dump(w Writer, data interface{}) int {
	di := dumpinfo{w, data}
	return int(lua_dump(uintptr(L), uintptr(unsafe.Pointer(&di))))
}

type Function func(L State) (retvals int32)

func lua_pushgofunction(uintptr, uintptr)
func (L State) Pushgofunction(f Function) {
	lua_pushgofunction(uintptr(L), uintptr(unsafe.Pointer(&f)))
}

func toluastring(s string) uintptr {
	return uintptr(unsafe.Pointer(&([]byte(s + "\x00"))[0]))
}

func fromluastring(rawaddr uintptr) []byte {
	// find terminating NULL
	strlen := uintptr(0)
	for ; ; strlen++ {
		if *((*byte)(unsafe.Pointer(rawaddr + strlen))) == 0 {
			break
		}
	}

	buf := make([]byte, strlen)
	for i := uintptr(0); i < strlen; i++ {
		addr := (*byte)(unsafe.Pointer(rawaddr + i))
		buf[i] = *addr
	}
	return buf
}

// FIXME: in 'name', notify about trimming on embedded zero-bytes, maybe
func (L State) Getfield(index int, key string) {
	//goc: lua_getfield((lua_State*)L, (int)index, (const char*)k)
	lua_getfield(uintptr(L), uintptr(index), toluastring(key))
}

// FIXME: in 'name', notify about trimming on embedded zero-bytes, maybe
func (L State) Getglobal(name string) {
	//goc: lua_getglobal((lua_State*)L, (const char*)name)
	lua_getglobal(uintptr(L), toluastring(name))
}

func (L State) Getupvalue(funcindex, n int) []byte {
	//goc: lua_getupvalue((lua_State*)L, (int)funcindex, (int)n) ret
	return fromluastring(lua_getupvalue(uintptr(L), uintptr(funcindex), uintptr(n)))
}

var (
	Open_base   uintptr
	Open_debug  uintptr
	Open_math   uintptr
	Open_string uintptr
	Open_table  uintptr
	Open_io     uintptr
	Open_os     uintptr
)

func initlibs()
func init() {
	initlibs()
}
