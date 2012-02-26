--[[
func lua_close(uintptr)
func lua_gettop(uintptr) uintptr
func lua_pushinteger(uintptr, uintptr)
func lua_equal(uintptr, uintptr, uintptr) uintptr

void lua_close (lua_State *L);
int lua_gettop (lua_State *L);
]]

methods = {
    'Close()',
    'Gettop() int',
    'Pushinteger(n int)',
    'Equal(index1, index2 int) bool',
}

entryfmt = ([[
func lua_${SMALLNAME}(${UINTPTR_ARGS})${UINTPTR_RET}

func (s State) ${NAME}(${ARGS})${RET} {
\t${BODY}
}
]]):gsub('\r\n', '\n'):gsub('\r', '\n'):gsub('\\t', '\t')

for _, m in ipairs(methods) do
    local goname, i0args, i1args, iret = m:match '([%w_]-)%(().-()%)()'
    local goargs = m:sub(i0args, i1args-1)
    local goret = m:sub(iret)
    print(i0args, i1args, iret, m, goname, goret)
    print((entryfmt:gsub('${([%w_]+)}', {
        SMALLNAME = goname:lower(),
        UINTPTR_ARGS = goargs:gsub('[^%s,][^,]*', 'uintptr'),
        UINTPTR_RET = goret:gsub('[^%s].*', 'uintptr'),
        NAME = goname,
        ARGS = goargs,
        RET = goret,
    })))
end


--[[
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
]]