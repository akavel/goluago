#ifndef __STDARG_H
#define __STDARG_H

#include <stddef.h>

typedef int va_list;

#define va_start(ap,lastarg) 

#define va_arg(ap,type) 0

#define va_end(ap)


// void va_start(va_list ap, lastarg);
// Initialisation macro which must be called once before any unnamed argument is accessed. Stores context information in ap. lastarg is the last named parameter of the function.
// type va_arg(va_list ap, type);
// Yields value of the type (type) and value of the next unnamed argument.
// void va_end(va_list ap);

#endif
