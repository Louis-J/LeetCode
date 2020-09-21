#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    ListNode* SortListImpl(ListNode* head, size_t n) {
        if(n <= 3) {
            if(n == 2) {
                if(head->next->val < head->val)
                    swap(head->next->val, head->val);
                head->next->next = nullptr;
            } else {
                if(head->next->val < head->val)
                    swap(head->next->val, head->val);
                if(head->next->next->val < head->next->val)
                    swap(head->next->next->val, head->next->val);
                if(head->next->val < head->val)
                    swap(head->next->val, head->val);
                head->next->next->next = nullptr;
            }
            return head;
        } else {
            ListNode *head2 = head;
            for(size_t i = 0; i < n/2; i++)
                head2 = head2->next;
            head = SortListImpl(head, n/2);
            head2 = SortListImpl(head2, n-n/2);

            ListNode newHead(0);
            ListNode *i = &newHead;
            while(head != nullptr && head2 != nullptr) {
                if(head->val <= head2->val) {
                    i->next = head;
                    i = head;
                    head = head->next;
                } else {
                    i->next = head2;
                    i = head2;
                    head2 = head2->next;
                }
            }
            if(head != nullptr) {
                i->next = head;
            } else {
                i->next = head2;
            }
            return newHead.next;
        }
        

    }
public:
    ListNode* sortList(ListNode* head) {
        size_t n = 0;
        for(ListNode *i = head; i != nullptr; i = i->next)
            n++;
        if(n <= 1)
            return head;
        else
            return SortListImpl(head, n);
    }
};

#ifdef LEETCODE
int main() {
    // auto l1 = Solution().sortList(ListNode::Create({4, 5}));
    // while(l1 != nullptr) {
    //     cout << l1->val << ' ';
    //     l1 = l1->next;
    // }
    // cout << endl;

    auto l1 = Solution().sortList(ListNode::Create({4, 1, 2, 3}));
    while(l1 != nullptr) {
        cout << l1->val << ' ';
        l1 = l1->next;
    }
    cout << endl;

    auto l2 = Solution().sortList(ListNode::Create({-1, 5, 3, 4, 0}));
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