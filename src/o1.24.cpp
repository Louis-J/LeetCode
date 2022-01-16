#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode newHead(0);
        for(auto i = head; i != nullptr;) {
            auto iNext   = i->next;
            i->next      = newHead.next;
            newHead.next = i;
            i            = iNext;
        }
        return newHead.next;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        ListNode *head = ListNode::Create({1, 2, 3, 4, 5});
        cout << Solution().reverseList(head) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif