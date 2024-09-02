#include <vector>
#include <iostream>
#include <time.h>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// 将链表转换为 std::vector<int>，便于验证输出结果
std::vector<int> listToVector(ListNode* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// 打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKListsHelper(std::vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeKListsHelper(lists, left, mid);
        ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    Solution sol;

    // 测试用例 1: 输入 [[1,4,5],[1,3,4],[2,6]]
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));
    std::vector<ListNode*> lists1 = {l1, l2, l3};
    ListNode* result1 = sol.mergeKLists(lists1);
    std::vector<int> vec1 = listToVector(result1);
    printList(result1); // 期望输出: 1 1 2 3 4 4 5 6 

    clock_gettime(CLOCK_MONOTONIC, &end);

    std::cout << "Time: " << (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec) << "ns" << std::endl;

    return 0;
}
