package internal

import (
	"math"
	"os"
	"time"
	"unsafe"
)

type alloc struct {
	p unsafe.Pointer
	s []byte
}

var allocs = make(map[uintptr]alloc)

func go_exit(code int) {
	os.Exit(code)
}

func go_realloc(ptr uintptr, size uint32, pnewptr uintptr) {
	var newptr uintptr = 0
	switch {
	case ptr == 0 && size == 0:
		break
	case ptr == 0: // malloc
		//TODO: if (size > int32.MAX) return 0; and set errno?
		if int(size) < 0 {
			break
		}
		buf := alloc{s: make([]byte, int(size))}
		buf.p = unsafe.Pointer(&buf.s[0])
		allocs[uintptr(buf.p)] = buf
		newptr = uintptr(buf.p)
	case size == 0: // free
		delete(allocs, ptr)
		break
	default: // realloc
		go_realloc(ptr, 0, uintptr(unsafe.Pointer(&newptr)))
		go_realloc(0, size, uintptr(unsafe.Pointer(&newptr)))
	}
	*((*uintptr)(unsafe.Pointer(pnewptr))) = newptr
}

func go_free(ptr uintptr) {
	go_realloc(ptr, 0, uintptr(unsafe.Pointer(&ptr)))
}

func go_pow(x, y uintptr) {
	px := (*float64)(unsafe.Pointer(x))
	py := (*float64)(unsafe.Pointer(y))
	*px = math.Pow(*px, *py)
}

func go_fmod(x, y uintptr) {
	px := (*float64)(unsafe.Pointer(x))
	py := (*float64)(unsafe.Pointer(y))
	*px = math.Mod(*px, *py)
}

func go_modf(f, iptr uintptr) {
	pf := (*float64)(unsafe.Pointer(f))
	pint := (*float64)(unsafe.Pointer(iptr))
	*pint, *pf = math.Modf(*pf)
}

func go_atan2(y, x uintptr) {
	px := (*float64)(unsafe.Pointer(x))
	py := (*float64)(unsafe.Pointer(y))
	*py = math.Atan2(*py, *px)
}

func go_time(t uintptr) {
	pt := (*int64)(unsafe.Pointer(t))
	*pt = time.Now().Unix()
}

type luapanic struct{}

func go_throw(L uintptr) {
	panic(luapanic{})
}

func golua_call(L, f, uv uintptr)

func go_try(L, f, uv uintptr) {
	defer func() {
		recover()
	}()

	golua_call(L, f, uv)
}
