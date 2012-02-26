
#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#include "time.h"

#include "goctypes.h"

void runtime·panicstring(int8*);

void
nyi(void) {
    runtime·panicstring("not yet implemented");
}

void
exit(int code) {
    void ·go_exit(uintptr);
    ·go_exit(code);
}

void*
realloc(void* ptr, size_t size) {
    void ·go_realloc(uintptr, uintptr, uintptr);
    void* ret = 0;
    ·go_realloc((uintptr)ptr, (uintptr)size, (uintptr)&ret);
    return ret;
}

void
free(void* ptr) {
    void ·go_free(uintptr);
    ·go_free((uintptr)ptr);
}

double
pow(double x, double y) {
    void ·go_pow(uintptr, uintptr);
    ·go_pow((uintptr)&x, (uintptr)&y);
    return x;
}

double
fmod(double x, double y) {
    void ·go_fmod(uintptr, uintptr);
    ·go_fmod((uintptr)&x, (uintptr)&y);
    return x;
}

double
modf(double x, double *iptr) {
    void ·go_modf(uintptr, uintptr);
    ·go_modf((uintptr)&x, (uintptr)iptr);
    return x;
}

double
atan2(double y, double x) {
    void ·go_atan2(uintptr, uintptr);
    ·go_atan2((uintptr)&y, (uintptr)&x);
    return y;
}

char*
strchr(const char* s, int ch) {
    char c = ch;
    while (*s && (*s != c)) {
        s++;
    }
    if (!*s) {
        return 0;
    }
    return (char*) s;
}

size_t
strlen(const char* s) {
    const char* p = s;
    while (*p++)
        ;
    return (size_t) (p - s - 1);
}

//FIXME
double
strtod(const char* nptr, char** endptr) {
    nyi();
    if (endptr) {
        *endptr = (char*) nptr+1;
    }
    return 0;
}

//FIXME
unsigned long
strtoul(const char* str, char** endptr, int base) {
    nyi();
    if (endptr) {
        *endptr = (char*) str+1;
    }
    return 0;
}

int
isspace(int c) {
    return (c == ' ') ||
        (c == '\n') ||
        (c == '\r') ||
        (c == '\t');
}

char*
strcpy(char* dst, const char* src) {
    char* dst0 = dst;
    while (*src) {
        *dst = *src;
        dst++; src++;
    }
    *dst = *src;
    return dst0;
}

char*
strncpy(char* dst, const char* src, size_t n) {
    char* dst0 = dst;
    while (*src && n>0) {
        *dst = *src;
        dst++; src++;
        n--;
    }
    while (n>0) {
        *dst = '\0';
        dst++;
        n--;
    }
    return dst0;
}

char*
strcat(char* dst, const char* src) {
    char* dst0 = dst;
    while (*dst) {
        dst++;
    }
    while (*src) {
        *dst = *src;
        dst++; src++;
    }
    *dst = *src;
    return dst0;
}

char*
strncat(char* dst, const char* src, size_t n) {
    char* dst0 = dst;
    if (n <= 0) {
        return dst0;
    }
    while (*dst) {
        dst++;
    }
    while (*src && n>0) {
        *dst = *src;
        dst++; src++;
        n--;
    }
    *dst = '\0';
    return dst0;
}

void*
memcpy(void* dst, const void* src, size_t n) {
    unsigned char* pdst = dst;
    unsigned char* psrc = src;
    while (n > 0) {
        *pdst = *psrc;
        pdst++; psrc++;
        n--;
    }
    return dst;
}

int
memcmp(const void* s1, const void* s2, size_t n) {
    unsigned char* p1 = s1;
    unsigned char* p2 = s2;
    while (*p1==*p2 && n>0) {
        p1++; p2++;
        n--;
    }
    if (n==0) {
        return 0;
    }
    return *p1 - *p2;
}

size_t
strcspn(const char* s, const char* tok) {
    const char* s0 = s;
    const char* tok0 = tok;
    while (*s) {
        for (tok=tok0; *tok; tok++) {
            if (*s == *tok) {
                goto end;
            }
        }
        s++;
    }
end:
    return s - s0;
}

//TODO: currently equal to strcmp()
int
strcoll(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1==*s2) {
        s1++; s2++;
    }
    return *s1 - *s2;
}

void*
memchr(const void* s, int c, size_t n) {
    unsigned char* p = s;
    unsigned char u = (unsigned char) c;
    while (n > 0) {
        if (*p == c) {
            return (void*) p;
        }
        n--;
    }
    return 0;
}

