#ifndef lcthw_Stack_h
#define lcthw_Stack_h

#include <lcthw/list.h>

// 我的评价是，这个写法也太丑了，这样写倒是方便，但是这也太占空间了

#define Stack List

#define Stack_create List_create
#define Stack_destroy List_destroy
#define Stack_push List_unshift
#define Stack_peek List_first
#define Stack_count List_count
#define Stack_pop List_shift
#define STACK_FOREACH(S, V) LIST_FOREACH(S, first, next, V)

#endif
