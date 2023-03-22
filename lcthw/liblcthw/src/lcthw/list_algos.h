#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include <lcthw/list.h>

typedef int (*List_compare)(const void* s1, const void* s2);

int List_bubble_sort(List *words, List_compare cmp);

List *List_merge_sort(List *words, List_compare cmp);

#endif
