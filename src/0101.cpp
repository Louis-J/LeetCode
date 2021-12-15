#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static inline bool IS(TreeNode *l, TreeNode *r) {
        if(l == nullptr || r == nullptr)
            return l == r;
        else if(l->val != r->val)
            return false;
        else
            return IS(l->left, r->right) && IS(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        else
            return IS(root->left, root->right);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().isSymmetric(TreeNode::CreateLev({1, 2, 2, 3, 4, 4, 3})) << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().isSymmetric(TreeNode::CreateLev({1, 2, 2, nullopt, 3, nullopt, 3})) << endl;
    }
    return 0;
}
#endif