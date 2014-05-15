
local funs = {
    'lua_assert',
--    'check_exp',
    'api_check',
    'api_checknelems',
    'api_checkvalidindex',
    'api_incr_top',
--    'luai_apicheck',
}

-----------------------------

local function sprintf(fmt, ...)
    return fmt:format(...)
end

local function printf(fmt, ...)
    print(fmt:format(...))
end

local function writefile(fname, data)
    local f = assert(io.open(fname, 'wb'))
    f:write(data)
    f:close()
end

-----------------------------

local function checkargs()
    if #arg<1 then
        printf([[USAGE: lua mark_asserts.lua FILE.c

Makes sure each call to assert functions (see below)
has as first argument filename and line number.

Currently recognized assert functions:
%s]], table.concat(funs, '\n'))
        os.exit(1)
    end
end

local function new_assert_marker(funs, fname)
    local self = {
        assert_funs = {},
        fname = fname,
    }
    for _,v in ipairs(funs) do
        self.assert_funs[v] = true
    end
    self.mark = function(self, s, lineno)
        if (s:find '^%s*#%s*define%s*') then
            return s
        end
        return (s:gsub('([%w_]+)(%s*)(%(.*)', function(fun, spaces, args)
            if not self.assert_funs[fun] then
                return fun .. spaces .. args
            end
            local mark = sprintf('"@%s:%d: "', self.fname, lineno)
            local i, j = args:find('^%("@[^:]*:[^:]*: "')
            if i then
                return fun .. spaces .. '(' .. mark .. args:sub(j+1)
            end
            return fun .. spaces .. '(' .. mark .. ', ' .. args:sub(2)
        end))
    end
    return self
end

-----------------------------

local function main()
    checkargs()
    local fname = arg[1]
    local marker = new_assert_marker(funs, fname)
    local lineno = 1
    local buf = {}
    local f = assert(io.open(fname))
    for line in f:lines() do
        buf[#buf+1] = marker:mark(line, lineno)
        lineno = lineno+1
    end
    f:close()
    writefile(fname, table.concat(buf, '\n')..'\n')
end

main()
