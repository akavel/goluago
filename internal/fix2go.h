#ifndef __FIX2GO_H
#define __FIX2GO_H

//FIXME: MC: is line below OK?
typedef unsigned long int size_t;
typedef signed long int ptrdiff_t;
//typedef struct va_list *va_list;
//typedef struct FILE FILE;
//typedef struct time_t time_t;
typedef unsigned long int uintptr;

typedef struct lua_State lua_State;
typedef struct lua_longjmp lua_longjmp;

#define lua_lock(L) NOP()
#define lua_unlock(L) NOP()
#define UNUSED(x) NOP()
void NOP();
void runtime_panicstring(const char *);
void mylua_assert(int);
void mylua_argcheck(lua_State *, int, int, const char *);
uintptr ROUND(uintptr, uintptr);
void _luai_throw(lua_State *);
void _luai_try(lua_State *, void (*f)(lua_State *, void *), void *);
int mylua_pclose(lua_State *, struct FILE *);
struct FILE *mylua_popen(lua_State *, const char *, const char *);

//FIXME: MC: below is temporary I hope
#define HARDSTACKTESTS

//FIXME: MC: is below ok?
void *NULL;

extern double HUGE_VAL;

#endif

/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////

#ifndef __CTYPE
#define __CTYPE

#ifdef __cplusplus
extern "C" {
#endif

extern int isalnum(int);
extern int isalpha(int);
extern int iscntrl(int);
extern int isdigit(int);
extern int isgraph(int);
extern int islower(int);
extern int isprint(int);
extern int ispunct(int);
extern int isspace(int);
extern int isupper(int);
extern int isxdigit(int);
extern int tolower(int);
extern int toupper(int);

#ifdef __cplusplus
}
#endif
enum
{
  _ISupper = 01,	/* UPPERCASE.  */
  _ISlower = 02,	/* lowercase.  */
  _ISdigit = 04,	/* Numeric.  */
  _ISspace = 010,	/* Whitespace.  */
  _ISpunct = 020,	/* Punctuation.  */
  _IScntrl = 040,	/* Control character.  */
  _ISblank = 0100,	/* Blank (usually SPC and TAB).  */
  _ISxdigit = 0200,	/* Hexadecimal numeric.  */
};

extern unsigned char _ctype[];
#define	isalnum(c)	(_ctype[(unsigned char)(c)]&(_ISupper|_ISlower|_ISdigit))
#define	isalpha(c)	(_ctype[(unsigned char)(c)]&(_ISupper|_ISlower))
#define	iscntrl(c)	(_ctype[(unsigned char)(c)]&_IScntrl)
#define	isdigit(c)	(_ctype[(unsigned char)(c)]&_ISdigit)
#define	isgraph(c)	(_ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit))
#define	islower(c)	(_ctype[(unsigned char)(c)]&_ISlower)
#define	isprint(c)	(_ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit|_ISblank))
#define	ispunct(c)	(_ctype[(unsigned char)(c)]&_ISpunct)
#define	isspace(c)	(_ctype[(unsigned char)(c)]&_ISspace)
#define	isupper(c)	(_ctype[(unsigned char)(c)]&_ISupper)
#define	isxdigit(c)	(_ctype[(unsigned char)(c)]&_ISxdigit)

#ifdef _BSD_EXTENSION
#define	isascii(c) (((unsigned int)(c))<0x80)
#endif

#endif /* __CTYPE */
#ifndef __ERRNO
#define __ERRNO

extern int errno;

#define EDOM	1000
#define ERANGE	1001
#define EPLAN9	1002

#ifdef _POSIX_SOURCE

#define E2BIG	1
#define EACCES	2
#define	EAGAIN	3
#define EBADF	4
#define EBUSY	5
#define ECHILD	6
#define EDEADLK	7
#define EEXIST	8
#define EFAULT	9
#define EFBIG	10
#define EINTR	11
#define EINVAL	12
#define EIO	13
#define EISDIR	14
#define EMFILE	15
#define EMLINK	16
#define ENAMETOOLONG	17
#define ENFILE	18
#define ENODEV	19
#define ENOENT	20
#define ENOEXEC	21
#define ENOLCK	22
#define ENOMEM	23
#define ENOSPC	24
#define ENOSYS	25
#define ENOTDIR	26
#define ENOTEMPTY	27
#define ENOTTY	28
#define ENXIO	29
#define EPERM	30
#define EPIPE	31
#define EROFS	32
#define ESPIPE	33
#define ESRCH	34
#define EXDEV	35

