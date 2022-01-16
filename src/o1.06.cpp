#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> reversePrint0(ListNode *head) {
        vector<int> vec;
        for(; head != nullptr; head = head->next) vec.emplace_back(head->val);
        return vector<int>(vec.rbegin(), vec.rend());
    }
    vector<int> reversePrint(ListNode *head) {
        vector<int> ret;
        for(; head != nullptr; head = head->next) ret.emplace_back(head->val);

        int len1 = ret.size() - 1;
        int len2 = ret.size() / 2;
        for(int i = 0; i < len2; i++) swap(ret[i], ret[len1 - i]);
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        ListNode *head = ListNode::Create({1, 3, 2});
        cout << Solution().reversePrint(head) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif