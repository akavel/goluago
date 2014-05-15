package internal

import (
	"runtime/debug"
	. "testing"
)

func TestRunSuite(t *T) {
	cases := []struct{ code, name string }{
		{code_calls, "@calls.lua"},
		{code_gc, "@gc.lua"},
		{code_closure, "@closure.lua"},
		{code_code, "@code.lua"},
		{code_constructs, "@constructs.lua"},
		{code_errors, "@errors.lua"},
		{code_strings, "@strings.lua"},
		{code_db, "@db.lua"},
		{code_literals, "@literals.lua"},
		{code_locals, "@locals.lua"},
		{code_nextvar, "@nextvar.lua"},
		{code_pm, "@pm.lua"},
		{code_events, "@events.lua"},
		{code_vararg, "@vararg.lua"},
		{code_checktable, "@checktable.lua"},
		{code_sort, "@sort.lua"},
		// needs C tmpfile() {code_math, "@math.lua"},
		// needs Lua require() {code_big, "@big.lua"},
		// needs Lua require() {code_attrib, "@attrib.lua"},
		// needs C tmpnam(), and others {code_verybig, "@verybig.lua"},
	}
	for _, c := range cases {
		func() {
			defer func() {
				if x := recover(); x != nil {
					t.Errorf("panic in \"%s\": %v", c.name, x)
					t.Errorf("panic stacktrace:\n%s", string(debug.Stack()))
				}
			}()
			l := Open()
			l.LOpenlibs()

			r := l.Loadbuffer([]byte(c.code), c.name)
			if r != 0 {
				t.Errorf("error in %s", c.name)
			}

			r = l.Pcall(0, 0, 0)
			if r != 0 {
				t.Errorf("error %d in %s: %s", r, c.name, string(l.Tostring(-1)))
			}
			l.Close()
		}()
	}

}
