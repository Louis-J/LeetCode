#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode *fast = head, *slow = head;
        while(1) {
            if(fast == nullptr || fast->next == nullptr)
                return false;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
    }
};


#ifdef LEETCODE
int main() {
    auto l1 = ListNode::Create({3, 2, 0, -4});
    l1->next->next->next->next = l1->next;
    cout << (Solution().hasCycle(l1) ? "true" : "false") << endl;

    auto l2 = ListNode::Create({1, 2});
    l2->next->next = l2;
    cout << (Solution().hasCycle(l2) ? "true" : "false") << endl;
    
    auto l3 = ListNode::Create({1});
    cout << (Solution().hasCycle(l3) ? "true" : "false") << endl;

    return 0;
}
#endif