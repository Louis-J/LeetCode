#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    void deleteNode0(ListNode* node) {
        while(1) {
            node->val = node->next->val;
            if(node->next->next == nullptr) {
                node->next = nullptr;
                return;
            } else {
                node = node->next;
            }
        }
    }
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

#ifdef LEETCODE
int main() {
    auto l1 = ListNode::Create({4, 5, 1, 9});
    Solution().deleteNode(l1->next);
    while(l1 != nullptr) {
        cout << l1->val << ' ';
        l1 = l1->next;
    }
    cout << endl;
    return 0;
}
#endif