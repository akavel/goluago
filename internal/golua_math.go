/* File generated automatically by gen_math.lua */
package internal

import (
	"math"
	"unsafe"
)

func go_asin(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Asin(*p)
}

func go_acos(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Acos(*p)
}

func go_atan(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Atan(*p)
}

func go_ceil(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Ceil(*p)
}

func go_cos(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Cos(*p)
}

func go_cosh(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Cosh(*p)
}

func go_exp(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Exp(*p)
}

func go_fabs(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Abs(*p)
}

func go_floor(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Floor(*p)
}

func go_log(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Log(*p)
}

func go_log10(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Log10(*p)
}

func go_sqrt(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Sqrt(*p)
}

func go_sin(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Sin(*p)
}

func go_sinh(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Sinh(*p)
}

func go_tan(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Tan(*p)
}

func go_tanh(x uintptr) {
	p := (*float64)(unsafe.Pointer(x))
	*p = math.Tanh(*p)
}
