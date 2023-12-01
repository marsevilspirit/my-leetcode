/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct ListNode *mergedList;

    if (list1->val <= list2->val) {
        mergedList = list1;
        mergedList->next = mergeTwoLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeTwoLists(list1, list2->next);
    }

    return mergedList;
}