char*
strrchr(const char* s, int c) {
    char ch = (char) c;
    const char* last = 0;
    do {
        if (*s == ch) {
            last = s;
        }
    } while (*s++);
    return (char*) last;
}

char*
strpbrk(const char* s, const char* tok) {
    const char* tok0 = tok;
    while (*s) {
        for (tok=tok0; *tok; tok++) {
            if (*s == *tok) {
                return (char*) s;
            }
        }
        s++;
    }
    return 0;
}

int isxdigit(int c) {
    return (c>='0' && c<='9') ||
        (c>='a' && c<='f') ||
        (c>='A' && c<='F');
}

int isupper(int c) {
    return (c>='A' && c<='Z');
}

int islower(int c) {
    return (c>='a' && c<='z');
}

int ispunct(int c) {
    return c=='!' ||
        c=='\"' ||
        c=='#' ||
        c=='$' ||
        c=='%' ||
        c=='&' ||
        c=='\'' ||
        c=='(' ||
        c==')' ||
        c=='*' ||
        c=='+' ||
        c==',' ||
        c=='-' ||
        c=='.' ||
        c=='/' ||
        c==':' ||
        c==';' ||
        c=='<' ||
        c=='=' ||
        c=='>' ||
        c=='?' ||
        c=='@' ||
        c=='[' ||
        c=='\\' ||
        c==']' ||
        c=='^' ||
        c=='_' ||
        c=='`' ||
        c=='{' ||
        c=='|' ||
        c=='}' ||
        c=='~';
}

int toupper(int c) {
    if (c>='a' && c<='z') {
        return c - 'a' + 'A';
    }
    return c;
}

int tolower(int c) {
    if (c>='A' && c<='Z') {
        return c - 'A' + 'a';
    }
    return c;
}

static char locale_[] = "C";
static char locale2_[] = "POSIX";

char*
setlocale(int category, const char* locale) {
    if (locale == 0) {
        return (char*) locale_;
    }
    if (*locale=='\0' ||
        !strcoll(locale, locale_) ||
        !strcoll(locale, locale2_)) {
        return (char*) locale;
    }
    return 0;
}

double
difftime(time_t t1, time_t t0) {
    return (double)(t1-t0);
}

time_t
time(time_t* tloc) {
    void ·go_time(uintptr);
    time_t t;
    ·go_time((uintptr) &t);
    if (tloc) {
        *tloc = t;
    }
    return t;
}

//FIXME
time_t
mktime(struct tm* timeptr) {
    nyi();
    return 0;
}

struct tm timebuf_ = {0};

//FIXME
struct tm*
localtime(const time_t* timer) {
    nyi();
    return &timebuf_;
}

//FIXME
struct tm*
gmtime(const time_t* timer) {
    nyi();
    return &timebuf_;
}

//FIXME
clock_t
clock(void) {
    nyi();
    return (clock_t) -1;
}

//FIXME
#pragma textflag 7
int
sprintf(char* str, const char* format, ...) {
    nyi();
    return 0;
}

FILE* stderr;
FILE* stdin;

//FIXME
#pragma textflag 7
int
fprintf(FILE* stream, const char* format, ...) {
    nyi();
    return 0;
}

//FIXME
int
fclose(FILE* stream) {
    nyi();
    return 0;
}

//FIXME
int
ferror(FILE* stream) {
    nyi();
    return 0;
}

//FIXME
FILE*
freopen(const char* filename, const char* mode, FILE* stream) {
    nyi();
    return stderr;
}

//FIXME
FILE*
fopen(const char* filename, const char* mode) {
    nyi();
    return stderr;
}

//FIXME
int
getc(FILE* stream) {
    nyi();
    return -1;
}

//FIXME
int
ungetc(int ch, FILE* stream) {
    nyi();
    return -1;
}

//FIXME
size_t
fread(void* ptr, size_t size, size_t count, FILE* stream) {
    nyi();
    return 0;
}

//FIXME
int
feof(FILE* stream) {
    nyi();
    return -1;
}

//FIXME is now O(len_h*len_n), could be O(len_h+len_n) or something
char*
strstr(const char* haystack, const char* needle) {
    const char* h;
    const char* n;
    while (*haystack) {
        h = haystack;
        for (n=needle; *n && *h && (*n==*h); ) {
            n++, h++;
        }
        if (*n == 0) {
            return haystack; // found!
        }
        if (*h == 0) {
            break; // end of string
        }
        haystack++;
    }
    return 0;
}

//FIXME
char*
strerror(int errnum) {
    nyi();
    return "(SOME ERROR)";
}

int errno;

int
strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1==*s2) {
        s1++; s2++;
    }
    return *s1 - *s2;
}

