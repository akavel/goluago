#ifndef __STDARG_H
#define __STDARG_H

#include <stddef.h>

#ifdef _64BIT
#define _BIGWORD 8
#else
#define _BIGWORD 4
#endif


typedef char* va_list;

#define va_start(ap,lastarg) ap = (((char*)(void*)&lastarg)+_BIGWORD)

#define va_arg(ap,type) (*(type*)(void*)(ap+=_BIGWORD, ap-_BIGWORD))

#define va_end(ap)


// void va_start(va_list ap, lastarg);
// Initialisation macro which must be called once before any unnamed argument is accessed. Stores context information in ap. lastarg is the last named parameter of the function.
// type va_arg(va_list ap, type);
// Yields value of the type (type) and value of the next unnamed argument.
// void va_end(va_list ap);

#endif
