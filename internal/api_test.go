package internal

import (
	. "testing"
)

func TestOpenClose(t *T) {
	l := Open()
	l.Close()
}

func TestStackBasic(t *T) {
	l := Open()
	defer l.Close()

	n := l.Gettop()
	if n != 0 {
		t.Error(n)
	}

	stack := []int{5, 5, 0}
	for i, x := range stack {
		l.Pushinteger(x)
		n = l.Gettop()
		if n != i+1 {
			t.Error("expected", i+1, "got", n)
		}
	}

	eqs := []struct {
		i1, i2 int
		eq     int // 1=true, 0=false
	}{
		{-1, -2, 0},
		{-2, -3, 1},
		{1, 2, 1},
		{2, 3, 0},
	}
	for _, x := range eqs {
		if l.Equal(x.i1, x.i2) != x.eq {
			t.Error("expected", x)
		}
	}
}

func TestNumStrConv(t *T) {
	cases := []struct {
		n float64
		s string
	}{
		{1.001, "1.001"},
	}

	for i, x := range cases {
		l := Open()
		l.Pushnumber(x.n)
		s := string(l.Tostring(-1))
		if s != x.s {
			t.Error("case", i, "wrong string", s)
		}
		l.Close()
	}

	for i, x := range cases {
		l := Open()
		l.Pushstring([]byte(x.s))
		n := l.Tonumber(-1)
		if n != x.n {
			t.Error("case", i, "wrong number", n)
		}
		l.Close()
	}
}

func TestParseAndRun(t *T) {
	cases := []struct {
		chunk string
		stack []string
	}{
		{"return 4+5", []string{"9"}},
	}

	for i, c := range cases {
		l := Open()

		r := l.Loadbuffer([]byte(c.chunk), "")
		if r != 0 {
			t.Error("case", i, "got error", r, "when loading")
			goto cont
		}

		l.Call(0, len(c.stack))

		if l.Gettop() != len(c.stack) {
			t.Error("case", i, "stack size expected", len(c.stack), "got", l.Gettop())
		}

		for j := range c.stack {
			res := string(l.Tostring(j + 1))
			if res != c.stack[j] {
				t.Error("case", i, "stack position", j, "got", res)
			}
		}

	cont:
		l.Close()
	}
}

func TestGetfieldGetglobal(t *T) {
	l := Open()
	defer l.Close()

	r := l.Loadbuffer([]byte(`t={k=15}`), `t={k=15}`)
	if r != 0 {
		t.Fatal("Loadbuffer=", r)
	}
	l.Call(0, 0)

	l.Getglobal("t")
	l.Getfield(-1, "k")
	if x := l.Tointeger(-1); x != 15 {
		t.Fatal("Tointeger=", x)
	}
}

func TestPushstringTostring(t *T) {
	l := Open()
	defer l.Close()

	l.Pushstring([]byte("foo"))
	if x := string(l.Tostring(-1)); x != "foo" {
		t.Fatal("Tostring=", x)
	}
}

func TestGetupvalue(t *T) {
	l := Open()
	defer l.Close()

	r := l.Loadbuffer([]byte(`local u=10; function f() return u end`), "test")
	if r != 0 {
		t.Fatal("Loadbuffer=", r)
	}
	l.Call(0, 0)

	l.Getglobal("f")
	name := string(l.Getupvalue(-1, 1))
	if name != "u" {
		t.Error("Getupvalue=", name)
	}
	top := l.Tointeger(-1)
	if top != 10 {
		t.Error("upvalue=", top)
	}
}

func TestSetmetatable(t *T) {
	l := Open()
	defer l.Close()

	l.Pushgofunction(Open_base)
	l.Call(0, 0)

	r := l.Loadbuffer([]byte(`m={i=10} t={}`), "test")
	if r != 0 {
		t.Fatal("Loadbuffer=", r)
	}
	l.Call(0, 0)

	l.Getglobal("t")
	l.Getglobal("m")
	l.Setmetatable(-2)

	r = l.Loadbuffer([]byte(`r=getmetatable(t) if r==m then r=1 else r=0 end`), "tmp")
	if r != 0 {
		t.Fatal("Loadbuffer=", r)
	}
	l.Call(0, 0)

	l.Getglobal("r")
	result := l.Tointeger(-1)
	if result != 1 {
		t.Error("result=", result)
	}
}

func TestLoad(t *T) {
	l := Open()
	defer l.Close()

	data := []string{"a=", "3", " ", "return a*2", ""}
	r := l.Load(func(L State) []byte {
		if len(data) == 0 {
			return nil
		}
		var h string
		h, data = data[0], data[1:]
		return []byte(h)
	}, "somechunk")
	if r != 0 {
		t.Fatal("Load=", r)
	}

	l.Call(0, 1)
	x := l.Tointeger(-1)
	if x != 6 {
		t.Error("expected return 6, got", x)
	}

	l.Getglobal("a")
	a := l.Tointeger(-1)
	if a != 3 {
		t.Error("expected a=3, got", a)
	}
}
