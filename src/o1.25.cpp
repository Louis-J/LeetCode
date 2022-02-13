#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;

        ListNode  head(0);
        ListNode *tail = &head;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                tail->next = l1;
                tail       = l1;
                l1         = l1->next;
            } else {
                tail->next = l2;
                tail       = l2;
                l2         = l2->next;
            }
        }
        if(l1 == nullptr)
            tail->next = l2;
        else
            tail->next = l1;

        return head.next;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        ListNode *l1 = ListNode::Create({1, 2, 4});
        ListNode *l2 = ListNode::Create({1, 3, 4});
        cout << Solution().mergeTwoLists(l1, l2) << endl;
    }
    cout << " 2:" << endl;
    {}
    cout << " 3:" << endl;
    {}
    return 0;
}
#endif