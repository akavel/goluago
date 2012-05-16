
#include "goctypes.h"

void runtime·panicstring(char *);

////////

#include "string.h"
#include "stdio.h"

void
TestStrlen(void) {
    if (strlen("abc")!=3)
        runtime·panicstring("strlen failed");
    if (strlen("")!=0)
        runtime·panicstring("strlen failed");
    if (strlen("1\0")!=1)
        runtime·panicstring("strlen failed");
}

void
TestStrcmp(void) {
    if (!(strcmp("abc", "abz")<0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("ab", "aba")<0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("", "a")<0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("aa", "ab")<0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("aaa", "ab")<0))
        runtime·panicstring("strcmp failed");

    if (!(strcmp("", "")==0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("abc", "abc")==0))
        runtime·panicstring("strcmp failed");

    if (!(strcmp("abz", "abc")>0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("aba", "ab")>0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("a", "")>0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("ab", "aa")>0))
        runtime·panicstring("strcmp failed");
    if (!(strcmp("ab", "aaa")>0))
        runtime·panicstring("strcmp failed");
}

void
TestSprintf(void) {
    char buf[256] = {0};

    if (sprintf(buf, "a%sa", "bbb"), strcmp(buf, "abbba")!=0)
        runtime·panicstring(buf);
    if (sprintf(buf, "a%%a"), strcmp(buf, "a%a")!=0)
        runtime·panicstring(buf);
    if (sprintf(buf, "a%sa%sa", "b", "c"), strcmp(buf, "abaca")!=0)
        runtime·panicstring(buf);

    if (sprintf(buf, "a%.14ga", 1.01l), strcmp(buf, "a1.01a")!=0)
        runtime·panicstring(buf);
}


////////

typedef void (*fptr)(void);

void ·go_ctest(uintptr t, fptr f);

void
·golua_ctestrun(fptr f) {
    (*f)();
}

void
·golua_ctests(uintptr t) {
    ·go_ctest(t, TestStrlen);
    ·go_ctest(t, TestStrcmp);
    ·go_ctest(t, TestSprintf);
}
