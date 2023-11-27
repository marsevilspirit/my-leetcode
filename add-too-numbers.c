#include <stdlib.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * current = list;

    int t = 0;

    while (l1 || l2 || t)
    {
        if(l1) 
        {
            t += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            t += l2->val;
            l2 = l2->next;
        }
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current->next->val = t % 10;
        current->next->next = NULL;

        current = current->next;

        t /= 10;
    }
    return list->next;
} 
