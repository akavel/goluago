
local go = io.open('golua_math.go', 'wb')
local c = io.open('golua_math.c', 'wb')
local EOL = '\n'

local msg = '/* File generated automatically by gen_math.lua */\n'
go:write(msg)
c:write(msg)

go:write(
'package internal' ..EOL..
'' ..EOL..
'import (' ..EOL..
'\t"math"' ..EOL..
'\t"unsafe"' ..EOL..
')' ..EOL..
'')

c:write('' ..EOL..
'#include "goctypes.h"' ..EOL..
'')

gofmt =
'' ..EOL..
'func go_${name}(x uintptr) {' ..EOL..
'\tp := (*float64)(unsafe.Pointer(x))' ..EOL..
'\t*p = math.${Name}(*p)' ..EOL..
'}' ..EOL..
''

cfmt =
'' ..EOL..
'double' ..EOL..
'${name}(double x) {' ..EOL..
'    void \194\183go_${name}(uintptr);' ..EOL..
'    \194\183go_${name}((uintptr) &x);' ..EOL..
'    return x;' ..EOL..
'}' ..EOL..
''

for line in io.lines('math.h') do
    --print(line)
    local s, e, name = line:find('double (%w+)%(double%);')
    if s then
        print(line:sub(s, e), name)
        
        local bigname = name:sub(1, 1):upper() .. name:sub(2)
        if bigname=='Fabs' then
            bigname = 'Abs' -- exception
        end
        
        go:write((gofmt:gsub('${name}', name):gsub('${Name}', bigname)))
        c:write((cfmt:gsub('${name}', name)))
    end
end

go:close()
c:close()
