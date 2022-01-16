#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static int digui(TreeNode* root) {
        int maxS = root->val;
        int sing = 0, doub = 0;//单链/双链
        if(root->left != nullptr) {
            maxS = max(maxS, digui(root->left));
            if(root->left->val > 0)
                sing = doub = root->left->val;
        }
        if(root->right != nullptr) {
            maxS = max(maxS, digui(root->right));
            if(root->right->val > sing)
                sing = root->right->val;
            if(root->right->val > 0)
                doub += root->right->val;
        }
        maxS = max({maxS, root->val+sing, root->val+doub});
        root->val += sing;
        return maxS;
    }
public:
    int maxPathSum0(TreeNode* root) {
        return digui(root);
        // int maxS = root->val;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1, 2, 3});
        cout << Solution().maxPathSum(root) << endl;
    }
    cout << "2:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({-10, 9, 20, nullopt, nullopt, 15, 7});
        cout << Solution().maxPathSum(root) << endl;
    }
    cout << "3:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({5, 4, 8, 11, nullopt, 13, 4, 7, 2, nullopt, nullopt, nullopt, 1});
        cout << Solution().maxPathSum(root) << endl;
    }
    return 0;
}
#endif