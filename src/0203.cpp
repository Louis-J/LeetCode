#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(1) {
            if(head == nullptr)
                return nullptr;
            if(head->val != val)
                break;
            head = head->next;
        }
        for(ListNode *i = head; i->next != nullptr;) {
            if(i->next->val == val)
                i->next = i->next->next;
            else
                i = i->next;
        }
        return head;
    }
};

#ifdef LEETCODE
int main() {
    auto l1 = Solution().removeElements(ListNode::Create({1, 2, 6, 3, 4, 5, 6}), 6);
    while(l1 != nullptr) {
        cout << l1->val << ' ';
        l1 = l1->next;
    }
    cout << endl;
    return 0;
}
#endif