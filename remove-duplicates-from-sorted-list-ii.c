#include <math.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;  

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* current = dummy;
    while (current->next && current->next->next)
    {
        if(current->next->val == current->next->next->val)
        {
            int x = current->next->val;
            while (current->next && current->next->val == x)
            {
                current->next = current->next->next; 
            }
        }
        else
        {
            current = current->next; 
        }
    }

    return dummy->next;
}        