/* bsd networking software */
#define ENOTSOCK	36
#define EPROTONOSUPPORT	37
#define EPROTOTYPE	37	/* two names for 37 */
#define ECONNREFUSED	38
#define EAFNOSUPPORT	39
#define ENOBUFS		40
#define EOPNOTSUPP	41
#define EADDRINUSE	42
#define EDESTADDRREQ	43
#define EMSGSIZE	44
#define ENOPROTOOPT	45
#define ESOCKTNOSUPPORT	46
#define EPFNOSUPPORT	47
#define EADDRNOTAVAIL	48
#define ENETDOWN	49
#define ENETUNREACH	50
#define ENETRESET	51
#define ECONNABORTED	52
#define EISCON	53
#define ENOTCONN	54
#define ESHUTDOWN	55
#define ETOOMANYREFS	56
#define ETIMEDOUT	57
#define EHOSTDOWN	58
#define EHOSTUNREACH	59
#define EGREG		60

/* These added in 1003.1b-1993 */
#define ECANCELED	61
#define EINPROGRESS	62

#endif /* _POSIX_SOURCE */

#endif /* __ERRNO */
#ifndef __FLOAT
#define __FLOAT
/* IEEE, default rounding */

#define FLT_ROUNDS	1
#define FLT_RADIX	2

#define FLT_DIG		6
#define FLT_EPSILON	1.19209290e-07
#define FLT_MANT_DIG	24
#define FLT_MAX		3.40282347e+38
#define FLT_MAX_10_EXP	38
#define FLT_MAX_EXP	128
#define FLT_MIN		1.17549435e-38
#define FLT_MIN_10_EXP	-37
#define FLT_MIN_EXP	-125

#define DBL_DIG		15
#define DBL_EPSILON	2.2204460492503131e-16
#define DBL_MANT_DIG	53
#define DBL_MAX		1.797693134862315708145e+308
#define DBL_MAX_10_EXP	308
#define DBL_MAX_EXP	1024
#define DBL_MIN		2.225073858507201383090233e-308
#define DBL_MIN_10_EXP	-307
#define DBL_MIN_EXP	-1021
#define LDBL_MANT_DIG	DBL_MANT_DIG
#define LDBL_EPSILON	DBL_EPSILON
#define LDBL_DIG	DBL_DIG
#define LDBL_MIN_EXP	DBL_MIN_EXP
#define LDBL_MIN	DBL_MIN
#define LDBL_MIN_10_EXP	DBL_MIN_10_EXP
#define LDBL_MAX_EXP	DBL_MAX_EXP
#define LDBL_MAX	DBL_MAX
#define LDBL_MAX_10_EXP	DBL_MAX_10_EXP

typedef 	union FPdbleword FPdbleword;
union FPdbleword
{
	double	x;
	struct {	/* little endian */
		long lo;
		long hi;
	};
};

#ifdef _RESEARCH_SOURCE
/* define stuff needed for floating conversion */
#define IEEE_8087	1
#define Sudden_Underflow 1
#endif
#ifdef _PLAN9_SOURCE
/* FCR */
#define	FPINEX	(1<<5)
#define	FPOVFL	(1<<3)
#define	FPUNFL	((1<<4)|(1<<1))
#define	FPZDIV	(1<<2)
#define	FPRNR	(0<<10)
#define	FPRZ	(3<<10)
#define	FPRPINF	(2<<10)
#define	FPRNINF	(1<<10)
#define	FPRMASK	(3<<10)
#define	FPPEXT	(3<<8)
#define	FPPSGL	(0<<8)
#define	FPPDBL	(2<<8)
#define	FPPMASK	(3<<8)
/* FSR */
#define	FPAINEX	FPINEX
#define	FPAOVFL	FPOVFL
#define	FPAUNFL	FPUNFL
#define	FPAZDIV	FPZDIV
#endif
#endif /* __FLOAT */
#ifndef __GOSTDC_STDARG_H
#define __GOSTDC_STDARG_H

