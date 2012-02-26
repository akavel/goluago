package internal

import (
	"unsafe"
)

func luaL_newstate() uintptr
func lua_close(uintptr)
func lua_gettop(uintptr) uintptr
func lua_pushinteger(uintptr, uintptr)
func lua_equal(uintptr, uintptr, uintptr) uintptr
func luaL_loadbuffer(uintptr, uintptr, uintptr, uintptr) uintptr
func lua_call(uintptr, uintptr, uintptr)

type State uintptr

func Open() State {
	return State(luaL_newstate())
}

func (s State) Close() {
	lua_close(uintptr(s))
}

func (s State) GetTop() int {
	return int(lua_gettop(uintptr(s)))
}

func (s State) PushInteger(n int) {
	lua_pushinteger(uintptr(s), uintptr(n))
}

func (s State) Equal(index1, index2 int) bool {
	return lua_equal(uintptr(s), uintptr(index1), uintptr(index2)) == 1
}

// FIXME: 'name' is currently ignored; in future, make sure
// it gets terminated by zero-byte and notify about trimming on embedded zero-bytes
// TODO: return error
func (s State) Loadbuffer(buff []byte, name string) int {
	return int(luaL_loadbuffer(uintptr(s), uintptr(unsafe.Pointer(&buff[0])), uintptr(len(buff)), uintptr(unsafe.Pointer(&([]byte("from loadbuffer\x00"))[0]))))
}

func (s State) Call(nargs, nresults int) {
	lua_call(uintptr(s), uintptr(nargs), uintptr(nresults))
}
