#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *nail = head;
        for(ListNode *next = nail->next, *after; next != nullptr; next = nail->next) {
            after = next->next;
            if(nail->val <= next->val) {
                nail = nail->next;
            } else if(head->val >= next->val) {
                next->next = head;
                head = next;
                nail->next = after;
            } else {
                ListNode *priv0 = head, *priv1 = head->next;
                while(priv1->val < next->val)
                    priv0 = priv1, priv1 = priv1->next;
                priv0->next = next;
                next->next = priv1;
                nail->next = after;
            }
        }
        return head;
    }
};

#ifdef LEETCODE
int main() {
    auto l1 = Solution().insertionSortList(ListNode::Create({4, 1, 2, 3}));
    while(l1 != nullptr) {
        cout << l1->val << ' ';
        l1 = l1->next;
    }
    cout << endl;

    auto l2 = Solution().insertionSortList(ListNode::Create({-1, 5, 3, 4, 0}));
    while(l2 != nullptr) {
        cout << l2->val << ' ';
        l2 = l2->next;
    }
    cout << endl;

    // auto l3 = ListNode::Create({1});
    // Solution().reorderList(l3);
    // cout << l3 << endl;

    return 0;
}
#endif