#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if(head->val == val) return head->next;
        auto node = head;
        for(; node->next->val != val; node = node->next) {
        }
        node->next = node->next->next;
        return head;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        ListNode *head = ListNode::Create({4, 5, 1, 9});
        int       val  = 5;
        cout << Solution().deleteNode(head, val) << endl;
    }
    cout << " 2:" << endl;
    {
        ListNode *head = ListNode::Create({4, 5, 1, 9});
        int       val  = 1;
        cout << Solution().deleteNode(head, val) << endl;
    }
    return 0;
}
#endif