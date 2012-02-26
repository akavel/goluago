#ifndef __LOCALE_H
#define __LOCALE_H

//TODO:
#define LC_ALL          0
#define LC_NUMERIC      1
#define LC_MONETARY     2
#define LC_COLLATE      3
#define LC_CTYPE        4
#define LC_TIME         5

struct lconv {
    char* decimal_point;
};

struct lconv* localeconv(void);
char* setlocale(int, const char*);

#endif
