#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        vector<ListNode*> ls;
        for(; head != nullptr; head = head->next)
            ls.emplace_back(head);

        const size_t n0 = ls.size()/2;
        const size_t n1 = ls.size();
        const size_t n2 = ls.size()-1;

        for(size_t i = 0; i < n0; i++)
            ls[i]->next = ls[n2-i];
        ls[n0]->next = nullptr;
        for(size_t i = n0+1; i < n1; i++)
            ls[i]->next = ls[n1-i];
    }
};


#ifdef LEETCODE
int main() {
    auto l1 = ListNode::Create({1, 2, 3, 4});
    Solution().reorderList(l1);
    while(l1 != nullptr) {
        cout << l1->val << ' ';
        l1 = l1->next;
    }
    cout << endl;

    auto l2 = ListNode::Create({1, 2, 3, 4, 5});
    Solution().reorderList(l2);
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