#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL)  
        return NULL;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    head = dummy;
    struct ListNode* current = head->next;
    struct ListNode* previous = head;

    while (current != NULL)
    {
        if(current->val < x) 
        {
            previous->next = current->next;
            current->next = head->next;
            head->next = current;
            head = head->next;
        }

        previous = current;
        current = current->next;
    }

    return dummy->next;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // 创建链表: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 4;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 2;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 2;
    head->next->next->next->next->next->next = NULL;

    // 打印原始链表
    printf("Original List: ");
    printList(head);

    // 对链表进行分割，小于3的节点移到前部分
    head = partition(head, 3);

    // 打印分割后的链表
    printf("Partitioned List: ");
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}
