#ifndef __FIX2GO_H
#define __FIX2GO_H

//FIXME: MC: is line below OK?
typedef unsigned long int size_t;
typedef signed long int ptrdiff_t;
typedef struct va_list *va_list;
typedef struct FILE FILE;
typedef struct time_t time_t;

#define lua_lock(L) NOP()
#define lua_unlock(L) NOP()
#define UNUSED(x) NOP()
void NOP();
void runtime_panicstring(const char *);
void mylua_assert(int);

//FIXME: MC: below is temporary I hope
#define HARDSTACKTESTS

//FIXME: MC: is below ok?
void *NULL;

#endif
