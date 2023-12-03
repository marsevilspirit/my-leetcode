#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct ListNode * tail = head;
    int len;
    for(len = 1; tail->next != NULL; len++)    
        tail = tail->next; 

    int fin_k = k % len;
    if(fin_k == 0) 
        return head; 

    struct ListNode * current = head;
    struct ListNode * previous = NULL;
    for(int i = 0; i < len - fin_k; i++)
    {
        previous = current;
        current = current->next;
    }   
    tail->next = head;
    head = current;
    previous->next = NULL;
     
    return head;
}
