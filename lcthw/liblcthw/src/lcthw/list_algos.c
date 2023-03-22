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

// List_bubble_sort成功的时候返回0, 失败的时候返回1
int List_bubble_sort(List *words, List_compare cmp)
{
    check(words != NULL, "List_bubble_sort", "Invalid string words");
    bool flag = 1;
    ListNode *now; 
    while(flag == 1) {
        flag = 0;
        now = words->first;
        while(now -> next) {
            if(cmp(now->value, now->next->value) > 0) {
                List_swap(now, now->next);
                flag = 1;
            }
        }
    }
    return 0;
error:
    return 1;
}

List *List_merge_sort(List *words, List_compare cmp)
{
    return NULL;
}
