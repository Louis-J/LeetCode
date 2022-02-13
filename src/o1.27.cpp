#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({ 4,2,7,1,3,6,9 });
        cout << Solution().mirrorTree(root) << endl;
    }
    cout << " 2:" << endl;
    {
    }
    return 0;
}
#endif