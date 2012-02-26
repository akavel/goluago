#ifndef __STDLIB_H
#define __STDLIB_H

#include <stddef.h>

#define EXIT_FAILURE 255
#define EXIT_SUCCESS 0
#define RAND_MAX INT_MAX

int abs(int);
void exit(int);
void free(void*);
int rand(void);
void* realloc(void*, size_t);
void srand(unsigned int);
double strtod(const char*, char**);
unsigned long strtoul(const char*, char**, int);
int system(const char*);

#endif
