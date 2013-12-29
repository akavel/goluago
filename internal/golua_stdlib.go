package internal

import (
	//	"runtime/debug"
	"unsafe"
)

type luapanic struct{}

func go_throw(L uintptr) {
	panic(luapanic{})
}

func golua_call(L, f, uv uintptr)

func go_try(L, f, uv uintptr) {
	defer func() {
		x := recover()
		if x == nil {
			return
		}

		_, ok := x.(luapanic)
		if ok {
			return
		}

		//		fmt.Fprintf(os.Stderr, "INTERNAL GOLUAGO PANIC: '%s' at:\n%s", x, string(debug.Stack()))
		panic(x)
	}()

	golua_call(L, f, uv)
}

func go_stubwriter(L_, pbuf, sz, ud_, pret_ uintptr) {
	L := State(L_)
	di := *((*dumpinfo)(unsafe.Pointer(ud_)))
	pret := (*int32)(unsafe.Pointer(pret_))
	*pret = int32(di.writer(L, pbuf, sz, di.data))
}

func go_stubcfunction(L_, f_, pret_ uintptr) {
	L := State(L_)
	f := (*Function)(unsafe.Pointer(f_))
	pret := (*int32)(unsafe.Pointer(pret_))
	*pret = (*f)(L)
}
