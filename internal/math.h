#ifndef __MATH_H
#define __MATH_H

//TODO: stolen from GCC (?), change to custom (non GPL) implementation
typedef union { unsigned char __c[8]; double __d; } __huge_val_t;
// # if __BYTE_ORDER == __BIG_ENDIAN
// #  define __HUGE_VAL_bytes      { 0x7f, 0xf0, 0, 0, 0, 0, 0, 0 }
// # endif
// # if __BYTE_ORDER == __LITTLE_ENDIAN
#define __HUGE_VAL_bytes      { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f }
// # endif
static __huge_val_t __huge_val = { __HUGE_VAL_bytes };
#define HUGE_VAL       (__huge_val.__d)

double asin(double);
double acos(double);
double atan(double);
double atan2(double, double);
double ceil(double);
double cos(double);
double cosh(double);
double exp(double);
double fabs(double);
double floor(double);
double fmod(double, double);
double frexp(double, int*);
double ldexp(double, int);
double log(double);
double log10(double);
double modf(double, double*);
double pow(double, double);
double sqrt(double);
double sin(double);
double sinh(double);
double tan(double);
double tanh(double);

#endif
