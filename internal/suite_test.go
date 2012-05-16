package internal

import (
	. "testing"
)

func TestRunSuite(t *T) {
	l := Open()

	l.Pushcclosure(Open_base, 0)
	l.Pushlstring([]byte(""))
	l.Call(1, 0)

	r := l.Loadbuffer([]byte(code_calls), "calls test")
	if r != 0 {
		t.Errorf("error")
	}

	l.Call(0, 0)

	l.Close()

}
