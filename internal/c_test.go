package internal

import (
	"testing"
	"unsafe"
)

func golua_ctests(t uintptr)

func TestC(t *testing.T) {
	golua_ctests(uintptr(unsafe.Pointer(t)))
}
