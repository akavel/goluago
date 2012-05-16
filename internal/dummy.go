package internal

import (
	"unsafe"
)

type State uintptr

func Open() State {
	//goc: luaL_newstate() ret
	return State(luaL_newstate())
}

//goc-simple: (L State) Close() = lua_close((lua_State*)L)
//goc-simple: (L State) Gettop() int = lua_gettop((lua_State*)L) int
//goc-simple: (L State) Pushinteger(n int) = lua_pushinteger((lua_State*)L, (lua_Integer)n)
//goc-simple: (L State) Equal(i1, i2 int) int = lua_equal((lua_State*)L, (int)i1, (int)i2) int
//goc-simple: (L State) Lessthan(index1, index2 int) int = lua_lessthan((lua_State*)L, (int)index1, (int)index2) int
//goc-simple: (L State) Call(nargs, nresults int) = lua_call((lua_State*)L, (int)nargs, (int)nresults)
//goc-simple: (L State) Pushcclosure(f uintptr, n int) = lua_pushcclosure((lua_State*)L, (lua_CFunction)f, (int)n)

// FIXME: 'name' is currently ignored; in future, make sure
// it gets terminated by zero-byte and notify about trimming on embedded zero-bytes
// TODO: return error
func (s State) Loadbuffer(buff []byte, name string) int {
	//goc: luaL_loadbuffer((lua_State*)L, (const char*)buff, (size_t)sz, (const char*)name) ret
	return int(luaL_loadbuffer(uintptr(s), uintptr(unsafe.Pointer(&buff[0])), uintptr(len(buff)), uintptr(unsafe.Pointer(&([]byte("from loadbuffer\x00"))[0]))))
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

type Function func(L State) (retvals int)

func lua_pushgofunction(uintptr, uintptr)
func (L State) Pushgofunction(f Function) {
	lua_pushgofunction(uintptr(L), uintptr(unsafe.Pointer(&f)))
}

var Open_base uintptr

func initlibs()
func init() {
	initlibs()
}