// FIXME: tested only on amd64
// FIXME: tested and supported only for usecases present in Lua source code
// varargs macros based on:
// - vprintf() in $GOROOT/src/pkg/runtime/print.c
// - http://plan9.bell-labs.com/sources/plan9/amd64/include/u.h
// see also:
// - https://bitbucket.org/floren/inferno/src/0513433e212b/Plan9/386/include/u.h?at=default
// - gargs() in $GOROOT/src/cmd/6c/txt.c
// - functions using '...' in $GOROOT/.../*.c
typedef struct {
	uintptr base;
	uintptr off;
} va_list;
#define va_start(list,arg0) \
	(((list).off=0), ((list).base = (uintptr)(void*)((&(arg0))+1)))
#define va_end(list) \
	USED((list).base)
#define va_arg(list,type) \
	((sizeof(type)==4) ? \
		(((list).off = ROUND((list).off, 4)+4), (type*)((list).base+(list).off))[-1] : \
	(sizeof(type)==8) ? \
		(((list).off = ROUND((list).off, sizeof(uintptr))+8), (type*)((list).base+(list).off))[-1] : \
		(runtime_panicstring("va_arg variant unsupported"), (type*)(list).base)[0])

#endif /* __GOSTDC_STDARG_H */
#ifndef __MATH
#define __MATH

/* a HUGE_VAL appropriate for IEEE double-precision */
/* the correct value, 1.797693134862316e+308, causes a ken overflow */
//#define HUGE_VAL 1.79769313486231e+308

#ifdef __cplusplus
extern "C" {
#endif

extern double acos(double);
extern double asin(double);
extern double atan(double);
extern double atan2(double, double);
extern double cos(double);
extern double sin(double);
extern double tan(double);
extern double cosh(double);
extern double sinh(double);
extern double tanh(double);
extern double exp(double);
extern double frexp(double, int *);
extern double ldexp(double, int);
extern double log(double);
extern double log10(double);
extern double modf(double, double *);
extern double pow(double, double);
extern double sqrt(double);
extern double ceil(double);
extern double fabs(double);
extern double floor(double);
extern double fmod(double, double);
extern double NaN(void);
extern int isNaN(double);
extern double Inf(int);
extern int isInf(double, int);

#ifdef _RESEARCH_SOURCE
/* does >> treat left operand as unsigned ? */
#define Unsigned_Shifts 1
#define	M_E		2.7182818284590452354	/* e */
#define	M_LOG2E		1.4426950408889634074	/* log 2e */
#define	M_LOG10E	0.43429448190325182765	/* log 10e */
#define	M_LN2		0.69314718055994530942	/* log e2 */
#define	M_LN10		2.30258509299404568402	/* log e10 */
#define	M_PI		3.14159265358979323846	/* pi */
#define	M_PI_2		1.57079632679489661923	/* pi/2 */
#define	M_PI_4		0.78539816339744830962	/* pi/4 */
#define	M_1_PI		0.31830988618379067154	/* 1/pi */
#define	M_2_PI		0.63661977236758134308	/* 2/pi */
#define	M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#define	M_SQRT2		1.41421356237309504880	/* sqrt(2) */
#define	M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */

extern double hypot(double, double);
extern double erf(double);
extern double erfc(double);
extern double j0(double);
extern double y0(double);
extern double j1(double);
extern double y1(double);
extern double jn(int, double);
extern double yn(int, double);

#endif


#ifdef __cplusplus
}
#endif

#define isnan(x) isNaN(x)
#define isinf(x) isInf(x)

#endif /* __MATH */
#ifndef __STDDEF_H
#define __STDDEF_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#define offsetof(ty,mem) ((size_t) &(((ty *)0)->mem))

typedef long ptrdiff_t;
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif
#ifndef _WCHAR_T
#define _WCHAR_T
typedef unsigned short wchar_t;
#endif

#endif /* __STDDEF_H */
/*
	local limits
*/

