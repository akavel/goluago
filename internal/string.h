#ifndef __STRING_H
#define __STRING_H

#include <stddef.h>

void* memchr(const void*, int, size_t);
int memcmp(const void*, const void*, size_t);
void* memcpy(void*, const void*, size_t);

char* strchr(const char*, int);
char* strcat(char*, const char*);
int strcmp(const char*, const char*);
int strcoll(const char*, const char*);
char* strcpy(char*, const char*);
size_t strcspn(const char*, const char*);
char* strerror(int);
size_t strlen(const char*);
char* strncat(char*, const char*, size_t);
char* strncpy(char*, const char*, size_t);
char* strpbrk(const char*, const char*);
char* strrchr(const char*, int);
char* strstr(const char*, const char*);

#endif
