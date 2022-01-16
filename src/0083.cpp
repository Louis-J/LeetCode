#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        for(ListNode *i = head; i->next != nullptr;)
            if(i->val == i->next->val)
                i->next = i->next->next;
            else
                i = i->next;
        return head;
    }
};

#ifdef LEETCODE
int main() {
    {
        auto r = Solution().deleteDuplicates(ListNode::Create({1, 1, 2}));
        while(r != nullptr) {
            cout << r->val << ' ';
            r = r->next;
        }
        cout << '\n';
    }
    {
        auto r = Solution().deleteDuplicates(ListNode::Create({1, 1, 2, 3, 3}));
        while(r != nullptr) {
            cout << r->val << ' ';
            r = r->next;
        }
        cout << '\n';
    }
    return 0;
}
#endif