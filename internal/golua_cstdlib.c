
#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#include "time.h"
#include "locale.h"

#include "goctypes.h"

void
·lua_tonumber(uintptr L, uintptr index, uintptr pret) {
    *((lua_Number*)pret) = lua_tonumber((lua_State*)L, (int)index);
}

void
·lua_pushnumber(uintptr L, uintptr n) {
    lua_pushnumber((lua_State*)L, *(lua_Number*)n);
}

static int
stubwriter(lua_State* L, const void* p, size_t sz, void* ud) {
    void ·go_stubwriter(uintptr, uintptr, uintptr, uintptr, uintptr);
    int ret;
    ·go_stubwriter((uintptr)L, (uintptr)p, (uintptr)sz, (uintptr)ud, (uintptr)&ret);
    return ret;
}

void
·lua_dump(uintptr L, uintptr dumpinfo, uintptr ret) {
    ret = lua_dump((lua_State*)L, stubwriter, (void*)dumpinfo);
    FLUSH(&ret);
}

static int
stubcfunction(lua_State* L) {
    void ·go_stubcfunction(uintptr, uintptr, uintptr);
    int ret = 0;
    void* f = lua_touserdata(L, lua_upvalueindex(1));
    ·go_stubcfunction((uintptr)L, (uintptr)f, (uintptr)&ret);
    return ret;
}

void
·lua_pushgofunction(uintptr L, uintptr f) {
    lua_pushlightuserdata((lua_State*)L, (void*)f);
    lua_pushcclosure((lua_State*)L, stubcfunction, 1);
}

void *·Open_base;
FILE* stderr;
FILE* stdin;
FILE* stdout;

void
·initlibs(void) {
    ·Open_base = (void*)luaopen_base;
    stdin = (FILE*)3;   // better not 0, because 0 means NULL means sometimes error
    stdout = (FILE*)1;
    stderr = (FILE*)2;
}

////////////////////

void runtime·panicstring(int8*);

static char* nyi_string = "0 not yet implemented";
void
nyi(char char_id) {
    nyi_string[0] = char_id;
    runtime·panicstring(nyi_string);
    //runtime·panicstring("not yet implemented");
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
    void ·go_strtod(uintptr, uintptr, uintptr presult);
    double result=0;
    ·go_strtod((uintptr)nptr, (uintptr)endptr, (uintptr)&result);
    return result;
}

//FIXME
unsigned long
strtoul(const char* str, char** endptr, int base) {
    nyi('1');
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

//FIXME
int isdigit(int c) {
    return (c>='0' && c<='9');
}

//FIXME
int isalpha(int c) {
    return isupper(c) || islower(c);
}

//FIXME
int isalnum(int c) {
    return isalpha(c) || isdigit(c);
}

//FIXME
int iscntrl(int c) {
    return (c>=0 && c<=0x1f) || c==0x7f;
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
    nyi('2');
    return 0;
}

struct tm timebuf_ = {0};

//FIXME
struct tm*
localtime(const time_t* timer) {
    nyi('3');
    return &timebuf_;
}

//FIXME
struct tm*
gmtime(const time_t* timer) {
    nyi('4');
    return &timebuf_;
}

//FIXME
clock_t
clock(void) {
    nyi('5');
    return (clock_t) -1;
}

//FIXME
#pragma textflag 7
int
sprintf(char* str, const char* format, ...) {
    void ·go_sprintf(uintptr, uintptr, uintptr, uintptr);
    va_list argp;
    va_start(argp, format);
    ·go_sprintf((uintptr)str, (uintptr)format, (uintptr)argp, (uintptr)_BIGWORD);
    va_end(argp);
    //nyi('6');
    return 0; //FIXME
}

//FIXME
#pragma textflag 7
int
fprintf(FILE* stream, const char* format, ...) {
    void ·go_fprintf(uintptr, uintptr, uintptr, uintptr);
    va_list argp;
    va_start(argp, format);
    ·go_fprintf((uintptr)stream, (uintptr)format, (uintptr)argp, (uintptr)_BIGWORD);
    va_end(argp);
    //nyi('7');
    return 0; //FIXME
}

//FIXME
int
fclose(FILE* stream) {
    nyi('8');
    return 0;
}

//FIXME
int
ferror(FILE* stream) {
    nyi('9');
    return 0;
}

//FIXME
FILE*
freopen(const char* filename, const char* mode, FILE* stream) {
    nyi('a');
    return stderr;
}

//FIXME
FILE*
fopen(const char* filename, const char* mode) {
    nyi('b');
    return stderr;
}

//FIXME
int
getc(FILE* stream) {
    nyi('c');
    return -1;
}

//FIXME
int
ungetc(int ch, FILE* stream) {
    nyi('d');
    return -1;
}

//FIXME
size_t
fread(void* ptr, size_t size, size_t count, FILE* stream) {
    nyi('e');
    return 0;
}

//FIXME
int
feof(FILE* stream) {
    nyi('f');
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
    nyi('g');
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

//FIXME
int abs(int x) {
    if (x<0)
        return -x;
    return x;
}

struct lconv a_locale = {"."};

//FIXME
struct lconv*
localeconv(void) {
    return &a_locale;
}

void ·goputc(uintptr, uintptr);

//FIXME
int
fputs(const char* s, FILE* stream) {
    while (*s) {
        ·goputc((uintptr)*s, (uintptr)stream);
        s++;
    }
    return 1; //FIXME
}
