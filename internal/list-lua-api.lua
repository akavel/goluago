--[[
Script tries to build a text-file with mapping of Lua API functions to their Go counterparts in goluago.
]]--

local GOC_FILES = {'golua_api.go', 'golua_lapi.go'}
local HTML_OUTFILE = '../list-lua-api.html'
local README_OUTFILE = '../README.md'
local API_TESTFILES = {'api_test.go'}

function sprintf(fmt, ...)
	return fmt:format(...)
end
function printf(fmt, ...)
	print(sprintf(fmt, ...))
end

function main()
	-- collect the C API function names
	local c_api = {}
	for line in io.lines "../lua-5.1.4/doc/contents.html" do
		local entry = line:match 'manual.html#(luaL?_[a-z][a-z]+)'
		if entry then
			--print(entry)
			c_api[entry] = {}
		end
	end
	
	local go_api_has_test = {}

	-- collect simple mappings
	for _, goc_file in ipairs(GOC_FILES) do
	for line in io.lines(goc_file) do
		--local entry = line:match '^//goc-simple: %(L State%) ([A-Z][a-z]+).- = (luaL?_[a-z]+)'
		local goname, cname = line:match '^//goc%-simple: %(L State%) ([A-Z][A-Za-z]+).-=.-(luaL?_[a-z]+)'
		local goname2, cname2 = line:match '^//goc%-simple: ([A-Z][A-Za-z]+).-=.-(luaL?_[a-z]+)'
		if goname then
			--print(goname, cname)
			goname = 'State.' .. goname
		elseif goname2 then
			goname, cname = goname2, cname2
		end
		if goname then
			--print(goname, cname)
			c_api[cname] = c_api[cname] or {special=true}
			c_api[cname].goname = goname
		end
	end
	end
	
	-- collect elaborate mappings
	local in_gofunc = nil
	for _, goc_file in ipairs(GOC_FILES) do
	for line in io.lines(goc_file) do
		local cfunc = line:match '[^%w_](luaL?_%w+)%('
		if line:match '^func.*{' then
			line = line:gsub('^func ', '')
			in_gofunc = ''
			line = line:gsub('^%(.-([^ ]+)%) ', function(x)
				in_gofunc = x .. '.'
				return ''
			end)
			local gofunc = line:match '^[%w_]+'
			in_gofunc = in_gofunc .. gofunc
			if not gofunc:match '^[A-Z]' then
				in_gofunc = nil
			end
			--print(in_gofunc)
		elseif in_gofunc and cfunc then
			c_api[cfunc] = c_api[cfunc] or {special=true}
			c_api[cfunc].goname = in_gofunc
		elseif line:match '^}' then
			in_gofunc = nil
		end
	end
	end
	
	-- try to find out which APIs are tested
	-- NOTE: very hackish for now, freely modify/rewrite if needed
	go_api_has_test['Open'] = true
	for _, fname in ipairs(API_TESTFILES) do
		local lua_state = nil
		for line in io.lines(fname) do
			lua_state = line:match '^\t([%w_]+) := Open%(%)' or lua_state
			
			local lua_func
			if lua_state then
				lua_func = line:match('[^%w_]' .. lua_state .. '%.([A-Z][A-Za-z]+)%(')
			end
			
			if line:match '^}' then
				lua_state = nil
			elseif lua_func then
				go_api_has_test['State.' .. lua_func] = true
			end
		end
	end
	
	-- sort results by C API function name
	local results = {}
	for k, v in pairs(c_api) do
		v.cname = k
		results[#results+1] = v
	end
	table.sort(results, function(first, second)
		return first.cname < second.cname
	end)
	
	-- calculate statistics
	local stats = {all=0, done=0, special=0, tested=0}
	for _, entry in ipairs(results) do
		if entry.special then
			stats.special = stats.special + 1
		elseif entry.goname then
			stats.done = stats.done + 1
			stats.all = stats.all + 1
		else
			stats.all = stats.all + 1
		end
		if entry.goname and go_api_has_test[entry.goname] then
			stats.tested = stats.tested + 1
			entry.has_test = true
		end
	end
	results.stats = stats
	
	--print_results(results)
	print_html_results(results)
	update_readme_status(results)
end

function update_readme_status(results)
	local fh = assert(io.open(README_OUTFILE, 'r'))
	local text = fh:read '*a'
	fh:close()
	
	local completed, tested = build_stat_strings(results)
	text = text:gsub(
		'(STATUS\n%-%-%-%-%-%-\n)\n[^\n]-complete[^\n]-have some test[^\n]-\n',
		function(pre) return pre..'\n[C API: '..completed..', '..tested..'](#C-API-STATUS)\n' end)

	text = text:gsub(
		'(C API STATUS\n%-%-%-%-%-%-%-%-%-%-%-%-\n)\n.-(\nLICENSE)',
		function(pre, post)
			return pre..'\n'..print_markdown_results(results)..'\n'..post
		end)

	--print(text)
	local fh = assert(io.open(README_OUTFILE, 'wb'))
	fh:write(text)
	fh:close()
end

function print_markdown_results(results)
	local t = {}
	local printf = function(fmt, ...) t[#t+1]=fmt:format(...) end
	
	local completed, tested = build_stat_strings(results)
	printf('%s, %s\n\n', completed, tested)
	printf('| Go  |  C  | tests? |\n')
	printf('| --- | --- | ------ |\n')
	for _, entry in ipairs(results) do
		local lua_url = sprintf('*[%s](http://lua.org/manual/5.1/manual.html#%s)*', entry.cname, entry.cname)
		local go_url = ' '
		if entry.goname then
			go_url = sprintf('**[%s](http://godoc.org/github.com/akavel/goluago/internal#%s)**', entry.goname, entry.goname)
			lua_url = sprintf('*%s*', lua_url)
		end
		if entry.special then
			lua_url = entry.cname
		end
		--local marker = (entry.special and '%%%%%%') or (entry.goname and '$$$$$$') or '......'
		local has_test = entry.has_test and '**has test!**' or ' '
		--printf('| %s | %s | %s | %s |\n', marker, lua_url, go_url, has_test)
		printf('| %s | %s | %s |\n', go_url, lua_url, has_test)
	end
	return table.concat(t)
end

function build_stat_strings(results)
	return 
		('~%d%% complete (%d/%d + %d)'):format(
			100 * results.stats.done / results.stats.all + 0.5,
			results.stats.done, results.stats.all, results.stats.special),
		('~%d%% have some test (%d/%d)'):format(
			100 * results.stats.tested / (results.stats.all+results.stats.special) + 0.5,
			results.stats.tested, results.stats.all+results.stats.special)
end

function print_results(results)
	for _, entry in ipairs(results) do
		print(("%s = %s%s"):format(
			entry.cname,
			entry.special and 'SPECIAL ' or '',
			entry.goname or ''))
	end
end

function print_html_results(results)
	local outf = assert(io.open(HTML_OUTFILE, "w"))
	local print = function(s) outf:write(s..'\n') end
	local printf = function(fmt, ...) outf:write(fmt:format(...)) end

	print '<html><head><title>Goluago API completeness</title></head>'
	print '<body>'
	local completed, tested = build_stat_strings(results)
	printf('<p>%s</p>\n<p>%s</p>\n', completed, tested)
	print '<table border="1">'
	for _, entry in ipairs(results) do
		local lua_url = sprintf('<a href="http://lua.org/manual/5.1/manual.html#%s">%s</a>', entry.cname, entry.cname)
		if entry.special then
			lua_url = entry.cname
		end
		local go_url = '---'
		if entry.goname then
			go_url = sprintf('<a href="http://godoc.org/github.com/akavel/goluago/internal#%s">%s</a>', entry.goname, entry.goname)
		end
		local color = (entry.special and 'yellow') or (entry.goname and '#88ff88') or '#ff8888'
		local has_test = entry.has_test and 'has test' or '&nbsp;'
		printf('<tr><td bgcolor="%s">%s</td><td>%s</td><td>%s</td></tr>\n', color, lua_url, go_url, has_test)
	end
	print '</table>'
	print '</body></html>'
end

main()
