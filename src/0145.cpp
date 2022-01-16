#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>{};
        vector<TreeNode*> stk{root};
        vector<int> rrlt;
        while(!stk.empty()) {
            TreeNode *last = stk[stk.size()-1];
            stk.pop_back();
            rrlt.emplace_back(last->val);

            if(last->left != nullptr)
                stk.emplace_back(last->left);
            if(last->right != nullptr)
                stk.emplace_back(last->right);
        }
        return vector<int>(rrlt.rbegin(), rrlt.rend());
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1, nullopt, 2, 3});
        cout << Solution().postorderTraversal(root) << endl;
    }
    // cout << "2:" << endl;
    // {
    //     TreeNode *root = TreeNode::CreateLev(1, nullopt, 2, 3);
    //     cout << Solution().postorderTraversal(root) << endl;
    // }
    return 0;
}
#endif