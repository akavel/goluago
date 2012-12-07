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
		s := string(l.Tolstring(-1))
		if s != x.s {
			t.Error("case", i, "wrong string", s)
		}
		l.Close()
	}

	for i, x := range cases {
		l := Open()
		l.Pushlstring([]byte(x.s))
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
			res := string(l.Tolstring(j + 1))
			if res != c.stack[j] {
				t.Error("case", i, "stack position", j, "got", res)
			}
		}

	cont:
		l.Close()
	}
}
