#include <lcthw/list.h>
#include <lcthw/dbg.h>
#include <lcthw/list_algos.h>
#include <stdbool.h>

// 用于实现两个ListNode之间值的交换
int List_swap(ListNode *a, ListNode *b)
{
    void *temp;
    temp = a->value;
    a->value = b->value;
    b->value = temp;

    return 0;
}

// List_bubble_sort成功的时候返回0
int List_bubble_sort(List *words, List_compare cmp)
{
    if(List_count(words) <= 1) {
        return 0;
    }
    bool flag = 1;
    while(flag == 1) {
        flag = 0;
        LIST_FOREACH(words, first, next, now) { 
            if(now->next != NULL && cmp(now->value, now->next->value) > 0) {
                List_swap(now, now->next);
                flag = 1;
            }
        }
    }
    return 0;
}

// 这个能实现的功能是，传入s1, s2字符串,返回排好序的s1和s2排好序的串
List *List_merge(List *s1, List *s2, List_compare cmp)
{
    // 此时假设s1与s2都已经有序
    List *result = List_create();
    void *value = NULL;
    while(s1->count > 0 && s2->count > 0) {
        if(cmp(s1->first->value, s2->first->value) > 0) {
            value = List_shift(s2);
            List_push(result, value);
        } else {
            value = List_shift(s1);
            List_push(result, value);
        }
    }
    if(s1->count == 0) {
        while(s2->count != 0) {
            value = List_shift(s2);
            List_push(result, value);
        }
    } else {
        while(s1->count != 0) {
            value = List_shift(s1);
            List_push(result, value);
        }
    }
    return result;
}


List *List_merge_sort(List *words, List_compare cmp)
{
    if(List_count(words) <= 1) {
        return words;
    }
    List *s1 = List_create();
    List *s2 = List_create();
    int count = List_count(words);
    void *val;
    for(int i = 0; i < count >> 1; ++i) {
        val = List_shift(words);
        List_push(s1, val);
    }
    for(int i = count >> 1; i < count; ++i) {
        val = List_shift(words);
        List_push(s2,val);
    }
    List *list_sorted_s1 = List_merge_sort(s1, cmp);
    List *list_sorted_s2 = List_merge_sort(s2, cmp);
    
    if(list_sorted_s1 != s1) {
        List_destroy(s1);
    }
    if(list_sorted_s2 != s2) {
        List_destroy(s2);
    }
    return List_merge(list_sorted_s1, list_sorted_s2, cmp);
}
