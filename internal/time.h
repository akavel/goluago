#ifndef __TIME_H
#define __TIME_H

//TODO:
#define CLOCKS_PER_SEC 1000

//TODO:
typedef unsigned long long int clock_t;
typedef unsigned long long int time_t;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

clock_t clock(void);
double difftime(time_t, time_t);
struct tm* gmtime(const time_t*);
struct tm* localtime(const time_t*);
time_t mktime(struct tm*);
size_t strftime(char*, size_t, const char*, const struct tm*);
time_t time(time_t*);

#endif
