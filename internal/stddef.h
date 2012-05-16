#ifndef __STDDEF_H
#define __STDDEF_H

#define NULL ((void*)0)

//typedef void* ptrdiff_t;
//typedef unsigned long long int ptrdiff_t;   // 64b expected
typedef unsigned int ptrdiff_t; // 32b; will it be ok on 64b PCs?

//typedef unsigned long long int size_t;      // 64b expected
typedef unsigned int size_t; // 32b, to match size described in Lua header for chunks compiled by lua.exe

#endif
