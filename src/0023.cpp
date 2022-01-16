#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    ListNode* mergeKLists0(vector<ListNode*>& lists) {
        class listcompare {
            public:
            bool operator () (ListNode* a, ListNode* b){
                return a->val > b->val;
            }  
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, listcompare> pq;
        for (auto list: lists)
            if (list)
                pq.push(list);
        if (pq.empty())
            return nullptr;
        
        ListNode *head = pq.top(), *curr = head;
        pq.pop();
        if (curr->next)
            pq.push(curr->next);
        
        while (!pq.empty()){
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next)
                pq.push(curr->next);
        }
        curr->next = NULL;
        return head;
    }
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        struct listcompare {
            bool operator () (const ListNode* a, const ListNode* b) const {
                return a->val < b->val;
            }  
        };
        std::multiset<ListNode*, listcompare> ms;
        for (auto list: lists)
            if (list)
                ms.emplace(list);
        if (ms.empty())
            return nullptr;
        
        ListNode *head = *ms.begin(), *curr = head;
        ms.erase(ms.begin());
        if (curr->next)
            ms.emplace(curr->next);
        
        while (!ms.empty()){
            curr->next = *ms.begin();
            ms.erase(ms.begin());
            curr = curr->next;
            if (curr->next)
                ms.emplace(curr->next);
        }
        curr->next = nullptr;
        return head;
    }
};

#ifdef LEETCODE
int main() {
    vector<ListNode*> lists = {
        ListNode::Create({1, 4, 5}),
        ListNode::Create({1, 3, 4}),
        ListNode::Create({2, 6}),
    };
    auto r = Solution().mergeKLists(lists);
    while(r != nullptr) {
        cout << r->val << ' ';
        r = r->next;
    }
    return 0;
}
#endif