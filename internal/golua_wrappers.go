/* File generated automatically by gen_wrappers.lua */

package internal

func luaL_newstate() uintptr
func lua_close(uintptr)
func (L State) Close() {
	lua_close(uintptr(L))
}

func lua_gettop(uintptr) uintptr
func (L State) Gettop() int {
	return int(lua_gettop(uintptr(L)))
}

func lua_pushinteger(uintptr, uintptr)
func (L State) Pushinteger(n int) {
	lua_pushinteger(uintptr(L), uintptr(n))
}

func lua_equal(uintptr, uintptr, uintptr) uintptr
func (L State) Equal(i1, i2 int) int {
	return int(lua_equal(uintptr(L), uintptr(i1), uintptr(i2)))
}

func lua_lessthan(uintptr, uintptr, uintptr) uintptr
func (L State) Lessthan(index1, index2 int) int {
	return int(lua_lessthan(uintptr(L), uintptr(index1), uintptr(index2)))
}

func lua_call(uintptr, uintptr, uintptr)
func (L State) Call(nargs, nresults int) {
	lua_call(uintptr(L), uintptr(nargs), uintptr(nresults))
}

func lua_pushcclosure(uintptr, uintptr, uintptr)
func (L State) Pushcclosure(f uintptr, n int) {
	lua_pushcclosure(uintptr(L), uintptr(f), uintptr(n))
}

func luaL_loadbuffer(uintptr, uintptr, uintptr, uintptr) uintptr
func lua_pushlstring(uintptr, uintptr, uintptr)
func lua_tolstring(uintptr, uintptr, uintptr) uintptr
