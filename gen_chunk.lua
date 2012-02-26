
-- generate some simple compiled chunks for testing the Lua VM

function dump(s)
    local c = assert(loadstring(s, ''))
    c = string.dump(c)

    local a, z, A, Z, d0, d9 = ('azAZ09'):byte(1, 6)
    local safe0 = '`~!@#$%^&*()-_=+[]{};\':|,./<>?' -- no: \ "
    local safe = {}
    for _, s in ipairs{safe0:byte(1, #safe0)} do
        safe[s] = true
    end

    c = c:gsub('.', function(x)
        local b = x:byte()
        if (a<=b and b<=z) or (A<=b and b<=Z) or (d0<=b and b<=d9) or safe[b] then
            return x
        end
        return ('\\x%02x'):format(b)
    end)
    return '"' .. c .. '"'
end

print(dump 'return 2+3')

"\x1bLuaQ\x00\x01\x04\x04\x04\x08\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x02\x03\x00\x00\x00\x01\x00\x00\x00\x1e\x00\x00\x01\x1e\x00\x80\x00\x01\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x14@\x00\x00\x00\x00\x03\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"