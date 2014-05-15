/* File generated automatically by gen_wrappers.lua */

package internal

func luaL_newstate() uintptr
func lua_close(uintptr)
func (L State) Close() {
	lua_close(uintptr(L))
}

func lua_call(uintptr, uintptr, uintptr)
func (L State) Call(nargs, nresults int) {
	lua_call(uintptr(L), uintptr(nargs), uintptr(nresults))
}

func lua_checkstack(uintptr, uintptr) uintptr
func (L State) Checkstack(extra int) int {
	return int(lua_checkstack(uintptr(L), uintptr(extra)))
}

func lua_concat(uintptr, uintptr)
func (L State) Concat(n int) {
	lua_concat(uintptr(L), uintptr(n))
}

func lua_createtable(uintptr, uintptr, uintptr)
func (L State) Createtable(narr, nrec int) {
	lua_createtable(uintptr(L), uintptr(narr), uintptr(nrec))
}

func lua_equal(uintptr, uintptr, uintptr) uintptr
func (L State) Equal(i1, i2 int) int {
	return int(lua_equal(uintptr(L), uintptr(i1), uintptr(i2)))
}

func lua_error(uintptr) uintptr
func (L State) Error() int {
	return int(lua_error(uintptr(L)))
}

func lua_gc(uintptr, uintptr, uintptr) uintptr
func (L State) Gc(what, data int) int {
	return int(lua_gc(uintptr(L), uintptr(what), uintptr(data)))
}

func lua_getfenv(uintptr, uintptr)
func (L State) Getfenv(index int) {
	lua_getfenv(uintptr(L), uintptr(index))
}

func lua_getmetatable(uintptr, uintptr) uintptr
func (L State) Getmetatable(index int) int {
	return int(lua_getmetatable(uintptr(L), uintptr(index)))
}

func lua_gettable(uintptr, uintptr)
func (L State) Gettable(index int) {
	lua_gettable(uintptr(L), uintptr(index))
}

func lua_gettop(uintptr) uintptr
func (L State) Gettop() int {
	return int(lua_gettop(uintptr(L)))
}

func lua_insert(uintptr, uintptr)
func (L State) Insert(index int) {
	lua_insert(uintptr(L), uintptr(index))
}

func lua_isboolean(uintptr, uintptr) uintptr
func (L State) Isboolean(index int) int {
	return int(lua_isboolean(uintptr(L), uintptr(index)))
}

func lua_isfunction(uintptr, uintptr) uintptr
func (L State) Isfunction(index int) int {
	return int(lua_isfunction(uintptr(L), uintptr(index)))
}

func lua_islightuserdata(uintptr, uintptr) uintptr
func (L State) Islightuserdata(index int) int {
	return int(lua_islightuserdata(uintptr(L), uintptr(index)))
}

func lua_isnil(uintptr, uintptr) uintptr
func (L State) Isnil(index int) int {
	return int(lua_isnil(uintptr(L), uintptr(index)))
}

func lua_isnone(uintptr, uintptr) uintptr
func (L State) Isnone(index int) int {
	return int(lua_isnone(uintptr(L), uintptr(index)))
}

func lua_isnoneornil(uintptr, uintptr) uintptr
func (L State) Isnoneornil(index int) int {
	return int(lua_isnoneornil(uintptr(L), uintptr(index)))
}

func lua_isnumber(uintptr, uintptr) uintptr
func (L State) Isnumber(index int) int {
	return int(lua_isnumber(uintptr(L), uintptr(index)))
}

func lua_isstring(uintptr, uintptr) uintptr
func (L State) Isstring(index int) int {
	return int(lua_isstring(uintptr(L), uintptr(index)))
}

func lua_istable(uintptr, uintptr) uintptr
func (L State) Istable(index int) int {
	return int(lua_istable(uintptr(L), uintptr(index)))
}

func lua_isthread(uintptr, uintptr) uintptr
func (L State) Isthread(index int) int {
	return int(lua_isthread(uintptr(L), uintptr(index)))
}

func lua_isuserdata(uintptr, uintptr) uintptr
func (L State) Isuserdata(index int) int {
	return int(lua_isuserdata(uintptr(L), uintptr(index)))
}

func lua_lessthan(uintptr, uintptr, uintptr) uintptr
func (L State) Lessthan(index1, index2 int) int {
	return int(lua_lessthan(uintptr(L), uintptr(index1), uintptr(index2)))
}

func lua_newtable(uintptr)
func (L State) Newtable() {
	lua_newtable(uintptr(L))
}

func lua_next(uintptr, uintptr)
func (L State) Next(index int) {
	lua_next(uintptr(L), uintptr(index))
}

func lua_pcall(uintptr, uintptr, uintptr, uintptr) uintptr
func (L State) Pcall(nargs, nresults, errfunc int) int {
	return int(lua_pcall(uintptr(L), uintptr(nargs), uintptr(nresults), uintptr(errfunc)))
}

func lua_pop(uintptr, uintptr)
func (L State) Pop(n int) {
	lua_pop(uintptr(L), uintptr(n))
}

func lua_pushboolean(uintptr, uintptr)
func (L State) Pushboolean(b int) {
	lua_pushboolean(uintptr(L), uintptr(b))
}

func lua_pushcclosure(uintptr, uintptr, uintptr)
func (L State) pushcclosure(f uintptr, n int) {
	lua_pushcclosure(uintptr(L), uintptr(f), uintptr(n))
}

func lua_pushinteger(uintptr, uintptr)
func (L State) Pushinteger(n int) {
	lua_pushinteger(uintptr(L), uintptr(n))
}

func lua_pushnil(uintptr)
func (L State) Pushnil() {
	lua_pushnil(uintptr(L))
}

func lua_pushvalue(uintptr, uintptr)
func (L State) Pushvalue(index int) {
	lua_pushvalue(uintptr(L), uintptr(index))
}

func lua_rawequal(uintptr, uintptr, uintptr) uintptr
func (L State) Rawequal(index1, index2 int) int {
	return int(lua_rawequal(uintptr(L), uintptr(index1), uintptr(index2)))
}

func lua_rawget(uintptr, uintptr)
func (L State) Rawget(index int) {
	lua_rawget(uintptr(L), uintptr(index))
}

func lua_rawgeti(uintptr, uintptr, uintptr)
func (L State) Rawgeti(index, n int) {
	lua_rawgeti(uintptr(L), uintptr(index), uintptr(n))
}

func lua_rawset(uintptr, uintptr)
func (L State) Rawset(index int) {
	lua_rawset(uintptr(L), uintptr(index))
}

func lua_rawseti(uintptr, uintptr, uintptr)
func (L State) Rawseti(index, n int) {
	lua_rawseti(uintptr(L), uintptr(index), uintptr(n))
}

func lua_setmetatable(uintptr, uintptr)
func (L State) Setmetatable(index int) {
	lua_setmetatable(uintptr(L), uintptr(index))
}

func luaL_loadbuffer(uintptr, uintptr, uintptr, uintptr) uintptr
func lua_pushlstring(uintptr, uintptr, uintptr)
func lua_tolstring(uintptr, uintptr, uintptr) uintptr
func lua_getfield(uintptr, uintptr, uintptr)
func lua_getglobal(uintptr, uintptr)
func lua_getupvalue(uintptr, uintptr, uintptr) uintptr
