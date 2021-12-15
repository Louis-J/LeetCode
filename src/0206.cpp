#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nail = nullptr;
        ListNode *tmpnext;//若放循环内则评测慢许多
        while(head != nullptr) {
            tmpnext = head->next;
            head->next = nail;
            nail = head;
            head = tmpnext;
        }
        return nail;
    }
};

#ifdef LEETCODE
int main() {
    auto l1 = Solution().reverseList(ListNode::Create({1, 2, 3, 4, 5}));
    while(l1 != nullptr) {
        cout << l1->val << ' ';
        l1 = l1->next;
    }
    cout << endl;
    return 0;
}
#endif