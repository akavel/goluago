package internal

import (
	"runtime/debug"
	. "testing"
)

func TestRunSuite(t *T) {
	cases := []struct{ code, name string }{
		{code_calls, "calls test"},
		{code_gc, "gc test"},
		{code_closure, "closure test"},
		{code_code, "code test"},
		{code_constructs, "constructs test"},
		{code_errors, "errors test"},
		{code_strings, "strings test"},
		{code_math, "math test"},
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

			for _, lib := range []uintptr{Open_base, Open_debug, Open_math, Open_string, Open_table} {
				l.Pushcclosure(lib, 0)
				l.Pushlstring([]byte(""))
				l.Call(1, 0)
			}

			r := l.Loadbuffer([]byte(c.code), c.name)
			if r != 0 {
				t.Errorf("error %d in %s: %s", r, c.name, string(l.Tolstring(-1)))
			}

			r = l.Pcall(0, 0, 0)
			if r != 0 {
				t.Errorf("error %d in %s: %s", r, c.name, string(l.Tolstring(-1)))
			}
			l.Close()
		}()
	}

}