#undef	ARG_MAX
#define	ARG_MAX		16384
#undef	CHILD_MAX
#define	CHILD_MAX	75
#undef	OPEN_MAX
#define	OPEN_MAX	96
#undef	LINK_MAX
#define	LINK_MAX	1
#undef	NAME_MAX
#define	NAME_MAX	27
#undef	PATH_MAX
#define	PATH_MAX	1023
#undef	NGROUPS_MAX
#define	NGROUPS_MAX	32
#undef	MAX_CANON
#define	MAX_CANON	1023
#undef	MAX_INPUT
#define	MAX_INPUT	1023
#undef	PIPE_BUF
#define	PIPE_BUF	8192

#define	_POSIX_SAVED_IDS		1
#define	_POSIX_CHOWN_RESTRICTED		1
#define	_POSIX_NO_TRUNC			1
#ifndef __TIMES_H
#define __TIMES_H

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long clock_t;
#endif

struct tms {
	clock_t	tms_utime;
	clock_t	tms_stime;
	clock_t	tms_cutime;
	clock_t	tms_cstime;
};

#ifdef __cplusplus
extern "C" {
#endif

clock_t times(struct tms *);

#ifdef __cplusplus
}
#endif

#endif
#ifndef __TYPES_H
#define __TYPES_H

typedef	unsigned short	ino_t;
typedef	unsigned short	dev_t;
typedef	long long		off_t;
typedef unsigned short	mode_t;
typedef short		uid_t;
typedef short		gid_t;
typedef short		nlink_t;
typedef int		pid_t;

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif
#ifndef _SSIZE_T
#define _SSIZE_T
typedef long ssize_t;
#endif

#ifndef _TIME_T
#define _TIME_T
typedef long time_t;
#endif

#ifdef _BSD_EXTENSION
#ifndef _CADDR_T
#define _CADDR_T
typedef char * caddr_t;
#endif
#ifndef _FD_SET_T
#define _FD_SET_T
/* also cf <select.h> */
typedef struct fd_set {
	long fds_bits[3];
} fd_set;
#define FD_SET(n,p)	((p)->fds_bits[(n)>>5] |= (1 << ((n) &0x1f)))
#define FD_CLR(n,p)	((p)->fds_bits[(n)>>5] &= ~(1 << ((n) &0x1f)))
#define FD_ISSET(n,p)	((p)->fds_bits[(n)>>5] & (1 << ((n) &0x1f)))
#define FD_ZERO(p)	((p)->fds_bits[0] =0, (p)->fds_bits[1] =0, (p)->fds_bits[2] =0)
#endif
#endif

#endif /* __TYPES_H */
#ifndef __WAIT_H
#define __WAIT_H

/* flag bits for third argument of waitpid */
#define WNOHANG		0x1
#define WUNTRACED	0x2

/* macros for examining status returned */
#ifndef WIFEXITED
#define WIFEXITED(s)	(((s) & 0xFF) == 0)
#define WEXITSTATUS(s)	((s>>8)&0xFF)
#define WIFSIGNALED(s)	(((s) & 0xFF) != 0)
#define WTERMSIG(s)	((s) & 0xFF)
#define WIFSTOPPED(s)	(0)
#define WSTOPSIG(s)	(0)
#endif

#ifdef __cplusplus
extern "C" {
#endif

pid_t wait(int *);
pid_t waitpid(pid_t, int *, int);
#ifdef _BSD_EXTENSION
struct rusage;
pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifndef __TIME_H
#define __TIME_H


#define CLOCKS_PER_SEC 1000

/* obsolsecent, but required */
#define CLK_TCK CLOCKS_PER_SEC

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long clock_t;
#endif
#ifndef _TIME_T
#define _TIME_T
typedef long time_t;
#endif

struct tm {
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};

#ifdef __cplusplus
extern "C" {
#endif

extern clock_t clock(void);
extern double difftime(time_t, time_t);
extern time_t mktime(struct tm *);
extern time_t time(time_t *);
extern char *asctime(const struct tm *);
extern char *ctime(const time_t *);
extern struct tm *gmtime(const time_t *);
extern struct tm *localtime(const time_t *);
extern size_t strftime(char *, size_t, const char *, const struct tm *);

#ifdef _REENTRANT_SOURCE
extern struct tm *gmtime_r(const time_t *, struct tm *);
extern struct tm *localtime_r(const time_t *, struct tm *);
extern char *ctime_r(const time_t *, char *);
#endif

#ifdef _POSIX_SOURCE
extern void tzset(void);
#endif

#ifdef __cplusplus
}
#endif

#ifdef _POSIX_SOURCE
extern char *tzname[2];
#endif

#endif /* __TIME_H */
#ifndef __STDLIB_H
#define __STDLIB_H


#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define MB_CUR_MAX 3
#define RAND_MAX 32767

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

#ifdef __cplusplus
extern "C" {
#endif

extern double atof(const char *);
extern int atoi(const char *);
extern long int atol(const char *);
extern long long atoll(const char *);
extern double strtod(const char *, char **);
extern long int strtol(const char *, char **, int);
extern unsigned long int strtoul(const char *, char **, int);
extern long long int strtoll(const char *, char **, int);
extern unsigned long long int strtoull(const char *, char **, int);
extern int rand(void);
extern void srand(unsigned int seed);
extern void *calloc(size_t, size_t);
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
extern void abort(void);
extern int atexit(void (*func)(void));
extern void exit(int);
extern char *getenv(const char *);
extern int system(const char *);
extern void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern int abs(int);
extern div_t div(int, int);
extern long int labs(long int);
extern ldiv_t ldiv(long int, long int);
extern int mblen(const char *, size_t);
extern int mbtowc(wchar_t *, const char *, size_t);
extern int wctomb(char *, wchar_t);
extern size_t mbstowcs(wchar_t *, const char *, size_t);
extern size_t wcstombs(char *, const wchar_t *, size_t);

#ifdef __cplusplus
}
#endif

#endif /* __STDLIB_H */
#ifndef __LOCALE
#define __LOCALE


#define LC_ALL		0
#define LC_COLLATE	1
#define LC_CTYPE	2
#define LC_MONETARY	3
#define LC_NUMERIC	4
#define LC_TIME		5

struct lconv {
	char *decimal_point;
	char *thousands_sep;
	char *grouping;
	char *int_curr_symbol;
	char *currency_symbol;
	char *mon_decimal_point;
	char *mon_thousands_sep;
	char *mon_grouping;
	char *positive_sign;
	char *negative_sign;
	char int_frac_digits;
	char frac_digits;
	char p_cs_precedes;
	char p_sep_by_space;
	char n_cs_precedes;
	char n_sep_by_space;
	char p_sign_posn;
	char n_sign_posn;
};

#ifdef __cplusplus
extern "C" {
#endif

extern char *setlocale(int, const char *);
extern struct lconv *localeconv(void);

#ifdef __cplusplus
}
#endif

#endif /* __LOCALE */
#ifndef __LIMITS
#define __LIMITS
/* 8 bit chars (signed), 16 bit shorts, 32 bit ints/longs */

#define CHAR_BIT	8
#define MB_LEN_MAX	3

#define UCHAR_MAX	0xff
#define USHRT_MAX	0xffff
#define UINT_MAX	0xffffffffU
#define ULONG_MAX	0xffffffffUL

#define CHAR_MAX	SCHAR_MAX
#define SCHAR_MAX	0x7f
#define SHRT_MAX	0x7fff
#define INT_MAX		0x7fffffff
#define LONG_MAX	0x7fffffffL

#define CHAR_MIN	SCHAR_MIN
#define SCHAR_MIN	(-SCHAR_MAX-1)
#define SHRT_MIN	(-SHRT_MAX-1)
#define INT_MIN		(-INT_MAX-1)
#define LONG_MIN	(-LONG_MAX-1)

#ifdef _POSIX_SOURCE

#define _POSIX_AIO_LISTIO_MAX	2
#define _POSIX_AIO_MAX			1
#define _POSIX_ARG_MAX			4096
#define _POSIX_CHILD_MAX		6
#define	_POSIX_CLOCKRES_MIN		20000000
#define	_POSIX_DELAYTIMER_MAX	32
#define _POSIX_LINK_MAX			8
#define _POSIX_MAX_CANON		255
#define _POSIX_MAX_INPUT		255
#define _POSIX_MQ_OPEN_MAX		8
#define	_POSIX_MQ_PRIO_MAX		32
#define _POSIX_NAME_MAX			14
#define _POSIX_NGROUPS_MAX		0
#define _POSIX_OPEN_MAX			16
#define _POSIX_PATH_MAX			255
#define _POSIX_PIPE_BUF			512
#define	_POSIX_RTSIG_MAX		8
#define	_POSIX_SEM_NSEMS_MAX	256
#define	_POSIX_SEM_VALUE_MAX	32767
#define	_POSIX_SIGQUEUE_MAX		32
#define _POSIX_SSIZE_MAX		32767
#define _POSIX_STREAM_MAX		8
#define	_POSIX_TIMER_MAX		32
#define _POSIX_TZNAME_MAX		3

/* pedagogy: those that standard allows omitting are commented out */
/*#define AIO_LIST_MAX _POSIX_AIO_LIST_MAX */
/*#define AIO_MAX _POSIX_AIO_MAX */
/*#define AIO_PRIO_DELTA_MAX 0 */
/*#define ARG_MAX _POSIX_ARG_MAX */
/*#define CHILD_MAX _POSIX_CHILD_MAX */
/*#define DELAYTIMER_MAX _POSIX_DELAYTIMER_MAX */
/*#define LINK_MAX _POSIX_LINK_MAX */
/*#define MAX_CANON _POSIX_MAX_CANON */
/*#define MAX_INPUT _POSIX_MAX_INPUT */
/*#define MQ_OPEN_MAX _POSIX_MQ_OPEN_MAX */
/*#define MQ_PRIO_MAX _POSIX_MQ_PRIO_MAX */
/*#define NAME_MAX _POSIX_NAME_MAX */
#define NGROUPS_MAX 10
/*#define OPEN_MAX _POSIX_OPEN_MAX */
/*#define PAGESIZE 1 */
/*#define PATH_MAX _POSIX_PATH_MAX */
/*#define PIPE_BUF _POSIX_PIPE_BUF */
/*#define RTSIG_MAX _POSIX_RTSIG_MAX */
/*#define SEM_NSEMS_MAX _POSIX_SEM_NSEMS_MAX */
/*#define SEM_VALUE_MAX _POSIX_SEM_VALUE_MAX */
/*#define SIGQUEUE_MAX _POSIX_SIGQUEUE_MAX */
#define SSIZE_MAX LONG_MAX
/*#define STREAM_MAX _POSIX_STREAM_MAX */
/*#define TIMER_MAX _POSIX_TIMER_MAX */
#define TZNAME_MAX _POSIX_TZNAME_MAX

#ifdef _LIMITS_EXTENSION
/* some things are just too big for pedagogy (X!) */
#endif
#endif /* _POSIX_SOURCE */

#endif /* __LIMITS */
#ifndef __STAT_H
#define __STAT_H

#ifndef __TYPES_H
#endif


/*
 * stat structure, used by stat(2) and fstat(2)
 */
struct	stat {
	dev_t	st_dev;
	ino_t	st_ino;
	mode_t 	st_mode;
	nlink_t	st_nlink;
	uid_t 	st_uid;
	gid_t 	st_gid;
	off_t	st_size;
	time_t	st_atime;
	time_t	st_mtime;
	time_t	st_ctime;
};

#define	S__MASK		     0170000
#ifdef _RESEARCH_SOURCE
#define S_ISLNK(m)	(((m)&S__MASK) == 0120000)
#endif
#define S_ISREG(m)	(((m)&S__MASK) == 0100000)
#define S_ISDIR(m)	(((m)&S__MASK) == 0040000)
#define S_ISCHR(m)	(((m)&S__MASK) == 0020000)
#define S_ISBLK(m)	(((m)&S__MASK) == 0060000)
#define S_ISFIFO(m)	(((m)&S__MASK) == 0010000)

#define	S_ISUID	04000		/* set user id on execution */
#define	S_ISGID	02000		/* set group id on execution */
#define	S_IRWXU	00700		/* read, write, execute: owner */
#define	S_IRUSR	00400		/* read permission: owner */
#define	S_IWUSR	00200		/* write permission: owner */
#define	S_IXUSR	00100		/* execute permission: owner */
#define	S_IRWXG	00070		/* read, write, execute: group */
#define	S_IRGRP	00040		/* read permission: group */
#define	S_IWGRP	00020		/* write permission: group */
#define	S_IXGRP	00010		/* execute permission: group */
#define	S_IRWXO	00007		/* read, write, execute: other */
#define	S_IROTH	00004		/* read permission: other */
#define	S_IWOTH	00002		/* write permission: other */
#define	S_IXOTH	00001		/* execute permission: other */

#ifdef _BSD_EXTENSION
#define S_IFMT S__MASK
#define S_IFDIR 0040000
#define S_IFCHR 0020000
#define S_IFBLK 0060000
#define S_IFREG 0100000
#define S_IFIFO 0010000
#define S_IFLNK 0120000
#define S_IFSOCK S_IFIFO
#endif

#ifdef __cplusplus
extern "C" {
#endif

//extern mode_t umask(mode_t);
//extern int mkdir(const char *, mode_t);
//extern int mkfifo(const char *, mode_t);
//extern int stat(const char *, struct stat *);
//extern int fstat(int, struct stat *);
//extern int chmod(const char *, mode_t);

#ifdef _BSD_EXTENSION
extern int	lstat(char *, struct stat *);
extern int	symlink(char *, char *);
extern int	readlink(char *, char*, int);
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifndef	_STDIO_H_
#define	_STDIO_H_

/*
 * pANS stdio.h
 */
/*
 * According to X3J11, there is only one i/o buffer
 * and it must not be occupied by both input and output data.
 *	If rp<wp, we must have state==RD and
 *	if wp<rp, we must have state==WR, so that getc and putc work correctly.
 *	On open, rp, wp and buf are set to 0, so first getc or putc will call _IO_getc
 *	or _IO_putc, which will allocate the buffer.
 *	If setvbuf(., ., _IONBF, .) is called, bufl is set to 0 and
 *	buf, rp and wp are pointed at unbuf.
 *	If setvbuf(., ., _IOLBF, .) is called, _IO_putc leaves wp and rp pointed at the
 *	end of the buffer so that it can be called on each putc to check whether it's got
 *	a newline.  This nonsense is in order to avoid impacting performance of the other
 *	buffering modes more than necessary -- putting the test in putc adds many
 *	instructions that are wasted in non-_IOLBF mode:
 *	#define putc(c, f)	(_IO_ctmp=(c),\
 *				(f)->wp>=(f)->rp || (f)->flags&LINEBUF && _IO_ctmp=='\n'\
 *					?_IO_putc(_IO_ctmp, f)\
 *					:*(f)->wp++=_IO_ctmp)
 *				
 */
typedef struct FILE{
	int fd;		/* UNIX file pointer */
	char flags;	/* bits for must free buffer on close, line-buffered */
	char state;	/* last operation was read, write, position, error, eof */
	char *buf;	/* pointer to i/o buffer */
	char *rp;	/* read pointer (or write end-of-buffer) */
	char *wp;	/* write pointer (or read end-of-buffer) */
	char *lp;	/* actual write pointer used when line-buffering */
	size_t bufl;	/* actual length of buffer */
	char unbuf[1];	/* tiny buffer for unbuffered io (used for ungetc?) */
}FILE;
typedef long long fpos_t;
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
/*
 * Third arg of setvbuf
 */
#define	_IOFBF	1			/* block-buffered */
#define	_IOLBF	2			/* line-buffered */
#define	_IONBF	3			/* unbuffered */
#define	BUFSIZ	4096			/* size of setbuf buffer */
#define	EOF	(-1)			/* returned on end of file */
#define	FOPEN_MAX	90		/* max files open */
#define	FILENAME_MAX	BUFSIZ		/* silly filename length */
#define	L_tmpnam	20		/* sizeof "/tmp/abcdefghij9999 */
#define	L_cuserid	32		/* maximum size user name */
#define	L_ctermid	32		/* size of name of controlling tty */
#define	SEEK_CUR	1
#define	SEEK_END	2
#define	SEEK_SET	0
#define	TMP_MAX		64		/* very hard to set correctly */
#define	stderr	(&_IO_stream[2])
#define	stdin	(&_IO_stream[0])
#define	stdout	(&_IO_stream[1])
#define	_IO_CHMASK	0377		/* mask for 8 bit characters */

#ifdef __cplusplus
extern "C" {
#endif

extern int remove(const char *);
extern int rename(const char *, const char *);
extern FILE *tmpfile(void);
extern char *tmpnam(char *);
extern int fclose(FILE *);
extern int fflush(FILE *);
extern FILE *fopen(const char *, const char *);
extern FILE *freopen(const char *, const char *, FILE *);
extern void setbuf(FILE *, char *);
extern int setvbuf(FILE *, char *, int, size_t);
extern int fprintf(FILE *, const char *, ...);
extern int fscanf(FILE *, const char *, ...);
extern int printf(const char *, ...);
extern int scanf(const char *, ...);
extern int sprintf(char *, const char *, ...);
extern int snprintf(char *, size_t, const char *, ...);
extern int sscanf(const char *, const char *, ...);
extern int vfprintf(FILE *, const char *, va_list);
extern int vprintf(const char *, va_list);
extern int vsprintf(char *, const char *, va_list);
extern int vsnprintf(char *, size_t, const char *, va_list);
extern int vfscanf(FILE *, const char *, va_list);
extern int fgetc(FILE *);
extern char *fgets(char *, int, FILE *);
extern int fputc(int, FILE *);
extern int fputs(const char *, FILE *);
extern int getc(FILE *);
#define	getc(f)	((f)->rp>=(f)->wp?_IO_getc(f):*(f)->rp++&_IO_CHMASK)
extern int _IO_getc(FILE *f);
extern int getchar(void);
#define	getchar()	getc(stdin)
extern char *gets(char *);
extern int putc(int, FILE *);
#define	putc(c, f) ((f)->wp>=(f)->rp?_IO_putc(c, f):(*(f)->wp++=c)&_IO_CHMASK)
extern int _IO_putc(int, FILE *);
extern int putchar(int);
#define	putchar(c)	putc(c, stdout)
extern int puts(const char *);
extern int ungetc(int, FILE *);
extern size_t fread(void *, size_t, size_t, FILE *);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern int fgetpos(FILE *, fpos_t *);
extern int fseek(FILE *, long, int);
extern int fseeko(FILE *, off_t, int);
extern int fsetpos(FILE *, const fpos_t *);
extern long ftell(FILE *);
extern off_t ftello(FILE *);
extern void rewind(FILE *);
extern void clearerr(FILE *);
extern int feof(FILE *);
extern int ferror(FILE *);
extern void perror(const char *);
extern FILE _IO_stream[FOPEN_MAX];

#ifdef _POSIX_SOURCE
extern int fileno(FILE *);
extern FILE* fdopen(int, const char*);
extern char *ctermid(char *);
#endif

#ifdef _REENTRANT_SOURCE
extern char *tmpnam_r(char *);
extern char *ctermid_r(char *);
#endif

#ifdef _BSD_EXTENSION
extern FILE *popen(char *, char *);
extern int	pclose(FILE *);
#endif

#ifdef __cplusplus
}
#endif

#endif
#ifndef __STRING_H_
#define __STRING_H_


#ifdef __cplusplus
extern "C" {
#endif

extern void *memcpy(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern char *strncat(char *, const char *, size_t);
extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern size_t strxfrm(char *, const char *, size_t);
extern void *memchr(const void *, int, size_t);
extern char *strchr(const char *, int);
extern size_t strcspn(const char *, const char *);
extern char *strpbrk(const char *, const char *);
extern char *strrchr(const char *, int);
extern size_t strspn(const char *, const char *);
extern char *strstr(const char *, const char *);
extern char *strtok(char *, const char *);
extern void *memset(void *, int, size_t);
extern char *strerror(int);
extern size_t strlen(const char *);

#ifdef _REENTRANT_SOURCE
extern char *strerror_r(int, const char *, int);
extern char *strtok_r(char *, const char *, char **);
#endif

#ifdef _BSD_EXTENSION
#endif

#ifdef __cplusplus
}
#endif

#endif
