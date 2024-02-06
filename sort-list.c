int cmp(const void *a, const void *b) {
    return (*(int *)a -*(int *)b);
}

struct ListNode* sortList(struct ListNode* head){
    int nums[50000];
    if (!head) {
        return head;
    }
    struct ListNode *List = head;
    int i = 0;
    while (List) {
        nums[i ++] = List -> val;
        List = List -> next;
    }
    qsort(nums,i,sizeof(int),cmp);
    i = 0;
    List = head;
    while (List) {
        List -> val = nums[i ++];
        List = List -> next;
    }
    return head;
}
