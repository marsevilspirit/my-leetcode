#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) 
{
    struct ListNode temp;
    temp.next = head;
    struct ListNode * current = &temp;
    
    while (current->next != NULL && current->next->next != NULL)
    {
        struct ListNode * first = current->next;
        struct ListNode * second = first->next;
        current->next = second;
        first->next = second->next;
        second->next = first;
        current = first;
    }
    
    return temp.next;
}
