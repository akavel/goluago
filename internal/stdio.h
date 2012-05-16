#ifndef __STDIO_H
#define __STDIO_H

#include <stddef.h>

#define BUFSIZ 1024
#define EOF ((int)-1)
//TODO
#define L_tmpnam 10

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

//TODO
typedef int FILE;

extern FILE* stderr;
extern FILE* stdin;
extern FILE* stdout;

void clearerr(FILE*);
int fclose(FILE*);
int feof(FILE*);
int ferror(FILE*);
int fflush(FILE*);
char* fgets(char* s, int n, FILE*);
FILE* fopen(const char*, const char*);
int fprintf(FILE*, const char*, ...);
int fputs(const char*, FILE*);
size_t fread(void*, size_t, size_t, FILE*);
FILE* freopen(const char*, const char*, FILE*);
int fscanf(FILE*, const char*, ...);
int fseek(FILE*, long, int);
long ftell(FILE*);
size_t fwrite(void*, size_t, size_t, FILE*);
int getc(FILE*);
char* getenv(const char*);
int remove(const char*);
int rename(const char*, const char*);
int setvbuf(FILE*, char*, int, size_t);
int sprintf(char*, const char*, ...);
FILE* tmpfile(void);
char* tmpnam(char[L_tmpnam]);
int ungetc(int, FILE*);

#endif
