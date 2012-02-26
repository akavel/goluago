#ifndef __ASSERT_H
#define __ASSERT_H

#define assert(x) _assert_impl(x)

void assert_impl(int expression);

#endif
