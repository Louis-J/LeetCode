#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        int len = 0;
        for(auto node = head; node != nullptr; node = node->next) len++;
        auto node = head;
        for(int goLen = len - k; goLen != 0; goLen--) node = node->next;
        return node;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        ListNode *head = ListNode::Create({4, 5, 1, 9});
        int       k    = 2;
        cout << Solution().getKthFromEnd(head, k) << endl;
    }
    cout << " 2:" << endl;
    {
        ListNode *head = ListNode::Create({4, 5, 1, 9});
        int       k    = 1;
        cout << Solution().getKthFromEnd(head, k) << endl;
    }
    return 0;
}
#endif