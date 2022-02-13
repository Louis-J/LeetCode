#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* odd = new ListNode(), *i = odd;
        ListNode* even = new ListNode(), *j = even;
        while (head != nullptr && head->next != nullptr) {
            i->next = head;
            j->next = head->next;
            i = i->next;
            j = j->next;

            head = j->next;
        }
        if (head != nullptr) {
            i->next = head;
            i = i->next;
        }
        i->next = even->next;
        j->next = nullptr;
        return odd->next;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        ListNode* head = ListNode::Create({ 1,2,3,4,5 });
        cout << Solution().oddEvenList(head) << endl;
        //1->3->5->2->4->NULL
    }
    cout << "2:" << endl;
    {
        ListNode* head = ListNode::Create({ 2,1,3,5,6,4,7 });
        cout << Solution().oddEvenList(head) << endl;
        //2->3->6->7->1->5->4->NULL
    }
    cout << "3:" << endl;
    {
    }
    cout << "4:" << endl;
    {
    }
    cout << "5:" << endl;
    {
    }

    return 0;
}
#endif
