#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for(auto node = headA; node != nullptr; node = node->next) lenA++;
        for(auto node = headB; node != nullptr; node = node->next) lenB++;

        if(lenA != lenB) {
            if(lenA > lenB)
                for(int lenDiff = lenA - lenB; lenDiff != 0; lenDiff--) headA = headA->next;
            else
                for(int lenDiff = lenB - lenA; lenDiff != 0; lenDiff--) headB = headB->next;
        }
        while(headA != nullptr) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        ListNode *l1 = ListNode::Create({1, 2, 4});
        ListNode *l2 = ListNode::Create({1, 3, 4});
        cout << Solution().getIntersectionNode(l1, l2) << endl;
    }
    cout << " 2:" << endl;
    {}
    cout << " 3:" << endl;
    {}
    return 0;
}
#endif