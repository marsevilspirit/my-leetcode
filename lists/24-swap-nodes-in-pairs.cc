struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* left = nullptr;
        ListNode* right = nullptr;

        while (pre->next != nullptr && pre->next->next != nullptr) {
            left = pre->next;
            right = left->next;

            left->next = right->next; 
            right->next = left;
            pre->next = right;

            pre = left; 
        }
        ListNode* newHead = dummyHead->next; 
        return newHead;
    }
};

