#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static bool ST(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr)
            return p==q;
        if(p->val != q->val)
            return false;
        return ST(p->left, q->left) && ST(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return ST(p, q);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *p = TreeNode::CreateLev({1, 2, 3});
        TreeNode *q = TreeNode::CreateLev({1, 2, 3});
        cout << Solution().isSameTree(p, q) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode *p = TreeNode::CreateLev({1, 2});
        TreeNode *q = TreeNode::CreateLev({1, nullopt, 2});
        cout << Solution().isSameTree(p, q) << endl;
    }
    cout << " 3:" << endl;
    {
        TreeNode *p = TreeNode::CreateLev({1, 2, 1});
        TreeNode *q = TreeNode::CreateLev({1, 1, 2});
        cout << Solution().isSameTree(p, q) << endl;
    }
    return 0;
}
#endif