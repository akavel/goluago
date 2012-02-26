#ifndef __SETJMP_H
#define __SETJMP_H

//TODO
typedef int jmp_buf;
void longjmp(jmp_buf, int);
int setjmp(jmp_buf);

#endif
