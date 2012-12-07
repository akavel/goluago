
local arg={...}
local path=arg[1]
if not path then
  print("USAGE: lua wrap-test.lua TEST_FILE_PATH")
  os.exit(1)
end

local basename = path:gsub('.*[/\\]', ''):gsub('%.lua$', '')

local f = assert(io.open(path, 'r'))
local data = f:read '*all'
f:close()

io.write((([[
package internal

var code_{TESTNAME} = `
{DATA}
`
]]):gsub('{(%w+)}', {
  TESTNAME=basename,
  DATA=data:gsub('`', '`+"`"+`'):gsub('.', function(c)
    if c:byte()>=128 then
      return ('`+"\\x%x"+`'):format(c:byte())
    end
    return c
  end),
})))


