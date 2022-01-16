#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *i = &head;
        for(; l1 != nullptr && l2 != nullptr;) {
            if(l1->val <= l2->val) {
                i->next = l1;
                i = l1;
                l1 = l1->next;
            } else {
                i->next = l2;
                i = l2;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr) {
            i->next = l1;
        } else {
            i->next = l2;
        }
        return head.next;
    }
};

#ifdef LEETCODE
int main() {
    auto r = Solution().mergeTwoLists(ListNode::Create({1, 2, 4}), ListNode::Create({1, 3, 4}));
    while(r != nullptr) {
        cout << r->val << ' ';
        r = r->next;
    }
    return 0;
}
#endif