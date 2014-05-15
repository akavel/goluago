
local input = 'golua_api.go'

-----------------

local pat_start = '^%s*//goc:%s*'
local pat_name = '([%w_]+)'
local pat_args = '%((.*)%)'
local pat_ret = '(%s*[%w_]*)'
local pat_line = pat_start..pat_name..pat_args..pat_ret

local pat_cast = '(%(.-%))'
local pat_arg = pat_cast..'%s*'..pat_name

function decode_goc(line)
    local name, args, ret = line:match(pat_line)
    if name == nil then
        return nil
    end
    
    return {
        name=name,
        sargs=args,
        ret=ret,
        args=args,
    }
end

local pat2_start = '^%s*//goc%-simple:%s*'
local pat2_gohead = '([^=]-)%s*=%s*'
local pat2_rest = '(.*)'
local pat2_line = pat2_start..pat2_gohead..pat2_rest
--local pat2_line = '^//goc%-si()'

function decode_goc_simple(line)
    local gohead, rest = line:match(pat2_line)
    if gohead == nil then
        return line, nil
    end
    --print(gohead, rest)
    local newline = '//goc:' .. rest
    print(newline)
    return newline, {
        gohead=gohead,
    }
end

----------------

local go = io.open('golua_wrappers.go', 'wb')
local c = io.open('golua_wrappers.c', 'wb')
local EOL = '\n'

local msg = '/* File generated automatically by gen_wrappers.lua */\n\n'
go:write(msg)
c:write(msg)

go:write(
'package internal' ..EOL..
'' ..EOL..
'')

c:write(
'#include "lua.h"' ..EOL..
'#include "lauxlib.h"' ..EOL..
'#include "lualib.h"' ..EOL..
'#include "goctypes.h"' ..EOL..
'' ..EOL..
'')

----------------

function fill(s, vars)
    return (s:gsub('${([%w_]+)}', vars))
end

----------------

for l in io.lines(input) do
    local l, func_simple = decode_goc_simple(l)
    local func = decode_goc(l)
    if func then
        local vars = {}
        vars.UINTPTR_ARGS_GO = func.sargs:gsub('[^%s,][^,]*', 'uintptr')
        vars.UINTPTR_ARGS_C = func.sargs:gsub(pat_cast, 'uintptr ')
        vars.ARGS_COMMA = (#func.sargs>0 and ', ' or '')
        vars.UINTPTR_RET = (func.ret or ''):gsub('[^%s].*', 'uintptr')
        vars.NAME = func.name
        vars.ARGS = func.sargs
        vars.GO_HEAD = func_simple and func_simple.gohead
        vars.GO_RET = func_simple and func_simple.gohead:gmatch('([%w_]+)%s*$')()
        vars.GO_ARGS = func_simple and func.sargs:gsub(pat_arg, 'uintptr(%2)') or ''
        print(vars.GO_ARGS)
        --func.sargs:gsub('%([^,%)]*%)%s*([^,]*)', 'uintptr(%1)')
        
        go:write(fill(
'func ${NAME}(${UINTPTR_ARGS_GO})${UINTPTR_RET}' ..EOL..
'', vars))

        if #(func.ret or '')>0 then
            c:write(fill(
'void' ..EOL..
'\194\183${NAME}(${UINTPTR_ARGS_C}${ARGS_COMMA}uintptr ret) {' ..EOL..
'    ret = (uintptr) ${NAME}(${ARGS});' ..EOL..
'    FLUSH(&ret);' ..EOL..
'}' ..EOL..
'' ..EOL..
'', vars))

            if func_simple then
                go:write(fill(
'func ${GO_HEAD} {' ..EOL..
'\treturn ${GO_RET}(${NAME}(${GO_ARGS}))' ..EOL..
'}' ..EOL..
'' ..EOL..
'', vars))
            end
        else
            c:write(fill(
'void' ..EOL..
'\194\183${NAME}(${UINTPTR_ARGS_C}) {' ..EOL..
'    ${NAME}(${ARGS});' ..EOL..
'}' ..EOL..
'' ..EOL..
'', vars))
            if func_simple then
                go:write(fill(
'func ${GO_HEAD} {' ..EOL..
'\t${NAME}(${GO_ARGS})' ..EOL..
'}' ..EOL..
'' ..EOL..
'', vars))
            end
        end
    end
end
