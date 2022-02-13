#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    static     bool isSymmetric(TreeNode* A, TreeNode* B) {
        if (A->val != B->val)
            return false;
        if (A->left == nullptr || B->right == nullptr) {
            if (A->left != B->right) return false;
        } else {
            if (!isSymmetric(A->left, B->right)) return false;
        }
        if (A->right == nullptr || B->left == nullptr) {
            if (A->right != B->left) return false;
        } else {
            if (!isSymmetric(A->right, B->left)) return false;
        }
        return true;

    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr || root->right == nullptr)
            return root->left == root->right;
        else
            return isSymmetric(root->right, root->left);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({ 1,2,2,3,4,4,3 });
        cout << Solution().isSymmetric(root) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({ 1,2,2,nullopt,3,nullopt,3 });
        cout << Solution().isSymmetric(root) << endl;
    }
    return 0;
}
#endif